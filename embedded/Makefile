ROOT_PATH:= $(patsubst %/,%,$(realpath ..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../build-configuration.mk

.PHONY: build
build:
	@$(MAKE) -C third-party build
	@$(MAKE) -C third-party install

.PHONY: install
install:

.PHONY: clean
clean:
	@$(MAKE) -C third-party clean
