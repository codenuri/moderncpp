#include <list>
#include <iostream>

// C++ 표준 std::list 에 멤버 함수 한개만 추가하고 싶다.
// => 상속 사용

class MyList : public std::list<int>
{
public:
	void print()
	{
		for (auto e : *this)
		{
			std::cout << e << ", ";
		}
		std::cout << '\n';
	}
	// list 의 모든 생성자도 물려 받겠다.
	// => MyList 객체 생성시 std::list 와 동일한 방법으로 사용가능.
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); 
	MyList st2(10);
}




