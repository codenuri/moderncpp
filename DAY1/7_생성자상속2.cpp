#include <list>
#include <iostream>

// 기존 클래스에서 상속을 받을때
// => 멤버 데이타를 추가하면 
//    "추가된 멤버 데이타를 초기화" 해야 하므로 생성자를 만드는 것이 원칙

class MyList : public std::list<int>
{
public:
	void print() const
	{
		for (auto e : *this)
			std::cout << ", ";
		std::cout << '\n';
	}
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




