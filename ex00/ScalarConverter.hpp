#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>

class ScalarConverter
{
	public:
		// Constructor
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);

		// Destructor
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &rhs);

		// Member Functions
		// assert function
		static void assertValue( bool condition );

		// is functions
		static bool	isChar( const std::string &arg );

		// print functions
		static void	printChar( const std::string &arg );
		static void	printInt( const std::string &arg );
		static void	printFloat( const std::string &arg );
		static void	printDouble( const std::string &arg );

		// convert function
		static void	convert( const std::string &arg );

		// Exceptions
		class AssertExceptions : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif