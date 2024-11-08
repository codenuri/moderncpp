// add.h
#pragma once
#include <iostream>

void foo();

inline int add(int a, int b)
{
	std::cout << "add\n";
	return a + b;
}

// inline variable : multiple definition 을 허용해 달라.
//					 전역변수를 헤더에 넣을수 있다.
//					 C++17
inline int x = 100;


