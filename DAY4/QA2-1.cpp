class Point
{
	int x, y;
public:
	void set(int a, int b) 
	{
		x = a;				
		y = b;				
	}
};
int main()
{
	void(*f)(int, int) = &Point::set; 
}