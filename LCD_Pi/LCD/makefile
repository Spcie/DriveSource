
#MODULE_DIR = $(shell pwd)
#MODULE = $(notdir $(MODULE_DIR))

#VPATH += $(ROOT_DIR)/$(MODULE) 
INC = -I ../SPI -I ../Font

object = lcd.o

all:$(object)

$(object) : lcd.c lcd.h ../SPI/spi.h ../Font/font.h ECHO
	@cc $(INC) -c lcd.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@

.PHONY : clean ECHO

ECHO :
	@echo "Module compile LCD ..."

clean : 
	rm spi.o
