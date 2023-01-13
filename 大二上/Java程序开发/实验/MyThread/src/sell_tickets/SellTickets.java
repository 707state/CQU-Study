/* ��Ʊ��
 * 3�����ڹ�ͬ����100��Ʊ
 * ˼·������3���̹߳�ͬ����1����Դ����˲���Runnable�ӿ�
 * ���ݰ�ȫ���⣺���̻߳����ж�����������������
 * ����취��Lock��:synchronized (obj)
 */
package sell_tickets;

public class SellTickets implements Runnable {
	private int tickets=100;
	private Object obj=new Object();
	public static void main(String[] args) {
		SellTickets st=new SellTickets();
		Thread t1=new Thread(st,"����1");
		Thread t2=new Thread(st,"����2");
		Thread t3=new Thread(st,"����3");
		t1.start();
		t2.start();
		t3.start();

	}
	@Override
	public void run() {
//��synchronized��ʱ����β������ظ�
//		while(tickets>0) {
//			try {
//				//Thread.sleep(1);		//������ʱ���޹�
//				Thread.sleep(100);
//				//t1�߳�����CPU����Ϣ100ms����ʱt2������ʼִ�У�t3ͬ����˻������ͬ���ֵ
//			}catch (InterruptedException e) {
//				e.printStackTrace();
//			}
//			System.out.println(Thread.currentThread().getName()+"���ڳ��۵�"+(101-tickets)+"��Ʊ");
//			tickets--;
//		}

//synchronized������ط�������һֱ�Ǵ���һ��Ʊ
//		synchronized (obj) {
//			//t1�߳�����CPU����סִ�г��򣬴�ʱt2�޷�����
//			while(tickets>0) {
//				try {
//					Thread.sleep(1);
//
//				}catch (InterruptedException e) {
//					e.printStackTrace();
//				}
//				System.out.println(Thread.currentThread().getName()+"���ڳ��۵�"+(101-tickets)+"��Ʊ");
//				tickets--;
//			}
//		}

		while(tickets>0) {
			synchronized (obj) {
			//t1�߳�����CPU����סִ�г���sleepʱt2����CPU���޷����У���Ҫ�ȵ�t1����������л���ִ��
				try {
					Thread.sleep(1);
				}catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println(Thread.currentThread().getName()+"���ڳ��۵�"+(101-tickets)+"��Ʊ");
				tickets--;
			}
		}
//		while(true) {
//			synchronized (obj) {
//				if(tickets>0){
//					try {
//						Thread.sleep(1);
//					}catch (InterruptedException e) {
//						e.printStackTrace();
//					}
//					System.out.println(Thread.currentThread().getName()+"���ڳ��۵�"+(101-tickets)+"��Ʊ");
//					tickets--;
//				}
//			}
//		}
	}
}
