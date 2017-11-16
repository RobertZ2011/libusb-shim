#ifndef LIBUSB_SHIM
#define LIBUSB_SHIM

#define LIBUSB_PATH "LIBUSB_PATH"

#include <libusb-1.0/libusb.h>

typedef int (*libusb_alloc_streams_t)(libusb_device_handle *dev, uint32_t num_streams, unsigned char *endpoints, int num_endpoints);
typedef struct libusb_transfer *(*libusb_alloc_transfer_t)(int iso_packets);
typedef int (*libusb_attach_kernel_driver_t)(libusb_device_handle *dev, int interface_number);
typedef int (*libusb_bulk_transfer_t)(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout);

typedef int (*libusb_cancel_transfer_t)(struct libusb_transfer *transfer);
typedef int (*libusb_claim_interface_t)(libusb_device_handle *dev, int interface_number);
typedef int (*libusb_clear_halt_t)(libusb_device_handle *dev, unsigned char endpoint);
typedef void (*libusb_close_t)(libusb_device_handle *dev_handle);
typedef int (*libusb_control_transfer_t)(libusb_device_handle *dev_handle, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, unsigned int timeout);

typedef int (*libusb_detach_kernel_driver_t)(libusb_device_handle *dev, int interface_number);

typedef const char *(*libusb_error_name_t)(int error_code);
typedef int (*libusb_event_handler_active_t)(libusb_context *ctx);
typedef int (*libusb_event_handling_ok_t)(libusb_context *ctx);
typedef void (*libusb_exit_t)(libusb_context *ctx);

typedef void (*libusb_free_bos_descriptor_t)(struct libusb_bos_descriptor *bos);
typedef void (*libusb_free_config_descriptor_t)(struct libusb_config_descriptor *config);
typedef void (*libusb_free_container_id_descriptor_t)(struct libusb_container_id_descriptor *container_id);
typedef void (*libusb_free_device_list_t)(libusb_device **list, int unref_devices);
typedef void (*libusb_free_pollfds_t)(const struct libusb_pollfd **pollfds);
typedef void (*libusb_free_ss_endpoint_companion_descriptor_t)(struct libusb_ss_endpoint_companion_descriptor *ep_comp);
typedef void (*libusb_free_ss_usb_device_capability_descriptor_t)(struct libusb_ss_usb_device_capability_descriptor *ss_usb_device_cap);
typedef int (*libusb_free_streams_t)(libusb_device_handle *dev, unsigned char *endpoints, int num_endpoints);
typedef void (*libusb_free_transfer_t)(struct libusb_transfer *transfer);
typedef void (*libusb_free_usb_2_0_extension_descriptor_t)(struct libusb_usb_2_0_extension_descriptor *usb_2_0_extension);

typedef int (*libusb_get_active_config_descriptor_t)(libusb_device *dev, struct libusb_config_descriptor **config);
typedef int (*libusb_get_bos_descriptor_t)(libusb_device_handle *handle, struct libusb_bos_descriptor **bos);
typedef uint8_t (*libusb_get_bus_number_t)(libusb_device *dev);
typedef int (*libusb_get_config_descriptor_t)(libusb_device *dev, uint8_t config_index, struct libusb_config_descriptor **config);
typedef int (*libusb_get_config_descriptor_by_value_t)(libusb_device *dev, uint8_t bConfigurationValue, struct libusb_config_descriptor **config);
typedef int (*libusb_get_configuration_t)(libusb_device_handle * dev, int *config);
typedef int (*libusb_get_container_id_descriptor_t)(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_container_id_descriptor **container_id);
typedef libusb_device *(*libusb_get_device_t)(libusb_device_handle *dev_handle);
typedef uint8_t (*libusb_get_device_address_t)(libusb_device *dev);
typedef int (*libusb_get_device_descriptor_t)(libusb_device *dev, struct libusb_device_descriptor *desc);
typedef ssize_t (*libusb_get_device_list_t)(libusb_context *ctx, libusb_device ***list);
typedef int (*libusb_get_device_speed_t)(libusb_device *dev);
typedef int (*libusb_get_max_iso_packet_size_t)(libusb_device *dev, unsigned char endpoint);
typedef int (*libusb_get_max_packet_size_t)(libusb_device *dev, unsigned char endpoint);
typedef int (*libusb_get_next_timeout_t)(libusb_context *ctx, struct timeval *tv);
typedef libusb_device *(*libusb_get_parent_t)(libusb_device *dev);
typedef const struct libusb_pollfd **(*libusb_get_pollfds_t)(libusb_context *ctx);
typedef uint8_t (*libusb_get_port_number_t)(libusb_device *dev);
typedef int (*libusb_get_port_numbers_t)(libusb_device *dev, uint8_t *port_numbers, int port_numbers_len);
typedef int (*libusb_get_port_path_t)(libusb_context *ctx, libusb_device *dev, uint8_t *port_numbers, uint8_t port_numbers_len);
typedef int (*libusb_get_ss_endpoint_companion_descriptor_t)(struct libusb_context *ctx, const struct libusb_endpoint_descriptor *endpoint, struct libusb_ss_endpoint_companion_descriptor **ep_comp);
typedef int (*libusb_get_ss_usb_device_capability_descriptor_t)(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_ss_usb_device_capability_descriptor **ss_usb_device_cap);
typedef int (*libusb_get_string_descriptor_ascii_t)(libusb_device_handle *dev, uint8_t desc_index, unsigned char *data, int length);
typedef int (*libusb_get_usb_2_0_extension_descriptor_t)(struct libusb_context *ctx, struct libusb_bos_dev_capability_descriptor *dev_cap, struct libusb_usb_2_0_extension_descriptor **usb_2_0_extension);
typedef const struct libusb_version *(*libusb_get_version_t)(void);

