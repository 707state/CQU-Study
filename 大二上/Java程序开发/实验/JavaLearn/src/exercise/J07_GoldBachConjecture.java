/* ��֤��°ͺղ���
 * �α�P43 T11
 * ��Ŀ�������֤��°ͺղ��룬���κδ���6��ż�����Ա�ʾΪ������֮�ͣ���10=3+7
 */
package exercise;
import java.util.Scanner;

public class J07_GoldBachConjecture {
	public static void main(String args[]) {
		System.out.println("----������һ������6��ż��----");
		Scanner sc=new Scanner(System.in);
		int num=sc.nextInt();
		boolean flag=false;
		if(num<=6||num%2!=0) {
			System.out.println("����ֵ����");
		}
		else {
			for(int i=7;i<num/2;i++) {
				if(isPrime(i)&&isPrime(num-i)) {
					flag=true;
					System.out.println(num+"="+i+"+"+(num-i));
					break;
				}
			}
			if(!flag) {
				System.out.println("�������");
			}
		}
		sc.close();
	}
	public static boolean isPrime(int n) {
		if(n==1) {
			return false;
		}
		if(n==2||n==3) {
			return true;
		}
		for(int i=2;i<=Math.sqrt(n)+1;i++) {
			if(n%i==0) {
				return false;
			}
		}
		return true;
	}
}
