#![allow(unused)]

// Rust 
// 규칙 #1. 모든 함수는 다른 타입이다.
//         signature 가 동일한 함수도 "다른 타입" 이다

// 규칙 #2. signature 가 동일한 함수는
//         같은 타입의 함수 포인터로 암시적 형변환 될수 있다.

fn cmp1(a : i32, b : i32) -> bool { return a < b;}
fn cmp2(a : i32, b : i32) -> bool { return b > a;}


fn sort<T>( f : T )
{
}

fn main()
{
	sort(cmp1);
	sort(cmp2);

//	sort(cmp1 as fn(i32, i32)->bool );
//	sort(cmp2 as fn(i32, i32)->bool );
} 