#include "Serializer.hpp"

int main( void ) {
	Data	data;
	data.n = 42;
	data.c = 'a';
	data.b = true;
	data.s = "Hello, world!";

	uintptr_t	serialized = Serializer::serialize( &data );
	Data		*deserialized = Serializer::deserialize( serialized );

	std::cout << "data->n: " << data.n << std::endl;
	std::cout << "data->c: " << data.c << std::endl;
	std::cout << "data->b: " << data.b << std::endl;
	std::cout << "data->s: " << data.s << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout << "serialized: " << serialized << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::cout << "deserialized->n: " << deserialized->n << std::endl;
	std::cout << "deserialized->c: " << deserialized->c << std::endl;
	std::cout << "deserialized->b: " << deserialized->b << std::endl;
	std::cout << "deserialized->s: " << deserialized->s << std::endl;

	return 0;
}