	package hust;
	
	import java.util.*;
	import java.math.*;
	
	public class Hdu1063 {
		public static void main(String args[]){
			Scanner cin = new Scanner(System.in);
			BigDecimal r = new BigDecimal("0");
			int b = 0;
			while(cin.hasNext()){
				r = cin.nextBigDecimal();
				b = cin.nextInt();
				BigDecimal ans = r.pow(b);
				String res = ans.stripTrailingZeros().toPlainString();
				if(res.startsWith("0"))
					res = res.substring(1);
				System.out.println(res);
			}
		}
	}
/*
 * Accepted	1063	359MS	6104K	467 B	Java	robotcator
 */