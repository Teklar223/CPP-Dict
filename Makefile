CXXVERSION=#-7.2.0
CXX=gcc$(CXXVERSION)
CXXSTANDARD=c++17
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXSTANDARD) -g -Wall -Wextra -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXSTANDARD) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

LIBS=-lstdc++ -ldbghelp

SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

all: run
run: main

main:  $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

tidy:
	clang-tidy $(SOURCES) $(TIDY_FLAGS) --

valgrind: test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f $(OBJECTS) *.o