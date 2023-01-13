package socket_TCP3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public static void main(String[] args) throws IOException {
		ServerSocket ss=new ServerSocket(50000);
		Socket s=ss.accept();
		
		BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
		BufferedWriter bw=new BufferedWriter(new FileWriter("D:\\JAVA\\eclipse-workspace\\MyNet\\src\\socket_TCP3\\write.txt"));	//������д��txt�ļ�
		String line;
		while((line=br.readLine())!=null) {
			bw.write(line);
			bw.newLine();
			bw.flush();
		}
		//Server�˽��յ�shutdownOutput()����Ϣ����˳���whileѭ��
		
		BufferedWriter bwServer=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
		bwServer.write("�ļ��ϴ��ɹ�");
		bwServer.newLine();
		bwServer.flush();
		
		bw.close();
		s.close();
		ss.close();
	}
}
