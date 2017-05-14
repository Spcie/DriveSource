
#MODULE_DIR = $(shell pwd)
#MODULE = $(notdir $(MODULE_DIR))

#VPATH += $(ROOT_DIR)/$(MODULE) 
INC = -I ../hardware

object = spi.o

all:$(object)

$(object) : spi.c spi.h ../hardware/Gpio.h ECHO
	@cc $(INC) -c spi.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@

.PHONY : clean ECHO

ECHO :
	@echo "Module compile SPI ..."

clean : 
	rm spi.o
