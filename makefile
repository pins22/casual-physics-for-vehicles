all: setup compile install 
setup:
	meson setup builddir
compile:
	meson compile -C builddir
install:
	meson install -C builddir
