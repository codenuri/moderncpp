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
	return f(std::forward<T>(arg)...);
}

int main()
{
	Point pt;
	chronometry(&Point::set, &pt, 1, 2); // pt.set(1,2) 의 성능을
										 // 측정해 달라.
}