// 참고
// 유즘 유행하는 개념
// RUST : if 도 expression 이다.		=> 한개의 값으로 계산될수 있다.
// C#   : switch 가 expression 이다. => ""

int main()
{
	int n = 10;

	// RUST
	int ret = if (n > 10) 5 else 20;

	// C#
	int ret2 = n switch 
				{
					1 => 10,
					2 => 20,
					_ => 0
				}

}