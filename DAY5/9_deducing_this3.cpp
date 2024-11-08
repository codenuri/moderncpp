class Object
{
	
	int data = 0;
public:
	// 함수가 & 를 반환하면 "함수 호출을 우변에 놓을수 있습니다."
	int& get() { return data; }
};

int main()
{
	Object obj;

	int n1 = obj.get();
	obj.get() = 0;
	

}