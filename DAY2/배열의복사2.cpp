#include <iostream>

void f1(int n2) {}


void f2(int y1[3])
{
	// 이 코드가 에러가 아닌데,, 주의해야 할점은 
	// y1 은 배열 아닙니다.
	// 포인터 입니다.
	printf("%zd\n", sizeof(y1)); // 배열이면 12
								// 포인터면 4 또는 8
}
int main()
{
	// 결국 변수의 복사는 "함수 인자 전달" 의 개념입니다.

	int n1 = 10;
	f1(n1);  // int n2 = n1;


	int x1[3] = { 1,2,3 };

	f2(x1); // int y[3] = x1;

}