int main()
{
	int n = 0;

	int x[3] = { 1,2,3 };

	
	// 포인터와 참조 변수 만들기

	int* p1 = &n;	// 포인터 변수 ( 주소로 초기화)
	int& r1 = n;	// 참조   변수 ( 이름으로 초기화)

	
	int(*p2)[3] = &x;	// 배열을 가리키는 포인터
	int(&r2)[3] = x;	// 배열을 가리키는 refernece
}