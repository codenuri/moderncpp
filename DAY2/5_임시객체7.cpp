#include <iostream>

class Counter
{
public:
	int cnt{ 0 };

	void increment()
	{
		++cnt;
	}
};

int main()
{
	Counter c;
	c.increment();
	c.increment();
	c.increment();

	std::cout << c.cnt << std::endl;
}
