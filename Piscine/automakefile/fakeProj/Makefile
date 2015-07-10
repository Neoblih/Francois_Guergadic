COMP	= clang

RM	 = rm -f

BLUE	= "\033[1;36m"
GREEN	= "\033[1;32m"
YELLOW	= "\033[1;33m"
RED	= "\033[1;31m"
NC	= "\033[0m"

DEBUG	= no

INCLUDE	= include

CFLAGS	= 
CFLAGS	+= -I./$(INCLUDE)/.
ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS	= 

NAME	= fakeProj

SRC	= $(wildcard ./*.c)

OBJS	= $(SRC:.c=.o)

aff_make	= echo -e $(GREEN) "** Make DONE **" $(NC) "\n\t-Compiled executed file: " $(NAME) "\n"

aff_clean	= echo -e $(YELLOW) "** clean DONE **" $(NC) "\n\t-Cleaned .o files \n"

aff_fclean	= echo -e $(BLUE) "** fclean DONE **" $(NC) "\n\t-Cleaned" $(NAME) "\n"

aff_comp	= echo -e "Creating .o file from" $<

aff_error	= echo -e $(RED) "\n |-----\n | Error while creating .o file from" $< "\n |-----\n" $(NC)

REP_SVG	= fakeProj_SVG
ZIP	= tar
ZIPFLAGS	= -cvvf
UNZIP	= 
UNZIPFLAGS	= 
ARCH	= `cat $(REP_SVG)/archive | tail -2 | head -1 | awk '{if (NF == 0) print 0; else print $$1;}'`
NEXT_ARCH	= `cat $(REP_SVG)/archive | tail -2 | head -1 | awk '{if (NF == 0) print 1; else print $$1 " + 1";}' | bc`

all:	$(NAME)


$(NAME): $(OBJS)
	@$(COMP) -o $@ $^ $(LDFLAGS)
	@$(aff_make)

%.o: %.c
	@($(COMP) -o $@ -c $< $(CFLAGS) && $(aff_comp)) || $(aff_error)

main.o: include/fakeProj.h

calc.o: include/fakeProj.h include/calc/calcul.h

clean:
	@$(RM) $(OBJS)
	@$(aff_clean)

fclean: clean
	@$(RM) $(NAME)
	@$(aff_fclean)

archive:
	@mkdir -p $(REP_SVG)
	@echo -n " " >> $(REP_SVG)/archive
	@$(ZIP) $(ZIPFLAGS) $(NEXT_ARCH).$(ZIP) $(SRC)
	@mv $(NEXT_ARCH).$(ZIP) $(REP_SVG)/
	@echo "Fichier" $(NEXT_ARCH).$(ZIP) "généré."
	@echo $(NEXT_ARCH) >> $(REP_SVG)/archive

num:
	@mkdir -p $(REP_SVG)
	@echo -n " " >> $(REP_SVG)/archive
	@echo "Numero de la prochaine archive:" $(NEXT_ARCH)

delete:
	@mkdir -p $(REP_SVG)
	@echo -n " " >> $(REP_SVG)/archive
	@rm -rf $(REP_SVG)/$(ARCH).$(ZIP)
	@echo "Suppression de l'archive:" $(ARCH).$(ZIP)
	@echo -n "`cat $(REP_SVG)/archive | head -n -1`" > $(REP_SVG)/archive

re: fclean all

.PHONY: all clean fclean re
