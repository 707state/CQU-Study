//���������
package exercise;
import java.util.Random;
import java.util.Scanner;
public class J08_RandomRollCall {
	public static void main(String[] args) {
		String student[]=new String[5];
		Scanner sc=new Scanner(System.in);
		for(int i=1;i<=student.length;i++) {
			System.out.println("�������"+i+"��ͬѧ����:");
			student[i-1]=sc.next();
		}
		int index=new Random().nextInt(student.length);
		System.out.print("----���������----\n���㵽����ͬѧ�ǣ�"+student[index]);
		sc.close();
	}
}
