
project3.x: Pair.o EntityInstance.o EntitySet.o EquityStats.o JSONToken.o JSONTokenizer.o JSONParser.o main.o
	g++ -std=c++17 Pair.o EntityInstance.o EntitySet.o EquityStats.o JSONToken.o main.o JSONTokenizer.o JSONParser.o -o project3.x

EntitySet.o: EntitySet.cpp EntitySet.hpp EntityInstance.hpp Pair.hpp
	g++ -std=c++17 EntitySet.cpp -o EntitySet.o -c

EntityInstance.o: EntityInstance.cpp EntityInstance.hpp Pair.hpp
	g++ -std=c++17 EntityInstance.cpp -o EntityInstance.o -c

Pair.o: Pair.cpp Pair.hpp
	g++ -std=c++17 Pair.cpp -o Pair.o -c

JSONToken.o: JSONToken.cpp JSONToken.hpp
	g++ -std=c++17 JSONToken.cpp -o JSONToken.o -c

JSONTokenizer.o: JSONTokenizer.cpp JSONTokenizer.hpp JSONToken.hpp
	g++ -std=c++17 JSONTokenizer.cpp -o JSONTokenizer.o -c

JSONParser.o: JSONParser.cpp JSONParser.hpp EntityInstance.hpp Pair.hpp EntitySet.hpp JSONTokenizer.hpp JSONToken.hpp
	g++ -std=c++17 JSONParser.cpp -o JSONParser.o -c

EquityStats.o: EquityStats.cpp EquityStats.hpp EntitySet.hpp EntityInstance.hpp Pair.hpp
	g++ -std=c++17 EquityStats.cpp -o EquityStats.o -c

main.o: main.cpp JSONToken.hpp JSONTokenizer.hpp EntityInstance.hpp Pair.hpp EntitySet.hpp JSONParser.hpp EquityStats.hpp
	g++ -std=c++17 main.cpp -o main.o -c

clean:
	/bin/rm -f project3.x EntitySet.o EntityInstance.o Pair.o JSONToken.o JSONTokenizer.o JSONParser.o EquityStats.o main.o