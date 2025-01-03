# INSTRUCTIONS:
# 'mingw32-make'                build executable file 'Program.exe'
# 'mingw32-make run'            run executable file
# 'mingw32-make .bin/Main.o'    build object file 'Main.o' into .bin folder
# 'mingw32-make rebuild'        clean and subsequently compile all
# 'mingw32-make clean'          removes every objects and executable files

#====================================================#
#                  EDITABLE OPTIONS                  #
#====================================================#
# Compiler
CXX          := g++
DEBUG        := -g
CXX_VERSION  := --std=c++20

BIN_DIR      := bin

HEADER_DIR   := include
SOURCE_DIR   := lib

EXAMPLE_DIR  := examples

#====================================================#
#     YOU CAN EDIT IF YOU KNOW WHAT YOU'RE DOING     #
#====================================================#
# Flags
CXXFLAGS     := -c -Wall $(DEBUG) -I./$(HEADER_DIR) $(CXX_VERSION)
LDFLAGS      :=

HEADERS      := $(wildcard $(HEADER_DIR)/*.hpp)
SOURCES      := $(wildcard $(SOURCE_DIR)/*.cpp)

EXAMPLES     := $(wildcard $(EXAMPLE_DIR)/*.cpp)

#====================================================#
#        DO NOT ALLOW EDITING BELOW THIS LINE        #
#====================================================#
.PHONY: build build-and-run rebuild run clean remove-dir build-examples run-examples

#===< VARIABLES >=========#
OBJECTS      := $(SOURCES:%.cpp=%.o)                                # Replace `*.cpp` into `*.o` file
OBJECTS_PATH := $(patsubst $(SOURCE_DIR)/%,$(BIN_DIR)/%,$(OBJECTS)) # Appprefix `.bin` to `*.o` file into `.bin/*.o`

# Replace `examples/main.cpp` into `bin/main_example.exe`
EXAMPLE_BIN  := $(patsubst $(EXAMPLE_DIR)/%.cpp,$(BIN_DIR)/%_example.exe,$(EXAMPLES))

#===< COMPILER >==========#
build:			$(OBJECTS_PATH)
	@echo Build successfully!!!
	@echo ------------------------

$(BIN_DIR)/%.o:	$(SOURCE_DIR)/%.cpp	$(HEADERS)	| $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $<
	@echo Compiled file - $(subst /,\,$(CURDIR)/$@)

#===< EXAMPLES >==========#
build-examples: $(EXAMPLE_BIN)
	@echo All examples built successfully!!!

$(BIN_DIR)/%_example.exe: $(EXAMPLE_DIR)/%.cpp $(HEADERS) $(OBJECTS_PATH) | $(BIN_DIR)
	@$(CXX) $(LDFLAGS) -Wall $(DEBUG) -I./$(HEADER_DIR) $(CXX_VERSION) -o $@ $< $(OBJECTS_PATH) $(HEADERS)
	@echo Built example - $(subst /,\,$(CURDIR)/$@)

#===< MISCELLANEOUS >=====#
$(BIN_DIR):
	@mkdir $(BIN_DIR)
	@echo Created directory - $(subst /,\,$(CURDIR)/$(BIN_DIR))

rebuild:		clean	build

clean:
	@del /s \
		$(subst /,\,$(OBJECTS_PATH)) \
		$(subst /,\,$(EXAMPLE_BIN))
	@echo Clean done
	@echo ------------------------

remove-dir:
	@rmdir /s /q $(BIN_DIR)
	@echo Removed directory - $(subst /,\,$(CURDIR)/$(BIN_DIR))
