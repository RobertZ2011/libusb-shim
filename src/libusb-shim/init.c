#include "log.h"
#include "shim.h"

__attribute__((constructor)) static void libusb_shim_init(void) {
    libusb_shim_init_log();
    libusb_shim_init_shim();
}

__attribute__((destructor)) static void libusb_shim_fini(void) {
    libusb_shim_fini_shim();
    libusb_shim_fini_log();
}
