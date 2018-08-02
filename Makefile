all:
	g++ -g main.cpp --std=c++11 -o sal -O2 -larmadillo
	./sal