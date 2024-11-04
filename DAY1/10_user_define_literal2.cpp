#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
using namespace std::chrono; 

using namespace std::literals; // C++ 표준에서 만든 다양한 접미사!

void foo(const char* s) { std::cout << "char*"; }   // 1
void foo(std::string s) { std::cout << "string"; }  // 2

int main()
{
	foo("hello"); // char*
//	foo(std::string("hello")); // std::string
	foo("hello"s); // std::string operator""s("hello")
	//------------------------------------------
	
	// 현재 스레드를 3초간 재우고 싶다.
//	std::this_thread::sleep_for(3); // error.
									// 정수가 아닌 "분", "초"등의 객체전달

	std::chrono::seconds sec(3);
	std::this_thread::sleep_for(sec); // ok

	std::this_thread::sleep_for(3s);
	std::this_thread::sleep_for(3ms);
	std::this_thread::sleep_for(3min);

	std::this_thread::sleep_for(3min + 20s + 30ms);

	std::vector<int> v1 = { 1,2,3 };

	// 컨테이너 사용시 C++17 이후는 초기값있으면 타입 생략가능합니다.

	std::vector v2 = { 1,2,3 };

	std::vector v3 = { "apple", "banane", "orange" };
				// std::vector<const char*>

	std::vector v4 = { "apple"s, "banane"s, "orange"s };
				// std::vector<std::string>

	// 정수형 타입은 많지만 정수형 리터럴은 한가지 형태입니다.
	// 타입 : int, short, long long
	// 리터럴 : 10
	// => 결국 접미사로 타입을 알려줘야 합니다.
	// => 10s, 10ll
}


