
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n, t;
		t = cin.nextInt();
		while((t --) != 0 ){
		//	t --;
			n = cin.nextInt();
			int data[] = new int[n+1];
			for(int i = 0; i < n; i ++){
				data[i] = cin.nextInt();
			//	System.out.println(data[i]);
			}
			BigInteger C[] = new BigInteger[n+1];
			C[0] = BigInteger.ONE;
			for(int i = 1; i <= n-1; i ++){
				BigInteger temp = BigInteger.valueOf(n-i);
				BigInteger temp2 = BigInteger.valueOf(i);
				C[i] = C[i-1].multiply(temp).divide(temp2);
			//	System.out.println(C[i]);
			}
			BigInteger sum = BigInteger.ZERO;
			int j = 1;
			for(int i = n-1; i >= 0; i --){
       // System.out.println(j*data[i]);
				BigInteger temp = BigInteger.valueOf(j*data[i]);
				//System.out.println(temp);
				sum = sum.add(C[i].multiply(temp));
				j = (-1)*j;
				//System.out.println(j);
			}
			System.out.println(sum);
		}
		cin.close();
	}
}
