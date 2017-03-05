OBJDIR	=	obj

SRC	=	src/components/AComponent.cpp 		\
		src/components/APin.cpp		    	\
		src/components/C2716.cpp	    	\
		src/components/C4001.cpp	    	\
		src/components/C4008.cpp	    	\
		src/components/C4011.cpp	    	\
		src/components/C4013.cpp	    	\
		src/components/C4017.cpp	    	\
		src/components/C4030.cpp	    	\
		src/components/C4040.cpp		    \
		src/components/C4069.cpp		    \
		src/components/C4071.cpp		    \
		src/components/C4081.cpp		    \
		src/components/C4094.cpp		    \
		src/components/C4503.cpp		    \
		src/components/C4512.cpp		    \
		src/components/C4514.cpp		    \
		src/components/CClock.cpp		    \
		src/components/CFalse.cpp		    \
		src/components/Ci4004.cpp		    \
		src/components/CInput.cpp		    \
		src/components/Cmk4801.cpp		    \
		src/components/CarryOutPin.cpp      \
		src/components/ComponentCreator.cpp	\
		src/components/Gates.cpp            \
		src/components/COutput.cpp		    \
		src/components/CTrue.cpp		    \
		src/components/InputPin.cpp		    \
		src/components/OutputPin.cpp		\
		src/components/SimpleInputPin.cpp	\
		src/components/SimpleOutputPin.cpp	\
		src/components/VoidPin.cpp          \
		src/parser/Lexer.cpp			    \
		src/parser/Parser.cpp			    \
		src/parser/StandardInput.cpp        \
		src/parser/Commands.cpp             \
		src/utils/FileHandler.cpp		    \
		src/utils/Logger.cpp			    \
		src/utils/SignalHandler.cpp		    \
		src/exceptions/UndefinedLinkage.cpp \
		src/main.cpp				        \

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	nanotekspice

LIBNAME =       libnanotekspice.a

INC     =       -Iinclude

LFLAGS  =	-W -Wall -Wextra -fPIC

all:    	$(NAME) $(LIBNAME)

$(OBJ): %.o : %.cpp
	g++ $(LFLAGS) $(INC) -c $< -o $@

$(LIBNAME): $(OBJ)
			g++ $(OBJ) -shared -o $(LIBNAME) $(INC)

$(NAME):    $(OBJ)
			g++ $(OBJ) -o $(NAME) $(INC)
.PHONY: clean

clean:
		rm -rf $(OBJ)
.PHONY: fclean                                                                                                                       2

fclean:     	clean
		rm -rf $(NAME)

re:		fclean all
