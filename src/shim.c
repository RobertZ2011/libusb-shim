#include <dlfcn.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sysexits.h>

#include "log.h"
#include "shim.h"

void *libusb_handle = NULL;

libusb_alloc_streams_t _libusb_alloc_streams = NULL;
libusb_alloc_transfer_t _libusb_alloc_transfer = NULL;

libusb_attach_kernel_driver_t _libusb_attach_kernel_driver = NULL;
libusb_bulk_transfer_t _libusb_bulk_transfer = NULL;

libusb_cancel_transfer_t _libusb_cancel_transfer = NULL;
libusb_claim_interface_t _libusb_claim_interface = NULL;
libusb_clear_halt_t _libusb_clear_halt = NULL;
libusb_close_t _libusb_close = NULL;
libusb_control_transfer_t _libusb_control_transfer = NULL;
libusb_detach_kernel_driver_t _libusb_detach_kernel_driver = NULL;
libusb_error_name_t _libusb_error_name = NULL;
libusb_event_handler_active_t _libusb_event_handler_active = NULL;
libusb_event_handling_ok_t _libusb_event_handling_ok = NULL;

libusb_exit_t _libusb_exit = NULL;
libusb_free_bos_descriptor_t _libusb_free_bos_descriptor = NULL;
libusb_free_config_descriptor_t _libusb_free_config_descriptor = NULL;
libusb_free_container_id_descriptor_t _libusb_free_container_id_descriptor = NULL;
libusb_free_device_list_t _libusb_free_device_list = NULL;
libusb_free_pollfds_t _libusb_free_pollfds = NULL;
libusb_free_ss_endpoint_companion_descriptor_t _libusb_free_ss_endpoint_companion_descriptor = NULL;
libusb_free_ss_usb_device_capability_descriptor_t _libusb_free_ss_usb_device_capability_descriptor = NULL;
libusb_free_streams_t _libusb_free_streams = NULL;
libusb_free_transfer_t _libusb_free_transfer = NULL;
libusb_free_usb_2_0_extension_descriptor_t _libusb_free_usb_2_0_extension_descriptor = NULL;

libusb_get_active_config_descriptor_t _libusb_get_active_config_descriptor = NULL;
libusb_get_bos_descriptor_t _libusb_get_bos_descriptor = NULL;
libusb_get_bus_number_t _libusb_get_bus_number = NULL;
libusb_get_config_descriptor_t _libusb_get_config_descriptor = NULL;
libusb_get_config_descriptor_by_value_t _libusb_get_config_descriptor_by_value = NULL;
libusb_get_configuration_t _libusb_get_configuration = NULL;
libusb_get_container_id_descriptor_t _libusb_get_container_id_descriptor = NULL;
libusb_get_device_t _libusb_get_device = NULL;
libusb_get_device_address_t _libusb_get_device_address = NULL;
libusb_get_device_descriptor_t _libusb_get_device_descriptor = NULL;
libusb_get_device_list_t _libusb_get_device_list = NULL;
libusb_get_device_speed_t _libusb_get_device_speed = NULL;
libusb_get_max_iso_packet_size_t _libusb_get_max_iso_packet_size = NULL;
libusb_get_max_packet_size_t _libusb_get_max_packet_size = NULL;
libusb_get_next_timeout_t _libusb_get_next_timeout = NULL;
libusb_get_parent_t _libusb_get_parent = NULL;
libusb_get_pollfds_t _libusb_get_pollfds = NULL;
libusb_get_port_number_t _libusb_get_port_number = NULL;
libusb_get_port_numbers_t _libusb_get_port_numbers = NULL;
libusb_get_port_path_t _libusb_get_port_path = NULL;
libusb_get_ss_usb_device_capability_descriptor_t _libusb_get_ss_usb_device_capability_descriptor = NULL;
libusb_get_ss_endpoint_companion_descriptor_t _libusb_get_ss_endpoint_companion_descriptor = NULL;
libusb_get_string_descriptor_ascii_t _libusb_get_string_descriptor_ascii = NULL;
libusb_get_usb_2_0_extension_descriptor_t _libusb_get_usb_2_0_extension_descriptor = NULL;
libusb_get_version_t _libusb_get_version = NULL;

libusb_handle_events_t _libusb_handle_events = NULL;
libusb_handle_events_completed_t _libusb_handle_events_completed = NULL;
libusb_handle_events_locked_t _libusb_handle_events_locked = NULL;
libusb_handle_events_timeout_t _libusb_handle_events_timeout = NULL;
libusb_handle_events_timeout_completed_t _libusb_handle_events_timeout_completed = NULL;
libusb_has_capability_t _libusb_has_capability = NULL;
libusb_hotplug_deregister_callback_t _libusb_hotplug_deregister_callback = NULL;
libusb_hotplug_register_callback_t _libusb_hotplug_register_callback = NULL;

libusb_init_t _libusb_init = NULL;
libusb_interrupt_transfer_t _libusb_interrupt_transfer = NULL;

libusb_kernel_driver_active_t _libusb_kernel_driver_active = NULL;

libusb_lock_events_t _libusb_lock_events = NULL;
libusb_lock_event_waiters_t _libusb_lock_event_waiters = NULL;

libusb_open_t _libusb_open = NULL;
libusb_open_device_with_vid_pid_t _libusb_open_device_with_vid_pid = NULL;

libusb_pollfds_handle_timeouts_t _libusb_pollfds_handle_timeouts = NULL;

