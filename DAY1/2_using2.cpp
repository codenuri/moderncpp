#include <unordered_set>

// C typedef : 
typedef std::unordered_set<int>    SETI;
typedef std::unordered_set<double> SETD;

// 아래 처럼 할수 없을까 ? 할수 없다!!!
typedef std::unordered_set    SET;     // 이렇게하거나
typedef std::unordered_set<T> SET<T>;  // 이렇게!!

// typedef     : 타입에 대한 별명만 가능하다.
// C++11 using : 타입 별명 + 템플릿 별명  모두 가능.
template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

	SETI s1;
	SETD s2;

	SET<int> s3;
	SET<double> s4;
}
