inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };


template<typename T>
void foo(T f)
{
	bool b = f(1, 2); // "A"
}

int main()
{
	Less f1;
	Greater f2;
	foo(cmp1);
	foo(cmp2);
	foo(f1);
	foo(f2);
}
// 1. 위 코드를 컴파일 하면 foo 함수는 몇개 일까요 ?
// 2. foo 외의 함수는 몇개 일까요 ?
// 3. 각 "foo" 에서 "A" 부분의 인라인 치환여부를 생각해보세요




