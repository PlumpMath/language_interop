mash: mash.c
	cp ../c/libclib.so.1 .
	cp ../cpp/libcclib.so .
	cp ../hs/DoStuff.o .
	cp ../hs/DoStuff_stub.h .
	cp ../rust/libtesting.so .
	gcc -c mash.c -o mash.o -I/nix/store/4860v2261lp6dnd9gs5hkrs458pajcdm-ghc-7.10.3/lib/ghc-7.10.3/include/
	ghc -no-hs-main -lstdc++ libclib.so.1 libcclib.so DoStuff.o libtesting.so mash.o -o mash
