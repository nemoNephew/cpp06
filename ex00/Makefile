src = ScalarConverter.cpp main.cpp
obj = $(src:.cpp=.o)
hdr = ScalarConverter.hpp
name = ScalarConverter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(name)
$(name): $(obj)
	$(CXX) $(CXXFLAGS) $(obj) -o $(name)
$(obj): $(hdr)
clean:
	rm -f $(obj)
fclean: clean
	rm -f $(name)
re: fclean all
.PHONY: all clean fclean re
.SECONDARY: $(obj)