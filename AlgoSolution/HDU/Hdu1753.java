package hust;
import java.util.*;
import java.math.*;

public class Hdu1753 {
   public static void main(String args[]){
	   Scanner cin = new Scanner(System.in);
	   while(cin.hasNext()){
		   BigDecimal a , b, ans;
		   a = cin.nextBigDecimal();
		   b = cin.nextBigDecimal();
		   ans = a.add(b);
		   System.out.println(a.add(b).stripTrailingZeros().toPlainString());
	   }
   }
}
/*
 * Accepted	1753	171MS	5716K	390 B
 * 1、stripTrailingZeros() ，返回类型为BigDecimal的小于此数的但除去尾部的0的数值。

2、toPlainString()，返回BigDecimal类型的String类型字符串。

3、startsWith()，确定此实例的开头是否与指定的字符串匹配。

4、substring()，返回一个新的字符串，它是此字符串的一个子字符串。该子字符串始于指定索引处的字符，一直到此字符串末尾。 
*/
