#include <iostream>
#include <chrono>

class StopWatch
{
public:
	StopWatch() : start(std::chrono::system_clock::now()) {}

	~StopWatch()
	{
		end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed = end - start;
		std::chrono::nanoseconds nano = end - start;

		std::cout << elapsed.count() << " seconds..." << std::endl;
	}
private:
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
};

int& foo(int a, double d, int& n) 
{ 
	for (int i = 0; i < 20; i++)
	{
		std::cout << "foo : " << i << std::endl;
	}
	n = 100; 
	return n; 
}
