#pragma once
#include<cassert>
#include<iostream>
#include <vector>
#include<stack>
using namespace std;
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
class Test
{
	bool INfor(vector<int>& push, vector<int>& pop)
	{
		stack<int> st;
		size_t popi = 0;

		for (auto e : push)
		{
			// 压入栈
			st.push(e);

			while (!st.empty() && popi < pop.size() && st.top() == pop[popi])
			{
				// 弹出栈
				st.pop();
				++popi;
			}

		}
		return st.empty();
	}
};

