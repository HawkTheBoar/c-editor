CC = gcc
CFLAGS = -I.  # Add project root to include path

editor: main.c screen/screen.c input/cursor.c
	$(CC) $(CFLAGS) $^ -o $@