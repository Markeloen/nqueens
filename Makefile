CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o Board.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAG) $(OBJECTS) -o $(TARGET)
main.o: main.cpp Board.cpp Board.h
	$(CXX) $(CXXFLAGS) main.cpp
Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) Board.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)