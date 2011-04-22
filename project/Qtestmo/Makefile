lib:
	g++ -shared -fPIC -o libtesmo.so event.cpp

test:
	gcc test.c -o test -lstdc++ -L. -ltesmo

clean:
	rm test
