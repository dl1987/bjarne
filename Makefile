MAKE_DIR = $(PWD)

CALCULATOR_DIR := $(MAKE_DIR)/calculator

all:
	@$(MAKE) -C calculator -f calculator.mk

clean:
	@$(MAKE) -C calculator -f calculator.mk clean