libusb_ref_device_t _libusb_ref_device = NULL;
libusb_release_interface_t _libusb_release_interface = NULL;
libusb_reset_device_t _libusb_reset_device = NULL;

libusb_set_auto_detach_kernel_driver_t _libusb_set_auto_detach_kernel_driver = NULL;
libusb_set_configuration_t _libusb_set_configuration = NULL;
libusb_set_debug_t _libusb_set_debug = NULL;
libusb_set_interface_alt_setting_t _libusb_set_interface_alt_setting = NULL;
libusb_setlocale_t _libusb_setlocale = NULL;
libusb_set_pollfd_notifiers_t _libusb_set_pollfd_notifiers = NULL;
libusb_strerror_t _libusb_strerror = NULL;
libusb_submit_transfer_t _libusb_submit_transfer = NULL;

libusb_transfer_get_stream_id_t _libusb_transfer_get_stream_id = NULL;
libusb_transfer_set_stream_id_t _libusb_transfer_set_stream_id = NULL;
libusb_try_lock_events_t _libusb_try_lock_events = NULL;

libusb_unlock_events_t _libusb_unlock_events = NULL;
libusb_unlock_event_waiters_t _libusb_unlock_event_waiters = NULL;
libusb_unref_device_t _libusb_unref_device = NULL;

libusb_wait_for_event_t _libusb_wait_for_event = NULL;

static void *load_function(const char *name) {
    void *func = dlsym(libusb_handle, name);
    if(!func) {
        libusb_shim_log_msg("Failed to load function %s: %s\n", func, dlerror());
        exit(EX_OSERR);
    }
    return func;
}

static void *load_function_version(const char *name, uint32_t version) {
#ifdef LIBUSB_API_VERSION
    if(LIBUSB_API_VERSION >= version) {
        return load_function(name);
    }
    else {
        return NULL;
    }
#else
    return NULL;
#endif
}

