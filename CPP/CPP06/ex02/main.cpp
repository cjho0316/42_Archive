#include "Base.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	Base* random = generate();
	identify(random);
	identify(*random);
	delete random;
	return 0;
}