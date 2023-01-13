/*����¼��5��ѧ����Ϣ�����������ĳɼ�����ѧ�ɼ���Ӣ��ɼ����������ǰ��ָܷߵ��������TreeSet*/
package exercise;
import java.util.TreeSet;
import java.util.Scanner;
import java.util.Comparator;

public class J17_SchoolReport2 {
	 static class Student{
		String name;
		int Chinese;
		int Math;
		int English;
		Student(String n,int c,int m,int e){
			this.name=n;
			this.Chinese=c;
			this.Math=m;
			this.English=e;
		}
		int getSum() {
			return Chinese+Math+English;
		}
	}
	public static void main(String[] args) {
		/*TreeSet���Զ�����Ĵ�С�ȽϷ�ʽ�����Զ��壬ʵ��Comparator�Ľӿڣ�int compare(T o1,T o2)
		 * ��������ʵ�֣�Boolean equals(Object obj)���Բ�ʵ�֡�����compare�ıȽϻ���Ϊ������ֵΪ��
		 * ����o1����o2��*/
		TreeSet<Student> ts=new TreeSet<Student>(new Comparator<Student>() {
			public int compare(Student s1,Student s2) {
				int num=s1.getSum()-s2.getSum();
				return num;
			}
		});
		for(int i=0;i<5;i++) {
			Scanner sc=new Scanner(System.in);
			System.out.println("�������"+(i+1)+"��ѧ������Ϣ��");
			System.out.println("������");
			String name=sc.nextLine();
			System.out.println("���ĳɼ���");
			int chinese=sc.nextInt();
			System.out.println("��ѧ�ɼ���");
			int math=sc.nextInt();
			System.out.println("Ӣ��ɼ���");
			int english=sc.nextInt();
			Student s=new Student(name,chinese,math,english);
			ts.add(s);
		}
		for(Student s:ts) {
			System.out.println("������"+s.name+" ���ĳɼ���"+s.Chinese+" ��ѧ�ɼ���"+s.Math+" Ӣ��ɼ���"+s.English+" �ܷ֣�"+s.getSum());
		}
	}
}
