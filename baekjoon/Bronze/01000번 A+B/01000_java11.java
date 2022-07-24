// Date         : 2022-07-24
// Problem      : No. 01000 A+B (https://www.acmicpc.net/problem/01000)
// Difficulty   : Bronze 5
// Step         : 1
// Language     : java11
// Source Link  : https://www.acmicpc.net/source/46587221

// using scanner
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

// Scanner takes much more time than using System.in.read(), which is basic IO
// https://travislife.tistory.com/48
// NOTE: this only works for 0 < A, B < 10

import java.io.*; // import java.io.IOException; is also acceptable

public class Main {
	public static void main(String[] args) throws IOException {
		int a = System.in.read(); // get one character as ASCII int
		System.in.read();
		int b = System.in.read(); // get one character as ASCII int
		System.in.read();
		
		// ASCII int to real int
		a = a-48;
		b = b-48;
		
		System.out.println(a+b);
	}
}