void libusb_shim_init_shim(void) {
    char *libusb_path = getenv(LIBUSB_PATH);
    const struct libusb_version *version;

    /* Open the library */
    if(!libusb_path) {
        libusb_path = "libusb-1.0.so";
    }

    libusb_shim_log_msg("Opening libusb at %s", libusb_path);
    libusb_handle = dlopen(libusb_path, RTLD_NOW | RTLD_LOCAL);
    if(!libusb_handle) {
        /* Seems like the best error code for this case */
        libusb_shim_log_msg("Cannot open libusb.so: %s\n", dlerror());
        exit(EX_OSERR);
    }

    _libusb_alloc_streams = load_function("libusb_alloc_streams");
    _libusb_alloc_transfer = load_function("libusb_alloc_transfer");

    _libusb_attach_kernel_driver = load_function("libusb_attach_kernel_driver");
    _libusb_bulk_transfer = load_function("libusb_bulk_transfer");
    _libusb_cancel_transfer = load_function("libusb_cancel_transfer");

    _libusb_claim_interface = load_function("libusb_claim_interface");
    _libusb_clear_halt = load_function("libusb_clear_halt");
    _libusb_close = load_function("libusb_close");
    _libusb_control_transfer = load_function("libusb_control_transfer");
    _libusb_detach_kernel_driver = load_function("libusb_detach_kernel_driver");
    _libusb_error_name = load_function("libusb_error_name");
    _libusb_event_handler_active = load_function("libusb_event_handler_active");
    _libusb_event_handling_ok = load_function("libusb_event_handling_ok");
    _libusb_exit = load_function("libusb_exit");

    _libusb_free_bos_descriptor = load_function("libusb_free_bos_descriptor");
    _libusb_free_config_descriptor = load_function("libusb_free_config_descriptor");
    _libusb_free_container_id_descriptor = load_function("libusb_free_container_id_descriptor");
    _libusb_free_device_list = load_function("libusb_free_device_list");
    _libusb_free_pollfds = load_function("libusb_free_pollfds");
    _libusb_free_ss_endpoint_companion_descriptor = load_function("libusb_free_ss_endpoint_companion_descriptor");
    _libusb_free_streams = load_function("libusb_free_streams");
    _libusb_free_ss_usb_device_capability_descriptor = load_function("libusb_free_ss_usb_device_capability_descriptor");
    _libusb_free_streams = load_function("libusb_free_streams");
    _libusb_free_transfer = load_function("libusb_free_transfer");
    _libusb_free_usb_2_0_extension_descriptor = load_function("libusb_free_usb_2_0_extension_descriptor");

    _libusb_get_active_config_descriptor = load_function("libusb_get_active_config_descriptor");
    _libusb_get_bos_descriptor = load_function("libusb_get_bos_descriptor");
    _libusb_get_bus_number = load_function("libusb_get_bus_number");
    _libusb_get_config_descriptor = load_function("libusb_get_config_descriptor");
    _libusb_get_config_descriptor_by_value = load_function("libusb_get_config_descriptor_by_value");
    _libusb_get_configuration = load_function("libusb_get_configuration");
    _libusb_get_container_id_descriptor = load_function("libusb_get_container_id_descriptor");
    _libusb_get_device = load_function("libusb_get_device");
    _libusb_get_device_address = load_function("libusb_get_device_address");
    _libusb_get_device_descriptor = load_function("libusb_get_device_descriptor");
    _libusb_get_device_list = load_function("libusb_get_device_list");
    _libusb_get_device_speed = load_function("libusb_get_device_speed");
    _libusb_get_max_iso_packet_size = load_function("libusb_get_max_iso_packet_size");
    _libusb_get_max_packet_size = load_function("libusb_get_max_packet_size");
    _libusb_get_next_timeout = load_function("libusb_get_next_timeout");
    _libusb_get_parent = load_function("libusb_get_parent");
    _libusb_get_pollfds = load_function("libusb_get_pollfds");
    _libusb_get_port_number = load_function("libusb_get_port_number");
    _libusb_get_port_numbers = load_function("libusb_get_port_numbers");
    _libusb_get_port_path = load_function("libusb_get_port_path");
    _libusb_get_ss_endpoint_companion_descriptor = load_function("libusb_get_ss_endpoint_companion_descriptor");
    _libusb_get_ss_usb_device_capability_descriptor = load_function("libusb_get_ss_usb_device_capability_descriptor");
    _libusb_get_string_descriptor_ascii = load_function("libusb_get_string_descriptor_ascii");
    _libusb_get_usb_2_0_extension_descriptor = load_function("libusb_get_usb_2_0_extension_descriptor");
    _libusb_get_version = load_function("libusb_get_version");

    _libusb_handle_events = load_function("libusb_handle_events");
    _libusb_handle_events_completed = load_function("libusb_handle_events_completed");
    _libusb_handle_events_locked = load_function("libusb_handle_events_locked");
    _libusb_handle_events_timeout = load_function("libusb_handle_events_timeout");
    _libusb_has_capability = load_function("libusb_has_capability");
    _libusb_hotplug_deregister_callback = load_function_version("libusb_hotplug_deregister_callback", 0x01000102);
    _libusb_hotplug_register_callback = load_function_version("libusb_hotplug_register_callback", 0x01000102);

    _libusb_init = load_function("libusb_init");
    _libusb_interrupt_transfer = load_function("libusb_interrupt_transfer");

    _libusb_kernel_driver_active = load_function("libusb_kernel_driver_active");

    _libusb_lock_events = load_function("libusb_lock_events");
    _libusb_lock_event_waiters = load_function("libusb_lock_event_waiters");

    _libusb_open = load_function("libusb_open");
    _libusb_open_device_with_vid_pid = load_function("libusb_open_device_with_vid_pid");

    _libusb_pollfds_handle_timeouts = load_function("libusb_pollfds_handle_timeouts");
    _libusb_handle_events_timeout_completed = load_function("libusb_handle_events_timeout_completed");

    _libusb_ref_device = load_function("libusb_ref_device");
    _libusb_release_interface = load_function("libusb_release_interface");
    _libusb_reset_device = load_function("libusb_reset_device");

    _libusb_set_auto_detach_kernel_driver = load_function("libusb_set_auto_detach_kernel_driver");
    _libusb_set_configuration = load_function("libusb_set_configuration");
    _libusb_set_debug = load_function("libusb_set_debug");
    _libusb_set_interface_alt_setting = load_function("libusb_set_interface_alt_setting");
    _libusb_setlocale = load_function("libusb_setlocale");
    _libusb_set_pollfd_notifiers = load_function("libusb_set_pollfd_notifiers");
    _libusb_strerror = load_function("libusb_strerror");
    _libusb_submit_transfer = load_function("libusb_submit_transfer");

    _libusb_transfer_get_stream_id = load_function_version("libusb_transfer_get_stream_id", 0x01000103);
    _libusb_transfer_set_stream_id = load_function_version("libusb_transfer_set_stream_id", 0x01000103);
    _libusb_try_lock_events = load_function("libusb_try_lock_events");

    _libusb_unlock_events = load_function("libusb_unlock_events");
    _libusb_unlock_event_waiters = load_function("libusb_unlock_event_waiters");
    _libusb_unref_device = load_function("libusb_unref_device");

    _libusb_wait_for_event = load_function("libusb_wait_for_event");

    version = _libusb_get_version();
    libusb_shim_log_msg("libusb version: %d.%d.%d.%d%s",
        version->major,
        version->minor,
        version->micro,
        version->nano,
        version->rc
    );
}

void libusb_shim_fini_shim(void) {
    if(libusb_handle) {
        libusb_shim_log_msg("Closing library");
        dlclose(libusb_handle);
    }
}

int libusb_alloc_streams(libusb_device_handle *dev, uint32_t num_streams, unsigned char *endpoints, int num_endpoints) {
    int err = _libusb_alloc_streams(dev, num_streams, endpoints, num_endpoints);

    libusb_shim_log_msg("libusb_alloc_streams@%s[%d]| dev: %p, num_streams: %u, num_endpoints: %d\n\tendpoints:", _libusb_error_name(err), err);

    for(int i = 0; i < num_endpoints; i++) {
        libusb_shim_log_msg("\t\t%x", endpoints[i]);
    }

    return err;
}

struct libusb_transfer *libusb_alloc_transfer(int iso_packets) {
    struct libusb_transfer *transfer = _libusb_alloc_transfer(iso_packets);
    libusb_shim_log_msg("libusb_alloc_transfer@%p| iso_packets: %d",
        transfer,
        iso_packets
    );
    return transfer;
}

int libusb_attach_kernel_driver(libusb_device_handle *dev, int interface_number) {
    int err = _libusb_attach_kernel_driver(dev, interface_number);
    libusb_shim_log_msg("libusb_attach_kernel@%s[%d]| dev: , interface_number: %d",
        _libusb_error_name(err),
        err,
        interface_number
    );
    return err;
}

