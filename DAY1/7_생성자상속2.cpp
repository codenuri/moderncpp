#include <list>
#include <iostream>

// STL 에서 부터 파생된 클래스를 만들어 봅시다.
// 1. 멤버 데이타를 추가하면
// => 생성자를 만들어서 데이타를 초기화 하는 것이 원칙 입니다.

// 2. 멤버 데이타를 추가하지 않고, 멤버 함수만 추가한다면

class MyList : public std::list<int>
{
public:
	void print()
	{
		for (auto& e : *this)
			std::cout << e << ", ";
		std::cout << std::endl;
	}

	// MyList 를 std::list 와 동일하게 사용하게 하려면
	// C++98 : std::list의 모든 생성자를 MyList 도 만들어야 합니다.
//	MyList(int size, int value) : std::list<int>(size, value) {}
//	MyList(int size)			: std::list<int>(size) {}

	// C++11 : 생성자 상속 문법 사용하면 됩니다.
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




