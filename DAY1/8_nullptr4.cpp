#include <memory>

class Sample
{
public:
	Sample(int* p) {}
};

int main()
{
	std::shared_ptr<Sample> p1(new Sample(0)); // ok

//	std::shared_ptr p2 = std::make_shared<Sample>(0); // error
						// new Sample(0) 의 의미를 객체를 생성하고
						// 해당 객체를 관리하는 스마트 포인터를 반환해 달라
						// 즉 의미상으로 위와 동일
						// 하지만, 0을 직접 보내지 않고
						// 한번 거쳐서 전달하므로 error

	std::shared_ptr p2 = std::make_shared<Sample>(nullptr); // ??
}