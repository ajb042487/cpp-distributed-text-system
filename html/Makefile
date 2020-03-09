ROOT_PATH:= $(patsubst %/,%,$(realpath ..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../build-configuration.mk

.PHONY: build
build:
	@$(call mkstddirs,$(HTML_OUTPUT))
	@$(MAKE) build-distributed-text-html

.PHONY: install
install:
	@$(MAKE) install-distributed-text-html

.PHONY: clean
clean:
	@$(MAKE) clean-distributed-text-html

.PHONY: build-distributed-text-html
build-distributed-text-html:
	@$(call mkstddirs,$(HTML_BUILD)/$(patsubst build-%,%,$@))
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(HTML_BUILD)/$(patsubst build-%,%,$@)/build/
	rsync -azH --numeric-ids $(HTML_BUILD)/$(patsubst build-%,%,$@)/build/src/*js $(HTML_STAGING)/

.PHONY: install-distributed-text-html
install-distributed-text-html:
	#rsync -azH --numeric-ids $(HTML_BUILD)/$(patsubst build-%,%,$@)/staging/lib/

.PHONY: clean-distributed-text-html
clean-distributed-text-html:
	#$(MAKE) -C $(HTML_BUILD)/$(patsubst build-%,%,$@)/build/ clean