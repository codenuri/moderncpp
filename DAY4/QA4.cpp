#include <string>

class Holder
{
public:
	std::string data = "hello";

	std::string& get_data() { return data; }
};

int main()
{
	std::string s = Holder{}.data;
	std::string s = Holder{}.get_data();
}