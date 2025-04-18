// 참조반환
int x = 0;

int  f1() { return x; } // x가 아닌 x의 값 "0" 반환
int& f2() { return x; } // x의 값이 아닌 x의 별명 반환
						// 기계어 코드는 결국
						// "x의 주소 반환"
int main()
{
	f1() = 3;	// error. "0 = 3"
	f2() = 3;	// ok.    "x = 3"

	// 결론
	// 참조를 반환하는 함수는 등호에 왼쪽에 올수 있다.(lvalue)
	// 값을 반환하는 함수는 등호에 왼쪽에 올수 없다.(rvalue)
}