#include <iostream>

class Functor
{
public:
	void operator()(int arg) &
	{
		std::cout << "operator &\n";
	}

	void operator()(int arg) &&
	{
		std::cout << "operator &&\n";
	}
};
int main()
{
	Functor f;

	f(1); 
	Functor{}(1);

}