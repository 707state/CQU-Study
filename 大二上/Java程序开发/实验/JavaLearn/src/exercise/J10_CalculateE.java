/*	��Ŀ��e^x�ļ���չ��ʽΪ(^��ʾ�ϱ�)��e^x=1+x+x^2/2!+x^3/3!+...+x^n/n!+...
 *	Ҫ��1.��дһ��������������Ӧ��ֵ 2.��main����������һ�������x�������Լ���д�ĺ�����ֵ
 */
package exercise;
import java.util.*;

public class J10_CalculateE {
	public static double CalculateE(int n) {
		//�������ķ�Χ��0~10����e^x��չ��ʽ��nȡ��20ʱ�����Ѿ��ǳ�С��
		double power[]=new double[20];		//������洢�ݣ������ظ�����
		double factorial[]=new double[20];	//������洢�׳�
		power[0]=1;
		factorial[0]=1;
		double res=1;
		for(int i=1;i<20;i++) {
			power[i]=power[i-1]*n;
			factorial[i]=factorial[i-1]*(i+1);
			res+=power[i]/factorial[i];
		}
		return res;
	}
	public static void main(String args[]) {
		int ran=new Random().nextInt(10);
		System.out.println("e^"+ran+"��ֵ��"+CalculateE(ran));
	}
}
