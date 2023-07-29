# the compiler to use
ifeq ($(PLATFORM),WIN)
	CXX = x86_64-w64-mingw32-g++
	MINGW_INCLUDE = -I/usr/x86_64-w64-mingw32
	LIBSSH_LIB = -L/usr/x86_64-w64-mingw32/lib -lssh  # Corrected library path for MinGW
	LIBSSH_INCLUDE = -I/usr/x86_64-w64-mingw32
	TARGET = build/devwake.exe
else
	CXX = g++
	LIBSSH_LIB = -L/usr/lib/x86_64-linux-gnu -lssh
	LIBSSH_INCLUDE = -I/usr/include
	TARGET = build/devwake
endif

# compiler flags
# -Wall turns on most, but not all, compiler warnings
# -std=c++20 for C++20 standard
# compiler flags
# -Wall turns on most, but not all, compiler warnings
# -std=c++20 for C++20 standard
# -D_HAS_STD_BYTE=0 to disable std::byte
# -Dbyte=unsigned char to define 'byte' as 'unsigned char'
CXXFLAGS = -Wall -std=c++20 -D_HAS_STD_BYTE=0 -Dbyte=unsigned\ char

# ... rest of the Makefile


# a list of all the cpp files in the project
CPP_FILES = src/main.cpp src/menu.cpp src/configuration.cpp src/main_menu.cpp src/wake_on_lan.cpp

all: $(TARGET)

$(TARGET): $(CPP_FILES)
	$(CXX) $(CXXFLAGS) $(LIBSSH_INCLUDE) $(MINGW_INCLUDE) -o $(TARGET) $(CPP_FILES) $(LIBSSH_LIB)

clean:
	$(RM) $(TARGET)
