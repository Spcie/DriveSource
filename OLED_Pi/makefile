#@echo OLED compile

OBJ_DIR = obj
SUBDIRS = $(shell ls -l | grep ^d | awk '{if($$9 != "obj") print $$9}')
SOURCES = $(wildcard ${SUBDIRS}/*.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
ROOT_DIR = $(shell pwd)
INC = -I ./IIC -I ./hw_gpio -I ./Font
MODULES = $(wildcard ./obj/*.o)

object = oled.o

export ROOT_DIR OBJ_DIR  

all:$(SUBDIRS) $(object)

$(SUBDIRS): ECHO
	@make --no-print-directory -C $@

$(object): $(MODULES) ./IIC/IIC.h  ./Font/font.h
	@cc $(INC) oled.c $^ -o oled.out -lwiringPi

.PHONY : clean ECHO DIR_ECHO 

clean :
	rm oled.o

ECHO : 
	@echo "Module compiles OLED"
	@echo $(SUBDIRS)

E:
	@echo $(MODULES)

