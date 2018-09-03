CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant

main: src/main.cpp src/TicTacToe.cpp
	g++ -g ${CXXFLAGS} src/main.cpp -o bin/main.out
