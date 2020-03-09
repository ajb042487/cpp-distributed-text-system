ROOT_PATH:= $(patsubst %/,%,$(realpath ../..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../common.mk
include ../../build-configuration.mk

VERSION_HASH:=
OUTPUT_FOLDER:= $(EMBEDDED_BUILD)/$(THIS_DIRECTORY)
INCLUDES:= $(shell find $(OUTPUT_FOLDER)/include -name "*.h" -name "*.hpp")
INCLUDE_DIRS:= -I include -I $(EMBEDDED_STAGING)/usr/include
LIBS:= -lcivetweb -lpthread -ldl -lpaho-mqtt3a -lpaho-mqtt3as -lpaho-mqtt3c -lpaho-mqtt3cs -lpaho-mqttpp3
LIB_DIRS:= -L$(EMBEDDED_STAGING)/usr/lib

ASM_SOURCES:= $(shell find $(OUTPUT_FOLDER)/source -name "*.s") $(shell find $(OUTPUT_FOLDER)/main.s)
C_SOURCES:= $(shell find $(OUTPUT_FOLDER)/source -name "*.c") $(shell find $(OUTPUT_FOLDER)/main.c)
CXX_SOURCES:= $(shell find $(OUTPUT_FOLDER)/source -name "*.cpp") $(shell find $(OUTPUT_FOLDER)/main.cpp)

ASM_OBJECTS:= $(patsubst %.s,%.o,$(ASM_SOURCES))
C_OBJECTS:= $(patsubst %.c,%.o,$(C_SOURCES))
CXX_OBJECTS:= $(patsubst %.cpp,%.o,$(CXX_SOURCES))

SOURCES:= $(ASM_SOURCES) $(C_SOURCES) $(CXX_SOURCES)
OBJECTS:= $(ASM_OBJECTS) $(C_OBJECTS) $(CXX_OBJECTS)

AR_FLAGS +=
CC_FLAGS += -g $(INCLUDE_DIRS) -DREVISION_CONTROL_HASH=$(REVISION_CONTROL_HASH) -DNDEBUG
CC_FLAGS += -Wall -Wextra -Werror -pedantic -Wunused-parameter -Wstrict-prototypes -Wmissing-prototypes -Wredundant-decls -Wno-cpp
CXX_FLAGS += -g $(INCLUDE_DIRS) -DREVISION_CONTROL_HASH=$(REVISION_CONTROL_HASH) -DNDEBUG -std=gnu++14 -D_GLIBCXX_USE_CXX11_ABI=0
CXX_FLAGS += -Wall -Wextra -Wunused-parameter -Wredundant-decls
LINKER_FLAGS += -v -Xlinker -Map=$(OUTPUT_FOLDER)/build/$(THIS_DIRECTORY).debug -Wl,-rpath,$(EMBEDDED_STAGING)/usr/lib $(LIB_DIRS) $(LIBS)


DISTRIBUTED_TEXT_LSS:=$(OUTPUT_FOLDER)/build/$(THIS_DIRECTORY).lss
DISTRIBUTED_TEXT_HEX:=$(OUTPUT_FOLDER)/images/$(THIS_DIRECTORY).hex
DISTRIBUTED_TEXT_ELF:=$(OUTPUT_FOLDER)/images/$(THIS_DIRECTORY).elf
DISTRIBUTED_TEXT_BIN:=$(OUTPUT_FOLDER)/images/$(THIS_DIRECTORY).bin
DISTRIBUTED_TEXT_LIB:=$(OUTPUT_FOLDER)/images/$(THIS_DIRECTORY).so
DISTRIBUTED_TEXT_MAP:=$(OUTPUT_FOLDER)/build/$(THIS_DIRECTORY).map

TARGET:= $(DISTRIBUTED_TEXT_ELF)

.PHONY: build
build: 
	@$(call mkstddirs,$(EMBEDDED_BUILD)/$(THIS_DIRECTORY))
	$(MAKE) $(DISTRIBUTED_TEXT_ELF)
	@echo "$(COLOR_GREEN)Building...$(COLOR_NORMAL)"

.PHONY: install
install:
	@echo "$(COLOR_GREEN)Installing...$(COLOR_NORMAL)"

.PHONY: format
format:
	@$(foreach file, $(INCLUDES) $(SOURCES), clang-format-9 -i $(file) &&) true;


.PHONY: clean
clean:
	@echo "$(COLOR_GREEN)Cleaning...$(COLOR_NORMAL)"

.PHONY: $(DISTRIBUTED_TEXT_HEX)
$(DISTRIBUTED_TEXT_HEX): $(DISTRIBUTED_TEXT_ELF)
	@echo "$(COLOR_GREEN)Built $@$(COLOR_NORMAL)"

.PHONY: $(DISTRIBUTED_TEXT_BIN)
$(DISTRIBUTED_TEXT_BIN): $(DISTRIBUTED_TEXT_ELF)
	@echo "$(COLOR_GREEN)Built $@$(COLOR_NORMAL)"

.PHONY: $(DISTRIBUTED_TEXT_ELF)
$(DISTRIBUTED_TEXT_ELF): $(OBJECTS)
	$(CXX) -o $@ $^ $(LINKER_FLAGS)
	@echo "$(CXX) $(LINKER_FLAGS) -o $@ $^"
	@echo "$(COLOR_GREEN)Building elf$@$(COLOR_NORMAL)"
	@echo "$(COLOR_GREEN)Built $@$(COLOR_NORMAL)"

.PHONY: $(DISTRIBUTED_TEXT_LIB)
$(DISTRIBUTED_TEXT_LIB): $(OBJECTS)
	@echo "$(COLOR_GREEN)Built $@$(COLOR_NORMAL)"

#.PHONY: $(OBJECTS)
#$(OBJECTS): $(SOURCES)
#	@echo "$(COLOR_GREEN)Building OBJECTS$(COLOR_NORMAL)"