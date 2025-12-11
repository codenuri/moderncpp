#include <iostream>

class Sample
{
public:
	void foo() &  { std::cout << "foo &\n";}
	void foo() && { std::cout << "foo &&\n"; }
};

int main()
{
	Sample s;
	s.foo();
	
	Sample{}.foo();
}