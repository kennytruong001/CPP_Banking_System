CC = g++
CFLAGS = -std=c++17 -g -Wall
INCLUDE_HEADERS = -I headers/
OBJ_DIR = obj
OBJS = obj/*.o
SRC_DIR = src
SRCS = src/*.cpp
TARGET_DIR = target
TARGET = target/atm.exe

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
	CREATE_DIRECTORIES := mkdir
	CLEAN := rmdir /Q/S
else
	CREATE_DIRECTORIES := mkdir -p
	CLEAN := rm -rf	
endif

all: atm

# this is the last step to create atm.exe
# this will create object files first in the objs/ directory
atm: create_directories display.o atm.o user.o
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) $(OBJS) -o $(TARGET)

atm.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/atm.cpp -o $(OBJ_DIR)/atm.o

display.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/display.cpp -o $(OBJ_DIR)/display.o

user.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/user.cpp -o $(OBJ_DIR)/user.o

# ensure object and target directories are created
create_directories: clean
	$(CREATE_DIRECTORIES) $(OBJ_DIR) $(TARGET_DIR)

# remove all objects and target executables
clean:
	$(CLEAN) $(OBJ_DIR) $(TARGET_DIR)
