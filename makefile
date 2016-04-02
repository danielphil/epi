CC=clang++
CFLAGS=-c -Weverything -MMD -MP -std=c++14 -Wno-c++98-compat -Wno-c++11-compat-pedantic -O3
LDFLAGS=
SOURCES=$(subst src/,,$(wildcard src/*.cpp))
EXECUTABLE=build/test
OBJECTS=$(SOURCES:.cpp=.o)
OBJECTFILES=$(OBJECTS:%=build/%)
SOURCEFILES=$(SOURCES:%=src/%)

all: build $(SOURCEFILES) $(EXECUTABLE)

-include $(OBJECTFILES:.o=.d)

$(EXECUTABLE): $(OBJECTFILES)
	$(CC) $(LDFLAGS) $^ -o $@

build/%.o: src/%.cpp build
	$(CC) $(CFLAGS) $< -o $@

build:
	mkdir build

clean:
	rm -rfv build
	
run: build/test
	build/test