CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98 #-Wpedantic
NAME = fixed
FILES = main.cpp Fixed.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(FILES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

re: clean all

fclean : clean 
	rm -f $(NAME)

.PHONY: all clean