ROOT_PATH:= $(patsubst %/,%,$(realpath ..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../build-configuration.mk

.PHONY: build
build:
	@$(MAKE) -C third-party build
	@$(MAKE) -C third-party install
	@$(MAKE) build-distributed-text

.PHONY: install
install:
	@$(MAKE) install-distributed-text

.PHONY: clean
clean:
	@$(MAKE) -C third-party clean
	@$(MAKE) clean-distributed-text

.PHONY: build-distributed-text
build-distributed-text:
	rsync -azH --numeric-ids distributed-text $(EMBEDDED_BUILD)/
	$(MAKE) -C $(EMBEDDED)/distributed-text build

.PHONY: install-distributed-text
install-distributed-text:
	mkdir -p $(EMBEDDED_BUILD)/distributed-text/output
	$(MAKE) -C $(EMBEDDED)/distributed-text install DESTDIR=$(EMBEDDED_BUILD)/distributed-text/output

.PHONY: clean-distributed-text
clean-distributed-text:
	$(MAKE) -C $(EMBEDDED)/distributed-text clean
