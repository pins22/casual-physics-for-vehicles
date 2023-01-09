all: setup compile install 
setup:
	meson setup builddir --buildtype=release
compile:
	meson compile -C builddir 
install:
	meson install -C builddir
