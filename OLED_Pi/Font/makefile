INC = -I ../Font

object = font.o

all:$(object)

$(object) : ECHO
	@cc $(INC) -c font.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@

.PHONY : clean ECHO

ECHO :
	@echo "Module compile Font ..."

clean : 
	rm font.o
