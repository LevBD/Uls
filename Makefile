NAME = uls

INC = uls.h

SRC = main.c \
    mx_dirwalk.c \
    mx_get_permissions.c \
    mx_init_m_struct.c \
    mx_print_long.c

OBJ = main.o \
    mx_dirwalk.o \
    mx_get_permissions.o \
    mx_init_m_struct.o \
    mx_print_long.o


CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
