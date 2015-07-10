#!/bin/sh
## new.sh for automakefile in /home/guerga_a/Piscine/automakefile
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Mon Jun 22 18:10:05 2015 francois guergadic
## Last update Tue Jun 23 18:56:08 2015 francois guergadic
##

F_NAME=$1
REP=`cat $F_NAME | grep "REP;" | awk -F ";" '{print $2}'`

function function_ARCHIVE()
{
    echo "archive:" >> ./$REP/Makefile
    echo -e "\t@mkdir -p \$(REP_SVG)" >> ./$REP/Makefile
    echo -e "\t@echo -n \" \" >> \$(REP_SVG)/archive" >> ./$REP/Makefile
    echo -e "\t@\$(ZIP) \$(ZIPFLAGS) \$(NEXT_ARCH).\$(ZIP) \$(SRC)" >> ./$REP/Makefile
    echo -e "\t@mv \$(NEXT_ARCH).\$(ZIP) \$(REP_SVG)/"  >> ./$REP/Makefile
    echo -e "\t@echo \"Fichier\" \$(NEXT_ARCH).\$(ZIP) \"généré.\"" >> ./$REP/Makefile
    echo -e "\t@echo \$(NEXT_ARCH) >> \$(REP_SVG)/archive" >> ./$REP/Makefile
    echo "" >> ./$REP/Makefile
    echo "num:" >> ./$REP/Makefile
    echo -e "\t@mkdir -p \$(REP_SVG)" >> ./$REP/Makefile
    echo -e "\t@echo -n \" \" >> \$(REP_SVG)/archive" >> ./$REP/Makefile
    echo -e "\t@echo \"Numero de la prochaine archive:\" \$(NEXT_ARCH)" >> ./$REP/Makefile
    echo "" >> ./$REP/Makefile
    echo "delete:" >> ./$REP/Makefile
    echo -e "\t@mkdir -p \$(REP_SVG)" >> ./$REP/Makefile
    echo -e "\t@echo -n \" \" >> \$(REP_SVG)/archive" >> ./$REP/Makefile
    echo -e "\t@rm -rf \$(REP_SVG)/\$(ARCH).\$(ZIP)" >> ./$REP/Makefile
    echo -e "\t@echo \"Suppression de l'archive:\" \$(ARCH).\$(ZIP)" >> ./$REP/Makefile
    echo -e "\t@echo -n \"\`cat \$(REP_SVG)/archive | head -n -1\`\" > \$(REP_SVG)/archive" >> ./$REP/Makefile
}

function function_ARCH()
{
    echo -e "ARCH\t= \`cat \$(REP_SVG)/archive | tail -2 | head -1 | awk '{if (NF == 0) print 0; else print \$\$1;}'\`" >> ./$REP/Makefile
    echo -e "NEXT_ARCH\t= \`cat \$(REP_SVG)/archive | tail -2 | head -1 | awk '{if (NF == 0) print 1; else print \$\$1 \" + 1\";}' | bc\`" >> ./$REP/Makefile
}

function function_REP_SVG()
{
    REP_SVG=`cat $F_NAME | grep "REP_SVG;" | awk -F ";" '{print $2}'`
    echo -e -n "REP_SVG\t= " >> ./$REP/Makefile
    echo -e $REP_SVG >> ./$REP/Makefile
}

function function_ZIP()
{
    ZIP=`cat $F_NAME | grep "ZIP;" | awk -F ";" '{print $2}'`
    echo -e -n "ZIP\t= " >> ./$REP/Makefile
    echo -e $ZIP >> ./$REP/Makefile
}

function function_ZIPFLAGS()
{
    ZIPFLAGS=`cat $F_NAME | grep "ZIPFLAGS;" | awk -F ";" '{print $2}'`
    echo -e -n "ZIPFLAGS\t= " >> ./$REP/Makefile
    echo -e $ZIPFLAGS >> ./$REP/Makefile
}

function function_UNZIP()
{
    UNZIP=`cat $F_NAME | grep "UNZIP;" | awk -F ";" '{print $2}'`
    echo -e -n "UNZIP\t= " >> ./$REP/Makefile
    echo -e $UNZIP >> ./$REP/Makefile
}

function function_UNZIPFLAGS()
{
    UNZIPFLAGS=`cat $F_NAME | grep "UNZIPFLAGS;" | awk -F ";" '{print $2}'`
    echo -e -n "UNZIPFLAGS\t= " >> ./$REP/Makefile
    echo -e $UNZIPFLAGS >> ./$REP/Makefile
}

