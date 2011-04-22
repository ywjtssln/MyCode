all:
	g++ -c event.cpp event.h cinterface.cpp
	g++ -shared -fPIC -o libtesmo.so event.o cinterface.o

test:
	gcc test.c -o test -lstdc++ -L. -ltesmo

clean:
	rm test
