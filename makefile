ttt : ttt.o tttgame.o
	g++ ttt.o tttgame.o -o ./bin/ttt
ttt.o : ./src/ttt.cpp
	g++ -c ./src/ttt.cpp -o ttt.o
tttgame.o : ./src/tttgame.cpp ./include/tttgame.h
	g++ -c ./src/tttgame.cpp -o tttgame.o -I./include
clean:
	rm -rf *.o
