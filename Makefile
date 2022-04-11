Project3.x: main.o JSONToken.o JSONTokenizer.o Pair.o EntityInstance.o EntitySet.o EquityStats.o
	g++ -std=c++17 main.o JSONToken.o JSONTokenizer.o Pair.o EntityInstance.o EntitySet.o EquityStats.o -o Project3.x

main.o: main.cpp JSONToken.hpp JSONTokenizer.hpp
	g++ -std=c++17 main.cpp -o main.o -c

JSONToken.o: JSONToken.cpp JSONToken.hpp
	g++ -std=c++17 JSONToken.cpp -o JSONToken.o -c

Pair.o: Pair.cpp Pair.hpp
	g++ -std=c++17 Pair.cpp -o Pair.o -c

EntityInstance.o: EntityInstance.cpp EntityInstance.hpp
	g++ -std=c++17 EntityInstance.cpp -o EntityInstance.o -c

EntitySet.o: EntitySet.cpp EntitySet.hpp
	g++ -std=c++17 EntitySet.cpp -o EntitySet.o -c

EquityStats.o: EquityStats.cpp EquityStats.hpp
	g++ -std=c++17 EquityStats.cpp -o EquityStats.o -c
