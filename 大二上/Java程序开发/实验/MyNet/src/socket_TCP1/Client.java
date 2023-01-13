package socket_TCP1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	public static void main(String[] args) throws UnknownHostException, IOException {
		Socket s=new Socket("192.168.3.29",50000);
		//��ȡ��������
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//���ֽ���ת��Ϊ�ַ�������BufferedReader����ʹ��
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
		String line;
		while((line=br.readLine())!=null) {
			if("886".equals(line)) {
				break;
			}
			bw.write(line);		//һ��дһ���ַ���
			bw.newLine();
			bw.flush();
		}
	
		s.close();
	}
}
