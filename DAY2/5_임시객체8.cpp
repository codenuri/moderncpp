#include <iostream>

class Vector
{
	int* ptr;
public:
	Vector(int sz)
	{
		ptr = new int[sz];
	}
	~Vector() { delete[] ptr;}
	
	int at(int idx) { return ptr[idx]; }
};

int main()
{
	Vector v(5); // 5개 크기 vector 

	v.at(3) = 0;  
}