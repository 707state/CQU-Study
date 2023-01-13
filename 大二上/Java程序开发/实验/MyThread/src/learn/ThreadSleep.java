/* void sleep(long millis)���÷�
 * Ϊ�����໥��ռ�̣߳�ÿ���߳�ÿִ��һ��ѭ��������1s���㹻�����߳���ɸô�ѭ��
 * ���֣�"Finished!"���ʼ���
 */
package learn;

public class ThreadSleep {

	public static void main(String[] args) {
		SleepThread st1=new SleepThread();
		SleepThread st2=new SleepThread();
		SleepThread st3=new SleepThread();
		st1.setName("�ܲ�");
		st2.setName("����");
		st3.setName("��Ȩ");
		st1.start();
		st2.start();
		st3.start();
		System.out.println("Finished!");
	}
	static class SleepThread extends Thread{
		public void run() {
			for(int i=0;i<10;i++) {
				System.out.println(getName()+":"+i);
				try {
					Thread.sleep(1000);		//sleep 1000ms
				}catch(InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
