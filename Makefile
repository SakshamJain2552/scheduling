all: fifo sjf rr

rr:
	g++ -std=c++20 -o rr rr.cpp loader.cpp simulator.cpp

fifo:
	g++ -std=c++20 -o fifo fifo.cpp loader.cpp simulator.cpp

sjf:
	g++ -std=c++20 -o sjf sjf.cpp loader.cpp simulator.cpp

clean:
	rm -f fifo sjf rr