int libusb_bulk_transfer(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout) {
    int err = _libusb_bulk_transfer(dev_handle, endpoint, data, length, transferred, timeout);
    libusb_shim_log_msg("libusb_bulk_transfer@%s[%d]| dev_handle: %p, endpoint: %x, data: %p, length: %d, transferred: %d, timeout: %u",
        _libusb_error_name(err),
        err,
        dev_handle,
        endpoint,
        data,
        length,
        *transferred,
        timeout
    );
    libusb_shim_log_data(data, *transferred);
    return err;
}

int libusb_cancel_transfer(struct libusb_transfer *transfer) {
    int err = _libusb_cancel_transfer(transfer);
    libusb_shim_log_msg("libusb_cancel_transfer@%s[%d]| transfer: %p",
        _libusb_error_name(err),
        err,
        transfer
    );
    return err;
}

void libusb_close(libusb_device_handle *dev_handle) {
    _libusb_close(dev_handle);
    libusb_shim_log_msg("libusb_close| dev_handle: %p", dev_handle);
}

int libusb_claim_interface(libusb_device_handle *dev, int interface_number) {
    int err = _libusb_claim_interface(dev, interface_number);
    libusb_shim_log_msg("libusb_cancel_transfer@s[%d]| dev: %p, interface_number: %d",
        _libusb_error_name(err),
        err,
        dev,
        interface_number
    );
    return err;
}

int libusb_clear_halt(libusb_device_handle *dev, unsigned char endpoint) {
    int err = _libusb_clear_halt(dev, endpoint);
    libusb_shim_log_msg("libusb_clear_halt@%s[%d]| dev: %p, endpoint: %x",
        _libusb_error_name(err),
        err,
        dev,
        endpoint
    );
    return err;
}

int libusb_control_transfer(libusb_device_handle *dev_handle, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, unsigned int timeout) {
    int err = _libusb_control_transfer(dev_handle, bmRequestType, bRequest, wValue, wIndex, data, wLength, timeout);
    //TODO: better log info
    libusb_shim_log_msg("libusb_control_transfer@%s[%d]|",
        _libusb_error_name(err),
        err
    );
    return err;
}

int libusb_detach_kernel_driver(libusb_device_handle *dev, int interface_number) {
    int err = _libusb_detach_kernel_driver(dev, interface_number);
    //TODO: better log info
    libusb_shim_log_msg("libusb_detach_kernel_driver@%s[%d]|",
        _libusb_error_name(err),
        err
    );
    return err;
}

const char *libusb_error_name(int error_code) {
    const char *name = _libusb_error_name(error_code);
    libusb_shim_log_msg("libusb_error_name@s| error_code: %d\n", name, error_code);
    return name;
}

int libusb_event_handler_active(libusb_context *ctx) {
    int active = _libusb_event_handler_active(ctx);
    libusb_shim_log_msg("libusb_event_handler_active@%d| ctx: %p", active, ctx);
    return active;
}

int libusb_event_handling_ok(libusb_context *ctx) {
    int ok = _libusb_event_handling_ok(ctx);
    libusb_shim_log_msg("libusb_event_handling_ok@%d| ctx: %p", ok, ctx);
    return ok;
}

void libusb_exit(libusb_context *ctx) {
    libusb_shim_log_msg("libusb_exit| ctx: %p", ctx);
    _libusb_exit(ctx);
}

void libusb_free_bos_descriptor(struct libusb_bos_descriptor *bos) {
    libusb_shim_log_msg("libusb_free_bos_descriptor| bos: %p", bos);
    _libusb_free_bos_descriptor(bos);
}

void libusb_free_config_descriptor(struct libusb_config_descriptor *config) {
    libusb_shim_log_msg("libusb_free_config_descriptor| config: %p", config);
    _libusb_free_config_descriptor(config);
}

void libusb_free_container_id_descriptor(struct libusb_container_id_descriptor *container_id) {
    libusb_shim_log_msg("libusb_free_container_id_descriptor| container_id: %p", container_id);
    _libusb_free_container_id_descriptor(container_id);
}

void libusb_free_device_list(libusb_device **list, int unref_devices) {
    //TODO: more log detail
    libusb_shim_log_msg("libusb_free_device_list| list: %p, unref_devices: %d", list, unref_devices);
    _libusb_free_device_list(list, unref_devices);
}

void libusb_free_pollfds(const struct libusb_pollfd **pollfds) {
    //TODO: more log detail
    libusb_shim_log_msg("libusb_free_pollfds| pollfds: %p", pollfds);
    _libusb_free_pollfds(pollfds);
}

void libusb_free_ss_endpoint_companion_descriptor(struct libusb_ss_endpoint_companion_descriptor *ep_comp) {
    libusb_shim_log_msg("libusb_free_ss_endpoint_companion_descriptor| ep_comp: %p", ep_comp);
    _libusb_free_ss_endpoint_companion_descriptor(ep_comp);
}

void libusb_free_ss_usb_device_capability_descriptor(struct libusb_ss_usb_device_capability_descriptor *ss_usb_device_cap) {
    libusb_shim_log_msg("libusb_free_ss_usb_device_capability_descriptor| ss_usb_device_cap: %p", ss_usb_device_cap);
    _libusb_free_ss_usb_device_capability_descriptor(ss_usb_device_cap);
}

int libusb_free_streams(libusb_device_handle *dev, unsigned char *endpoints, int num_endpoints) {
    int err = _libusb_free_streams(dev, endpoints, num_endpoints);
    //TODO: more log detail
    libusb_shim_log_msg("libusb_free_streams@%s[%d]| dev: %p, endpoints: %p, num_endpoints: %d",
        _libusb_error_name(err),
        err,
        dev,
        endpoints,
        num_endpoints
    );
    return err;
}

