
#MODULE_DIR = $(shell pwd)
#MODULE = $(notdir $(MODULE_DIR))

#VPATH += $(ROOT_DIR)/$(MODULE) 
INC = -I ../hw_gpio

object = IIC.o

all:$(object)

$(object) : IIC.c IIC.h ../hw_gpio/Gpio.h ECHO
	@cc $(INC) -c IIC.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@

.PHONY : clean ECHO

ECHO :
	@echo "Module compile IIC ..."

clean : 
	rm IIC.o
