#include <vector>

class Object
{
	int data = 0;
public:
	// 아래 2개는 반환 타입을 제외하고는 구현이 완전히 동일합니다.
	// => template 으로 자동생성하면 좋지 않을까요 ?
	// => 그런데, template 사용하려면 인자의 타입(this)에 따라 코드를생성
	//    해야 합니다. 그런데, 아래 코드는 this 가 드러나지 않습니다.
	/*
	int& get()					// int& get(Point* this) 
	{ 
		return data; 
	}
	const int& get() const		// const int& get(const Point* this)
	{ 
		return data; 
	}
	*/

	// 상수 멤버 함수 개념을 "explicit object parameter"로 만들어 봅시다.
	// => 기존 C++98 은 const 가 함수 () 뒤에 있는데
	// => 아래 코드는 함수 인자로 되었습니다.
	/*
	int& get(this Point& self)					
	{
		return self.data;
	}
	const int& get(this const Point& self) 
	{
		return self.data;
	}
	*/
	// 아래 처럼 하면 2개를 자동생성할수 있습니다.
	template<typename T>
	decltype(auto) get(this T&& self)
	{
		return self.data;
	}
};

int main()
{
	Object obj;
	const Object cobj;

	int n1 = obj.get();  // get(obj) => get(Point&)		  생성
	int n2 = cobj.get(); // get(cobj)=> get(const Point&) 생성

}