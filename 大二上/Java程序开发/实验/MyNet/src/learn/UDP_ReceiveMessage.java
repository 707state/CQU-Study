/*UDP�������ݵĲ��裺
	1.�������ն�Socket����DatagramSocket��
	2.�������ݰ�
	3.����DatagramSocket����ķ�����������
	4.�������ݰ������������ڿ���̨��ʾ
	5.�رշ��Ͷ�
	(����ʱ���������նˣ����������Ͷ�)
*/
package learn;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDP_ReceiveMessage {
	public static void main(String[] args) throws IOException {
		//DatagramSocket(int port)�������ݱ��׽���(Socket)������������������ϵ�ָ���˿�
		DatagramSocket ds=new DatagramSocket(10086);
		
		byte[] bs=new byte[1024];
		
		//DatagramPacket(byte[] buf,int length)����һ������ָ���������ݵ����ݰ�
		DatagramPacket dp=new DatagramPacket(bs,bs.length);
		
		ds.receive(dp);
		
		//byte[] getData()�������ݻ�����
		byte[] datas=dp.getData();
		//int getLength()����ʵ�����ݳ���
		int len=dp.getLength();
		String dataString=new String(datas,0,len);
		System.out.println("�����ǣ�"+dataString);
		
		ds.close();
	}
}


