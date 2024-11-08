#include <vector>

class Object
{
	int data = 0;
public:
	// 아래 2개는 반환 타입을 제외하고는 구현이 완전히 동일합니다.
	int& get() 
	{ 
		return data; 
	}
	const int& get() const 
	{ 
		return data; 
	}
};

int main()
{
	Object obj;

	int n1 = obj.get();
	obj.get() = 0;


	const Object cobj;
	int n2 = cobj.get();

}