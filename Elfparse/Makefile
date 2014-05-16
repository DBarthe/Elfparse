##
## Makefile for elfparse in /home/bade/Dev/tek2/Unix/PSU_2013_nmobjdump/elfparse
## 
## Made by Barthelemy Delemotte
## Login   <bade@epitech.net>
## 
## Started on Tue Mar  4 14:50:37 2014 Barthelemy Delemotte
## Last update Sun Mar 16 18:32:10 2014 Barthelemy Delemotte
##

CC ?= gcc
AR = ar -rc

INCPATH = ./includes
SRCPATH = ./sources

LIBSPATH = ../libs
LIBSINCPATH = ../includes

CFLAGS = -I $(INCPATH) -Wall -Wextra -pedantic
DBGFLAGS = -ggdb3 -DDEBUG
NDBGFLAGS = -DNDEBUG
OFLAGS = -O3
LDFLAGS =

SRC =	$(SRCPATH)/elf_free.c \
	$(SRCPATH)/elf_get_strtab.c \
	$(SRCPATH)/elf_get_symtab.c \
	$(SRCPATH)/elf_header_get.c \
	$(SRCPATH)/elf_header_get_ph.c \
	$(SRCPATH)/elf_header_get_sh.c \
	$(SRCPATH)/elf_load_buffer.c \
	$(SRCPATH)/elf_load_file.c \
	$(SRCPATH)/elf_load_header.c \
	$(SRCPATH)/elf_load_sections.c \
	$(SRCPATH)/elf_section_get2.c \
	$(SRCPATH)/elf_section_get.c \
	$(SRCPATH)/elf_strtab.c \
	$(SRCPATH)/elf_sym2.c \
	$(SRCPATH)/elf_sym.c \
	$(SRCPATH)/elf_symtab.c \
	$(SRCPATH)/utils.c

OBJ = $(SRC:.c=.o)

RM = rm -vf

TARGET = libelfparse.a

ifeq ($(DEBUG), 1)
CFLAGS += $(DBGFLAGS)
else
CFLAGS += $(NDBGFLAGS) $(OFLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET) $(OBJ)
	cp $(TARGET) $(LIBSPATH)/
	cp $(INCPATH)/elfparse.h $(LIBSINCPATH)/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
