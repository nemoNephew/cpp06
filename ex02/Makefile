src = typeinfo.cpp main.cpp
obj = $(src:.cpp=.o)
hdr = typeinfo.hpp
name = typeinfo
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
.SECONDERY: $(obj)
