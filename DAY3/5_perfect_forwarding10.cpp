#include <iostream>
#include "stopwatch.h" // 이 헤더 만드세요
						// git 에 소스 있습니다. 복사해 넣으세요

int sum(int first, int last)
{
	int s = 0;

	while (first != last)
	{
		s = s + first;
		++first;
	}
	return s;
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);	
		// => 생성자에서 시간 기록
		// => 소멸자에서 수행시간 출력
		// => "true" 의미는 소멸자에서 출력해 달라는 것.

	return f(std::forward<T>(arg)...);
}

int main()
{
	int ret = chronometry(sum, 1, 1000000); // 0 6개

	std::cout << "결과 : " << ret << std::endl;
}
