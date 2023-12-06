# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Source files
SRC = day1.cpp

# Output executable
OUT = day1

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)