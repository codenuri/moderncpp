class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

int main()
{
	// ������ ������ ã������
	void(*f1)(int) = &foo;
	void(*f2)(int) = &Dialog::close1;
	void(*f3)(int) = &Dialog::close2; 
}