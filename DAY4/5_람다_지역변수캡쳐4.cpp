// 149
int main()
{
	int v1 = 0, v2 = 0;

	// ĸ���� �پ��� ���

	auto f1 = [v1, &v2](int a) {  };  // v1�� �� ĸ��, v2�� ���� ĸ��
	auto f2 = [&v1, v2](int a) {  };

	auto f3 = [=](int a) {  };	// main �� ��� ���������� �� ĸ��
	auto f4 = [&](int a) {  };  // main �� ��� ���������� ���� ĸ��

	auto f5 = [=, &v2](int a) {  }; // ��� ���������� ��, ��, v2�� ����
	auto f6 = [&, v2](int a)  {  };
	auto f7 = [&, &v2](int a) {  }; // error. mode�� �ٸ� ��츸 ǥ��

	
	// int x = v1; ó�� v1�� �̸��� x�� �����ؼ� ���(�� ĸ��)
	// int& y = v2 ó�� �ؼ� y �̸����� ���
	auto f8 = [x = v1, &y = v2](int a) { x, y };
}




