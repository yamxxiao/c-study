#pragma once
#include<iostream>

using namespace std;

template<class T>
T Add(const T& left, const T& right)
{
	cout << "T Add(const T& left, const T& right)" << endl;
	return left + right;
}

void func(const int& left, const int& right)
{
	cout << "void func(const int& left, const int& right)" << endl;
}

	
