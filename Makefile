Project3.x: main.o JSONToken.o JSONTokenizer.o
	g++ -std=c++17 main.o JSONToken.o JSONTokenizer.o -o Project3.x 

main.o: main.cpp JSONToken.hpp JSONTokenizer.hpp
	g++ -std=c++17 main.cpp -o main.o -c

JSONToken.o: JSONToken.cpp JSONToken.hpp
	g++ -std=c++17 JSONToken.cpp -o JSONToken.o -c

JSONTokenizer.o: JSONTokenizer.cpp JSONTokenizer.hpp JSONToken.hpp
	g++ -std=c++17 JSONTokenizer.cpp -o JSONTokenizer.o -c
