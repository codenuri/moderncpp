// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0;

	// C++11 부터는 포인터 초기화시 0대신 nullptr 사용하세요
//	int  n2 = nullptr; // errror. 포인터만 가능
	int* p2 = nullptr; // ok 좋은 코드
}
