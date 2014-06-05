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
 * 1��stripTrailingZeros() ����������ΪBigDecimal��С�ڴ����ĵ���ȥβ����0����ֵ��

2��toPlainString()������BigDecimal���͵�String�����ַ�����

3��startsWith()��ȷ����ʵ���Ŀ�ͷ�Ƿ���ָ�����ַ���ƥ�䡣

4��substring()������һ���µ��ַ��������Ǵ��ַ�����һ�����ַ����������ַ���ʼ��ָ�����������ַ���һֱ�����ַ���ĩβ�� 
*/
