import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger x, y;
		while(cin.hasNext()){
			x = cin.nextBigInteger();
			y = cin.nextBigInteger();
			System.out.println(x.multiply(y));
		}
		cin.close();
	}
}

/*
conclusion:
13775668 	10106 	Product
Accepted 	JAVA 	0.215 	2014-06-21 13:09:00
1: 用ava大数类秒杀
2：找个时间自己写写大叔模板
*/
