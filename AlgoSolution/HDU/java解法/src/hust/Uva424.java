package hust;

import java.util.Scanner;
import java.math.*;

public class Uva424 {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger sum = new BigInteger("0");
		while(cin.hasNext()){
			BigInteger a;
			a = cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO) == 0) break;
			// �������Դ�0��1
			sum = sum.add(a);
		}
		System.out.println(sum);
		
		cin.close();
	}
}
