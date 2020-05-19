#include "Vector.h"
#include <algorithm>
#include <ostream>

using std::min;
using std::max;

Vector::Vector(int size, Zp init)
{
	m_vector = DataStruct(size, init);
}

Vector::Vector(const Zp arr[], int size)
{
	m_vector = DataStruct(arr, size);
}

int Vector::size() const
{
	return m_vector.size();
}

Zp Vector::operator[](int index) const
{
	return m_vector[index];
}

Zp& Vector::operator[](int index)
{
	return m_vector[index];
}

Vector operator+(const Vector& a, const Vector& b)
{
	int minSize = min(a.size(), b.size());
	int maxSize = max(a.size(), b.size());

	Vector c(maxSize, 0);

	int i;
	for (i = 0; i < minSize; i++)
	{
		c[i] = a[i] + b[i];
	}
	for (i; i < maxSize; i++)
	{
		c[i] = 0;
	}
	return c;
}

Vector operator-(const Vector& a, const Vector& b)
{
	int minSize = min(a.size(), b.size());
	int maxSize = max(a.size(), b.size());
	Vector c(maxSize, 0);

	int i;
	for (i = 0; i < minSize; i++)
	{
		c[i] = a[i] - b[i];
	}
	for (i; i < maxSize; i++)
	{
		c[i] = 0;
	}
	return c;
}

Vector operator*(const Vector& a, const Vector& b)
{
	int minSize = min(a.size(), b.size());
	int maxSize = max(a.size(), b.size());

	Vector c(maxSize, 0);

	int i;
	for (i = 0; i < minSize; i++)
	{
		c[i] = a[i] * b[i];
	}
	for (i; i < maxSize; i++)
	{
		c[i] = 0;
	}
	return c;
}


Vector operator/(const Vector& a, const Vector& b)
{
	int minSize = min(a.size(), b.size());
	int maxSize = max(a.size(), b.size());
	Vector c(maxSize, 0);

	int i;
	for (i = 0; i < minSize; i++)
	{
		c[i] = a[i] / b[i];
	}
	if (minSize != maxSize)
	{
		bool bigger = false;
		if (minSize == a.size())
			bigger = true;

		for (int j = 0; j < maxSize; j++)
		{
			if (bigger)
				c[i] = b[j];
			else
				c[i] = a[i];
		}
	}
	return c;
}
Vector operator+=(Vector& a, const Vector& b)
{
	Vector c = a + b;
	return Vector(c);
}

Vector operator-=(Vector& a, const Vector& b)
{
	Vector c = a - b;
	return Vector(c);
}

Vector operator*=(Vector& a, const Vector& b)
{
	Vector c = a * b;
	return c;
}

Vector operator/=(Vector& a, const Vector& b)
{
	Vector c = a / b;
	return Vector(c);
}
bool operator== (const Vector& a, const Vector& b)
{
	if (a.size() != b.size())
		return false;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
bool operator!= (const Vector& a, const Vector& b)
{
	return (!(a == b));
}
Vector operator - (const Vector& num1)
{
	Vector c;
	for (int i = 0; i < c.size(); i++)
		c[i] = -num1[i];							// Unary -
	return c;
}

Vector operator*(const Zp& skalar, const Vector& vec)
{
	Vector new1 = vec;
	for (int i = 0; i < vec.size(); i++)
	{
		new1[i] *= skalar;
	}
	return Vector(new1);
}

Vector operator*(const Vector& vec, const Zp& skalar)
{
	Vector new1 = vec;
	for (int i = 0; i < vec.size(); i++)
	{
		new1[i] *= skalar;
	}
	return Vector(new1);
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)	// <<
{
	for (int i = 0; i < vec.size(); i++)
	{
		os << vec[i] << " ";
	}
	return os;
}