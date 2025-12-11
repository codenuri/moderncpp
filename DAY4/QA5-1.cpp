#include <iostream>

class Sample
{
public:
	void operator()()& { std::cout << "&\n"; }
	void operator()()&& { std::cout << "&&\n"; }
};

template<typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
	return std::forward<F>(f)(std::forward<T>(arg)...);
}
int main()
{
	Sample s;
	chronometry(s);			// operator() & 성능 측정
	chronometry(Sample{});	// operator() && 성능 측정
}



