all: setup compile install create_assembly
setup:
	meson setup builddir
compile:
	meson compile -C builddir
install:
	meson install -C builddir
create_assembly:
	msbuild "c#/cpv/cpv.sln"
	
