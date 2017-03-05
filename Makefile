OBJDIR	=	obj

SRC	=	src/components/C2716.cpp	    	        \
		src/components/C4001.cpp	    	        \
		src/components/C4008.cpp	    	        \
		src/components/C4011.cpp	    	        \
		src/components/C4013.cpp	    	        \
		src/components/C4017.cpp	    	        \
		src/components/C4030.cpp	    	        \
		src/components/C4040.cpp		            \
		src/components/C4069.cpp		            \
		src/components/C4071.cpp		            \
		src/components/C4081.cpp		            \
		src/components/C4094.cpp		            \
		src/components/C4503.cpp		            \
		src/components/C4512.cpp		            \
		src/components/C4514.cpp		            \
		src/components/CClock.cpp		            \
		src/components/CFalse.cpp		            \
		src/components/Ci4004.cpp		            \
		src/components/CInput.cpp		            \
		src/components/Cmk4801.cpp		            \
		src/components/ComponentCreator.cpp	        \
		src/components/Gates.cpp                    \
		src/components/COutput.cpp		            \
		src/components/CTrue.cpp		            \
		src/components/AComponent.cpp 	            \
		src/components/pins/CarryOutPin.cpp         \
		src/components/pins/InputPin.cpp	        \
		src/components/pins/OutputPin.cpp	        \
		src/components/pins/SimpleInputPin.cpp	    \
		src/components/pins/SimpleOutputPin.cpp	    \
		src/components/pins/CarryInPin.cpp          \
		src/components/pins/VoidPin.cpp             \
    	src/components/pins/APin.cpp		        \
    	src/components/pins/BasicPin.cpp            \
    	src/components/pins/BasicOutputPin.cpp      \
    	src/components/pins/ClockedPin.cpp          \
    	src/components/pins/OneEntryOutputPin.cpp   \
    	src/parser/Lexer.cpp			            \
		src/parser/Parser.cpp			            \
		src/parser/StandardInput.cpp                \
		src/parser/Commands.cpp                     \
		src/utils/FileHandler.cpp		            \
		src/utils/Logger.cpp			            \
		src/utils/SignalHandler.cpp		            \
		src/exceptions/UndefinedLinkage.cpp         \
		src/exceptions/NonPinComponent.cpp          \
		src/exceptions/NonImplemented.cpp           \
		src/main.cpp				                \

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
		rm -rf $(NAME) $(LIBNAME)

re:		fclean all
