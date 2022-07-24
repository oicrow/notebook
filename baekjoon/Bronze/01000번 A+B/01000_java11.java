// Date         : 2022-07-24
// Problem      : No. 01000 A+B (https://www.acmicpc.net/problem/01000)
// Difficulty   : Bronze 5
// Step         : 1
// Language     : java11
// Source Link  : https://www.acmicpc.net/source/46587221

import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		int A = 0;
		int B = 0;
		
		Scanner sc = new Scanner(System.in);
		
		A = sc.nextInt();
		B = sc.nextInt();
		
		System.out.println(A+B);
		
		sc.close();
	}
}
