int main()
{
	// generic lambda - C++14
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap(n, d); // 에러가 없는게 좋을까요 ? 에러가 있는게 좋을까요 ?
}
