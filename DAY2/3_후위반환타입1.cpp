// 1_후위반환타입1.cpp - 교재 73 page

// 전통적인 함수 모양 : 반환 타입이 함수 이름 앞에. 
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 부터 나오는 새로운 모양
// => 리턴 타입을 함수 () 뒤에 표기
// => suffix return type(trailing return type, 후위 반환타입)
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}
