// 5_����ǥ����6
// ����ǥ������ ���ڸ� �޴� ��� - 143p �Ʒ� �κ�

// #1. �Լ� ������
// => ĸ���� ���ٴ� ������ ����.!!
void foo( int(*f)(int, int) )
{
}

// #2. std::function
// => ��� ���� ǥ���� ����. 
void foo( std::function<int(int, int)> f )
{
	f(1, 2); // ��, �̰�� �ζ��� ġȯ�� �ȵ�
			 // foo ��ü�� ���ø� �ƴϹǷ� �Ѱ��� ����
}

// #3. template
template<typename T>
void foo(T f)
{
	f(1, 2); // �ζ��� ġȯ ����
			 // ���ø��̹Ƿ� ������ foo ������. 
}

// #4. T&
template<typename T>
void foo(T& f) {} // error. ���� ǥ������ rvalue!


int main()
{
	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) { return a - b; });
}


