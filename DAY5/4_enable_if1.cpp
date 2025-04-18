// 6_enable_if1.cpp

// �Ʒ� �ڵ尡 ���� C++ ǥ�ؿ� �ֽ��ϴ�. (ǥ�ص� �Ʒ��� ���� �����մϴ�.)
template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
	// �ٽ� : �� �ȿ��� type �� �����ϴ�.
};

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2  void Ÿ�Ժ����ȵǹǷ� error
	enable_if<false, int>::type n3; // error. "::type" �� ����.

//	enable_if<false>::type n4; // 
//  enable_if<false, void>::type n4; // �� �ڵ�� ���ڵ�
}