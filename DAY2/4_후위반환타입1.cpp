// 1_후위반환타입1.cpp - 교재 73 page

// 전통적인 함수 모양
int square1(int a)
{
	return a * a;
}

// C++11 부터 나오는 후위 반환 타입(suffix return type)
auto square2(int a) -> int
{
	return a * a;
}

int main()
{
	square1(3);
}