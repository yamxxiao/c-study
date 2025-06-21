#pragma once
#include<iostream>

using namespace std;

class Palyer {
private:
	int _Attack;
	int _magic_power;
	int _Health_power;
	int _Defense_power;

public:
	 Player(int Attack = 1, int _magic_power=1, int _Health_power=1, int _Defense_power=1):_Attack(_Attack), _Health_power(_Health_power), _Defense_power(_Defense_power) {};
};