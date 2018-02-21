CXX=gcc
FLAGS=-pedantic -Wall -Wextra -Werror

TARGET=dyc
SOURCES=$(wildcard *.c)\
	$(wildcard utils/*.c)
HEADERS=$(wildcard *.h)\
	$(wildcard utils/*.h)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

compile: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(FLAGS) 

o/%.o: %.c $(HEADERS)
	$(CXX) -c $< -o $@ $(FLAGS)

clean:
	rm -rf *.o
