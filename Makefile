##
## Makefile for nm-objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump
## 
## Made by Barthelemy Delemotte
## Login   <delemo_b@epitech.net>
## 
## Started on Tue Mar 11 10:40:40 2014 Barthelemy Delemotte
## Last update Sun Mar 16 18:33:34 2014 Barthelemy Delemotte
##

OBJDUMP_PATH = Objdump
NM_PATH = Nm
ARPARSE_PATH = Arparse
ELFPARSE_PATH = Elfparse
LIBS_PATH = libs

OBJDUMP_TARGET = my_objdump
NM_TARGET = my_nm
ARPARSE_TARGET = $(LIBS_PATH)/libarparse.a
ELFPARSE_TARGET = $(LIBS_PATH)/libelfparse.a

LIBS = $(ELFPARSE_TARGET) $(ARPARSE_TARGET)

RM = rm -vf

all: objdump nm
clean: objdump-clean nm-clean
fclean: objdump-fclean nm-fclean
re: objdump-re nm-re

clean-all: clean libs-clean
fclean-all: fclean libs-fclean
re-all: libs-re re

# objdump
objdump: $(OBJDUMP_TARGET)
objdump-re: $(LIBS)
	make re -C $(OBJDUMP_PATH)/
	@cp $(OBJDUMP_PATH)/$(OBJDUMP_TARGET) .
objdump-clean:
	make clean -C $(OBJDUMP_PATH)/
objdump-fclean:
	make fclean -C $(OBJDUMP_PATH)/
	$(RM) $(OBJDUMP_TARGET)
$(OBJDUMP_TARGET): $(LIBS)
	make -C $(OBJDUMP_PATH)/
	@cp $(OBJDUMP_PATH)/$(OBJDUMP_TARGET) .

#nm
nm: $(NM_TARGET)
nm-re: $(LIBS)
	make re -C $(NM_PATH)/
	@cp $(NM_PATH)/$(NM_TARGET) .
nm-clean:
	make clean -C $(NM_PATH)/
nm-fclean:
	make fclean -C $(NM_PATH)/
	$(RM) $(NM_TARGET)
$(NM_TARGET): $(LIBS)
	make -C $(NM_PATH)/
	@cp $(NM_PATH)/$(NM_TARGET) .

# libs
libs-clean: $(foreach lib, $(LIBS), $(lib)-clean)
libs-fclean: $(foreach lib, $(LIBS), $(lib)-fclean)
	$(RM) $(LIBS)
libs-re: $(foreach lib, $(LIBS), $(lib)-re)

# elfparse
$(ELFPARSE_TARGET):
	make -C $(ELFPARSE_PATH)/
$(ELFPARSE_TARGET)-fclean:
	make fclean -C $(ELFPARSE_PATH)/
$(ELFPARSE_TARGET)-clean:
	make clean -C $(ELFPARSE_PATH)/
$(ELFPARSE_TARGET)-re:
	make re -C $(ELFPARSE_PATH)/

# arparse
$(ARPARSE_TARGET):
	make -C $(ARPARSE_PATH)/
$(ARPARSE_TARGET)-fclean:
	make fclean -C $(ARPARSE_PATH)/
$(ARPARSE_TARGET)-clean:
	make clean -C $(ARPARSE_PATH)/
$(ARPARSE_TARGET)-re:
	make re -C $(ARPARSE_PATH)/
