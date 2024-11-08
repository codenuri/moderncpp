#include <vector>

class Object
{	
	int data = 0;
public:
	// 함수가 & 를 반환하면 "함수 호출을 우변에 놓을수 있습니다."
	// => 동일이름의 "비상수", "상수" 멤버 함수를 동시에 만들수 있습니다.
	
	// 상수객체 : 상수 함수만 호출 가능
	// 
	// 비상수객체 : 1. 비상수 함수 호출.
	//             2. 없다면 상수멤버 함수 호출

	int& get()             { return data; } 
	const int& get() const { return data; }
};

int main()
{
	Object obj;

	int n1 = obj.get();
	obj.get() = 0;
	

	const Object cobj;

	int n2 = cobj.get();
//	cobj.get() = 0;   // 상수객체이므로 안되야 합니다.

	//------------------
	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	auto p1 = v1.begin();
	auto p2 = v2.begin();

	*p1 = 10; // 되야 합니다.
	*p2 = 10; // 안되야 합니다.
}