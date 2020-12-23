NAME_EXECUTABLE=oven

BUILD_DIR = build/
SOURCE_DIR = src/
HEADERS_DIR = headers/

INCLUDE_DIR =$(SOURCE_DIR)$(HEADERS_DIR)
CPP_FLAGS = -O0 -g3 -Wall -Wextra -I $(INCLUDE_DIR) -pthread
CC = g++

SRC_FILES := $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)*.cpp))
OBJ_FILES = $(subst $(SOURCE_DIR),$(BUILD_DIR),$(SRC_FILES:.cpp=.o))

.DEFAULT_GOAL = build
build: $(OBJ_FILES) | $(BUILD_DIR)
	$(QUITE) $(CC) $(CPP_FLAGS) $(OBJ_FILES) -o $(BUILD_DIR)$(NAME_EXECUTABLE)

# generic object file generation
$(BUILD_DIR)%.o : $(SOURCE_DIR)%.cpp | $(BUILD_DIR)
	$(CC) $< $(CPP_FLAGS) -c -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: docs
docs:
	doxygen

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) docs/html docs/latex
