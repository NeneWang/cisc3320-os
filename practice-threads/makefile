test:
	# make compile < sample-arguments
	make compile 

test-all:
	make compile-f file=thread-exec 
	make compile-f file=bank

compile:
	g++ main.cpp && ./a.out


compile-f:
	g++ ${file}.cpp -std=c++11 && ./a.out








