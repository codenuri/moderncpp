int main()
{
	auto swap1 = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap1(n, d); // �Ǵ� �� ������� ? ���� ���°� �������?
				// ������ ���°� �����ϴ�.
				// �׷���, ���� �ƴմϴ�.
				// generic lambda �� 1, 2 ���ڰ� �ٸ� ���ø��� �ǹǷ�

	// �� ������ �ذ��ϰ�
	// ��� ���ø� ����� ���� ǥ���Ŀ��� ��밡���ϰ� �ϱ� ����
	// C++20 ���� template ���� ǥ���� ���Ե˴ϴ�.
	auto swap2 = []<typename T>(T& a, T& b) { T tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };

	swap2(n, d); // error;
}