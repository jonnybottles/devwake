# the compiler to use
CXX = g++

# compiler flags
# -Wall turns on most, but not all, compiler warnings
# -std=c++20 for C++20 standard
CXXFLAGS = -Wall -std=c++20

# the name of the output file
TARGET = devwake

# a list of all the cpp files in the project
CPP_FILES = main.cpp menu.cpp configuration.cpp main_menu.cpp

all: $(TARGET)

$(TARGET): $(CPP_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(CPP_FILES)

clean:
	$(RM) $(TARGET)
