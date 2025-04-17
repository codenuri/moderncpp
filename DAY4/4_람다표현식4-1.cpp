#include <vector>
#include <functional> // std::less, std::greater

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� �ڵ��� ���� ã������
	// => ��� ���� ǥ������ �ٸ� Ÿ���̹Ƿ�
	// => 3���� std::sort ����
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// ���� : ������ ���� ǥ������ ������ ����Ҷ��� auto �� ��Ƽ� 
	//        ����ϴ� ���� �����ϴ�.
	auto cmp = [](int a, int b) { return a < b; };

	// �Ʒ� �ڵ�� �Ѱ��� sort() ����
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// �׷���!! < �񱳰� �ʿ� �ߴٸ� ���� ǥ������ ������� ����
	// �̹� ǥ�ؿ� �ִ� less �� ����ϸ� ���� ?
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});

}