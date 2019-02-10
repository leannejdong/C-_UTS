#ifndef DEMO_H
#define DEMO_H
#include <string>
class Demo
{
public:
	Demo();
	Demo(int xc);
	~Demo();
	std::string getX(bool military = false);
	void setX(int cx);
private:
	int x;
};
#endif
