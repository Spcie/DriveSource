
object = font.o

all:$(object)

$(object) : ECHO
	@cc -c font.c -o $(ROOT_DIR)/$(OBJ_DIR)/$@

.PHONY : clean ECHO

ECHO :
	@echo "Module compile Font ..."

clean : 
	rm font.o