/* UDP���ͺͽ������ݵ�Socket������DatagramSocket��ʵ��������
 * UDP�������ݵĲ��裺
 	1.�������Ͷ�Socket����DatagramSocket��
 	2.�������ݲ�������
 	3.����DatagramSocket����ķ�����������
 	4.�رշ��Ͷ�
 */
package learn;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDP_SendMessage {
	public static void main(String[] args) throws IOException {
		//DatagramSocket()�������ݱ��׽���(Socket)������������������ϵ�����˿�
		DatagramSocket ds=new DatagramSocket();
		
		byte[] bs="hello,udp,������".getBytes();
		InetAddress address=InetAddress.getByName("192.168.3.29");
		
		//DatagramPacket(byte[] buf,int length,InetAddress address,int port)
		//����һ�����ݰ�������ָ�����ȵ����ݰ���ָ�������ϵ�ָ���˿ں�
		DatagramPacket dp=new DatagramPacket(bs,bs.length,address,10086);
		
		ds.send(dp);
		
		ds.close();
	}

}
