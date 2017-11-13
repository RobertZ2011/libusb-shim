#ifndef LIBUSB_SHIM_LOG
#define LIBUSB_SHIM_LOG

#define DEFAULT_LOG_FILE "libusb-shim-log"
#define LIBUSB_SHIM_LOG_PATH "LIBUSB_SHIM_LOG_PATH"

void libusb_shim_init_log(void);
void libusb_shim_fini_log(void);

void libusb_shim_log_msg(const char *fmt, ...);
void libusb_shim_log_data(void *data, int size);

const char *libusb_shim_debug_level_string(int level);
const char *libusb_shim_speed_string(int speed);

const char *libusb_shim_hotplug_event_string(int event);
const char *libusb_shim_hotplug_flag_string(int flag);

#endif
