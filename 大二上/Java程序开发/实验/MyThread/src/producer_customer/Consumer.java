package producer_customer;

public class Consumer implements Runnable{
	private Box b;
	public Consumer(Box b) {
		this.b=b;
	}
	@Override
	public void run() {
		while(true) {		//���н�������Ҫ���ն��ֶ���ֹ
			b.get();
		}
	}
}