void libusb_free_transfer(struct libusb_transfer *transfer) {
    libusb_shim_log_msg("libusb_free_transfer| transfer: %p", transfer);
    _libusb_free_transfer(transfer);
}


void libusb_free_usb_2_0_extension_descriptor(struct libusb_usb_2_0_extension_descriptor *usb_2_0_extension) {
    libusb_shim_log_msg("libusb_free_usb_2_0_extension_descriptor| usb_2_0_extension: %p");
    _libusb_free_usb_2_0_extension_descriptor(usb_2_0_extension);
}


int libusb_get_active_config_descriptor(libusb_device *dev, struct libusb_config_descriptor **config) {
    int err = _libusb_get_active_config_descriptor(dev, config);
    libusb_shim_log_msg("libusb_get_active_config_descriptor@%s[%d]| dev: %p, config: %p",
        _libusb_error_name(err),
        err,
        dev,
        config
    );
    return err;
}

int libusb_get_bos_descriptor(libusb_device_handle *handle, struct libusb_bos_descriptor **bos) {
    //TODO: better logging
    int err = _libusb_get_bos_descriptor(handle, bos);
    libusb_shim_log_msg("libusb_get_bos_descriptor@%s[%d]| handle: %p, bos: %p",
        _libusb_error_name(err),
        err,
        handle,
        bos
    );
    return err;
}

uint8_t libusb_get_bus_number(libusb_device *dev) {
    uint8_t number = _libusb_get_bus_number(dev);
    libusb_shim_log_msg("libusb_get_bus_number@%o| dev: %p", number, dev);
    return number;
}

int libusb_get_config_descriptor(libusb_device *dev, uint8_t config_index, struct libusb_config_descriptor **config) {
    int err = _libusb_get_config_descriptor(dev, config_index, config);
    libusb_shim_log_msg("libusb_get_config_descriptor@%s[%d]| dev: %p, config_index: %d, config: %p",
        _libusb_error_name(err),
        err,
        dev,
        config_index,
        config
    );
    return err;
}

int libusb_get_config_descriptor_by_value(libusb_device *dev, uint8_t bConfigurationValue, struct libusb_config_descriptor **config) {
    int err = _libusb_get_config_descriptor_by_value(dev, bConfigurationValue, config);
    libusb_shim_log_msg("libusb_get_config_descriptor_by_value@%s[%d]| dev: %p, bConfigurationValue: %d, config: %p",
        _libusb_error_name(err),
        err,
        dev,
        bConfigurationValue,
        config
    );
    return err;
}


int libusb_get_configuration(libusb_device_handle *dev, int *config) {
    int err = _libusb_get_configuration(dev, config);
    libusb_shim_log_msg("libusb_get_configuration@%s[%d]| dev: %p, config: %d[%p]",
        _libusb_error_name(err),
        err,
        dev,
        *config,
        config
    );
    return err;
}

int libusb_get_container_id_descriptor(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_container_id_descriptor **container_id) {
    int err = libusb_get_container_id_descriptor(ctx, dev_cap, container_id);
    libusb_shim_log_msg("libusb_get_container_id_descriptor@%s[%d]| ctx: %p, dev_cap: %p, container_id: %p",
        _libusb_error_name(err),
        err,
        ctx,
        dev_cap,
        container_id
    );
    return err;
}


libusb_device *libusb_get_device(libusb_device_handle *dev_handle) {
    libusb_device *device = _libusb_get_device(dev_handle);
    libusb_shim_log_msg("libusb_get_device@%p| dev_handle: %p",
        device,
        dev_handle
    );
    return device;
}

uint8_t libusb_get_device_address(libusb_device *dev) {
    uint8_t address = _libusb_get_device_address(dev);
    libusb_shim_log_msg("libusb_get_device_address@%o| dev: %p",
        address,
        dev
    );
    return address;
}

int libusb_get_device_descriptor(libusb_device *dev, struct libusb_device_descriptor *desc) {
    int err = _libusb_get_device_descriptor(dev, desc);
    libusb_shim_log_msg("libusb_get_device_descriptor@%s[%d]| dev: %p, desc: %p",
        _libusb_error_name(err),
        err,
        dev,
        desc
    );
    return err;
}

ssize_t libusb_get_device_list(libusb_context *ctx, libusb_device ***list) {
    ssize_t res = _libusb_get_device_list(ctx, list);
    libusb_shim_log_msg("libusb_get_device_list@%d| ctx: %p, list: %p",
        res,
        ctx,
        list
    );
    return res;
}

int libusb_get_device_speed(libusb_device *dev) {
    int speed = _libusb_get_device_speed(dev);
    libusb_shim_log_msg("libusb_get_device_speed@%s[%d]| dev: %p",
        libusb_shim_speed_string(speed),
        speed,
        dev
    );
    return speed;
}


int libusb_get_max_iso_packet_size(libusb_device *dev, unsigned char endpoint) {
    //TODO: proper error handling
    int res = _libusb_get_max_iso_packet_size(dev, endpoint);
    libusb_shim_log_msg("libusb_get_max_iso_packet_size@%d| dev: %p, endpoint: %x",
        res,
        dev,
        endpoint
    );
    return res;
}


int libusb_get_max_packet_size(libusb_device *dev, unsigned char endpoint) {
    //TODO: proper error handling
    int res = _libusb_get_max_packet_size(dev, endpoint);
    libusb_shim_log_msg("libusb_get_max_iso_packet_size@%d| dev: %p, endpoint: %x",
        res,
        dev,
        endpoint
    );
    return res;
}


