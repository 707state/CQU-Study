/* void join()���÷�
 * ���øú������߳�ִ����Ϻ������̲߳ſ���ִ��(�������߳�)
 */
package learn;

public class ThreadJoin {

	public static void main(String[] args) throws InterruptedException {
		JoinThread jt1=new JoinThread();
		JoinThread jt2=new JoinThread();
		JoinThread jt3=new JoinThread();
		jt1.setName("�ܲ�");
		jt2.setName("����");
		jt3.setName("��Ȩ");
		jt1.start();
		jt1.join();
		System.out.println("break!");
		jt2.start();
		jt3.start();
	}
	static class JoinThread extends Thread{
		public void run() {
			for(int i=0;i<10;i++) {
				System.out.println(getName()+":"+i);
			}
		}
	}
}
