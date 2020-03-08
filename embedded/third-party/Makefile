ROOT_PATH:= $(patsubst %/,%,$(realpath ..))
THIS_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
THIS_DIRECTORY_PATH:= $(patsubst %/,%,$(dir $(THIS_MAKEFILE)))
THIS_DIRECTORY:= $(patsubst %/,%,$(notdir $(THIS_DIRECTORY_PATH)))

include ../../build-configuration.mk

.PHONY: build
build:
	@$(call mkstddirs,$(EMBEDDED_BUILD))
	@$(MAKE) build-civetweb build-paho.mqtt.cpp

.PHONY: install
install:
	@$(MAKE) install-civetweb install-paho.mqtt.cpp

.PHONY: clean
clean:
	@$(MAKE) clean-civetweb clean-paho.mqtt.cpp

.PHONY: build-civetweb
build-civetweb:
	@$(call mkstddirs,$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@))
	mkdir -p $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/usr/lib
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/
	cd $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/ && \
	$(MAKE) lib slib CC=$(CC) WITH_LUA_SHARED=1 WITH_DUKTAPE_SHARED=1 WITH_IPV6=1 WITH_WEBSOCKET=1 \
	WITH_SERVER_STATS=1 WITH_DEBUG=1 WITH_CPP=1 HTMLDIR=./html DOCUMENT_ROOT=./html \
	PORTS=8080
	rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/*.a $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/usr/lib/
	rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/*.so $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/usr/lib/
	rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/include $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/

.PHONY: install-civetweb
install-civetweb:
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/lib/
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/include/

.PHONY: clean-civetweb
clean-civetweb:
	$(MAKE) -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/ clean

.PHONY: build-rapidjson
build-rapidjson:
	@$(call mkstddirs,$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@))
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/
	cd $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/ && cmake .
	$(MAKE) all -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build
	$(MAKE) install -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build DESTDIR=$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/

.PHONY: install-rapidjson
install-rapidjson:
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/lib/
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/include/

.PHONY: clean-rapidjson
clean-rapidjson:
	$(MAKE) -C $(EMBEDDED_BUILD)/$(patsubst clean-%,%,$@)/build clean

.PHONY: build-paho.mqtt.c
build-paho.mqtt.c:
	@$(call mkstddirs,$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@))
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/
	cd $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/ && cmake . -bBuild -H. -DPAHO_WITH_SSL=ON -DPAHO_ENABLE_TESTING=OFF
	$(MAKE) all -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build
	$(MAKE) install -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build DESTDIR=$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/

.PHONY: install-paho.mqtt.c
install-paho.mqtt.c:
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/lib/
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/include/

.PHONY: clean-paho.mqtt.c
clean-paho.mqtt.c:
	$(MAKE) -C $(EMBEDDED_BUILD)/$(patsubst clean-%,%,$@)/build clean

.PHONY: build-paho.mqtt.cpp
build-paho.mqtt.cpp:
	@$(call mkstddirs,$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@))
	rsync -azH --numeric-ids $(patsubst build-%,%,$@)/ $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/
	cd $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build/ && cmake . \
	-DPAHO_MQTT_C_INCLUDE_DIRS=$(EMBEDDED_BUILD)/$(patsubst build-%pp,%,$@)/staging/usr/local/include/ \
	-DPAHO_MQTT_C_LIBRARIES=$(EMBEDDED_BUILD)/$(patsubst build-%pp,%,$@)/staging/usr/local/lib/libpaho-mqtt3c.so
	$(MAKE) all -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build
	$(MAKE) install -C $(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/build DESTDIR=$(EMBEDDED_BUILD)/$(patsubst build-%,%,$@)/staging/

.PHONY: install-paho.mqtt.cpp
install-paho.mqtt.cpp:
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/lib/
	#rsync -azH --numeric-ids $(EMBEDDED_BUILD)/$(patsubst install-%,%,$@)/staging/include/

.PHONY: clean-paho.mqtt.cpp
clean-paho.mqtt.cpp:
	$(MAKE) -C $(EMBEDDED_BUILD)/$(patsubst clean-%,%,$@)/build clean
