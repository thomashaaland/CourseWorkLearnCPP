CFLAGS = -O
GXX = g++
SRC = main.cpp Sclass.cpp
OBJ = $(SRC:.cpp = .o)

testPointer: main.cpp Sclass.cpp
	$(GXX) $(CFLAGS) -o testPointer $(OBJ)

clean:
	rm -f core *.o
