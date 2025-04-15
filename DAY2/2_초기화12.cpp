#include <complex>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다
	// => {} 초기화로 해결
	int n1 = { 10 };
	int x[2] = { 1,2 };
	std::complex<double> c = { 1,2 };



	// 2. 동적 할당한 배열을 초기화 할수 없다.
	// => {} 초기화로 가능
	int* p = new int[3] {1, 2, 3};

	// 3. std::vector 를 1~5로 초기화 할수 없었다
	// => {} 초기화와 std::initializer_list 로 해결
	// => C++17 부터는 초기값이 있으면 타입도 생략가능
//	std::vector<int> v = { 1,2,3,4,5 };
	std::vector v = { 1,2,3,4,5 };
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	// => {} 초기화와 필드 std::initialization 문법으로 해결
	int x[3]{ 1,2,3 };
//	int x[3] = { 1,2,3 };
};



