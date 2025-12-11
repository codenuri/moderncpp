#include <iostream>

class Sample
{
public:
	void foo() &  { std::cout << "foo &\n";}
	void foo() && { std::cout << "foo &&\n"; }

	void operator()()&  { std::cout << "&\n"; }
	void operator()()&& { std::cout << "&&\n"; }
};

int main()
{
	Sample s;
	s.foo();	// foo() &	
	Sample{}.foo();	// foo() &&

	s();
	Sample{}();
}