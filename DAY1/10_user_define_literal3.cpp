// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // 이안에 모든 표준 리터럴 있습니다.
							   // 35 page 예제에 적어 두세요

void foo(const char* s) { std::cout << "char*\n"; }
void foo(std::string s) { std::cout << "string\n"; }

int main()
{
	foo("hello");  // const char* 
	foo("hello"s); // string, 원리는 
				   // std::string operator""s("hello")가 표준에있음
				
	// C++ 표준의 시간 관련 타입
	std::chrono::seconds s1(30);
	auto s2 = 30s; // 위와 동일

	auto s3 = 1h + 3min + 2s;
	std::cout << s3.count() << std::endl; // 3600+180+2

	// C++17 부터 vector 사용시 타입생략 가능합니다.
	// => 초기값으로 추론
	std::vector v1 = { "AB", "CD" };
	std::vector v2 = { "AB"s, "CD"s };

	// 현재 스레드를 재우려면 sleep_for 라는 표준함수 사용
	std::this_thread::sleep_for(30); // error.
									 // 인자로 시간관련 타입필요

	std::chrono::nanoseconds ns(30);
	std::this_thread::sleep_for(ns); // ok

	std::this_thread::sleep_for(30ns); // ok. 외와 동일
	std::this_thread::sleep_for(30us);
}


