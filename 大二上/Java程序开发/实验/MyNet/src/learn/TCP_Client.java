/* TCPʹ��Socket����������˵�ͨ�Ŷ˿ڣ���ͨ��Socket����IO������������ͨ�š�
 * �ͻ���Socket�������ݺͷ�������ServerSocket��������
   TCP�������ݲ��裺
  	1.�����ͻ���Socket����
  	2.��ȡ�������д����
  	3.�ͷ���Դ
   TCPֻ���пͻ��˻ᱨ����Ϊû�и������������������֣����ӱ��ܾ���
   �˿ںž���д50000���ϣ��������ױ�ռ��
 */
package learn;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class TCP_Client {
	public static void main(String[] args) throws UnknownHostException, IOException {
		//Socket(InetAddress address,int port)����Socket���������ӵ�ָ��IP��ַ��ָ���˿�
		//Socket s=new Socket(InetAddress.getByName("192.168.3.29"),50000);
		//Socket(String host,int port)����Socket���������ӵ�ָ��������ָ���˿ڣ�����ͬ��
		Socket s=new Socket("192.168.3.29",50000);
		
		//OutputStream getOutputStream()����Socket�������
		OutputStream os=s.getOutputStream();
		os.write("hello,tcp,������".getBytes());
		
		s.close();
	}

}
