/*����˷�
 * �α�P54 T2
 */
package exercise;
import java.util.Scanner;


public class J09_MatrixMultiplication {
	public static void main(String args[]) {
		System.out.println("�������������������������");
		Scanner sc=new Scanner(System.in);
		int r1=sc.nextInt();
		int c1=sc.nextInt();
		int r2=sc.nextInt();
		int c2=sc.nextInt();
		int matrix1[][]=new int[50][50];
		int matrix2[][]=new int[50][50];
		int matrix3[][]=new int[50][50];
		System.out.println("�������һ������");
		for(int i=0;i<r1;i++) {
			for(int j=0;j<c1;j++) {
				matrix1[i][j]=sc.nextInt();
			}
		}
		System.out.println("������ڶ�������");
		for(int i=0;i<r2;i++) {
			for(int j=0;j<c2;j++) {
				matrix2[i][j]=sc.nextInt();
			}
		}
		if(c1!=r2) {
			System.out.println("�޷����");
		}
		else {
			for(int i=0;i<r1;i++) {
				for(int j=0;j<c2;j++) {
					int tmp=0;
					for(int k=0;k<c1;k++) {
						tmp+=matrix1[i][k]*matrix2[k][j];
					}
					matrix3[i][j]=tmp;
				}
			}
			System.out.println("����ĳ˻�Ϊ��");
			for(int i=0;i<r1;i++) {
				for(int j=0;j<c2;j++) {
					System.out.print(matrix3[i][j]+" ");
				}
				System.out.println();
			}
		}
		sc.close();
	}
}
