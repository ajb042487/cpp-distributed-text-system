
AR = ar
CC = gcc
CXX = g++
OBJCOPY = objcopy
OBJDUMP = objdump
STRIP = strip

CC_FLAGS +=
CXX_FLAGS +=
LINKER_FLAGS +=

DEPS := $(OBJS:.o=.d)

.PHONY: %.hex
%.hex: %.o
	$(OBJCOPY) $@ -O ihex $^

.PHONY: %.hex
%.hex: %.bin
	$(OBJCOPY) $@ -I binary -O ihex $<

.PHONY: %.hex
%.hex: %.elf
	$(OBJCOPY) $@ -O ihex $<

.PHONY: %.bin
%.bin: %.o
	$(OBJCOPY) $@ -O binary $^

.PHONY: %.bin
%.bin: %.elf
	$(OBJCOPY) $@ -O binary $<

.PHONY: %.bin
%.bin: %.hex
	$(OBJCOPY) $@ -I ihex -O binary $<

.PHONY: %.lss
%.lss: %.asm
	$(OBJDUMP) -S $< > $@

.PHONY: %.asm
%.asm: %.c
	$(CC) -S -fverbose-asm $(CC_FLAGS) $(INCLUDES) -c $<

.PHONY: %.asm
%.asm: %.cpp
	$(CXX) -S -fverbose-asm $(CXX_FLAGS) $(INCLUDES) -c $<

.PHONY: %.asm
%.asm: %.hpp
	$(CXX) -S -fverbose-asm $(CXX_FLAGS) $(INCLUDES) -c $<

.PHONY: %.o
%.o: %.asm
	$(CC) -S -o $@ $<
	@echo "$(COLOR_GREEN)Building asm$@$(COLOR_NORMAL)"

.PHONY: %.o
%.o: %.c
	$(CC) $(CC_FLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(COLOR_GREEN)Building c$@$(COLOR_NORMAL)"

.PHONY: %.o
%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -o $@ -c $<
	@echo "$(COLOR_GREEN)Building cpp$@$(COLOR_NORMAL)"

.PHONY: %.o
%.o: %.hpp
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(COLOR_GREEN)Building hpp$@$(COLOR_NORMAL)"

.PHONY: %.so
%.so: %.a
	$(CC) -shared -o $@ -Wl,--whole-archive $<
	@echo "$(COLOR_GREEN)Building so$@$(COLOR_NORMAL)"

.PHONY: %.so
%.so: %.o
	$(CC) -shared -o $@ $^
	@echo "$(COLOR_GREEN)Building so$@$(COLOR_NORMAL)"

.PHONY: %.a
%.a: %.o
	$(AR) rcs $@ $^
	@echo "$(COLOR_GREEN)Building a$@$(COLOR_NORMAL)"

.PHONY: %.elf
%.elf: %.o
	$(CC) -o $@ $^
	@echo "$(CC) -o $@ $^"
	@echo "$(COLOR_GREEN)Building elf$@$(COLOR_NORMAL)"

.PHONY: %.debug
%.debug: %.elf
	$(OBJCOPY) --only-keep-debug $< $@
	$(STRIP) --strip-debug --strip-unneeded $<
	$(OBJCOPY) --add-gnu-debuglink=$@ $<

.PHONY: %.debug
%.debug: %.a
	$(OBJCOPY) --only-keep-debug $< $@
	$(STRIP) --strip-debug --strip-unneeded $<
	$(OBJCOPY) --add-gnu-debuglink=$@ $<

.PHONY: %.debug
%.debug: %.so
	$(OBJCOPY) --only-keep-debug $< $@
	$(STRIP) --strip-debug --strip-unneeded $<
	$(OBJCOPY) --add-gnu-debuglink=$@ $<

#Build Dependencies
%.asm.d: %.asm
	@$(CC) -M $< > $@

%.c.d: %.c
	@$(CC) -M $< > $@

%.cpp.d: %.cpp
	@$(CXX) -M $< > $@

include $(patsubst %.asm,%.asm.d,$(ASM_SOURCES))
include $(patsubst %.c,%.c.d,$(C_SOURCES))
include $(patsubst %.cpp,%.cpp.d,$(CXX_SOURCES))
