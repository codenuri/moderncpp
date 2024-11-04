// 51page.. if constexpr (static if)
// 아래 코드가 왜 에러인지 생각해 보세요 ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;
	}
};
int main()
{
	A a;
}
