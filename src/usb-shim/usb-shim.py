#!/usr/bin/env python
import os
import sys

def usage():
    print(
"""usb-shim: runs a command with the libusb-shim library injected into it
usage: usb-shim [usb-shim args] -- command [command args]
arguments:
-l, --log-file: the location of the libusb-shim log file, defaults to ./libusb-shim-log
-u, --libusb: the location of the libusb library, defaults to libusb.so
-s, --shim: the location of the libusb-library, defaults to libusb-shim.so""")

def find_argument(short_flag, long_flag):
    try:
        index = sys.argv.index(short_flag)
        return sys.argv[index + 1]
    except (ValueError, IndexError) as e:
        try:
            index = sys.argv.index(long_flag)
            return sys.argv[index + 1]
        except (ValueError, IndexError) as e:
            return None

def find_index(flag):
    try:
        index = sys.argv.index(flag)
        return index
    except ValueError:
        return None

def main():
    if len(sys.argv) == 1 or find_argument("-h", "--help") != None:
        usage()
        sys.exit(0)

    environment = {}

    shim_path = find_argument("-s", "--shim")
    if shim_path == None:
        environment["LD_PRELOAD"] = "libusb-shim.so"
    else:
        environment["LD_PRELOAD"] = shim_path

    log_path = find_argument("-l", "--log-file")
    if log_path != None:
        environment["LIBUSB_SHIM_LOG_PATH"] = log_path

    library_path = find_argument("-u", "--libusb")
    if library_path != None:
        environment["LIBUSB_PATH"] = library_path

    command = find_argument("--", "--")
    if command == None:
        print("missing command")
        sys.exit(1)

    args_index = find_index("--")
    args = [command]
    if args_index + 2 < len(sys.argv):
        args += sys.argv[args_index + 2:]

    os.execvpe(command, args, environment)

if __name__ == "__main__":
    main()
