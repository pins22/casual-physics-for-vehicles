all: setup compile install 
test: setup compile test
setup:
	meson setup builddir --buildtype=release
compile:
	meson compile -C builddir 
test:
	meson test -C builddir
install:
	meson install -C builddir
