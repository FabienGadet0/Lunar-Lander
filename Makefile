NAME:=	LunarLander

SCR_FILE:= srcs

SRC:=	$(SCR_FILE)/main.cpp \
		$(SCR_FILE)/game.cpp \
		$(SCR_FILE)/spaceship.cpp \
		$(SCR_FILE)/entity.cpp \
		$(SCR_FILE)/ground.cpp \
		$(SCR_FILE)/collider.cpp \
				
OBJ:=	$(SRC:.cpp=.o)

CXX:=	g++

CXXFLAGS:=	-I incs
LDLIBS:=	-lpthread -lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME)


$(NAME):	$(OBJ)
		$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $(LIB)
		@echo ============== OK ================

clean:
		@rm -rfv $(OBJ)

fclean:	clean
		@rm -rfv $(NAME)

re:		fclean all

.PHONY: all clean fclean re .PHONY