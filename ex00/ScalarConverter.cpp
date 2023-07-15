#include "ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
}

// Destructor
ScalarConverter::~ScalarConverter() {
}

// Operator Overload
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

// Helper Functions
int checkNanInfString( const std::string &arg ) {
	if ( arg == "nan" || arg == "nanf" ) {
		return 1;
	}
	else if ( arg == "inf" || arg == "inff" ) {
		return 2;
	}
	return 0;
}

// Member Functions
void ScalarConverter::assertValue( bool condition ) {
	if ( !condition )
		throw ScalarConverter::AssertExceptions();
}

bool ScalarConverter::isChar( const std::string &arg ) {
	if (arg.length() == 1 && std::isprint( arg[0] ) )
		return true;
	return false;
}

void ScalarConverter::printChar( const std::string &arg ) {
	std::cout << "char: ";
	if ( arg == "nan" || arg == "nanf" || arg == "inf" || arg == "inff" ) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	// arg is ascii number
	try {
		int pos = arg.find('.');
		assertValue( !pos || arg[ pos + 1] == '0' );
		assertValue( std::atoi( arg.c_str() ) <= 128 );
		int a = std::atoi( arg.c_str() ) + '\0';
		char c = static_cast<char>( a );
		if ( std::isprint( c ) ) {
			std::cout << "'" << c << "'" << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}
	// when arg is number but out of range
	catch ( std::out_of_range &e ) {
		std::cout << "impossible" << std::endl;
	}
	// arg is char
	catch ( std::invalid_argument &e ) {
		if ( isChar( arg ) ) {
			std::cout << "'" << arg << "'" << std::endl;
		}
		else {
			std::cout << "impossible" << std::endl;
		}
	}
	// arg cannot be converted
	catch ( ScalarConverter::AssertExceptions &e ) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::printInt( const std::string &arg ) {
	std::cout << "int: ";
	try {
		long num = std::atol( arg.c_str() );
		assertValue( num <= std::numeric_limits<int>::max() );
		assertValue( num >= std::numeric_limits<int>::min() );
		std::cout << static_cast<int>( num ) << std::endl;
	}
	catch ( std::invalid_argument &e ) {
		std::cout << "impossible" << std::endl;
	}
	catch ( ScalarConverter::AssertExceptions &e ) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::printFloat( const std::string &arg ) {
	std::cout << "float: ";
	int nanInf = checkNanInfString( arg );
	if ( nanInf ) {
		if ( nanInf == 1 ) {
			std::cout << "nanf" << std::endl;
		}
		else {
			if ( arg[0] == '-' ) {
				std::cout << "-";
			}
			std::cout << "inff" << std::endl;
		}
		return ;
	}
	// if ( arg == "inf" || arg == "inff" ) {
	// 	if ( arg[0] == '-' ) {
	// 		std::cout << "-";
	// 	}
	// 	std::cout << "inff" << std::endl;
	// 	return ;
	// }
	// else if ( arg == "nan" || arg == "nanf" ) {
	// 	std::cout << "nanf" << std::endl;
	// 	return ;
	// }
	try {
		float num = std::atof( arg.c_str() );
		assertValue( num <= std::numeric_limits<float>::max() );
		if ( std::isnan( num ) || arg == "nan" ) {
			std::cout << "nanf" << std::endl;
		}
		else if ( std::isinf( num ) ) {
			if ( num > 0 ) {
				std::cout << "+inff" << std::endl;
			}
			else {
				std::cout << "-inff" << std::endl;
			}
		}
		else {
			std::cout << std::fixed << std::setprecision(1) << num << "f" << std::endl;
		}
	}
	catch ( std::out_of_range &e ) {
		std::cout << "impossible" << std::endl;
	}
	catch ( std::invalid_argument &e ) {
		std::cout << "impossible" << std::endl;
	}
	catch ( ScalarConverter::AssertExceptions &e ) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::printDouble( const std::string &arg ) {
	std::cout << "double: ";
	int nanInf = checkNanInfString( arg );
	if ( nanInf ) {
		if ( nanInf == 1 ) {
			std::cout << "nan" << std::endl;
		}
		else {
			if ( arg[0] == '-' ) {
				std::cout << "-";
			}
			std::cout << "inf" << std::endl;
		}
		return ;
	}
	try {
		double num = std::atof( arg.c_str() );
		assertValue( num <= std::numeric_limits<double>::max() );
		if ( std::isnan( num ) || arg == "nan" ) {
			std::cout << "nan" << std::endl;
		}
		else if ( std::isinf( num ) ) {
			if ( num > 0 ) {
				std::cout << "+inf" << std::endl;
			}
			else {
				std::cout << "-inf" << std::endl;
			}
		}
		else {
			std::cout << std::fixed << std::setprecision(1) << num << std::endl;
		}
	}
	catch ( std::out_of_range &e ) {
		std::cout << "impossible" << std::endl;
	}
	catch ( std::invalid_argument &e ) {
		std::cout << "impossible" << std::endl;
	}
	catch ( ScalarConverter::AssertExceptions &e ) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convert( const std::string &arg ) {
	printChar( arg );
	printInt( arg );
	printFloat( arg );
	printDouble( arg );
}

// Exceptions
const char *ScalarConverter::AssertExceptions::what() const throw() {
	return "conversion is impossible";
}
