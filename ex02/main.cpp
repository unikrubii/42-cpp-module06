#include "Base.hpp"

int main( void ) {
	Base *base = Base::generate();

	Base::identify(base);
	Base::identify(*base);

	delete base;

	return (0);
}