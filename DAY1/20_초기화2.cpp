#include <complex>

int main()
{
	// C++98 : 변수에 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11부터는 한가지 방법({}) 로 모두 초기화 가능합니다.
	// => "일관된 초기화(uniform initialization)"이라는 문법
	// => 중괄호 초기화(brace init) 이라고도 합니다.
	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };

	// = 이 없어도 됩니다.
	int n3{ 10 };
	int x3[2]{ 1,2 };
	std::complex<double> c3{ 1, 2 };

	// copy   initialization(복사초기화) : = 을 사용한 초기화
	// direct initialization(직접초기화) : = 이 없는 초기화
}












