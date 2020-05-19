#include "Vector.h"
#include "Zp.h"
#include "DataStruct.h"
#include <iostream>

bool checkPrime();

int main()
{
	if (!checkPrime())
	{
		std::cout << "p isn't a Prime Number!" << std::endl;
		return EXIT_FAILURE;
	}
}

bool checkPrime()
{
	for (int i = 2; i <= p / 2; ++i)
	{
		if (p % i == 0)
		{
			return false;
		}
	}
	return true;
}