/* void setDaemon(boolean on)���÷�
 * �������߳�ֻʣ�ػ��߳�ʱ��������˳�
 * ��������˳���Ҫʱ�䣬����ػ��̲߳�������ֹͣ�������н����̺߳��ػ��߳�ѭ���������ýϴ��༴�ɿ���
 */
package learn;

public class ThreadDaemon {
	public static void main(String[] args) throws InterruptedException {
		DaemonThread dt1=new DaemonThread();
		DaemonThread dt2=new DaemonThread();
		dt1.setName("����");
		dt2.setName("�ŷ�");
		Thread.currentThread().setName("����");
		dt1.setDaemon(true);
		dt2.setDaemon(true);
		
		dt1.start();
		dt2.start();
		for(int i=0;i<5;i++) {
			System.out.println(Thread.currentThread().getName()+":"+i);
		}
	}
	static class DaemonThread extends Thread{
		public void run() {
			for(int i=0;i<20;i++) {
				System.out.println(getName()+":"+i);
			}
		}
	}

}
