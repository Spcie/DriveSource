
#MODULE_DIR = $(shell pwd)
#MODULE = $(notdir $(MODULE_DIR))
#VPATH += $(ROOT_DIR)/$(MODULE)

object = Gpio.o

all : $(object) 

$(object) : Gpio.c Gpio.h ECHO
	@cc -c Gpio.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@ -lwiringPi 

.PHONY : clean ECHO

ECHO:
	@echo "Module compile Gpio ..."

clean :
	rm $(object)
