// 7_move05-1.cpp

int main()
{
	// java, C#, python 
	// => ��ü�� ���� ����� ������(reference) �� �����ϴ� ���.
	// => move ������ ����, clone ������ �ֽ��ϴ�]
	// => �Ʒ� �ڵ带 C#, Java ��� ����
	// => C#, Java �� Cat �� ��� "Cat*" �ǹ�.

	Cat c1 = new Cat("yaong", 3);
	Cat c2 = c1;	// ���絵 �ƴϰ�, �̵��� �ƴ�, ��ü ������ ����
	Cat c3 = c1.Clone();

	// ����Ĵ�� �����ϴ� ���� 
	// => move ������ ���� �ʿ� �����ϴ�
	// ������
	// => ��ü�� ������ ���� �ذ�å�� �־�� �մϴ�
	// => ��ü�� ���� �ǹǷ� "�������"�� ���� �Ǿ�� �մϴ�.
	// => �ᱹ, �� �� å������ �մϴ�.(C++�� ����ڰ� �ؾ� �ؼ� �����մϴ�)
	// => ��Ƽ ������ ȯ�濡�� ����ȭ�� �ʿ� �մϴ�.
	// ----------------------------------------------

	// C++ : ��� ���� �Ҽ� �ִ� �����ο� ��� �Դϴ�

	// Java, C# ��Ÿ�Ϸ� �Ϸ���
	Cat* c1 = new Cat("yaong", 2);
	Cat* c2 = c1;
	// => delete å���� �ʿ� �մϴ�

	// C++ : �� ��� ���, stack �� ������ ���� ������ ���� ����
	// => �Ʒ� �ڵ�� stack �� ���� ����ϴ� �ڵ�
	std::string s1 = "hello";
	std::string s2 = s1; 

	
	// �Ϲ������� move �� ������, copy �� �����ϴ�.
	// C++ : �������� move ������. 
	std::string s2 = s1;			// copy.   ���� ����� ����Ʈ
	std::string s3 = std::move(s1);	// move.   ���� ����� ����

	// RUST : ��κ��� ������ C++�� �ݴ�
	s2: String = s1;		// move �� ����, �����ٿ��� s1 �� �ڿ��� ����.
	s3: String = s1.Clone();// copy �� ����, �����߿��� s2 �� �ڿ� ����. 
}