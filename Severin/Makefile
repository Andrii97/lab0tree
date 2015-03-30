name=tree

all: compile link

compile: tree.cpp
	g++ $< -c

link:
	g++ tree.o -o $(name)

run: compile link
	./$(name)

clean:
	rm *.o $(name)
