/*���Զ��̵߳�ִ��˳�򣬷���������ͬ�̲߳���ִ�У�һ���߳���˳��ִ�С�ͨ��������Կ�������������ִ�е�
 * �߳��ȿ�ʼ��Ҳ���ܺ����
 */
package learn;

public class SequenceDemo {
	public static void main(String[] args) {
		Thread sum=new SumThread();
		Thread squaresum=new SquareSumThread();
		squaresum.start();
		sum.start();
	}
	static class SumThread extends Thread{
		public void run() {
			int sum=0;
			for(int i=1;i<20;i++) {
				System.out.println("sum:"+i);
				sum+=i;
			}
			System.out.println("Sum="+sum);
		}
	}
	static class SquareSumThread extends Thread{
		public void run() {
			int sum=0;
			for(int i=1;i<20;i++) {
				System.out.println("squaresum:"+i*i);
				sum+=i*i;
			}
			System.out.println("SquareSum="+sum);
		}
	}
}
