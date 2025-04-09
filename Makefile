CC = gcc
CFLAGS = -I.  # Add project root to include path
LINKS = -lncurses
editor: main.c screen/screen.c input/cursor.c  input/handler.c handlefile.c
	$(CC) $(CFLAGS) $^ -o $@ $(LINKS)