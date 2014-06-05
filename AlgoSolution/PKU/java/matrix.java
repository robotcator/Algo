import java.util.Scanner;

public class matrix{	
	public static void main(String args[]){
	       	Scanner cin = new Scanner(System.in);
	 	int n, m;
		System.out.println("please input the first matrix's dimension");
		n = cin.nextInt();
		m = cin.nextInt();
		System.out.println("please input the frist matrix");
	       	double matrix1[][] = new double[m+1][n+1];
	       	for(int i = 0; i < m; i ++){
			for(int j = 0; j < n; j ++){
				matrix1[i][j] = cin.nextDouble();
			}
		}
		int p, q;
		System.out.println("please input the second matrix's dimension");
		p = cin.nextInt();
		q = cin.nextInt();
		System.out.println("please input the second matrix");
		double matrix2[][] = new double[p+1][q+1];
		for(int i = 0; i < p; i ++){
			for(int j = 0; j < q; j ++){
				matrix2[i][j] = cin.nextDouble();
			}
		}

		if(n == p){
			double ans[][] = new double[m+1][q+1];
			for(int i = 0; i < m; i ++){
				for(int j = 0; j < n; j ++){
					ans[i][j] = 0;
					for(int k = 0; k < p; k ++){
						ans[i][j] += matrix1[i][k]*matrix2[k][j]; 
					}
				}
			}
			System.out.println("the ans is");
			for(int i = 0; i < m; i ++){
				for(int j = 0; j < q; j ++){
					System.out.print(ans[i][j] +  " ");
				}
				System.out.println();
			}
		}
		else System.out.println("the error dimensions");
		
	}
}
