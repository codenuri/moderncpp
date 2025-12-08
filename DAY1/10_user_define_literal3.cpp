// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

void foo(const char* s) { std::cout << "char*\n"; }	 // 1
void foo(std::string s) { std::cout << "string\n"; } // 2

int main()
{
	foo("hello");  // 1호출. "hello" 는 const char[6] 인데, const char* 로 암시적 형변환가능
	foo("hello"s); // 2호출, std::string operator""s(const char*) 호출됨.
				
}


