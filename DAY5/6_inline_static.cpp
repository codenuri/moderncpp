// C++17 inline static 

// Object.h
class Object
{
public:
	static int data;

	// inline static : static 멤버변수의 외부선언이 필요 없다.
	//					C++17
	inline static int data2 = 0;
};

// Object.cpp 
int Object::data = 0;	// static 변수의 외부선언은
						// 반드시 소스 쪽에 있어야 합니다.
						// 결국 "전역변수와 같은 성격" 입니다.
						// 헤더에 넣으면 여러곳에서 include 시에
						// 전역변수가 여러개 있는 것과 동일

int main()
{

}