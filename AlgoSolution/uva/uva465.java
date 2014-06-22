import java.math.*;
import java.util.*;

public class Test {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger x, y, Max;
		Max = new BigInteger(Integer.toString(Integer.MAX_VALUE));
		String s, a, b, c;
		while(cin.hasNextLine()){
			s = cin.nextLine();
			System.out.println(s);
			int i = 0;
			a = b = c = "";
			for(i = 0; ; i ++){
				if(s.charAt(i) == '*' || s.charAt(i) == '+') break;
				if(s.charAt(i) == ' ') continue;
				a += s.charAt(i);
			}
			b += s.charAt(i);
			i ++;
			for(; i < s.length(); i ++){
				if(s.charAt(i) == ' ') continue;
				c += s.charAt(i);
			}
			x = new BigInteger(a);
			y = new BigInteger(c);
			if(x.compareTo(Max) > 0) System.out.println("first number too big");
			if(y.compareTo(Max) > 0) System.out.println("second number too big");
			if(b.equals("+") && x.add(y).compareTo(Max) > 0 )
				System.out.println("result too big");
			if(b.equals("*") && x.multiply(y).compareTo(Max) > 0)
				System.out.println("result too big");
		}
		cin.close();
	}
}

/*
conclusion:
13777396 	465 	Overflow
Accepted 	JAVA 	0.178 	2014-06-22 02:29:42
1: 选择etLine多行输入比较好
2: bigInteger 构造函数中字符不能用
*/
