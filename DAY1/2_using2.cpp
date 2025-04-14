#include <unordered_set>

// #1. 아래 코드는 "타입"에 대한 별명입니다.
typedef std::unordered_set<int>    SETI;
typedef std::unordered_set<double> SETD;

// #2. 아래 처럼 할수 없을까요?
// => 타입이 아닌 "템플릿" 에 대한 별명 
// => typedef 로는 할수 없습니다
typedef std::unordered_set SET;

// #3. typedef 와 using 차이점
// typedef : 타입에 대한 별명만 가능
// using   : 타입에 대한 별명 + 템플릿에 대한 별명도 가능


// #4. using 사용법
using DWORD = int;		// 타입의 별명

template<typename T>
using SET<T> = std::unordered_set<T>; // 템플릿 별명

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;
	SETI s1;
	SETD s2;

	// SET 은 템플릿의 별명이므로 사용시 템플릿 인자 전달해야 합니다.
	SET<int> s3;
	SET<double> s4;
}
