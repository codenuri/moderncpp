// 1_rvalue - 87 page

int main()
{
	int v1 = 10;

	v1 = 20;	// ok    v1 은 = 의 왼쪽에 올수 있다. lvalue
	10 = v1;	// error 10 은 = 의 왼쪽에 올수 없고, 오른쪽에만 가능 rvalue
	
	int n = v1; // ok. v1 은 오른쪽도 가능.
}

// lvalue : 등호의 양쪽에 올수 있다.
// rvalue : 등호의 오른쪽만 가능, 왼쪽 안됨








