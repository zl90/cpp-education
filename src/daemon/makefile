all: filewatcher

filewatcher:
	# Ensure tabs are used for indentation
	gcc -Wall -pedantic -std=gnu99 -o build/filewatcherd filewatcher.c \
	-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/gdk-pixbuf-2.0 \
	$(pkg-config --cflags --libs libnotify) -lglib-2.0 -lgdk_pixbuf-2.0 -lnotify
