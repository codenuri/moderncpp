#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	
	// ��� #1. Point ��ü�� �������� �ֱ�
//	Point pt(1, 2);
//	v.push_back(pt);


	// ��� #2. �ӽð�ü ���·� ����
//	v.push_back(Point{ 1, 2 });
//	v.push_back({ 1, 2 }); //  ���� ����


	// ���	#3. �� ������ �ٽ�!!!!!
	// => ��ü�� �������� ����,
	//    ��ü�� ����� ���� ������ ���ڸ� ��������

	v.emplace_back(1, 2);
		// => �� �Լ��� ���������� �ڽ��� ���ۿ�
		// => new Point(1,2) �� ��ü�� ����.

		// 1, 2 ===> emplace_back(a, b) 
		//			 a, b �� �ٽ� Point �����ڿ� ���� ===> Point(x, y)

		// ��, emplace_back �� �ڽ��� ���� ���ڸ�
		// Point �����ڷ� �����մϴ�
		// => �Ϻ��� ���� ����� �ʿ� �մϴ�.

	std::cout << "-----" << std::endl;
}
// STL container ����

// 1. primitive Ÿ���� �����ϴ� �����̳� 
// => std::vector<int> v;
// => push_xxx() �Ǵ� emplace_xxx() ��� �����ϴ�.
// => �׳�, �������� ���� push_xxx() �ϼ���



// 2. ����� ���� Ÿ���� ������ �����ϴ� �����̳�
// => std::vector<Point> v;
// => push_xxx() ���ٴ� emplace_xxx() �� �����ϴ�.

// push_back()	==> emplace_back();
// push_front()	==> emplace_front();
// insert()	    ==> emplace();


// 3. ����� ���� Ÿ���� �����͸� �����ϴ� �����̳�
// => �׳� push_xxx �ϸ� �˴ϴ�.

// 4. �����̳ʴ� ���۷����� �����Ҽ� �����ϴ�.
// std::vector<Point&> v; // error..  
