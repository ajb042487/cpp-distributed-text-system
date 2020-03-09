ROOT_PATH:= $(patsubst %/,%,$(realpath ..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../build-configuration.mk

.PHONY: build
build:
	@$(call mkstddirs,$(JS_OUTPUT))
	@$(MAKE) build-paho.mqtt.javascript

.PHONY: install
install:
	@$(MAKE) install-paho.mqtt.javascript

.PHONY: clean
clean:
	@$(MAKE) clean-paho.mqtt.javascript

.PHONY: build-paho.mqtt.javascript
build-paho.mqtt.javascript:
	@$(call mkstddirs,$(JS_BUILD)/$(patsubst build-%,%,$@))
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(JS_BUILD)/$(patsubst build-%,%,$@)/build/
	rsync -azH --numeric-ids $(JS_BUILD)/$(patsubst build-%,%,$@)/build/src/*js $(JS_STAGING)/

.PHONY: install-paho.mqtt.javascript
install-paho.mqtt.javascript:
	#rsync -azH --numeric-ids $(JS_BUILD)/$(patsubst build-%,%,$@)/staging/lib/

.PHONY: clean-paho.mqtt.javascript
clean-paho.mqtt.javascript:
	#$(MAKE) -C $(JS_BUILD)/$(patsubst build-%,%,$@)/build/ clean