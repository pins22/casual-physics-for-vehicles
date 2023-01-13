all: setup compile install 
all_test: setup compile test
setup:
	meson setup builddir --buildtype=release
compile:
	meson compile -C builddir 
test:
	meson test -C builddir
install:
	meson install -C builddir
