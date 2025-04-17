class Point
{
	int x, y;
public:
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;		
		y = b;				//		this->y = b;
	}						// }

	// C++23 에서 등장하는 엄청난 변화!!!
	// => 컴파일러가 this 를 추가하는 것이 아니라 
	// => 개발자가 직접 받들수 있습니다.
	// => 아래 코드는 위와 완전히 동일합니다.
	// => visual studio 도 현재 지원
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}

};
int main()
{
	Point p1;

	p1.set(10, 20);
	p1.set2(10, 20);

}