#include <iostream>

class Window
{
public:
	void msg_loop()
	{
		click();
	}
	void click() { std::cout << "window click\n"; }
};

class MainWindow : public Window
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.msg_loop();
}