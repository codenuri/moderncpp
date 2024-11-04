#include <memory>

class Sample
{
public:
	Sample(int* p) {}
};

int main()
{
	std::shared_ptr<Sample> p1(new Sample(0)); // ok

	std::shared_ptr p2 = std::make_shared<Sample>(0); // ??
}