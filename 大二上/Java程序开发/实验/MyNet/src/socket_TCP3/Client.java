package socket_TCP3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class Client {
	public static void main(String[] args) throws IOException {
		Socket s=new Socket("192.168.3.29",50000);
		BufferedReader br=new BufferedReader(new FileReader("D:\\JAVA\\eclipse-workspace\\MyNet\\src\\socket_TCP3\\read.txt"));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
		
		String line;
		while((line=br.readLine())!=null) {
			bw.write(line);
			bw.newLine();
			bw.flush();
		}
		//Client����txt�ļ����˳���whileѭ������û�з���line=null������Server��brһֱ�ڵȴ�readLine�޷��˳�
		
		//�Զ���������
//		bw.write("886");
//		bw.newLine();
//		bw.flush();
		
		//void shutdownOutput()����һ����ӦSocket��������ı��
		s.shutdownOutput();
		
		//���շ������˷��������s.getInputStream()
		BufferedReader brClient=new BufferedReader(new InputStreamReader(s.getInputStream()));
		String data=brClient.readLine();
		System.out.println("������������"+data);
		
		br.close();
		s.close();
	}
}
