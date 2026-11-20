CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude

TARGET = triage.exe

SOURCES = src/main.c \
          src/models.c \
          src/io.c \
          src/sorting.c \
          src/search.c \
          src/assignment.c \
          src/dependency.c \
          src/matching.c

TEST_SORTING = test_sorting.exe
TEST_SEARCH = test_search.exe
TEST_ASSIGNMENT = test_assignment.exe
TEST_DEPENDENCY = test_dependency.exe
TEST_MATCHING = test_matching.exe
TEST_SCENARIOS = test_scenarios.exe

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(TEST_SORTING): tests/test_sorting.c src/sorting.c
	$(CC) $(CFLAGS) tests/test_sorting.c src/sorting.c -o $(TEST_SORTING)

$(TEST_SEARCH): tests/test_search.c src/search.c
	$(CC) $(CFLAGS) tests/test_search.c src/search.c -o $(TEST_SEARCH)

$(TEST_ASSIGNMENT): tests/test_assignment.c src/assignment.c
	$(CC) $(CFLAGS) tests/test_assignment.c src/assignment.c -o $(TEST_ASSIGNMENT)

$(TEST_DEPENDENCY): tests/test_dependency.c src/dependency.c
	$(CC) $(CFLAGS) tests/test_dependency.c src/dependency.c -o $(TEST_DEPENDENCY)

$(TEST_MATCHING): tests/test_matching.c src/matching.c
	$(CC) $(CFLAGS) tests/test_matching.c src/matching.c -o $(TEST_MATCHING)

$(TEST_SCENARIOS): tests/test_scenarios.c src/io.c src/models.c src/sorting.c src/matching.c
	$(CC) $(CFLAGS) tests/test_scenarios.c src/io.c src/models.c src/sorting.c src/matching.c -o $(TEST_SCENARIOS)

test: $(TEST_SORTING) $(TEST_SEARCH) $(TEST_ASSIGNMENT) $(TEST_DEPENDENCY) $(TEST_MATCHING) $(TEST_SCENARIOS)
	-./$(TEST_SORTING)
	-./$(TEST_SEARCH)
	-./$(TEST_ASSIGNMENT)
	-./$(TEST_DEPENDENCY)
	-./$(TEST_MATCHING)
	-./$(TEST_SCENARIOS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_SORTING) $(TEST_SEARCH) $(TEST_ASSIGNMENT) $(TEST_DEPENDENCY) $(TEST_MATCHING) $(TEST_SCENARIOS) *.o