int libusb_get_next_timeout(libusb_context *ctx, struct timeval *tv) {
    //TODO: better log ouput
    int err = _libusb_get_next_timeout(ctx, tv);
    libusb_shim_log_msg("libusb_get_next_timeout@%s[%d]| ctx: %p, tv %p",
        _libusb_error_name(err),
        err,
        ctx,
        tv
    );
    return err;
}


libusb_device *libusb_get_parent(libusb_device *dev) {
    //TODO: better log info
    libusb_device *device = _libusb_get_parent(dev);
    libusb_shim_log_msg("libusb_get_parent@%p| dev: %p",
        device,
        dev
    );
    return device;
}

const struct libusb_pollfd **libusb_get_pollfds(libusb_context *ctx) {
    //TODO: better log info
    const struct libusb_pollfd **fds = _libusb_get_pollfds(ctx);
    libusb_shim_log_msg("libusb_get_pollfds@%p| ctx: %p",
        fds,
        ctx
    );
    return fds;
}

uint8_t libusb_get_port_number(libusb_device *dev) {
    uint8_t port = _libusb_get_port_number(dev);
    libusb_shim_log_msg("libusb_get_port_number@%d| dev: %p",
        port,
        dev
    );
    return port;
}

int libusb_get_port_numbers(libusb_device *dev, uint8_t *port_numbers, int port_numbers_len) {
    int err = _libusb_get_port_numbers(dev, port_numbers, port_numbers_len);
    libusb_shim_log_msg("libusb_get_port_numbers@%s[%d]| dev: %p, port_numbers: %p, port_numbers_len: %d",
        _libusb_error_name(err),
        err,
        dev,
        port_numbers,
        port_numbers_len
    );
    for(int i = 0; i < port_numbers_len; i++) {
        libusb_shim_log_msg("\t%d", port_numbers[i]);
    }
    return err;
}

int libusb_get_port_path(libusb_context *ctx, libusb_device *dev, uint8_t *port_numbers, uint8_t port_numbers_len) {
    int err = _libusb_get_port_path(ctx, dev, port_numbers, port_numbers_len);
    libusb_shim_log_msg("libusb_get_port_path@%s[%d]| dev: %p, port_numbers: %p, port_numbers_len: %d",
        _libusb_error_name(err),
        err,
        dev,
        port_numbers,
        port_numbers_len
    );
    for(int i = 0; i < port_numbers_len; i++) {
        libusb_shim_log_msg("\t%d", port_numbers[i]);
    }
    return err;
}

int libusb_get_ss_endpoint_companion_descriptor(struct libusb_context *ctx, const struct libusb_endpoint_descriptor *endpoint, struct libusb_ss_endpoint_companion_descriptor **ep_comp) {
    int res = _libusb_get_ss_endpoint_companion_descriptor(ctx, endpoint, ep_comp);
    libusb_shim_log_msg("libusb_get_ss_endpoint_companion_descriptor@%s[%d]| ctx: %p, endpoint: %p, ep_comp: %p",
        _libusb_error_name(res),
        res,
        ctx,
        endpoint,
        ep_comp
    );
    return res;
}


int libusb_get_ss_usb_device_capability_descriptor(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_ss_usb_device_capability_descriptor **ss_usb_device_cap) {
    int err = _libusb_get_ss_usb_device_capability_descriptor(ctx, dev_cap, ss_usb_device_cap);
    libusb_shim_log_msg("libusb_get_ss_usb_device_capability_descriptor@%s[%d]| ctx: %p, dev_cap: %p, ss_usb_device_cap: %p",
        _libusb_error_name(err),
        err,
        ctx,
        dev_cap,
        ss_usb_device_cap
    );
    return err;
}


int libusb_get_string_descriptor_ascii(libusb_device_handle *dev, uint8_t desc_index, unsigned char *data, int length) {
    int err = _libusb_get_string_descriptor_ascii(dev, desc_index, data, length);
    libusb_shim_log_msg("libusb_get_string_descriptor_ascii@%d| dev: %p, desc_index: %d, data: %s[%p], length: %d",
        err,
        dev,
        desc_index,
        data,
        length
    );
    return err;
}

int libusb_get_usb_2_0_extension_descriptor(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_usb_2_0_extension_descriptor **usb_2_0_extension) {
    int err = _libusb_get_usb_2_0_extension_descriptor(ctx, dev_cap, usb_2_0_extension);
    libusb_shim_log_msg("libusb_get_usb_2_0_extension_descriptor@%s[%d]| ctx: %p, dev_cap: %p, usb_2_0_extension: %p",
        _libusb_error_name(err),
        err,
        ctx,
        dev_cap,
        usb_2_0_extension
    );
    return err;
}

const struct libusb_version *libusb_get_version(void) {
    const struct libusb_version *v = _libusb_get_version();
    libusb_shim_log_msg("libusb_version@%d.%d.%d.%d%s[%p]|",
        v->major,
        v->minor,
        v->micro,
        v->nano,
        v->rc
    );
    return v;
}

int libusb_handle_events(libusb_context *ctx) {
    int err = _libusb_handle_events(ctx);
    libusb_shim_log_msg("libusb_handle_events@%s[%p]| ctx: %p",
        _libusb_error_name(err),
        err,
        ctx
    );
    return err;
}

int libusb_handle_events_completed(libusb_context *ctx, int *completed) {
    int err = _libusb_handle_events_completed(ctx, completed);
    libusb_shim_log_msg("libusb_handle_events_completed@%s[%d]| ctx: %p, completed: %d[%p]",
        _libusb_error_name(err),
        err,
        ctx,
        *completed,
        completed
    );
    return err;
}

