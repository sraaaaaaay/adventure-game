CC=gcc
DEPS = include/location.h include/parsexec.h include/misc.h include/noun.h include/object.h

%.o: %.c $(DEPS)
	$(CC) -Iinclude -c -o $@ $<

game: src/main.c src/parsexec.c src/location.c src/misc.c src/noun.c src/object.c
	$(CC) -Iinclude src/main.c src/parsexec.c src/location.c src/misc.c src/noun.c src/object.c -o bin/game