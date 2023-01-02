all: setup compile install create_assembly
setup:
	meson setup builddir
compile:
	cd builddir; meson compile
install:
	cd builddir; meson install
create_assembly:
	xbuild "c#/cpv/cpv.sln"
	
