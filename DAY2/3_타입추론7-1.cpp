template<typename T> void f1(T a, T b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// ������ ������ ?
	f1("apple", "orange");	// ok
	f2("apple", "orange");	// error

	// Ÿ���� ��Ȯ�� �˾ƾ� �մϴ�.
	// "apple"  : const char[6] 
	// "orange" : const char[7] 
	// => ũ�Ⱑ �ٸ� �迭�� "�ٸ�Ÿ��" �Դϴ�.

	// f2 : ���ڷ� reference �� ����ϹǷ� �迭�� ������ 
	//	    �迭�� ���� �ް� �˴ϴ�.
	//      f2(T&, T&) �̹Ƿ� ���� Ÿ���� �����ؾ� �ϴµ�, 
	//	    "apple", "orange" �� �ٸ� Ÿ���̹Ƿ� ����

	// f1 : ���ڷ� ��Ÿ���� ����ϹǷ�
	//	    �迭�� ������ �����ͷ� �ް� �˴ϴ�.(decay �����̶�� �մϴ�.)
	// "apple"  : const char[6] ������ const char* �� ��ȯ ����
	// "orange" : const char[7] ������ const char* �� ��ȯ ����

	// �ᱹ ���� Ÿ���Դϴ�. ���� �ƴ�. 
}

// �ٽ� 
template<typename T> void f3(T) {}
template<typename T> void f4(T&) {}

f3(�迭); // T = ������ �Դϴ�.
f4(�迭); // T = �迭 �Դϴ�.




