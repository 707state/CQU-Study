/*classǰ����public���Σ�����Խ�CA,CBд��ͬһ��class�ļ��������ǰ���main��������*/
package object_oriented;
class CA{
	String s="class CA";
	void callme() {
		System.out.println("inside A");
	}
}
class CB extends CA{
	String s="class CB";
	void callme() {
		System.out.println("inside B");
	}
}

public class TestInheritance {
	public static void main(String args[]) {
		CA a=new CA();
		CB b=new CB();
		CA c=new CB();
		System.out.println(a.s);
		a.callme();
		System.out.println(b.s);
		b.callme();
		System.out.println(c.s);
		c.callme();
		/*��Ա�����ͷ����ĵ��÷�ʽ��ͬ��CA c=new CB()��c��������CA�����洢����CB��ʵ�������ó�Ա
		  ����ʱ���õ��Ǹ��࣬���÷���ʱ���õ�������
		*/
	}
}
