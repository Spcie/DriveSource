OBJ_DIR = obj
SUBDIRS = $(shell ls -l | grep ^d | awk '{if($$9 != "obj") print $$9}')
SOURCES = $(wildcard ${SUBDIRS}/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
ROOT_DIR = $(shell pwd)
INC = -I ./SPI -I ./hardware -I ./LCD -I ./Font
MODULES = $(wildcard ./obj/*.o)

object = lcd.a
example = example.c

export ROOT_DIR OBJ_DIR  

all:$(SUBDIRS) $(object) $(example)

$(SUBDIRS): ECHO
	@make --no-print-directory -C $@

#$(object): $(MODULES) ./SPI/spi.h  ./Font/font.h
#	@cc $(INC) lcd.c $^ -o lcd.o  -lwiringPi
$(object): $(MODULES) ./SPI/spi.h  ./Font/font.h
	ar rcs $@ $^
	
$(example): $(object) ./LCD/lcd.h
	@cc $(INC) example.c $^ -o example.out -lwiringPi

.PHONY : clean ECHO DIR_ECHO 

clean :
	rm lcd.o

ECHO : 
	@echo "Module compiles LCD"
	@echo $(SUBDIRS)

E:
	@echo $(MODULES)