#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct data {
	int			n;
	char		c;
	bool		b;
	std::string	s;
}	Data;

class Serializer
{
	public:
		// Constructor
		Serializer();
		Serializer( Serializer const &other );

		// Destructor
		~Serializer();

		// Operator overloads
		Serializer	&operator=( Serializer const &other );

		// Member functions
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
};

#endif