#include <iostream>
#include <vector>
#include <string>
// type traits : 템플릿 부분 특수화 기술로 만들것
//				 => 문법이라기 보다는 "테크닉"에 가까운 라이브러리

// concept : 특정 타입이 가져야 하는 개념을 "정의" 하는 기술
//			=> 개념의 정의 라는 의미로 "concept"
//			=> 조사가 주목적이 아니라 "개념의 정립"이다.
//			   is_xxx 로 시작하지 말라고 권장

// 컨테이너 인지 조사하는게 아니라
// 컨테이너가 뭔지에 대한 정의!!
template<typename T>
concept container = requires(T& t)
{
//	t.begin();
//	t.end();
	std::begin(t);
	std::end(t);
};

int main()
{
	bool b1 = container<int>;
	bool b2 = container<std::string>;
	bool b3 = container<int[3]>;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
}



