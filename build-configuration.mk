BUILD_CONFIGURATION_MAKEFILE:= $(abspath $(lastword $(MAKEFILE_LIST)))
BUILD_CONFIGURATION_PATH:= $(patsubst %/,%,$(dir $(BUILD_CONFIGURATION_MAKEFILE)))
BUILD_CONFIGURATION_DIRECTORY:= $(patsubst %/,%,$(notdir $(BUILD_CONFIGURATION_PATH)))

COLOR_GREEN=\033[0;32m
COLOR_NORMAL=\033[0m

REVISION_CONTROL_HASH:=$(shell git rev-parse HEAD)

OUTPUT=$(BUILD_CONFIGURATION_PATH)/output

mkstddirs= mkdir -p $(1)/host && mkdir -p $(1)/build && mkdir -p $(1)/target && mkdir -p $(1)/images && mkdir -p $(1)/staging

EMBEDDED=$(BUILD_CONFIGURATION_PATH)/embedded
EMBEDDED_HOST=$(OUTPUT)/embedded/host
EMBEDDED_BUILD=$(OUTPUT)/embedded/build
EMBEDDED_TARGET=$(OUTPUT)/embedded/target
EMBEDDED_IMAGES=$(OUTPUT)/embedded/images
EMBEDDED_STAGING=$(OUTPUT)/embedded/staging

