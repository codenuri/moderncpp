// 9_enum - 32 page

// C/C++98 스타일 enum
enum COLOR { red = 1, green, blue};

void set_color(int c) {}

int main()
{
	// 단점 #1. 타입성 약화, int 로의 암시적 형변환 허용
	COLOR c1 = COLOR::red;
	int c2 = COLOR::red;  // ok. 하지만 이코드를 허용하면 버그가 발생할수 있습니다.
							// 아래 "A" 부분
	c1 = 100; // error
	c2 = 100; // ok	"A"

	// 단점 #2. COLOR 이름 없이 사용가능. unscoped enum
	int c3 = COLOR::red; // ok 정확한 표기법
	int c4 = red;        // ok. COLOR 생략가능.

	int red = 100;
	int n = red; // ok 하지만 enum 값이 아닌 지역변수 red!! 혼란스러운 코드.. 
}





