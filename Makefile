NAME_EXECUTABLE=oven

BUILD_DIR := build/
SOURCE_DIR := src/
INCLUDE_DIR := include/
CONFIG_DIR := .config/

DIALECT := --std=c++17
CPP_FLAGS := -O0 -g3 -Wall -Wextra -I $(INCLUDE_DIR) -pthread $(DIALECT)
CC := g++

SRC_FILES := $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)*.cpp))
OBJ_FILES := $(subst $(SOURCE_DIR),$(BUILD_DIR),$(SRC_FILES:.cpp=.o))
HEADER_FILES := $(foreach sdir,$(INCLUDE_DIR),$(wildcard $(sdir)*.hpp))

QUITE := @

.DEFAULT_GOAL := build
build: $(OBJ_FILES) | $(BUILD_DIR)
	$(QUITE) echo building $(NAME_EXECUTABLE)
	$(QUITE) $(CC) $(CPP_FLAGS) $(OBJ_FILES) -o $(BUILD_DIR)$(NAME_EXECUTABLE)

# generic object file generation
$(BUILD_DIR)%.o : $(SOURCE_DIR)%.cpp | $(BUILD_DIR)
	$(QUITE) echo compiling $(notdir $<)
	$(QUITE) $(CC) $< $(CPP_FLAGS) -c -o $@

$(BUILD_DIR):
	$(QUITE) mkdir -p $(BUILD_DIR)

.PHONY: docs
docs:
	$(QUITE) doxygen $(CONFIG_DIR)doxyfile

.PHONY: clean
clean:
	$(QUITE) rm -rf $(BUILD_DIR) docs/html docs/latex

.PHONY: install
install: build
	$(QUITE) cp build/$(NAME_EXECUTABLE) /usr/bin/$(NAME_EXECUTABLE)

.PHONY: uninstall
uninstall:
	$(QUITE) rm -f /usr/bin/$(NAME_EXECUTABLE)

GITHUB_DOCKER_IMAGE = ubuntu-latest=nektos/act-environments-ubuntu:18.04
.PHONY: test
test:
	$(QUITE) act -P $(GITHUB_DOCKER_IMAGE)

.PHONY: format
format:
	$(QUITE) clang-format -style="Microsoft" -i $(SRC_FILES) $(HEADER_FILES)

.PHONY: check
check:
# clang tidy does not work with modern c++ features and gives false positive errors
#$(QUITE) clang-tidy -p . -checks="cppcoreguidelines-*" -format-style="Microsoft" -header-filter=".*" $(SRC_FILES) -- -I$(INCLUDE_DIR)
	$(QUITE) cppcheck $(DIALECT) --enable=all $(SRC_FILES) -I$(INCLUDE_DIR) --suppress=missingIncludeSystem
