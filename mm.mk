q=$(shell uname -s)

all:
ifeq ($(q),Linux)
	@echo Linux

else
	@echo solaris

endif
