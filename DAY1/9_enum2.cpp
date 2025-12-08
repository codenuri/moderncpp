
// C/C++98 스타일 enum
// enum COLOR { red = 1, green, blue };

// C++11 의 enum class 문법. scoped enum 이라도고 합니다.
enum class COLOR { red = 1, green, blue };

int main()
{
	COLOR c1 = COLOR::red;	// ok
	int   c2 = COLOR::red;  // error. int 타입으로 형변환 안됨
	COLOR c3 = red;			// error. COLOR 이 반드시 필요

	// C기법중 enum 값 끼리 - 하는 기법도 있습니다.
	// => 명시적 cast 하면 int 로 변경가능합니다.
	int n1 = static_cast<int>(c1); // ok.. 1
	int n2 = static_cast<int>(COLOR::blue); // ok..3
}





