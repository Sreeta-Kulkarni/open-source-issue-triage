CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude

TARGET = triage
SOURCES = src/main.c src/models.c src/io.c src/sorting.c src/search.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)