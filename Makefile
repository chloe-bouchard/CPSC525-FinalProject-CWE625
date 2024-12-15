CC = gcc
CFLAGS = -Wall -g
TARGET = addEmail
SRC = addEmail.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
