package hust;

import java.util.Scanner;
import java.math.*;

public class Hdu1047 {
	public static void main(String agrs[]){
		int n;
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		for(int i = 0; i < n; i ++){
			if(i != 0) System.out.println();
			// 空白行用输出来填充
			BigInteger ans = new BigInteger("0");
			while(true){
				BigInteger temp = cin.nextBigInteger();
				if(temp.compareTo(BigInteger.ZERO) == 0) break;
				ans = ans.add(temp);
			}
			System.out.println(ans);
		}
	}
}
/*
 * Accepted	1047	156MS	5060K	513 B	Java	robotcator
 * */
