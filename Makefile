CC=gcc
DEPS = include/location.h include/parsexec.h

%.o: %.c $(DEPS)
	$(CC) -Iinclude -c -o $@ $<

game: src/main.c src/parsexec.c src/location.c
	$(CC) -Iinclude src/main.c src/parsexec.c src/location.c -o bin/game