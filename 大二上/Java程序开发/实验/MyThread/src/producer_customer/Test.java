/* �����������߰����е��ࣺ
 * 1.������Box�������Ա����milk��ʾ��xƿ�̣�state��ʾ�Ƿ���ţ�̣���Ա�����洢�ͻ�ȡţ��
 * 2.��������Producer��ʵ��Runnable�ӿڣ���дrun()���������ô洢ţ�̵Ĳ���
 * 3.��������Consumer��ʵ��Runnable�ӿڣ���дrun()���������û�ȡţ�̵Ĳ���
 * 4.������Test 
 * ע��wait()��notify()��Ҫ�ɶ�ʹ��
 * 	  ע���synchronized�ؼ���
 */
package producer_customer;

public class Test {

	public static void main(String[] args) {
		Box b=new Box();
		Producer p=new Producer(b);		//����������������߹��캯��
		Consumer c=new Consumer(b);		//����������������߹��캯��
		Thread t1=new Thread(p);		//�������߳�
		Thread t2=new Thread(c);		//�������߳�
		
		t1.start();
		t2.start();
	}

}
