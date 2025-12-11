// 149
int main()
{
	int v1 = 0, v2 = 0;

	auto f1 = [v1, &v2](int a) { ... };	// v1 은 값, v2 는 참조로 캡쳐
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... }; // main 의 모든 지역변수를 값으로 캡쳐(실제사용되는 것만 캡쳐됨)
	auto f4 = [&](int a) { ... }; // main 의 모든 지역변수를 참조로 캡쳐

	auto f5 = [=, &v2](int a) { ... }; // v2 만 참조, 나머지 모든 것은 값
	auto f6 = [&, v2](int a) { ... };  // v2 만 값, 나머지는 참조로
	auto f7 = [&, &v2](int a) { ... }; // error. 디폴트 모드와 다른 것만 표기가능

	auto f8 = [x = v1, &y = v2](int a) { x, y }; // v1은 값으로, 그런데, 멤버이름을 x로
												 // int x = v1
												// int& y = v2 
					
}




