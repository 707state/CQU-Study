/* �α�P43 T10
 * ��1~10�Ľ׳� 
 */
package exercise;

public class J06_Factorial {
	public static void main(String args[]) {
		int ans=0;
		for(int i=1;i<=10;i++) {
			int fac=1;
			for(int j=1;j<=i;j++) {
				fac*=j;
			}
			ans+=fac;
		}
		System.out.println(ans);
	}
}
