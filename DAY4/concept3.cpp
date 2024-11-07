#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>  
#include <concepts> 

int main()
{
	std::vector<int> v = { 1,2,3 };

	std::find   (v.begin(), v.end(), 3);
	std::find_if(v.begin(), v.end(), [](int n) {return n % 2 == 0; });


}
