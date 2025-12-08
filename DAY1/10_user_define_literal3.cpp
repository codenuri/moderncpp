// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::literals;    // C++ 표준에서 만든 다양한 리터럴 접미사를 사용하기위해

void foo(const char* s) { std::cout << "char*\n"; }	 // 1
void foo(std::string s) { std::cout << "string\n"; } // 2

int main()
{
	foo("hello");  // 1호출. "hello" 는 const char[6] 인데, const char* 로 암시적 형변환가능
	foo("hello"s); // 2호출, std::string operator""s(const char*) 호출됨.
				

	std::chrono::seconds s1(3); // 3초를 관리하는 타입
	auto s2 = 3s; // operator""s(3) 호출. 그런데, 반환 타입이 std::chrono::seconds

	auto s3 = 1h + 20min + 30s;

	std::cout << s3.count() << std::endl; // 3600 + 1200 + 30 => 4830

	// 현재 스레드 재우기(sleep)
	// => 인자는 반드시 시간 타입(second)등만 사용해야 합니다.

//	std::this_thread::sleep_for(3); // error. 인자는 int 아닙니다.

	std::chrono::seconds s(3);
	std::this_thread::sleep_for(s); // ok

	std::this_thread::sleep_for(3s); // ok
	std::this_thread::sleep_for(3ms); // ok
	std::this_thread::sleep_for(3ns); // ok
	std::this_thread::sleep_for(3us); // ok
	std::this_thread::sleep_for(3min); // ok
	std::this_thread::sleep_for(3hour); // ok

	// 참고 : 시간 타입 다루기
	std::chrono::seconds n1 = 3min + 40s; // ok. 데이타 손실없음.
//	std::chrono::minutes n2 = 3min + 40s; // error. 데이타 손실 발생

	std::chrono::minutes n2 =
		std::chrono::duration_cast<std::chrono::minutes>(3min + 40s); // ok. 버림
}


