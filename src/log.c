#include "log.h"

#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sysexits.h>
#include <string.h>

#define MIN(x, y) ((x) > (y)) ? y : x

FILE *log_handle;

void libusb_shim_init_log(void) {
    char *log_path = getenv(LIBUSB_SHIM_LOG_PATH);
    char cwd[1024];

    if(!getcwd(cwd, 1024)) {
        exit(EX_SOFTWARE);
    }

    /* Open the log file */
    if(!log_path) {
        /* one +1 for the /, another for null */
        log_path = malloc(strlen(cwd) + 1 + strlen(DEFAULT_LOG_FILE) + 1);
        sprintf(log_path, "%s/%s", cwd, DEFAULT_LOG_FILE);
    }

    if(strcmp(log_path, "stderr") == 0) {
        log_handle = stderr;
    }
    else
    if(strcmp(log_path, "stdout") == 0) {
        log_handle = stdout;
    }
    else {
        log_handle= fopen(log_path, "w");
    }

    log_handle = fopen(log_path, "w");
    if(!log_handle) {
        exit(EX_CANTCREAT);
    }

    if(!getenv(LIBUSB_SHIM_LOG_PATH)) {
        free(log_path);
    }

    libusb_shim_log_msg("Log start");
}

void libusb_shim_fini_log(void) {
    if(log_handle) {
        libusb_shim_log_msg("Closing log");
        if(log_handle != stdout && log_handle != stderr) {
            fclose(log_handle);
        }
    }
}

void libusb_shim_log_msg(const char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    vfprintf(log_handle, fmt, args);
    fputc('\n', log_handle);
    va_end(args);
}

void libusb_shim_log_data(void *data, int size) {
    uint32_t *ints = (uint32_t*) ints;
    int remaining_ints = size / sizeof(uint32_t);
    int remainder = size % sizeof(uint32_t);
    int i;

    while(remaining_ints > 0) {
        for(i = 0; i < MIN(remaining_ints, 9); i++) {
            fprintf(log_handle, "%x ", ints[i]);
        }

        fputc('\n', log_handle);

        remaining_ints -= i;
        ints += i;
    }

    if(remainder != 0) {
        for(i = 0; i < remainder; i++) {
            fprintf(log_handle, "%x ", ints[i]);
        }

        fputc('\n', log_handle);
    }
}

const char *libusb_shim_debug_level_string(int level) {
    switch(level) {
        case LIBUSB_LOG_LEVEL_NONE:
            return "LIBUSB_LOG_LEVEL_NONE";

        case LIBUSB_LOG_LEVEL_ERROR:
            return "LIBUSB_LOG_LEVEL_ERROR";

        case LIBUSB_LOG_LEVEL_WARNING:
            return "LIBUSB_LOG_LEVEL_WARNING";

        case LIBUSB_LOG_LEVEL_INFO:
            return "LIBUSB_LOG_LEVEL_INFO";

        case LIBUSB_LOG_LEVEL_DEBUG:
            return "LIBUSB_LOG_LEVEL_DEBUG";

        default:
            return "UNKNOWN";
    }
}

const char *libusb_shim_speed_string(int speed) {
    switch(speed) {
        case LIBUSB_SPEED_UNKNOWN:
            return "LIBUSB_SPEED_UNKNOWN";

        case LIBUSB_SPEED_LOW:
            return "LIBUSB_SPEED_LOW";

        case LIBUSB_SPEED_FULL:
            return "LIBUSB_SPEED_FULL";

        case LIBUSB_SPEED_HIGH:
            return "LIBUSB_SPEED_HIGH";

        case LIBUSB_SPEED_SUPER:
            return "LIBUSB_SPEED_SUPER";

        default:
            return "UNKNOWN";
    }
}

const char *libusb_shim_hotplug_event_string(int event) {
    switch(event) {
#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
        case LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED:
            return "LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED";

        case LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT:
            return "LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT";
#endif

        default:
            return "UNKNOWN";
    }
}

const char *libusb_shim_hotplug_flag_string(int flag) {
    switch(flag) {
#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
        case LIBUSB_HOTPLUG_NO_FLAGS:
            return "LIBUSB_HOTPLUG_NO_FLAGS";

        case LIBUSB_HOTPLUG_ENUMERATE:
            return "LIBUSB_HOTPLUG_ENUMERATE";
#endif

        default:
            return "UNKNOWN";
    }
}
