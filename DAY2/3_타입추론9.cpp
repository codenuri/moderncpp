// decltype ��Ģ 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };


	// () �ȿ� �̸��� �����Ƿ� ��Ģ #1 ����
	decltype(p)		d1;		//int* d1
	

	// ��Ģ #2. () �ȿ� �̸��� �����ڵ��� �ڵ尡 ���� ������
	//			(id-expression �� �ƴҶ�)
	// ǥ������ ��ȣ�� ���ʿ� �ü� �ִٸ�(lvalue) : ���� Ÿ��
	// ǥ������ ��ȣ�� ���ʿ� �ü� ���ٸ�(rvalue) : �� Ÿ��

	decltype(*p)	d2; // "*p = 10" �����ϴ�. int& d2  �ε� �ʱⰪ������ ����
	decltype(x[0])	d3; // "x[0] = 10" ok..   int& d3

	decltype(n) d;	// "n = 10" �� ������, id-expression �̹Ƿ�
					// ��Ģ #1 ���� �ؼ�  ������ ���� ����
					// int d
					
	decltype(n + n) d4;  // "n + n = 10" �ȵȴ�. ���� rvalue
						 // int d4;
							
	decltype(++n)   d5; // "++n = 10" �� �ȴ�.!!!
						// int& d5  
						// �ʱⰪ ���� ������ ����
						
						
	decltype(n++)   d6; // "n++ = 10" �� �ȵȴ�.
						// int d6
			
}

// ��Ģ #1 : () �ȿ� id ��������
// => id �� ����� ������ Ÿ��

// ��Ģ #2 : () �ȿ� id �� �ִ� ��찡 �ƴҶ�
// => �ش� ǥ������ ��ȣ�� ���ʿ� �ü��ִ°� ���°��� ����
// lvalue ��� reference type
// rvalue ��� value type
