// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization
// => �����ڰ� ��� {}�� �ʱ�ȭ ������ �͵��� "aggregate" Ÿ���̶��
//    �մϴ�.
// => �迭, C ��� ����ü���� �ֽ��ϴ�.

// POD : Plain Old Data, C�� ���� Ÿ���̶�� �ǹ�.
//
struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {}		// ����ڰ� ����Ʈ ������ ����
					// ���� Point �� POD �ƴ�. = {} �ʱ�ȭ �ȵ�
					// aggregate type �ƴ�.
		
//	Point() = default;	// �� �����ڰ� ������
						// C++17 : aggregate Ÿ��
						// C++20 : aggregate Ÿ�� �ƴ�.

//	void foo() {} // ��� �Լ��� �־ "aggregate"
	
	virtual void goo() {} // �����Լ�.
						  // aggregate �ƴ�
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };

	// �ٽ�. �Ʒ� �ڵ带 2������ �����ϼ���
	Point p3 = { 1, 2 }; // 1. C����� �������� ����ü �ʱ�ȭ ���
						 // 2. ���ڰ� 2���Ǵ� std::initializer_list
						//     ������ ȣ���ϴ� �ڵ�
}