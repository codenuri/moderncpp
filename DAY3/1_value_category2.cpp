// �ٽ� : rvalue, lvalue �� ������ 
//       ����(��ü)�� �ο��Ǵ� ������ �ƴ�
//       ǥ����(expression) �� �ο� �Ǵ� ����
// 
// statememtn(����)   : �����ݷ����� ������ ������ �ڵ�
//						���α׷��� ���� ����.
//						��� ���α׷��� main �Լ��� 1��° "����" ���� ���ʴ�� ����ȴ�.
// 
// expression(ǥ����) : �Ѱ��� ���� ��Ÿ���� �ڵ� ����
// result : expression �� ���� ��
// result �� 2���� �Ӽ��� �ֽ��ϴ�.
// => type
// => value category : ��ȣ�� ���ʿ� �ü� �ִ°�(lvalue, rvalue )

int main()
{
	int n = 2;

					//					 result    type   
	n * 2 + 3 - 2;	// expression "n" :		2(n)	int		lvalue
					// expression "n*2" :	4		int		rvalue
					// expression "n*2+3" : 7		int		rvalue
					// expression "n*2+3-2" : 5		int		rvalue

	n = 2;			// ok.  n �̶�� ǥ������ lvalue expressin
	n * 2 = 10;		// error. n * 2 ��� ǥ������ rvalue expression

	n = 3;
	++n = 10;		// ++n �̶�� ǥ������
					// result : "n(4)"	
					// type : int,   
					// value category : lvalue

	n = 3;
	n++; // n �� �����ϰ� �������� 3��ȯ
		 // "n++" ��������� �����Ǳ� �������� 3
		// type : int
		// value category : rvalue



}