function function_DEPEND()
{
    local INCLUDE=`cat $F_NAME | grep "HEADERS;" | awk -F ";" '{print $2}'`
    local numberLine=`cat $F_NAME | grep -v "REP_SVG;" | grep -v "ZIP;" | grep -v "ZIPFLAGS;" | grep -v "UNZIP;" | grep -v "UNZIPFLAGS;" | grep -v "EXEC;" | grep -v "REP;" | grep -v "SOURCES;" | grep -v "HEADERS;" | grep -v "LIBS;" | grep -v "COMP;" | grep -v "CFLAGS;" | grep -v "LDFLAGS" | wc -l`
    local i=0
    while [[ $i < $numberLine ]]
    do	
	local line=`cat $F_NAME | grep -v "REP_SVG;" | grep -v "ZIP;" | grep -v "ZIPFLAGS;" | grep -v "UNZIP;" | grep -v "UNZIPFLAGS;" | grep -v "EXEC;" | grep -v "REP;" | grep -v "SOURCES;" | grep -v "HEADERS;" | grep -v "LIBS;" | grep -v "COMP;" | grep -v "CFLAGS;" | grep -v "LDFLAGS" | awk '{if (NR == '$i' + 1) print }' > temp1`
	local numberArg=`cat $F_NAME | grep -v "REP_SVG;" | grep -v "ZIP;" | grep -v "ZIPFLAGS;" | grep -v "UNZIP;" | grep -v "UNZIPFLAGS;" | grep -v "EXEC;" | grep -v "REP;" | grep -v "SOURCES;" | grep -v "HEADERS;" | grep -v "LIBS;" | grep -v "COMP;" | grep -v "CFLAGS;" | grep -v "LDFLAGS" | awk '{if (NR == '$i' + 1) print }' | grep -o ";" | wc -l`
	numberArg=$(($numberArg + 1))
	i=$(($i + 1))
	local j=0
	while [[ $j < $numberArg ]]
	do
	    j=$(($j + 1))
	    echo -n "`awk -F ";" '{print $'$j'}' temp1 > temp2`" >> ./$REP/Makefile
	    if [[ $j == 1 ]]; then
		echo -n "`cat temp2 | sed 's/\.c/\.o/g'`" >> ./$REP/Makefile 
		echo -n ":" >> ./$REP/Makefile
	    else 
		numberArg=$(($numberArg + 1))
		if [[ $j != $numberArg ]]; then
		    echo -n " $INCLUDE/" >> ./$REP/Makefile 
		    echo -n "`cat temp2`" >> ./$REP/Makefile 
		fi
		numberArg=$(($numberArg - 1))
	    fi
	done
	echo -e "\n" >> ./$REP/Makefile
    done
    rm -rf temp2
    rm -rf temp1
}

function function_REP()
{
    local REP=`cat $F_NAME | grep "REP;" | awk -F ";" '{print $2}'`
    echo -n -e "REP\t= " >> ./$REP/Makefile
    echo $REP >> ./$REP/Makefile
}

function function_EXEC()
{
    local EXEC=`cat $F_NAME | grep "EXEC;" | awk -F ";" '{print $2}'`
    echo -n -e "NAME\t= " >> ./$REP/Makefile
    echo $EXEC >> ./$REP/Makefile
}

function function_INCLUDE()
{
    local HEADER=`cat $F_NAME | grep "HEADERS;" | awk -F ";" '{print $2}'`
    echo -n -e "INCLUDE\t= " >> ./$REP/Makefile
    echo $HEADER >> ./$REP/Makefile
}

function function_CFLAGS()
{
    local CFLAGS=`cat $F_NAME | grep "CFLAGS;" | awk -F ";" '{print $2}'`
    echo -n -e "CFLAGS\t= " >> ./$REP/Makefile
    echo $CFLAGS >> ./$REP/Makefile
    echo -e "CFLAGS\t+= -I./\$(INCLUDE)/." >> ./$REP/Makefile
}

function function_LDFLAGS()
{
    local LDFLAGS=`cat $F_NAME | grep "LDFLAGS;" | awk -F ";" '{print $2}'`
    echo -n -e "LDFLAGS\t= " >> ./$REP/Makefile
    echo $LDFLAGS >> ./$REP/Makefile
}

function function_LIBS()
{
    local LIBS=`cat $F_NAME | grep "LIBS;" | awk -F ";" '{print $2}'`
    echo -n -e "LDFLAGS\t+= " >> ./$REP/Makefile
    echo $LIBS >> ./$REP/Makefile
}

function function_COMP()
{
    local COMP=`cat $F_NAME | grep "COMP;" | awk -F ";" '{print $2}'`
    echo -n -e "COMP\t= " >> ./$REP/Makefile
    echo $COMP >> ./$REP/Makefile
}

function function_RM()
{
    echo -e "RM\t = rm -f" >> ./$REP/Makefile
}

