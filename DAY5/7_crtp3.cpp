#include <iostream>

// class template 만들때 T를 사용하지 멤버가 있다면
// => 템플릿이 아닌 기반 클래스를 만들어서 제공해라
// => "thin template" 또는 "template hoisting" 이라는 기술

class Window
{
	int handle;
	int color;
public:
	void move() {}
	void show() {}

	void click() { std::cout << "window click\n"; }
	void keydown() {}
};

template<typename T>
class MsgWindow : public Window
{
public:
	void msg_loop()			
	{
		static_cast<T*>(this)->click();
	}
};

class MainWindow : public MsgWindow<MainWindow>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.msg_loop();
}