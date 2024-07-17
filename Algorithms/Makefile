.PHONY : all build execute clear 

# To disable debug Type in command line ----> make DEBUG = 0
# To disable warnings Type in command line ---> make ENABLE_WARNINGS = 0
# To enable warnings threat as errors Type in command line ----> make WARNINGS_AS_ERRORS = 1
#	↓↓↓		CHANGABLE VARIABLES	   ↓↓↓	#
DEBUG ?= 1
ENABLE_WARNINGS ?= 1
WARNINGS_AS_ERRORS ?= 0
#	↑↑↑		IF NEEDED	  ↑↑↑	#

INCLUDE_DIR = Sorting
SOURCE_DIR = Src
BUILD_DIR = Build

ifeq ($(ENABLE_WARNINGS), 1)
CXX_WARNINGS = -Wall # optional can be added [-Wextra -Wpedantic -Wconversion] if needed
else
CXX_WARNINGS = 
endif

ifeq ($(WARNING_AS_ERRORS), 1)
CXX_WARNINGS += -Werror
endif

CXX = g++
CXX_STANDARD_VERSION = c++17
CPPFLAGS = -I $(INCLUDE_DIR)
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STANDARD_VERSION)

ifeq ($(DEBUG), 1)
CXXFLAGS += -g -O0
else
CXXFLAGS += -O3
endif

CXX_COMPILER_CALL = $(CXX) $(CXXFLAGS) $(CPPFLAGS)

EXECUTABLE_NAME = Algorithm
CXX_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
CXX_OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CXX_SOURCES))

all: build

build: create_dir $(CXX_OBJECTS)
	@$(CXX_COMPILER_CALL) $(CXX_OBJECTS) -o $(EXECUTABLE_NAME)

create_dir:
	@if not exist "Build" (mkdir build)
    # ↑ for work with Windows 
    #mkdir -p build works for Linux and Mac

execute:
	@$(EXECUTABLE_NAME)

clear:
	@del $(BUILD_DIR)\*.o *.exe 2>nul 
    #del works for Windows   
    #rm -f works for Linux and Mac

$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@$(CXX_COMPILER_CALL) -c $< -o $@


# Type in command line to bulid project ----> make
# Type in command line to execute ----> make execute
# If you want to delete files created with Makefile, Type in command line ----> make clear