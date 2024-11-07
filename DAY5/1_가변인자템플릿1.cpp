// 가변인자템플릿1 - 225 page

// 가변인자 클래스 템플릿
// => 모양 알아 두세요. ... 위치
template<typename ... Ts> class tuple 
{
};
int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, char> t2;
	tuple<int, double, char> t3; // Ts : int, double, char 
}
