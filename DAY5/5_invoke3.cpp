#include <iostream>

class Object
{
public:
	void foo(int a, double d) {}
};

void goo(int a, double d) {}

// 가변인자템플릿8에서 chronometry 복사

int main()
{
	chronometry(goo, 1, 3.4);
}