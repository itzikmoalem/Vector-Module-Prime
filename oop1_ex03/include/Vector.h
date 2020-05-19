#pragma once

#include "Zp.h"
#include "DataStruct.h"

class Vector
{

public:
	explicit Vector(int size = 0, Zp init = {});
	Vector(const Zp arr[], int size);
	int size() const;
	Zp operator[](int index) const;
	Zp & operator[](int index);

private:
	DataStruct m_vector;
};

Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(const Vector& a, const Vector& b);
Vector operator/(const Vector& a, const Vector& b);
Vector operator+=(Vector& a, const Vector& b);
Vector operator-=(Vector& a, const Vector& b);
Vector operator*=(Vector& a, const Vector& b);
Vector operator/=(Vector& a, const Vector& b);
Vector operator - (const Vector& num1);
Vector operator* (const Zp& skalar, const Vector& vec);
Vector operator* (const Vector& vec, const Zp& skalar);
std::ostream& operator<<(std::ostream& os, const Vector& vec);	// <<
bool operator== (const Vector& a, const Vector& b);
bool operator!= (const Vector& a, const Vector& b);

