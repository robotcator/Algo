package hust;
import java.util.Scanner;

public class StringTask {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		String data;
		while(cin.hasNext()){
			data = cin.next();
			data = data.toLowerCase();
			for(int i = 0; i < data.length(); i ++){
				if(data.charAt(i) == 'a' || data.charAt(i) == 'e' ||
				   data.charAt(i) == 'i' || data.charAt(i) == 'o' || 
				   data.charAt(i) == 'u' || data.charAt(i) == 'y')
				  continue;
				else System.out.print("." + data.charAt(i));
			}
			System.out.println();
		}
		cin.close();
	}
}
