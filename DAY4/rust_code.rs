#![allow(unused)]

// Rust 
// ��Ģ #1. ��� �Լ��� �ٸ� Ÿ���̴�.
//         signature �� ������ �Լ��� "�ٸ� Ÿ��" �̴�

// ��Ģ #2. signature �� ������ �Լ���
//         ���� Ÿ���� �Լ� �����ͷ� �Ͻ��� ����ȯ �ɼ� �ִ�.

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