typedef int (*libusb_handle_events_t)(libusb_context *ctx);
typedef int (*libusb_handle_events_completed_t)(libusb_context *ctx, int *completed);
typedef int (*libusb_handle_events_locked_t)(libusb_context *ctx, struct timeval *tv);
typedef int (*libusb_handle_events_timeout_t)(libusb_context *ctx, struct timeval *tv);
typedef int (*libusb_handle_events_timeout_completed_t)(libusb_context *ctx, struct timeval *tv, int *completed);
typedef int (*libusb_has_capability_t)(uint32_t capability);
typedef void (*libusb_hotplug_deregister_callback_t)(libusb_context *ctx, libusb_hotplug_callback_handle handle);
typedef int (*libusb_hotplug_register_callback_t)(libusb_context *ctx, libusb_hotplug_event events, libusb_hotplug_flag flags, int 	vendor_id, int 	product_id, int 	dev_class, libusb_hotplug_callback_fn 	cb_fn, void *user_data, libusb_hotplug_callback_handle *handle);

typedef int (*libusb_init_t)(libusb_context **ctx);
typedef int (*libusb_interrupt_transfer_t)(struct libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout);

typedef int (*libusb_kernel_driver_active_t)(libusb_device_handle *dev, int interface_number);

typedef void (*libusb_lock_events_t)(libusb_context *ctx);
typedef void (*libusb_lock_event_waiters_t)(libusb_context *ctx);

typedef int (*libusb_open_t)(libusb_device *dev, libusb_device_handle **handle);
typedef libusb_device_handle *(*libusb_open_device_with_vid_pid_t)(libusb_context *ctx, uint16_t vendor_id, uint16_t product_id);

typedef int (*libusb_pollfds_handle_timeouts_t)(libusb_context *ctx);

typedef libusb_device *(*libusb_ref_device_t)(libusb_device *dev);
typedef int (*libusb_release_interface_t)(libusb_device_handle *dev, int interface_number);
typedef int (*libusb_reset_device_t)(libusb_device_handle *dev);

typedef int (*libusb_set_auto_detach_kernel_driver_t)(libusb_device_handle *dev, int enable);
typedef int (*libusb_set_configuration_t)(libusb_device_handle *dev, int configuration);
typedef void (*libusb_set_debug_t)(libusb_context *ctx, int level);
typedef int (*libusb_set_interface_alt_setting_t)(libusb_device_handle *dev, int interface_number, int alternate_setting);
typedef int (*libusb_setlocale_t)(const char *locale);
typedef void (*libusb_set_pollfd_notifiers_t)(libusb_context *ctx, libusb_pollfd_added_cb added_cb, libusb_pollfd_removed_cb removed_cb, void *user_data);
typedef const char *(*libusb_strerror_t)(enum libusb_error errcode);
typedef int (*libusb_submit_transfer_t)(struct libusb_transfer *transfer);

typedef uint32_t (*libusb_transfer_get_stream_id_t)(struct libusb_transfer *transfer);
typedef void (*libusb_transfer_set_stream_id_t)(struct libusb_transfer *transfer, uint32_t stream_id);
typedef int (*libusb_try_lock_events_t)(libusb_context *ctx);

typedef void (*libusb_unlock_events_t)(libusb_context *ctx);
typedef void (*libusb_unlock_event_waiters_t)(libusb_context *ctx);
typedef void (*libusb_unref_device_t)(libusb_device *dev);

typedef int (*libusb_wait_for_event_t)(libusb_context *ctx, struct timeval *tv);

void libusb_shim_init_shim(void);
void libusb_shim_fini_shim(void);

#endif
