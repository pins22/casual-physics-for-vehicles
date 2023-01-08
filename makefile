all: setup compile install create_assembly
setup:
	meson setup builddir
compile:
	meson compile -C builddir
install:
	meson install -C builddir
