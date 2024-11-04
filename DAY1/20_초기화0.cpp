// C++98 초기화의 문제점 - 54 page
#include <complex>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);

	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = new int[3];
	p[0] = 0; // 대입.. 초기화 아님

	// 3. STL 컨테이너를 배열 처럼 초기화 안됨.
	std::vector<int> v1(10, 0); // ok. 10개를 0으로
	std::vector<int> v2 = { 1,2,3 }; // C++98 시절은 error
									 // C++11 부터 가능
}
class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int x[3];
};



