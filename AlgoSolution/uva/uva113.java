import java.math.*;
import java.util.*;

public class Test {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger p;
		int n;
		while(cin.hasNext()){
			n = cin.nextInt();
			p = cin.nextBigInteger();
			BigInteger l, r;
			l = BigInteger.ZERO;
			r = new BigInteger("1000000000");
			while(l.compareTo(r) <= 0){
				BigInteger mid = l.add(r).divide(new BigInteger("2"));
				if(mid.pow(n).compareTo(p) ==  0){
					System.out.println(mid);
					break;
				}
				else if(mid.pow(n).compareTo(p) > 0)
					r = mid.subtract(BigInteger.ONE);
				else l = mid.add(BigInteger.ONE);
			}
		}
		cin.close();
	}
}

/*
conclusion :
13778523 	113 	Power of Cryptography
Accepted 	JAVA 	0.722 	2014-06-22 10:35:11
1:java 大数，二分
2：

*/
