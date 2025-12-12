// 7_가변인자템플릿1 - 225 page

// C++11 가변인자 템플릿
// => 타입 인자 갯수에 제한이 없다
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2; // Types : int, double 
}
