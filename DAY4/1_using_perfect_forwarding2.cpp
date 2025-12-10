#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

template<typename T>
class Vector
{
	T* buffer;
public:

	// 아래 2개의 push_back 은 인자로 Point 객체
	void push_back(const T& pt) //  T 는 Point
	{
		// pt 의 복사본을 자신의 버퍼에 생성
		buffer = new T{ pt }; // 복사 생성자
	}
	void push_back(T&& pt)
	{
		buffer = new T{ std::move(pt) }; // 이동 생성자
	}

	// emplace_back 은 결국 전달 받은 인자를 모두 생성자에 보내야 합니다.
	// => 완벽한 전달 기술밖에 없습니다.
	// => 이 기술이 없으면 만들수 없습니다.
	// => 그래서, emplace_back() 은 C++11 에서 등장
	template<typename ... A>
	void emplace_back(A&& ... arg)
	{
		// 전달 받은 인자를 T의 생성자로 다시 forwarding
		buffer = new T{ std::forward<A>(arg)... };
	}
	
};

int main()
{
	Vector<Point> v;

	Point pt{ 1,1 };
//	v.push_back(pt);
//	v.push_back(std::move(pt));

	v.emplace_back(1, 1);
			// 1, 1 을 emplace_back 이 받게 되지만
			// 결국 2개의 인자는 다시 Point 생성자에 전달
			// new Point(1,1)
			// 1, 1 ====> emplace_back() ====> Point(int a, int b)
}