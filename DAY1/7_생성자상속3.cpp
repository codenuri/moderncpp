#include <list>
#include <iostream>

// STL 에서 부터 파생된 클래스를 만들어 봅시다.
// 1. 멤버 데이타를 추가하면
// => 생성자를 만들어서 데이타를 초기화 하는 것이 원칙 입니다.

// 2. 멤버 데이타를 추가하지 않고, 멤버 함수만 추가한다면

template<typename T, typename Alloc = std::allocator<T> >
class MyList : public std::list<T, Alloc>
{
public:
	using std::list<T, Alloc>::list;

	void print()
	{
		for (auto& e : *this)  // *this 는 결국 자기 자신인데
								// std::list 에서 파생되므로
								// 이렇게 사용가능.
			std::cout << e << ", ";
		std::cout << std::endl;
	}
};

int main()
{
	MyList<int> st1(10, 3); // 10개를 3으로 초기화
	MyList<double> st2(10);

	st1.print();
}




