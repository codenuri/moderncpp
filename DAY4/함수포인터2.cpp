class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

int main()
{
	// 다음중 에러를 찾으세요
	void(*f1)(int) = &foo;
	void(*f2)(int) = &Dialog::close1;
	void(*f3)(int) = &Dialog::close2; 
}