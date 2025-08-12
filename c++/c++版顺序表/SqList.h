#pragma once
#include<iostream>

using namespace std;

typedef size_t SLDataType;
class SeList
{
public:
	SLDataType* _arr;
	SLDataType _size;
	SLDataType _capacity;

	SeList():_arr(nullptr),_size(0),_capacity(0){}
};
