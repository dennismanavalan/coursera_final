#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Week-2 Assignment for Intro to Embedded System
#
# Author: Peter Ling
# Date: 4/3/2022
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	make build PLATFORM = HOST / MSP432
#
# Platform Overrides:
# 
#
#------------------------------------------------------------------------------
include sources.mk

# Platform selection #
ifeq ($(PLATFORM),HOST)

	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
	OBJDUMP = objdump

endif

ifeq ($(PLATFORM),MSP432)

	CC=arm-none-eabi-gcc
	CPU = cortex-m4
	ARCH = thumb
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
	LDFLAGS= -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -mfpu=$(FPU) -march=armv7e-m -mfloat-abi=hard 
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
	LINKER_FILE = ../msp432p401r.lds

endif

# FLAGS definition
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)
CPPFLAGS = -E

# 
TARGET = c1m2_ling
PREP = $(SOURCES:.c=.i)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)

# all generated files for make clean use
FILES= *.o *.map *.d *.i *.out *.s *.asm

# Support the following output request
%.i:%.c
	$(CC) $(INCLUDES) $(CFLAGS) $(CPPFLAGS) $^ -o $@

%.d:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -M $^ -o $@

%.asm:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -S $^ -o $@

$(TARGET).asm:%.c
	$(OBJDUMP) -d $(TARGET).out -o $@

%.o:%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $^ -o $@

$(TARGET).out:$(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) $(TARGET).out

# Support the following make commands:

.PHONY:compile-all
compile-all:$(OBJS)
	$(CC) $(INCLUDES) $(CFLAGS) -c $^ -o $(TARGET).o

.PHONY:build
build:all

.PHONY:all
all:$(TARGET).out

.PHONY:clean
clean:
	rm -f *.o *.i *.d *.asm *.map $(TARGET).out