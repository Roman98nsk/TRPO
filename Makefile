OBJECTS = obj/interface.o obj/word.o obj/hangman.o obj/game.o
CC = gcc -std=c99 -Wall
LIBS = `pkg-config --cflags --libs gtk+-3.0` -rdynamic

.PHONY: clean prepare cli game

#############

game: prepare ${OBJECTS}
	$(CC) -o bin/game ${OBJECTS} $(LIBS)

obj/interface.o: src/interface.c
	$(CC) -c src/interface.c -o obj/interface.o $(LIBS)

obj/word.o: src/word.c
	$(CC) -c src/word.c -o obj/word.o $(LIBS)

obj/hangman.o: src/hangman.c
	$(CC) -c src/hangman.c -o obj/hangman.o $(LIBS)

obj/game.o: src/game.c
	$(CC) -c src/game.c -o obj/game.o $(LIBS)

word_test: objects
	gcc -Wall -O0 -g3 -o bin/word_test obj/word_test.o obj/word.o
	./bin/word_test

test: word_test cli_test

cli: prepare objects
	gcc -Wall -O0 -g3 -o bin/cli obj/conio.o obj/hangman_cli.o obj/cli.o obj/word.o

cli_test: prepare objects
	gcc -Wall -O0 -g3 -o bin/cli_test obj/conio.o obj/hangman_cli.o obj/hangman_cli_test.o
	./bin/cli_test

objects: prepare
	gcc -Wall -O0 -g3 -c src/*.c $(LIBS)
	mv *.o obj

prepare:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/* obj/*.o

lint: SHELL=/bin/bash
lint:
	diff -u <(cat src/*.[hc]) <(clang-format --style=file ./src/*.[hc])
lint-fix: SHELL=/bin/bash
lint-fix:
	clang-format --style=file -i src/*.[hc]
