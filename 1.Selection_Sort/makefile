all: clear clean run


run: main.cpp
	@g++ -c main.cpp
	@g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system 
	@./main

clean:
	@rm -f *.o
	@rm -f main
	
clear:
	@clear
