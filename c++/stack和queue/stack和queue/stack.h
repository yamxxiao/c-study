#pragma once
#include<cassert>
#include<iostream>
#include <vector>
#include<stack>
using namespace std;
// ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
class Test
{
	bool INfor(vector<int>& push, vector<int>& pop)
	{
		stack<int> st;
		size_t popi = 0;

		for (auto e : push)
		{
			// ѹ��ջ
			st.push(e);

			while (!st.empty() && popi < pop.size() && st.top() == pop[popi])
			{
				// ����ջ
				st.pop();
				++popi;
			}

		}
		return st.empty();
	}
};