int libusb_handle_events_locked(libusb_context *ctx, struct timeval *tv) {
    int err = _libusb_handle_events_locked(ctx, tv);
    libusb_shim_log_msg("libusb_handle_events_locked@%s[%d]| ctx: %p, tv: %p",
        _libusb_error_name(err),
        err,
        ctx,
        tv
    );
    return err;
}

int libusb_handle_events_timeout(libusb_context *ctx, struct timeval *tv) {
    int err = _libusb_handle_events_locked(ctx, tv);
    libusb_shim_log_msg("libusb_handle_events_timeout@%s[%d]| ctx: %p, tv: %p",
        _libusb_error_name(err),
        err,
        ctx,
        tv
    );
    return err;
}


int libusb_handle_events_timeout_completed(libusb_context *ctx, struct timeval *tv, int *completed) {
    int err = _libusb_handle_events_timeout_completed(ctx, tv, completed);
    libusb_shim_log_msg("libusb_handle_events_timeout@%s[%d]| ctx: %p, tv: %p, completed %d[%p]",
        _libusb_error_name(err),
        err,
        ctx,
        tv,
        *completed,
        completed
    );
    return err;
}

int libusb_has_capability(uint32_t capability) {
    int res = _libusb_has_capability(capability);
    libusb_shim_log_msg("libusb_has_capability@%d| capability: %x",
        res,
        capability
    );
    return res;
}

void libusb_hotplug_deregister_callback(libusb_context *ctx, libusb_hotplug_callback_handle handle) {
    _libusb_hotplug_deregister_callback(ctx, handle);
    libusb_shim_log_msg("libusb_hotplug_deregister_callback| ctx: %p, handle: %d",
        ctx,
        handle
    );
}

int libusb_hotplug_register_callback(libusb_context *ctx, libusb_hotplug_event events, libusb_hotplug_flag flags, int vendor_id, int product_id, int dev_class, libusb_hotplug_callback_fn cb_fn, void *user_data, libusb_hotplug_callback_handle *handle) {
    int err = _libusb_hotplug_register_callback(ctx, events, flags, vendor_id, product_id, dev_class, cb_fn, user_data, handle);
    libusb_shim_log_msg("libusb_hotplug_register_callback@%s[%d]| cxt: %p, events: %s[%d], flags: %s[%d], vendor_id: %x, product_id: %x, dev_class: %d, cb_fn: %s[%p], user_data: %s[%p], handle: %d[%p]",
        _libusb_error_name(err),
        err,
        ctx,
        libusb_shim_hotplug_event_string(events),
        events,
        libusb_shim_hotplug_flag_string(flags),
        flags,
        vendor_id,
        product_id,
        dev_class,
        "??",
        cb_fn,
        "??",
        user_data,
        *handle,
        handle
    );
    return err;
}

int libusb_init(libusb_context **ctx) {
    int err = _libusb_init(ctx);
    libusb_shim_log_msg("libusb_init@%s[%d]| ctx: %p", _libusb_error_name(err), err, ctx);
    return err;
}

int libusb_interrupt_transfer(struct libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout) {
    int err = _libusb_interrupt_transfer(dev_handle, endpoint, data, length, transferred, timeout);
    libusb_shim_log_msg("libusb_interrupt_transfer@%s[%d]| dev_handle: %p, endpoint: %x, data %p, length: %d, transferred: %d[%p], timeout: %u",
        _libusb_error_name(err),
        err,
        dev_handle,
        endpoint,
        data,
        length,
        *transferred,
        transferred,
        timeout
    );
    libusb_shim_log_data(data, *transferred);
    return err;
}

int libusb_kernel_driver_active(libusb_device_handle *dev, int interface_number) {
    int err = _libusb_kernel_driver_active(dev, interface_number);
    libusb_shim_log_msg("libusb_kernel_driver_active@%d| dev: %p, interface_number: %d",
        err,
        dev,
        interface_number
    );
    return err;
}

void libusb_lock_events(libusb_context *ctx) {
    _libusb_lock_events(ctx);
    libusb_shim_log_msg("libusb_lock_events| ctx: %p",
        ctx
    );
}


void libusb_lock_event_waiters(libusb_context *ctx) {
    _libusb_lock_event_waiters(ctx);
    libusb_shim_log_msg("libusb_lock_event_waiters| ctx: %p",
        ctx
    );
}


int libusb_open(libusb_device *dev, libusb_device_handle **handle) {
    int err = _libusb_open(dev, handle);
    libusb_shim_log_msg("libusb_open@%s[%d]| dev: %p, handle: %p",
        _libusb_error_name(err),
        err,
        dev,
        handle
    );
    return err;
}

libusb_device_handle *libusb_open_device_with_vid_pid(libusb_context *ctx, uint16_t vendor_id, uint16_t product_id) {
    libusb_device_handle *handle = _libusb_open_device_with_vid_pid(ctx, vendor_id, product_id);
    libusb_shim_log_msg("libusb_open_device_with_vid_pid@%p| ctx: %p, vendor_id: %x, product_id: %x",
        handle,
        ctx,
        vendor_id,
        product_id
    );
    return handle;
}

int libusb_pollfds_handle_timeouts(libusb_context *ctx) {
    int res = _libusb_pollfds_handle_timeouts(ctx);
    libusb_shim_log_msg("libusb_pollfds_handle_timeouts@%d| ctx: %p",
        res,
        ctx
    );
    return res;
}


