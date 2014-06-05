package hust;

import java.math.BigInteger;
import java.util.Scanner;

public class Hdu1715 {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n, p;
		while(cin.hasNext()){
			n = cin.nextInt();
			for(int i = 0; i < n; i ++){
				p = cin.nextInt();
				BigInteger f1 = new BigInteger("1");
				BigInteger f2 = new BigInteger("1");
				for(int j = 2; j < p; j ++){
					f1 = f1.add(f2);
					f2 = f1.subtract(f2);
				}
				System.out.println(f1);
			}
		}
		cin.close();
	}
}
