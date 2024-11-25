#include "ScalarConverter.hpp"
#include <iostream>
#include <string> 
#include <variant>


void printChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)) == false)
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void printConvertFloat(std::string& rep)
{
	try {
		std::stringstream ss;
		float nb;
		ss << rep;
		ss >> nb;
		if(ss.fail())
			throw std::exception();
		printChar(static_cast<char>(nb));
		std::cout << "int: " << static_cast<int> (nb) << std::endl;
		std::cout << "float: " << static_cast<float> (nb) << "f" << std::endl;
		std::cout << "double: " << static_cast<double> (nb)<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printConvertDouble(std::string& rep)
{
	try {
		std::stringstream ss;
		double nb;
		ss << rep;
		ss >> nb;
		if(ss.fail())
			throw std::exception();
		printChar(static_cast<char>(nb));
		std::cout << "int: " << static_cast<int> (nb) << std::endl;
		std::cout << "float: " << static_cast<float> (nb) << "f" << std::endl;
		std::cout << "double: " << static_cast<double> (nb)<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printConvertInt(std::string& rep)
{
	try {
		std::stringstream ss;
		int nb;
		ss << rep;
		ss >> nb;
		if(ss.fail())
			throw std::exception();
		printChar(static_cast<char>(nb));
		std::cout << "int: " << static_cast<int> (nb) << std::endl;
		std::cout << "float: " << static_cast<float> (nb) << "f" << std::endl;
		std::cout << "double: " << static_cast<double> (nb)<< std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
bool isSpecial(std::string& rep)
{
	return (rep == "nan" || rep == "nanf" || 
		rep == "-inff" || rep == "inff" || rep == "+inff"
			|| rep == "-inf" || rep == "inf" || rep == "+inf");
}




void SpecialPrint(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff") {
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	return ;
}




void ScalarConverter::convert(std::string &rep)
{

	if (isSpecial(rep))
		SpecialPrint(rep);
	else if(rep.find('.') != std::string::npos)
		printConvertDouble(rep);
	else if(rep.find('f') != std::string::npos)
		printConvertFloat(rep);
	else
		printConvertInt(rep);


} 
