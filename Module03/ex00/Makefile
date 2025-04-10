NAME = claptrap
CC = c++
RM = rm -f
INCLUDES = -I./includes
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJ_DIR = obj/

SRC_1 = srcs/main.cpp \
		srcs/ClapTrap.cpp

OBJ_1 = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC_1))

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

.cpp.o:
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

${NAME}: ${OBJ_1}
	@echo "Compiling $(NAME)..."
	@${CC} ${FLAGS} ${OBJ_1} -o ${NAME}
	@echo "$(NAME) compiled successfully."

all: ${NAME}

clean:
	@echo "Cleaning object files..."
	@${RM} ${OBJ_1}
	@rm -rf ${OBJ_DIR}
	@echo "Object files cleaned."

fclean: clean
	@echo "Cleaning executable..."
	@${RM} ${NAME}
	@rm -rf ${OBJ_DIR}
	@echo "Executable cleaned."

re: clean all

.PHONY: all clean fclean re
