#include "stdafx.h"
#include "Demo.h"
#include <iostream>
#include <string>
using namespace std;

Demo::Demo()
{
	x = 0;
}
Demo::Demo(int xc)
{
	x = xc;
	
}

Demo::~Demo() {}

string Demo::getX(bool military)
{
	if (military && x > 12 )
	{
        std::string s = std::to_string(static_cast<long long>(x));
        return s;
	}
	else if( x > 12)
	{
        std::string s = std::to_string(static_cast<long long>(x-12)) + " AM";
        return s;
	}
	else
	{
        std::string s = std::to_string(static_cast<long long>(x));
        return s;
	}
}

void Demo::setX(int xc)
{
	x = xc;
}
