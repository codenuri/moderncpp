// 배열의복사
int main()
{
	// 모든 변수는 자신과 동일한 타입의 변수에 복사 될수 있습니다.
	
	int n1 = 10;
	int n2 = n1; // 복사

	double d1 = 3.4;
	double d2 = d1;

	// 단, 배열은 복사 될수 없는 타입입니다.
	int x[3] = { 1,2,3 };
	int y[3] = x; // error

	// 대신 배열의 이름이 배열의 1번째 요소의 주소로 암시적 형변환 됩니다.
	int* p = x; // ok

}