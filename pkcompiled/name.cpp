#include "utils.h"
#include "name.h"

void print_name()
{
	std::cout << "Your first name? ";
	std::string name;
	std::cin >> name;
	std::cout << name;
}