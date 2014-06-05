package hust;

import java.util.*;
import java.math.*;

public class Solution {
	public static void main(String args[]){
		int n;
		int num[] = new int[30];
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			n = cin.nextInt();
			if(n == 0) break;
			int cnt = 0;
			for(int i = 0; i < n; i ++){
				num[i] = cin.nextInt();
				cnt += num[i];
			}			
			BigInteger f1, f2;
			f1 = new BigInteger("1");
			f2 = new BigInteger("1");
			for(int i = 0; i < n; i ++){
				for(int j = 1; j <= num[i]; j ++){
					f1 = f1.multiply(BigInteger.valueOf(j));
				}
			}
			//System.out.println(f1);
			for(int i = 1; i <= cnt; i ++)
				f2 = f2.multiply(BigInteger.valueOf(i));
			//System.out.println(f2);
			System.out.println(f2.divide(f1));	
		}
	}
}
/*
 * 10798510	2014-05-25 15:52:19	Accepted	1261	234MS	5776K	773 B	Java	robotcator
 * */