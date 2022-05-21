# gtklock-example-module
# Copyright (c) 2022 Jovan Lanik

# Makefile

NAME := example-module.so

LIBS := gtk+-3.0 gmodule-export-2.0
CFLAGS += -std=c11 $(shell pkg-config --cflags $(LIBS))
LDLIBS += $(shell pkg-config --libs $(LIBS))

SRC = $(wildcard *.c) 
OBJ = $(SRC:%.c=%.o)

TRASH = $(OBJ) $(NAME)

.PHONY: all clean

all: $(NAME)

clean:
	@rm $(TRASH) | true

$(NAME): $(OBJ)
	$(LINK.c) -shared $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
