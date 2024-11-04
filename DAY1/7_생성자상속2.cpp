#include <list>
#include <iostream>

// 기존 클래스에서 상속을 받을때
// => 멤버 데이타를 추가하면 
//    "추가된 멤버 데이타를 초기화" 해야 하므로 생성자를 만드는 것이 원칙
// => 멤버 데이타 없이 단지, 멤버 함수만 추가한다면
//    생성자를 만들 필요는 없습니다.
// => 그런데, MyList 를 list<int> 와 동일하게 사용하려면
//    list<int> 의 생성자를 상속해야 합니다.

class MyList : public std::list<int>
{
public:
	// C++98 이라면
//	MyList(int sz, int value) : std::list<int>(sz, value) {}
//	MyList(int sz)            : std::list<int>(sz) {}

	// C++11 이라면
	// 생성자 상속으로 하면 편리합니다.
//	using std::list<int>::list;


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




