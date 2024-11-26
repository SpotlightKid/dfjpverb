#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX, Christopher Arndt, and Patrick Desaulniers
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = dfjpverb

# --------------------------------------------------------------
# FAUST DSP source

FAUST_DSP_DIR ?= ../../faust
FAUST_ARCH_DIR ?= $(FAUST_DSP_DIR)/arch
FAUST_DSP_SOURCE = $(FAUST_DSP_DIR)/$(NAME).dsp
FAUST_IDENTIFIER := $(shell grep 'declare name' $(FAUST_DSP_SOURCE) | cut -f 2 -d '"')

# --------------------------------------------------------------
# Plugin types to build

BUILD_CLAP ?= true
BUILD_DSSI ?= false
BUILD_JACK ?= false
BUILD_LADSPA ?= false
BUILD_LV2 ?= true
BUILD_VST2 ?= false
BUILD_VST3 ?= true

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	$(FAUST_IDENTIFIER).cpp \
	PluginDFJPverb.cpp

# --------------------------------------------------------------
# Do some magic
include ../../dpf/Makefile.plugins.mk

# --------------------------------------------------------------
# Enable all selected plugin types

ifeq ($(BUILD_CLAP),true)
TARGETS += clap
endif

ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
TARGETS += dssi
endif
endif
endif
endif

ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif
endif

ifeq ($(BUILD_LADSPA),true)
TARGETS += ladspa
endif

ifeq ($(BUILD_LV2),true)
TARGETS += lv2_dsp
endif

ifeq ($(BUILD_VST2),true)
TARGETS += vst
endif

ifeq ($(BUILD_VST3),true)
TARGETS += vst3
endif


# --------------------------------------------------------------
# Make targets

all: $(TARGETS)

# --------------------------------------------------------------
# Generate C++ source & header from FAUST DSP source

$(BUILD_DIR)/$(FAUST_IDENTIFIER).cpp.o: $(FAUST_IDENTIFIER).hpp $(FAUST_IDENTIFIER).cpp

$(FAUST_IDENTIFIER).cpp: $(FAUST_DSP_SOURCE)
	faustdr -DIdentifier=$(FAUST_IDENTIFIER) -a $(FAUST_ARCH_DIR)/generic.cpp $< > $@

$(FAUST_IDENTIFIER).hpp: $(FAUST_DSP_SOURCE)
	faustdr -DIdentifier=$(FAUST_IDENTIFIER) -a $(FAUST_ARCH_DIR)/generic.hpp $< > $@

# --------------------------------------------------------------
# Installation

install: all
ifeq ($(BUILD_CLAP),true)
	@mkdir -p -m755 $(DESTDIR)$(CLAP_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME).clap $(DESTDIR)$(CLAP_DIR)
endif
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
	@mkdir -p -m755 $(DESTDIR)$(DSSI_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) $(DESTDIR)$(DSSI_DIR)
endif
endif
endif
endif
ifeq ($(BUILD_LADSPA),true)
	@mkdir -p -m755 $(DESTDIR)$(LADSPA_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) $(DESTDIR)$(LADSPA_DIR)
endif
ifeq ($(BUILD_LV2),true)
	@mkdir -p -m755 $(DESTDIR)$(LV2_DIR)/$(NAME).lv2 && \
	  install -m755 $(TARGET_DIR)/$(NAME).lv2/*$(LIB_EXT) $(DESTDIR)$(LV2_DIR)/$(NAME).lv2 && \
	  install -m644 $(TARGET_DIR)/$(NAME).lv2/*.ttl $(DESTDIR)$(LV2_DIR)/$(NAME).lv2
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@mkdir -p -m755 $(DESTDIR)$(BINDIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)$(APP_EXT) $(DESTDIR)$(BINDIR)
endif
endif
ifeq ($(BUILD_VST2),true)
	@mkdir -p -m755 $(DESTDIR)$(VST2_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) $(DESTDIR)$(VST2_DIR)
endif
ifeq ($(BUILD_VST3),true)
	@mkdir -p -m755 $(DESTDIR)$(VST3_DIR)/$(dir $(VST3_FILENAME)) && \
	  install -m755 $(TARGET_DIR)/$(VST3_FILENAME) $(DESTDIR)$(VST3_DIR)/$(VST3_FILENAME)
endif


install-user: all
ifeq ($(BUILD_CLAP),true)
	@mkdir -p -m755 $(USER_CLAP_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME).clap $(USER_CLAP_DIR)
endif
ifeq ($(BUILD_DSSI),true)
ifneq ($(MACOS_OR_WINDOWS),true)
ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_LIBLO),true)
	@mkdir -p -m755 $(USER_DSSI_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-dssi$(LIB_EXT) $(USER_DSSI_DIR)
endif
endif
endif
endif
ifeq ($(BUILD_JACK),true)
ifeq ($(HAVE_JACK),true)
	@mkdir -p -m755 $(HOME)/bin && \
	  install -m755 $(TARGET_DIR)/$(NAME)$(APP_EXT) $(HOME)/bin
endif
endif
ifeq ($(BUILD_LV2),true)
	@mkdir -p -m755 $(USER_LV2_DIR)/$(NAME).lv2 && \
	  install -m755 $(TARGET_DIR)/$(NAME).lv2/*$(LIB_EXT) $(USER_LV2_DIR)/$(NAME).lv2 && \
	  install -m644 $(TARGET_DIR)/$(NAME).lv2/*.ttl $(USER_LV2_DIR)/$(NAME).lv2
endif
ifeq ($(BUILD_LADSPA),true)
	@mkdir -p -m755 $(USER_LADSPA_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-ladspa$(LIB_EXT) $(USER_LADSPA_DIR)
endif
ifeq ($(BUILD_VST2),true)
	@mkdir -p -m755 $(USER_VST2_DIR) && \
	  install -m755 $(TARGET_DIR)/$(NAME)-vst$(LIB_EXT) $(USER_VST2_DIR)
endif
ifeq ($(BUILD_VST3),true)
	@mkdir -p -m755 $(USER_VST3_DIR)/$(dir $(VST3_FILENAME)) && \
	  install -m755 $(TARGET_DIR)/$(VST3_FILENAME) $(USER_VST3_DIR)/$(VST3_FILENAME)
endif

# --------------------------------------------------------------

.PHONY: all install install-user
