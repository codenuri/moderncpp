// C++98 시절 초기화의 문제점 - 54 page
#include <complex>
#include <vector>

int main()
{
	// #1. 변수에 종류에 따라 초기화 방법이 다르다. 
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);


	// #2. 동적할당한 배열을 초기화 할수 없다
	int* p = new int[3];


	// #3. STL 컨테이너를 배열 처럼 초기화 할수 없었다.
	std::vector<int> v1(5, 3);		// C++98 스타일, 5개를 3으로		
	std::vector<int> v2 = { 1,2,3,4,5 }; //  C++11 부터 가능. C++98 안됨
}

class Test
{
	// #4. 멤버 데이타로 사용되는 배열을 초기화 하는 방법이 없었다
	int x[3];
};



