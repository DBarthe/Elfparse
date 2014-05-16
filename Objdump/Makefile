##
## Makefile for objdump in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/objdump
## 
## Made by Barthelemy Delemotte
## Login   <delemo_b@epitech.net>
## 
## Started on Fri Mar  7 23:32:25 2014 Barthelemy Delemotte
## Last update Sun Mar 16 18:33:12 2014 Barthelemy Delemotte
##

CC ?= gcc

INCPATH = ./includes
LIBSPATH = ../libs
LIBSINCPATH = ../includes
SRCPATH = ./sources

CFLAGS = -I $(INCPATH) -I $(LIBSINCPATH) -Wall -Wextra -pedantic
DBGFLAGS = -ggdb3 -DDEBUG
NDBGFLAGS = -DNDEBUG
OFLAGS = -O3
LDFLAGS = -L $(LIBSPATH) -lelfparse -larparse

SRC =	$(SRCPATH)/display_archive.c \
	$(SRCPATH)/display_elf.c \
	$(SRCPATH)/display_elf_header.c \
	$(SRCPATH)/display_file.c \
	$(SRCPATH)/display_flags.c \
	$(SRCPATH)/dump_section.c \
	$(SRCPATH)/main.c

OBJ = $(SRC:.c=.o)

RM = rm -vf

TARGET = my_objdump

ifeq ($(DEBUG), 1)
CFLAGS += $(DBGFLAGS)
else
CFLAGS += $(NDBGFLAGS) $(OFLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
