#include "ScalarConverter.hpp"
#include <iostream>
int main (int ac, char **av)
{
	if (ac > 1)
	{
		ScalarConverter i;
		std::string s = av[1];
		//std::cout << s << std::endl;
		i.convert(s);	
	}
}