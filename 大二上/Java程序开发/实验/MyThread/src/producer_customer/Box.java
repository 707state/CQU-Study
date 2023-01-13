package producer_customer;

public class Box {
	private int milk;
	private boolean state=false;
	public synchronized void put(int milk) {
		if(state) {
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.milk=milk;
		System.out.println("���̹�����"+this.milk+"ƿ�̷�������");
		state=true;
		notifyAll();		//�ǵû��������ȴ��ĳ���
	}
	public synchronized void get() {
		if(!state) {
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("�û��õ���"+this.milk+"ƿ��");
		state=false;
		notifyAll();
	}
}