libusb_device *libusb_ref_device(libusb_device *dev) {
    libusb_device *device = _libusb_ref_device(dev);
    libusb_shim_log_msg("libusb_ref_device@%p| dev: %p",
        device,
        dev
    );
    return device;
}

int libusb_release_interface(libusb_device_handle *dev, int interface_number) {
    int err = _libusb_release_interface(dev, interface_number);
    libusb_shim_log_msg("libusb_release_interface@%s[%d]| dev: %p, interface_number: %d",
        _libusb_error_name(err),
        err,
        dev,
        interface_number
    );
    return err;
}

int libusb_reset_device(libusb_device_handle *dev) {
    int err = _libusb_reset_device(dev);
    libusb_shim_log_msg("libusb_reset_device@%s[%d]| dev: %p",
        _libusb_error_name(err),
        err,
        dev
    );
    return err;
}

int libusb_set_auto_detach_kernel_driver(libusb_device_handle *dev, int enable) {
    int err = _libusb_set_auto_detach_kernel_driver(dev, enable);
    libusb_shim_log_msg("libusb_set_auto_detach_kernel_driver@%s[%d]| dev: %p, enable: %d",
        _libusb_error_name(err),
        err,
        dev,
        enable
    );
    return err;
}


int libusb_set_configuration(libusb_device_handle *dev, int configuration) {
    int err = _libusb_set_configuration(dev, configuration);
    libusb_shim_log_msg("libusb_set_configuration@%s[%d]| dev: %p, configuration: %d",
        _libusb_error_name(err),
        err,
        dev,
        configuration
    );
    return err;
}

void libusb_set_debug(libusb_context *ctx, int level) {
    libusb_shim_log_msg("libusb_set_debug| ctx: %p, level: %s[%d]",
        ctx,
        libusb_shim_debug_level_string(level),
        level
    );
    _libusb_set_debug(ctx, level);
}


int libusb_set_interface_alt_setting(libusb_device_handle *dev, int interface_number, int alternate_setting) {
    int err = _libusb_set_interface_alt_setting(dev, interface_number, alternate_setting);
    libusb_shim_log_msg("libusb_set_interface_alt_setting@%s[%d]| dev: %p, interface_number: %d, alternate_setting: %d",
        _libusb_error_name(err),
        err,
        dev,
        interface_number,
        alternate_setting
    );
    return err;
}

int libusb_setlocale(const char *locale) {
    int err = _libusb_setlocale(locale);
    libusb_shim_log_msg("libusb_setlocale@%s[%d]| locale: %s",
        _libusb_error_name(err),
        err,
        locale
    );
    return err;
}

void libusb_set_pollfd_notifiers(libusb_context *ctx, libusb_pollfd_added_cb added_cb, libusb_pollfd_removed_cb removed_cb, void *user_data) {
    _libusb_set_pollfd_notifiers(ctx, added_cb, removed_cb, user_data);
    libusb_shim_log_msg("libusb_set_pollfd_notifiers| ctx: %p, added_cb %s[%p], removed_cb: %s[%p], user_data: %s[%p]",
        ctx,
        "??",
        added_cb,
        "??",
        removed_cb,
        "??",
        user_data
    );
}


int libusb_submit_transfer(struct libusb_transfer *transfer) {
    int err = _libusb_submit_transfer(transfer);
    libusb_shim_log_msg("libusb_submit_transfer@s[%d]| transfer: %p",
        _libusb_error_name(err),
        err,
        transfer
    );
    return err;
}

const char *libusb_strerror(enum libusb_error errcode) {
    const char *str = _libusb_strerror(errcode);
    libusb_shim_log_msg("libusb_sterror@%s[%p]| errocode: %d", str, str, errcode);
    return str;
}

uint32_t libusb_transfer_get_stream_id(struct libusb_transfer *transfer) {
    uint32_t id = _libusb_transfer_get_stream_id(transfer);
    libusb_shim_log_msg("libusb_transfer_get_stream_id@%x| transfer: %p",
        id,
        transfer
    );
    return id;
}

void libusb_transfer_set_stream_id(struct libusb_transfer *transfer, uint32_t stream_id) {
    _libusb_transfer_set_stream_id(transfer, stream_id);
    libusb_shim_log_msg("libusb_transfer_set_stream_id| transfer: %p, stream_id: %x",
        transfer,
        stream_id
    );
}

int libusb_try_lock_events(libusb_context *ctx) {
    int res = _libusb_try_lock_events(ctx);
    libusb_shim_log_msg("libusb_try_lock_events@%d| ctx: %p",
        res,
        ctx
    );
    return res;
}

void libusb_unlock_events(libusb_context *ctx) {
    _libusb_unlock_events(ctx);
    libusb_shim_log_msg("libusb_unlock_events| ctx: %p",
        ctx
    );
}


void libusb_unlock_event_waiters(libusb_context *ctx) {
    _libusb_unlock_event_waiters(ctx);
    libusb_shim_log_msg("libusb_unlock_event_waiters| ctx: %p",
        ctx
    );
}


void libusb_unref_device(libusb_device *dev) {
    _libusb_unref_device(dev);
    libusb_shim_log_msg("libusb_unref_device| dev: %p",
        dev
    );
}


int libusb_wait_for_event(libusb_context *ctx, struct timeval *tv) {
    int res = _libusb_wait_for_event(ctx, tv);
    libusb_shim_log_msg("libusb_wait_for_event@%d| ctx: %p, tv: %p",
        ctx,
        tv
    );
    return res;
}
