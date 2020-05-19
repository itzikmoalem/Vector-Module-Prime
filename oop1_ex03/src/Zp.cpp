#include "Zp.h"
#include <ostream>

Zp::Zp(int value)
{

	if (value < 0)
	{
		value += p;
	}
	m_number = value % p;

}


int Zp::get() const
{
	return m_number;
}

Zp Zp::inverse() const
{
	for (int i = 1; i < p; i++)
	{
		if ((m_number * i) % p == 1)
			return Zp(i);
	}
	return Zp(p);
}

Zp operator+=(Zp& num1, const Zp& num2)		// +=
{
	num1 = num1 + num2;
	return num1;
}

Zp operator-=(Zp& num1, const Zp& num2)		// -=
{
	num1 = num1 - num2;
	return num1;
}

Zp operator*=(Zp& num1, const Zp& num2)		// *=
{
	num1 = num1 * num2;
	return num1;
}

Zp operator/=(Zp& num1, const Zp& num2)		// /=
{
	num1 = num1 / num2.inverse();
	return num1;
}

Zp operator-(const Zp& num1)
{
	return Zp(-num1.get());							// Unary -
}

bool operator==(const Zp& num1, const Zp& num2)
{
	return (Zp(num1.get()) == num2.get());
}

bool operator!=(const Zp& num1, const Zp& num2)
{
	return !(Zp(num1.get()) != num2.get());
}

std::ostream& operator<<(std::ostream& num1, const Zp &num2)	// <<
{
	num1 << num2.get();
	return num1;
}

Zp operator+(const Zp& num1, const Zp& num2)		// +
{
	return Zp(num1.get() + num2.get());
}

Zp operator-(const Zp& num1, const Zp& num2)		// -
{
	return Zp(num1.get() - num2.get());
}

Zp operator*(const Zp& num1, const Zp& num2)		// *
{
	return Zp(num1.get() * num2.get());
}

Zp operator/(const Zp& num1, const Zp& num2)		// /
{
	return Zp(num1.get() * num2.inverse().get());
}

