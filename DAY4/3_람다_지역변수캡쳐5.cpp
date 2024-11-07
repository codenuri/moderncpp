// 149
int main()
{
	int v1 = 0, v2 = 0;

	auto f1 = [v1, &v2](int a) { ... }; // v1은 값, v2 참조 캡쳐
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... }; // main 의 모든 지역변수를 "값 캡쳐"
	auto f4 = [&](int a) { ... }; //					    "참조"

	auto f5 = [=, &v2](int a) { ... }; // v2만 참조, 나머지는 값
	auto f6 = [&,  v2](int a) { ... }; // v2만 값,   나머지는 참조
	auto f7 = [&, &v2](int a) { ... }; // error

	// 멤버데이타 이름 변경
	// => int x = v1 
	// => int& y = v2   로 멤버데이타 만들어서 사용
	auto f8 = [x = v1, &y = v2](int a) { x, y };

	auto f9 = [x = std::move(v1)](int a) {  x };
				// class xxx{}; xxx( std::move(v1)); 
	// 여기서 v1 는 자원 없음. 
}




