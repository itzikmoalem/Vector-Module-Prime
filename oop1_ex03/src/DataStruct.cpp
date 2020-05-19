#include "DataStruct.h"
#include <algorithm>

using std::min;
using std::max;

DataStruct::DataStruct(int size, Zp init)
{
	m_size = (size > 0 ? size : 0);

	m_array = new Zp[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = init.get();
	}
}

DataStruct::DataStruct(const Zp arr[], int size)
{
	m_size = (size > 0 ? size : 0);

	m_array = new Zp[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = arr[i].get();
	}
}

DataStruct::DataStruct(const DataStruct& other)		//copy constarctur
{
	m_size = other.size();
	m_array = new Zp[m_size];

	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other[i];
	}
}

DataStruct& DataStruct::operator=(const DataStruct& right)
{
	if (this != &right)
	{
		delete[] m_array;
		m_size = right.size();
		m_array = new Zp[m_size];
		
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = right.m_array[i];
		}
	}
	return *this;
}

Zp DataStruct::operator[](int index) const
{
	if (index < 0 || index >= m_size)
		return m_array[index];
	return m_array[0];
}

Zp& DataStruct::operator[](int index)
{
	if (index < 0 || index >= m_size)
		return m_array[index];
	return m_array[0];
}

int DataStruct::size() const
{
	return m_size;
}

DataStruct::~DataStruct()
{
	delete[] m_array;
}

DataStruct operator+(const DataStruct& a, const DataStruct& b)
{
	int new_size = a.size() + b.size();
	int i;

	DataStruct temp(new_size, 0);
	for (i = 0; i < a.size(); i++)
	{
		temp[i] = a[i];
	}
	for (int j = 0; j < b.size(); j++, i++)
	{
		temp[i] = b[j];
	}

	return DataStruct(temp);
}

DataStruct operator+=(DataStruct& a, const DataStruct& b)
{
	a = a + b;
	return DataStruct(a);
}

bool operator==(const DataStruct& a, const DataStruct& b)
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
bool operator!=(const DataStruct& a, const DataStruct& b)
{
	if (!(a == b))
		return true;
	return false;
}