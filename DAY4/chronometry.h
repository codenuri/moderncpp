// stopwatch.h

#pragma once

#include <iostream>
#include <chrono>	// C++표준 시간 라이브러리

class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);

	// 아래 처럼 하면 f 가 일반 함수 일때만 동작합니다
	// 멤버 함수라면 에러!!
	//return f(std::forward<T>(arg)...);

	// 아래 처럼 하면 일반 함수 뿐 아니라 멤버 함수, 람다 표현식, 함수객체 모두 사용
	return std::invoke(f, std::forward<T>(arg)...);
}