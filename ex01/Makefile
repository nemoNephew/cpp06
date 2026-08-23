src = Serializer.cpp main.cpp
obj = $(src:.cpp=.o)
name = serialize
hdr = Serializer.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(name)
$(name): $(obj)
	$(CXX) $(CXXFLAGS) -o $(name) $(obj)
$(obj): $(hdr)
clean:
	rm -f $(obj)
fclean: clean
	rm -f $(name)
re: fclean all
.PHONY: all clean fclean re
.SECONDERY: $(obj)