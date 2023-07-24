# the compiler to use
CXX = g++

# compiler flags
# -Wall turns on most, but not all, compiler warnings
# -std=c++20 for C++20 standard
CXXFLAGS = -Wall -std=c++20

# the name of the output file
TARGET = devwake

# a list of all the cpp files in the project
CPP_FILES = main.cpp menu.cpp configuration.cpp main_menu.cpp wake_on_lan.cpp

# path to libssh and the library name
LIBSSH_LIB = -L/usr/lib/x86_64-linux-gnu -lssh

# include path for libssh headers
LIBSSH_INCLUDE = -I/usr/include

all: $(TARGET)

$(TARGET): $(CPP_FILES)
	$(CXX) $(CXXFLAGS) $(LIBSSH_INCLUDE) -o $(TARGET) $(CPP_FILES) $(LIBSSH_LIB)

clean:
	$(RM) $(TARGET)
