TARGET_EXEC := %final_program%

SRC_DIRS := ./src
INC_DIRS := ./include
BUILD_DIR := ./build

# Find all the C/C++ and assembly files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %) to define compiler generated dependency Makefiles
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in INC_DIRS (recursive) will need to be passed to GCC so that it can find header files
ALL_INC_DIRS := $(shell find $(INC_DIRS) -type d)
# Add a prefix to ALL_INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(ALL_INC_DIRS))

# The -MMD and -MP flags together will make the compiler generate Makefiles as a side-effect for us!
# Those Makefiles will contain direct and indirect non-system header files a source file depends on.
# The -MP flag adds dummy rules to avoid errors for when an indirect header file is removed and the source file(s) did not change.
# (since the .d file(s) will not be regenerated in such case)
# These files will have .d instead of .o as the output.
# CPP stands for C PreProcessor, whereas CXX stands for C++.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Set default C flags
CFLAGS := -std=c99 -Wall -fdiagnostics-color=always
# Allow passing DEBUG=1 on the command line to compile with debug flags
ifdef DEBUG
	CFLAGS += -g -Og
else
	CFLAGS += -O2
endif
# Set C++ flags to same as C flags
CXXFLAGS := $(CFLAGS)

# Map default 'build' target to build final executable
.PHONY: build
build: $(BUILD_DIR)/$(TARGET_EXEC)

# The final build step
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
ifdef SRCS
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
else
	$(info [INFO] No sources found)
endif

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d Makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
