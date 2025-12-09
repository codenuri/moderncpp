// 후위 반환 타입 -  73 page

// C/C++의 일반적인 함수 모양
int square(int a)
{
	return a * a;
}

// C++11 에서 추가된 새로운 함수 모양
// => suffix return type 이라는 문법	
// => 파이썬, Rust, Swift 등의 언어가 사용하는 방식
auto square2(int a) -> int 
{
	return a * a;
}

int main()
{
	square(3);
}
