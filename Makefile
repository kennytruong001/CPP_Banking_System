CC = g++
CFLAGS = -std=c++17 -g -Wall
INCLUDES = -Iheaders/
LINKER = -lshlwapi
OBJ_DIR = obj
OBJS = obj/*.o
SRC_DIR = src
SRCS = src/*.cpp
TARGET_DIR = target
TARGET = target/atm.exe
DATA_DIR = data

all: atm

# NOTE TO SELF: Linker is safest when you put at end of command to help resolve issues, here we need at end of atm.cpp
atm: create_directories display.o user.o customer.o manager.o atm.o sha256.o 
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LINKER)

atm.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/atm.cpp -o $(OBJ_DIR)/atm.o $(LINKER)

user.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/user.cpp -o $(OBJ_DIR)/user.o $(LINKER)

customer.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/customer.cpp -o $(OBJ_DIR)/customer.o $(LINKER)

manager.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/manager.cpp -o $(OBJ_DIR)/manager.o $(LINKER)

display.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/display.cpp -o $(OBJ_DIR)/display.o $(LINKER)

utils.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/utils.cpp -o $(OBJ_DIR)/utils.o $(LINKER)

sha256.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/sha256.cpp -o $(OBJ_DIR)/sha256.o $(LINKER)



# ensure object and target directories are created
create_directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TARGET_DIR)
	mkdir -p $(DATA_DIR)

# remove all objects and target executables
clean:
	rm -fr $(OBJ_DIR) $(TARGET_DIR)
