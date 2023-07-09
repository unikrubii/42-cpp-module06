#include "ScalarConverter.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "Usage: ./convert [argument]" << std::endl;
		return 1;
	}

	std::string arg(argv[1]);
	ScalarConverter::convert( arg );
	return 0;
}