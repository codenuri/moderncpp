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

int& goo(int& a) { a = 100; return a; }


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw;	// 생성자에서 시간 기록
					// 함수 종료될때 소멸자 호출됨 - 여기서 소요시간 출력
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;

	int& ret = chronometry(foo, 1, 3.4, n);
	

	std::cout << n << std::endl;
}
