# libusb-shim

A shim library that intercepts and logs calls to libusb, designed to be used to reverse engineer USB protocols.

## Usage

`LD_PRELOAD=/path/to/libusb-shim.so command`

libusb-shim can be configured through these enviromental variables

* LIBUSB\_SHIM\_LOG\_PATH: Path to log file, defaults to ./libusb-shim-log
* LIBUSB\_PATH: Path to libusb shared object, defaults to libusb-1.0.so

## usb-shim.py

This is a simple script that makes it easier to use libusb-shim, see usb-shim.py --help for usage
