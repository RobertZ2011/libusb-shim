CC := gcc
CFLAGS := -shared -fPIC
CFILES := $(wildcard src/libusb-shim/*.c)

all: build/libusb-shim.so

clean:
	rm -f build/*

build/libusb-shim.so:
	$(CC) -g $(CFLAGS) -o build/libusb-shim.so $(CFILES) -ldl
