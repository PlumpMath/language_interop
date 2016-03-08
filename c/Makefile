.PHONY: clean

clib.o: clib.c
	gcc -c -o clib.o clib.c
	gcc -shared -Wl,-soname,libclib.so.1 -o libclib.so.1 clib.o

clean:
	rm clib.o libclib.so.1
