#include <iostream>

// CRTP 를 사용해서 가상함수가 아닌 코드를 가상함수 처럼 동작하게 하는 기술

template<typename T>
class Window
{
public:
	void msg_loop()		// void msg_loop(Window* this)	
	{
//		click();		//	this->click()

		static_cast<T*>(this)->click();
	}
	void click() { std::cout << "window click\n"; }
};

class MainWindow : public Window<MainWindow>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.msg_loop();
}