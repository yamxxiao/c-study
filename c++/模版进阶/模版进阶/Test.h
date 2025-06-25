#pragma once
#include<iostream>
using namespace std;

//模版分为类型模版和非类型模版
//非类型模版参数和宏定义有区别，是可以更改的,只能用于整型。c++20下支持double
//array数组模版 可以检查越界问题
template<size_t n=10>
class Stack
{
private:
	int _a[n];
	int _top;
};
//函数模版特化--参数匹配
template<class T>
bool Less(T left, T right)
{
	return left < right;
}