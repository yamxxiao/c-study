#pragma once
#include<iostream>
using namespace std;

//ģ���Ϊ����ģ��ͷ�����ģ��
//������ģ������ͺ궨���������ǿ��Ը��ĵ�,ֻ���������͡�c++20��֧��double
//array����ģ�� ���Լ��Խ������
template<size_t n=10>
class Stack
{
private:
	int _a[n];
	int _top;
};
//����ģ���ػ�--����ƥ��
template<class T>
bool Less(T left, T right)
{
	return left < right;
}