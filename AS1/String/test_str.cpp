// test_string.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"


using namespace std;
#include "Demo.h"
#include <iostream>


int main()
{
	Demo d;
	for (int i = 0; i<= 24; i++)
	{
		d.setX(i);
		cout << "x = " << d.getX() << endl;
	}
	return 0;
}
