#include "Serializer.hpp"

// Constructor
Serializer::Serializer() {
}

Serializer::Serializer( Serializer const &src ) {
	*this = src;
}

// Destructor
Serializer::~Serializer() {
}

// Operator overloads
Serializer	&Serializer::operator=( Serializer const &rhs ) {
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}

// Member functions
uintptr_t Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>( ptr );
}

Data* Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>( raw );
}