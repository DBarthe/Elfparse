##
## Makefile for arparse in /home/common/Dev/tek2/Unix/PSU_2013_nmobjdump/arparse
## 
## Made by Barthelemy Delemotte
## Login   <delemo_b@epitech.net>
## 
## Started on Thu Mar  6 12:56:19 2014 Barthelemy Delemotte
## Last update Sun Mar 16 18:31:18 2014 Barthelemy Delemotte
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

SRC =	$(SRCPATH)/ar_entry.c \
	$(SRCPATH)/ar_free.c \
	$(SRCPATH)/ar_get_next_entry.c \
	$(SRCPATH)/ar_load_file.c \
	$(SRCPATH)/ar_strtab.c 

OBJ = $(SRC:.c=.o)

RM = rm -vf

TARGET = libarparse.a

ifeq ($(DEBUG), 1)
CFLAGS += $(DBGFLAGS)
else
CFLAGS += $(NDBGFLAGS) $(OFLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET) $(OBJ)
	cp $(TARGET) $(LIBSPATH)/
	cp $(INCPATH)/arparse.h $(LIBSINCPATH)/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
