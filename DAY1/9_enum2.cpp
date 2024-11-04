
// C/C++98 enum
//enum COLOR { red = 0, green = 1, blue = 2 };

// C++11 의 새로운 enum
enum class COLOR { red = 0, green = 1, blue = 2 };

int main()
{
	int n1 = red;			// error. COLOR 표기해야 한다.
	int n2 = COLOR::red;	// error. int 타입이 아니다.

	COLOR n3 = COLOR::red; // ok
}

// 색상을 인자로 받을때
void foo(int color) {} // C++98 
						// COLOR::red 뿐아니라 100도 받을수있습니다.

void foo(COLOR color) {} // C++11   COLOR만 전달 가능. 안전!!


