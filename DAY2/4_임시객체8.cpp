#include <string>
#include <iostream>

struct String : public std::string
{
	using std::string::basic_string;

	~String()
	{
		std::cout << "~String() [\"" << data() << " \"]\n";
	}
};

const String& f1(const String& s) { return s; }

int main()
{
	const String& s = String("abc");
	//	const String& s = f1(String("abc"));
	//	const String& s = f2();

	std::cout << "-----------------\n";
}

const String& f2()
{
	String s = "abc";
	return s;
}
