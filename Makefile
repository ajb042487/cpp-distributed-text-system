ROOT_PATH:= $(patsubst %/,%,$(realpath .))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include build-configuration.mk

.PHONY: all
all: distributed-text-application

.PHONY: clean
clean: clean-embedded clean-html clean-js

.PHONY: prep-ubuntu-18.04
prep-ubuntu-18.04:
	@sudo apt-get install -y make cmake build-essential clang-format-9 libssl-dev

.PHONY: build-embedded
build-embedded:
	$(MAKE) -C $(EMBEDDED) build
	$(MAKE) -C $(EMBEDDED) install

.PHONY: build-js
build-js:
	$(MAKE) -C $(JS) build
	$(MAKE) -C $(JS) install

.PHONY: build-html
build-html:
	$(MAKE) -C $(HTML) build
	$(MAKE) -C $(HTML) install

.PHONY: clean-embedded
clean-embedded:
	$(MAKE) -C $(EMBEDDED) clean

.PHONY: clean-js
clean-js:
	$(MAKE) -C $(JS) clean

.PHONY: clean-html
clean-html:
	$(MAKE) -C $(HTML) clean

.PHONY: distributed-text-application
distributed-text-application: build-embedded build-js build-html
	@mkdir -p $(OUTPUT)/$@
	