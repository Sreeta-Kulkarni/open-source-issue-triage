CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude

TARGET = triage.exe

SOURCES = src/main.c \
          src/models.c \
          src/io.c \
          src/sorting.c \
          src/search.c \
          src/assignment.c \
          src/dependency.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o