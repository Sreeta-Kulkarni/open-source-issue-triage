CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude

TARGET = triage
SOURCES = src/main.c src/models.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)