/*TCP�������ݲ��裺
  	1.���������ServerSocket����
  	2.��ȡ�������������ݣ�����������ʾ�ڿ���̨
  	3.�ͷ���Դ
 */
package learn;

import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCP_Server {
	public static void main(String[] args) throws IOException {
		ServerSocket ss=new ServerSocket(50000);
		
		//Socket accept()���ڼ���ss��һ�������ӱ�����Socket�����ҽ���
		Socket s=ss.accept();
		
		InputStream is=s.getInputStream();
		byte[] bys=new byte[1024];
		int len=is.read(bys);
		String data=new String(bys,0,len);
		System.out.println("�����ǣ�"+data);
		
		s.close();
		ss.close();
	}

}
