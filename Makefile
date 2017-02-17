OBJ 	=   	$(SRC:.cpp=.o)

OBJDIR	=	obj/

SRC	=	src/components/AComponent.cpp 		\
		src/components/APin.cpp			\
		src/components/C2716.cpp		\
		src/components/C4001.cpp		\
		src/components/C4008.cpp		\
		src/components/C4011.cpp		\
		src/components/C4013.cpp		\
		src/components/C4017.cpp		\
		src/components/C4030.cpp		\
		src/components/C4040.cpp		\
		src/components/C4069.cpp		\
		src/components/C4071.cpp		\
		src/components/C4081.cpp		\
		src/components/C4094.cpp		\
		src/components/C4503.cpp		\
		src/components/C4512.cpp		\
		src/components/C4514.cpp		\
		src/components/CClock.cpp		\
		src/components/CFalse.cpp		\
		src/components/Ci4004.cpp		\
		src/components/CInput.cpp		\
		src/components/Cmk4801.cpp		\
		src/components/ComponentCreator.cpp	\
		src/components/COutput.cpp		\
		src/components/CTrue.cpp		\
		src/components/InputPin.cpp		\
		src/components/OutputPin.cpp		\
		src/components/SimpleInputPin.cpp	\
		src/components/SimpleOutputPin.cpp	\
		src/parser/Lexer.cpp			\
		src/parser/Parser.cpp			\
		src/utils/FileHandler.cpp		\
		src/utils/Logger.cpp			\
		src/utils/SignalHandler.cpp		\
		src/main.cpp				\

NAME =      	nanotekspice

INC =       	-Iinclude

LFLAGS =  	-W -w -Wall -Wextra

OBJTARGET=	$(addprefix $(OBJDIR), $(OBJ))

all:    	$(NAME)

$(OBJ): %.o : %.cpp
	mkdir -p $(OBJDIR)/$(@D)
	g++ $(LFLAGS) $(INC) -c $< -o $(OBJDIR)/$@

$(NAME):    	$(OBJ)
		g++ $(OBJTARGET) -o $(NAME) $(INC)

.PHONY: clean
clean:
		rm -rf $(OBJTARGET)
		@rm -rf obj/
.PHONY: fclean
fclean:     	clean
		rm -rf $(NAME)

re:		fclean all
