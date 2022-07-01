CC = g++
CFLAGS = -std=c++17 -g -Wall
INCLUDE_HEADERS = -I headers/
OBJ_DIR = obj
OBJS = obj/*.o
SRC_DIR = src
SRCS = src/*.cpp
TARGET_DIR = target
TARGET = target/atm.exe
DATA_DIR = data

all: atm

# this is the last step to create atm.exe
# this will create object files first in the objs/ directory
atm: create_directories utils.o display.o user.o atm.o
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) $(OBJS) -o $(TARGET)

atm.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/atm.cpp -o $(OBJ_DIR)/atm.o

user.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/user.cpp -o $(OBJ_DIR)/user.o

display.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/display.cpp -o $(OBJ_DIR)/display.o

utils.o:
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) -c $(SRC_DIR)/utils.cpp -o $(OBJ_DIR)/utils.o

# ensure object and target directories are created
create_directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TARGET_DIR)
	mkdir -p $(DATA_DIR)

# remove all objects and target executables
clean:
	rm -fr $(OBJ_DIR) $(TARGET_DIR)
