all: compile install create_assembly
compile:
	cd builddir; meson compile
install:
	cd builddir; meson install
create_assembly:
	xbuild "c#/cpv/cpv.sln"
	
