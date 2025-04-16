struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}

// ��� #1. call by value
// Ư¡ : ���纻 �����ȴ�.
void foo(Point pt) {}

// ��� #2. call by const lvalue reference
// Ư¡ 1 : ���纻�� ����.
// Ư¡ 2 : const �Ӽ��� �߰��ȴ�. ������ �״�� ���� ���� �ƴϴ�.
void foo(const Point& pt) {}

// C++98 ����� �� 2���� ����
// C++11 ���� �Ʒ� ����� ����

// ��� #3. 2���� foo �Լ� ����
// Ư¡ : ���纻�� ����, ������� �߰����� �ʴ´�.
// ���� : 2���� �Լ��� �ϴ����� �����ϴٸ� �ߺ��� �ڵ�
void foo(Point&  pt) {}
void foo(Point&& pt) {}

// ��� #4. forwarding reference(T&&) �� ����ϸ�
// => "���#3" �� 2�� �Լ��� �ڵ������Ѵ�.
// => Point Ÿ�Ի� �ƴ϶� ��� Ÿ�Կ� ���ؼ��� �ڵ� ����
template<typename T> void foo(T&& a)
{
}

foo(pt);			// => void foo(Point&  pt) ����
foo(Point{1,2});	// => void foo(Point&&  pt) ����

// T&& �� �ǹ�
// => lvalue, rvalue �� ��� ���纻 ���� ���ڷ� ������ �ִ� ���ø��� 
//    �ʿ� �߽��ϴ�.
// => �׷��� T&& ���� �߷� ��Ģ�� �����ؼ� �����
// foo(n) ���� int n ������, T = int �� �ƴ� T = int& �� �߷��ϱ�� ���