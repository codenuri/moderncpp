#include <iostream>

template<typename T>
class Vector
{
	T* ptr;
public:
	Vector(int sz)
	{
		ptr = new T[sz];
	}
	~Vector() { delete[] ptr;}
	
	// 아래처럼 하면 v.at(0) =  0; 안됨
//	T at(int idx) { return ptr[idx]; }

	// 아래 처럼하면 ok. 
	T& at(int idx) { return ptr[idx]; }

	T& operator[](int idx) { return ptr[idx]; }
};

int main()
{
	Vector<int> v(5); // 5개 크기 vector 

	v.at(2) = 0;  
	v.at(3) = 0; 
	v[2] = 0;

	std::cout<< v.at(2) << std::endl; // 0
}