#pragma once

#include <iosfwd>

const int p = 5;

class Zp
{
public:
	Zp(int value = 0);	//constarctor
	int get() const;
	Zp inverse() const;		//take inverse of the num

private:
	int m_number;
};

std::ostream& operator << (std::ostream& num1,  const Zp &num2);	//cout 

Zp operator + (const Zp& num1, const Zp& num2);
Zp operator - (const Zp& num1, const Zp& num2);
Zp operator * (const Zp& num1, const Zp& num2);
Zp operator / (const Zp& num1, const Zp& num2);
Zp operator += (Zp& num1, const Zp& num2);
Zp operator -= (Zp& num1, const Zp& num2);
Zp operator *= (Zp& num1, const Zp& num2);
Zp operator /= (Zp& num1, const Zp& num2);
Zp operator - (const Zp& num1);
bool operator == (const Zp& num1, const Zp& num2);
bool operator != (const Zp& num1, const Zp& num2);

