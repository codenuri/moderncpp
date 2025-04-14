// C/C++98 enum - unscoped enum 이라고 합니다.
// enum COLOR { red = 1, green, blue };

// C++11 의 새로운 enum - scoped enum 이라고 합니다.
// => COLOR 를 생략할수 없기 때문에 붙은 이름
enum class COLOR { red = 1, green, blue };

int main()
{
	COLOR c1 = COLOR::red; // ok 

//	COLOR c2 = red; // error. COLOR 생략 안됨

//	int c3 = COLOR::red; // error. COLOR 타입만 가능

	// enum 값들의 - 같은 연산을 하는 경우도 있습니다.
	// static_cast 사용하세요

	int n1 = static_cast<int>(COLOR::red); // ok 
}





