package hust;
import java.util.Scanner;

public class Tram {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n;
		while(cin.hasNext()){
			n = cin.nextInt();
			int a, b;
			int min = 0;
			int total = 0;
			for(int i = 0; i < n; i ++){
				a = cin.nextInt();
				b = cin.nextInt();
				total = total + b - a;
				if(total > min) min = total;
			}
			System.out.println(min);
		}
		cin.close();
	}

}
