#include <iostream>

class Functor
{
public:
	void operator()(int arg)&  { std::cout << "operator &\n"; }
	void operator()(int arg)&& { std::cout << "operator &&\n"; }
};

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);

	return f(std::forward<T>(arg)...);
}
int main()
{
	Functor f;

	f(1);
	Functor{}(1);

}