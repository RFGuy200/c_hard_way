#SHELL:=/bin/bash
.EXPORT_ALL_VARIABLES:
	
text_path := ./text
misc_path := ./misc
misc_path_local := this_is_local
TEXT_FILE := $(text_path)/text.txt
TEXT_READ = $(shell cat $(TEXT_FILE))
EXTERNAL = internal

all:test_target init f1.o f2.o 
	@echo $$misc_path_local
	@echo $$text_path
	$(file > $(TEXT_FILE), "Hello")
	$(file >> $(TEXT_FILE), "World")
	@echo $(TEXT_READ)
	@echo "EXTERNAL in makfile = $(EXTERNAL)"
.PHONY: all

include */*.mk

init:
	touch test1.c 

%.o:
	@echo $@

.PHONY:clean
clean:
	@find -name "*.c" -exec rm {} \;
