// 8_nullptr - 29page

int main()
{
	// C++98 : 포인터 초기화시 0 사용. 나쁜 코드
	int  n1 = 0;
	int* p1 = 0; // bad

	// C++11 : 포인터 초기화를 위한 nullptr 키워드 제공. 
	int* p2 = nullptr; // good

	// 0 이 안좋은 이유.
	// => 0의 타입은 int 입니다.
	// => 아래 p3, p4, p5 를 생각해 보세요

	int k = 0;

	int* p3 = 0;
	int* p4 = k;
	int* p5 = 10;
}