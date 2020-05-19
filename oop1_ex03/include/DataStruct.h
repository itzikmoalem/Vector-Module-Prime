#pragma once

#include "Zp.h"

class DataStruct
{
public:
	explicit DataStruct(int size = 0, Zp init = {});
	DataStruct(const Zp arr[], int size);
	DataStruct(const DataStruct& other);		//copy constractor

	DataStruct& operator= (const DataStruct& right);	// = operator
	
	Zp operator[](int index) const;
	Zp &operator[](int index) ;

	int size() const;
	~DataStruct();

private:
	Zp *m_array;
	int m_size = 0;

};

DataStruct operator+ (const DataStruct& a, const DataStruct& b);
DataStruct operator+= (DataStruct& a, const DataStruct& b);
bool operator== (const DataStruct& a, const DataStruct& b);
bool operator!= (const DataStruct& a, const DataStruct& b);



