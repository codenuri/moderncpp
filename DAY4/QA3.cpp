#include <iostream>

class Functor
{
public:
	void operator()(int arg)&  { std::cout << "operator &\n"; }
	void operator()(int arg)&& { std::cout << "operator &&\n"; }
};

template<typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
//	return std::forward<F>(f) (std::forward<T>(arg)...);

	return std::invoke(std::forward<F>(f), std::forward<T>(arg)...);
}
int main()
{
	Functor f;

	// chronometry 로 아래 2개 성능 측정
	chronometry(f, 1);			// f(1);
	chronometry(Functor{}, 1);  // Functor{}(1);

}