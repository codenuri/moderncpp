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

	decltype(*p)	d2; 
	decltype(x[0])	d3; 

	decltype(n) d; 
					

	decltype(n + n) d4; 
	decltype(++n)   d5; 
						
						
	decltype(n++)   d6; 
			
}

