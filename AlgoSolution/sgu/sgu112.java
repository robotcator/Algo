import java.util.*;
import java.math.*;

public class Sgu112 {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			Integer m, n;
			m = cin.nextInt();
			n = cin.nextInt();
			String temp = m.toString();
			BigDecimal a = new BigDecimal(temp);
			temp = n.toString();
			BigDecimal b = new BigDecimal(temp);
			BigDecimal ans = a.pow(n).subtract(b.pow(m));
			System.out.println(ans.toPlainString());
		}
	}
}
/*
 * 1561427	12.05.14 18:41	robotcator	112 	.JAVA	Accepted 	0 ms	0 kb
 */
