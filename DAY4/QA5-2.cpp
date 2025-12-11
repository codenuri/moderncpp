#include <functional>

// 2-1 에서 Point 복사
// 5-1. 에서 chronometry 복사
class Point
{
	int x, y;
public:
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
};

template<typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
	// 일반 함수 포인터 : f(인자)
	// 멤버 함수 포인터 : (객체.*f)(인자)
	// std::invoke 를 사용하면
	//std::invoke(일반함수주소, 인자);
	//std::invoke(멤버함수주소, 객체, 인자);

	//return f(std::forward<T>(arg)...);
	return std::invoke(std::forward<F>(f), std::forward<T>(arg)...);
}

int main()
{
	Point pt;
	chronometry(&Point::set, &pt, 1, 2); // pt.set(1,2) 의 성능을
										 // 측정해 달라.
}