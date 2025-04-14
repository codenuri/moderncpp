#include <unordered_set>

// #1. �Ʒ� �ڵ�� "Ÿ��"�� ���� �����Դϴ�.
typedef std::unordered_set<int>    SETI;
typedef std::unordered_set<double> SETD;

// #2. �Ʒ� ó�� �Ҽ� �������?
// => Ÿ���� �ƴ� "���ø�" �� ���� ���� 
// => typedef �δ� �Ҽ� �����ϴ�
typedef std::unordered_set SET;

// #3. typedef �� using ������
// typedef : Ÿ�Կ� ���� ���� ����
// using   : Ÿ�Կ� ���� ���� + ���ø��� ���� ���� ����


// #4. using ����
using DWORD = int;		// Ÿ���� ����

template<typename T>
using SET<T> = std::unordered_set<T>; // ���ø� ����

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;
	SETI s1;
	SETD s2;

	// SET �� ���ø��� �����̹Ƿ� ���� ���ø� ���� �����ؾ� �մϴ�.
	SET<int> s3;
	SET<double> s4;
}
