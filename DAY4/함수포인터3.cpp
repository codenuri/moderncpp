#include "chronometry.h"


class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

int main()
{
	Dialog dlg;

	chronometry(&foo, 10); // foo(10)의 성능 측정
	chronometry(&Dialog::close2, 10); 
	chronometry(&Dialog::close1, &dlg, 10); 
}