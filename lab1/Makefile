SOURCES = $(shell find . -path ./test -prune -o -name "*.cpp" -print)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
C_OBJ = $(patsubst %.o, $(OBJ_DIR)/%.o, $(notdir $(OBJECTS)))
PROG=U201614898_1

# macro for tools
# CC = x86_64-w64-mingw32-g++
CC = g++
RM = rm -fr
MV = mv
CP = cp -fr
MKDIR = mkdir -p
# BROWSER = google-chrome
# DOCS = doxygen


# macro for flags
FLAGS = -c -Wall -g $(addprefix -I, $(INCLUDE))

# path macro
BIN_DIR = ./bin
OBJ_DIR = ./obj


# include macro
INCLUDE += ./include/

all: $(OBJECTS) link

.cpp.o:
	@echo Compiling C Source Files $< ...
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(FLAGS) $< -o $@
	$(MV) $@ $(OBJ_DIR)/$(notdir $@)

link:
	@echo Linking Binary File
	$(MKDIR) $(BIN_DIR)
	$(CC) $(C_OBJ) -o $(BIN_DIR)/$(PROG)
	@echo
	@echo Build Success!


.PHONY:run
run:
	./bin/$(PROG)
