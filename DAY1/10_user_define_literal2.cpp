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
				
}


