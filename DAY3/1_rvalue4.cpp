#include <iostream>
#include <type_traits>

int main()
{
	int n = 0;

	n = 10; // ok

	(n + 1) = 10; // ?

	(n = 1) = 10; // ?
}