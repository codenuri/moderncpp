#include <unordered_set>

// std::unordered_set<int> 의 별명을 만들어 봅시다.
// #1. typedef
typedef std::unordered_set<int> USET_I;
typedef std::unordered_set<double> USET_D;

// "std::unordered_set<int>" 라는 타입의 별명이 아닌 
// "std::unordered_set" 라는 template 의 별명을 만들수 없을까 ?
// 아래 처럼 ??
//typedef std::unordered_set USET; // error.
								 // typedef 는 type의 별명만 만들수있다

// typedef : 타입의 별명 만 가능
// using   : 타입의 별명 + template 의 별명
template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

	USET_I s1;
	USET_D s2;

	SET<int> s3;
	SET<double> s4;
}