function function_COLOR()
{
    echo -e "BLUE\t= \"\\\033[1;36m\"" >> ./$REP/Makefile
    echo -e "GREEN\t= \"\\\033[1;32m\"" >> ./$REP/Makefile
    echo -e "YELLOW\t= \"\\\033[1;33m\"" >> ./$REP/Makefile
    echo -e "RED\t= \"\\\033[1;31m\"" >> ./$REP/Makefile
    echo -e "NC\t= \"\\\033[0m\"" >> ./$REP/Makefile
}

function function_DEBUG()
{
    echo -e "DEBUG\t= no" >> ./$REP/Makefile
}

function function_DEBUG_FLAG()
{
    echo "ifeq (\$(DEBUG), yes)" >> ./$REP/Makefile
    echo -e "\tCFLAGS += -g" >> ./$REP/Makefile
    echo "endif" >> ./$REP/Makefile
}

function function_SRC()
{
    local SOURCES=`cat $F_NAME | grep "SOURCES;" | awk -F ";" '{print $2}'`
    echo -e "SRC\t= \$(wildcard $SOURCES/*.c)" >> ./$REP/Makefile
}

function function_OBJS()
{
    echo -e "OBJS\t= \$(SRC:.c=.o)" >> ./$REP/Makefile
}

function function_AFF()
{
    echo -e "aff_make\t= echo -e \$(GREEN) \"** Make DONE **\" \$(NC) \"\\\n\\\t-Compiled executed file: \" \$(NAME) \"\\\n\"\n" >> ./$REP/Makefile
    echo -e "aff_clean\t= echo -e \$(YELLOW) \"** clean DONE **\" \$(NC) \"\\\n\\\t-Cleaned .o files \\\n\"\n" >> ./$REP/Makefile
    echo -e "aff_fclean\t= echo -e \$(BLUE) \"** fclean DONE **\" \$(NC) \"\\\n\\\t-Cleaned\" \$(NAME) \"\\\n\"\n" >> ./$REP/Makefile
    echo -e "aff_comp\t= echo -e \"Creating .o file from\" \$<\n" >> ./$REP/Makefile
    echo -e "aff_error\t= echo -e \$(RED) \"\\\n |-----\\\n | Error while creating .o file from\" \$< \"\\\n |-----\\\n\" \$(NC)" >> ./$REP/Makefile
}

function function_ALL()
{
    echo -e "all:\t\$(NAME)\n\n" >> ./$REP/Makefile
    echo "\$(NAME): \$(OBJS)" >> ./$REP/Makefile
    echo -e "\t@\$(COMP) -o \$@ \$^ \$(LDFLAGS)" >> ./$REP/Makefile
    echo -e "\t@\$(aff_make)\n" >> ./$REP/Makefile
    echo -e "%.o: %.c" >> ./$REP/Makefile
    echo -e "\t@(\$(COMP) -o \$@ -c \$< \$(CFLAGS) && \$(aff_comp)) || \$(aff_error)" >> ./$REP/Makefile
}

function function_CLEAN()
{
    echo "clean:" >> ./$REP/Makefile
    echo -e "\t@\$(RM) \$(OBJS)" >> ./$REP/Makefile
    echo -e "\t@\$(aff_clean)" >> ./$REP/Makefile
}

function function_FCLEAN()
{
    echo "fclean: clean" >> ./$REP/Makefile
    echo -e "\t@\$(RM) \$(NAME)" >> ./$REP/Makefile
    echo -e "\t@\$(aff_fclean)" >> ./$REP/Makefile
}

function function_RE()
{
    echo "re: fclean all" >> ./$REP/Makefile
}

function function_PHONY()
{
    echo ".PHONY: all clean fclean re" >> ./$REP/Makefile
}

echo -n "" > ./$REP/Makefile
function_COMP
echo "" >> ./$REP/Makefile
function_RM
echo "" >> ./$REP/Makefile
function_COLOR
echo "" >> ./$REP/Makefile
function_DEBUG
echo "" >> ./$REP/Makefile
function_INCLUDE
echo "" >> ./$REP/Makefile
function_CFLAGS
function_DEBUG_FLAG
echo "" >> ./$REP/Makefile
function_LDFLAGS
echo "" >> ./$REP/Makefile
function_EXEC
echo "" >> ./$REP/Makefile
function_SRC
echo "" >> ./$REP/Makefile
function_OBJS
echo "" >> ./$REP/Makefile
function_AFF
echo "" >> ./$REP/Makefile
function_REP_SVG
function_ZIP
function_ZIPFLAGS
function_UNZIP
function_UNZIPFLAGS
function_ARCH
echo "" >> ./$REP/Makefile
function_ALL
echo "" >> ./$REP/Makefile
function_DEPEND
function_CLEAN
echo "" >> ./$REP/Makefile
function_FCLEAN
echo "" >> ./$REP/Makefile
function_ARCHIVE
echo "" >> ./$REP/Makefile
function_RE
echo "" >> ./$REP/Makefile
function_PHONY
