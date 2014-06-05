package hust;

import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger sum = new BigInteger("0");
		while(cin.hasNext()){
			BigInteger a;
			a = cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO) == 0) break;
			sum = sum.add(a);
		}
		System.out.println(sum);
		cin.close();
	}
}
