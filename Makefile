all: build/example
	@build/example

build/example: example.cpp termfmt.h
	g++ -Wall -Wextra -std=c++17 -lfmt example.cpp -o build/example
