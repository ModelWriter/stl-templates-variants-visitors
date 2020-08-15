# Author: Michael J. Fischer
# Date: February 1, 2016

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++11
OBJ = brackets.o main.o stack.o token.o tools.o
TARGET = brackets
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
brackets.o: brackets.cpp brackets.hpp tools.hpp token.hpp stack.hpp
main.o: main.cpp tools.hpp brackets.hpp token.hpp stack.hpp
stack.o: stack.cpp stack.hpp tools.hpp token.hpp
token.o: token.cpp token.hpp tools.hpp
tools.o: tools.cpp tools.hpp
