package exercise;

import java.util.Random;
import java.util.Scanner;

public class J03_GuessNumber {
	public static void main(String args[]) {
		int randomnum=new Random().nextInt(10);	//���������
		System.out.println("-----������µ�����-----");
		Scanner sc=new Scanner(System.in);		//�Ӽ��̽�������
		int enternum=sc.nextInt();				//���յ����ݸ���enternum
		while(enternum!=randomnum) {
			if(enternum>randomnum) {
				System.out.println("�´���");
			}
			else {
				System.out.println("��С��");
			}
			System.out.println("-----������µ�����-----");
			enternum=sc.nextInt();	
		}
		System.out.println("��ϲ�㣬�����");
		sc.close();								//�ر�����˿�
	}
}
