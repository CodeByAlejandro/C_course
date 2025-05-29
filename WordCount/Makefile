TARGET_EXEC := WordCount

SRC_DIRS := ./src
INC_DIRS := ./include
BUILD_DIR := ./build
BIN_DIR := ./bin

# Check if build directory exists (needed for 'clean' target)
BUILD_DIR_EXISTS := $(shell [ -d $(BUILD_DIR) ] && echo 1 || echo 0)

# Check if bin directory exists (needed for 'clean' target)
BIN_DIR_EXISTS := $(shell [ -d $(BIN_DIR) ] && echo 1 || echo 0)

# Find all the C/C++ and assembly files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./src/hello.cpp turns into ./build/./src/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %) to define compiler generated dependency Makefiles
# As an example, ./build/./src/hello.cpp.o turns into ./build/./src/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in INC_DIRS (recursive) will need to be passed to GCC so that it can find header files
ALL_INC_DIRS := $(shell find $(INC_DIRS) -type d)
# Add a prefix to ALL_INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(ALL_INC_DIRS))

# The -MMD and -MP flags together will make the compiler generate Makefiles as a side-effect for us!
# Those Makefiles will contain direct and indirect non-system header files a source file depends on.
# The -MP flag adds dummy rules to avoid errors for when direct or indirect non-system header files are removed.
# (since the generated dependency Makefile(s) will still contain them on the subsequent build)
# These files will have .d instead of .o as the output.
# CPP stands for C PreProcessor, whereas CXX stands for C++.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Set default C flags
CFLAGS := -std=c99 -Wall -fdiagnostics-color=always
# Allow passing DEBUG=1 on the command line to compile with debug flags
ifdef DEBUG
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif
# Set C++ flags to same as C flags
CXXFLAGS := $(CFLAGS)

# Map default 'build' target to build final executable and symlink it to bin directory
.PHONY: build
build: $(BIN_DIR)/$(TARGET_EXEC)

# The symlink step to expose the binary via the bin directory
$(BIN_DIR)/$(TARGET_EXEC): $(BUILD_DIR)/$(TARGET_EXEC)
	mkdir -p $(BIN_DIR)
	ln -sf $(addprefix ../,$(BUILD_DIR)/$(TARGET_EXEC)) $(BIN_DIR)

# The final build step
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
ifdef SRCS
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
endif

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Clean rule to delete previous build
.PHONY: clean
clean:
ifeq ($(BUILD_DIR_EXISTS),1)
	rm -r $(BUILD_DIR)
endif
ifeq ($(BIN_DIR_EXISTS),1)
	rm -r $(BIN_DIR)
endif

# Include the .d Makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
