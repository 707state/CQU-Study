/*��Сд��ĸת��
 * �α�P167 T1
 * ��Ŀ����һ���ַ�����Сд��ĸת���ɴ�д��ĸ����д��ĸת����Сд��ĸ
 */
package exercise;
import java.util.Scanner;

public class J12_ConvertUpperLower {
	public static char Convert(char a) {
		char c=a;						//�����Ǵ�Сд��ĸ��ԭ�����
		if(a>='a'&&a<='z') {
			c=(char)(a-'a'+'A');
		}
		if(a>='A'&&a<='Z') {
			c=(char)(a-'A'+'a');
		}
		return c;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String sin=sc.next();
		StringBuffer sout=new StringBuffer();
		for(int i=0;i<sin.length();i++) {
			char a=sin.charAt(i);		//Java���ַ�����֧���±���ʣ���˲���charAt����
			sout.append(Convert(a));
		}
		System.out.println(sout);
		sc.close();
	}

}
