package socket_TCP4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class ServerThread implements Runnable{
	private Socket s;
	public ServerThread(Socket s) {
		this.s=s;
	}
	@Override
	public void run() {
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
			//����ͻ����ļ������г�ͻ
			//BufferedWriter bw=new BufferedWriter(new FileWriter("D:\\JAVA\\eclipse-workspace\\MyNet\\src\\socket_TCP4\\write.txt"));
			int cnt=0;
			File file=new File("D:\\JAVA\\eclipse-workspace\\MyNet\\src\\socket_TCP4\\write0.txt");
			while(file.exists()) {
				cnt++;
				file=new File("D:\\JAVA\\eclipse-workspace\\MyNet\\src\\socket_TCP4\\write"+cnt+".txt");
			}
			BufferedWriter bw=new BufferedWriter(new FileWriter(file));
			
			String line;
			while((line=br.readLine())!=null) {
				bw.write(line);
				bw.newLine();
				bw.flush();
			}
			
			BufferedWriter bwServer=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
			bwServer.write("�ļ��ϴ��ɹ�");
			bwServer.newLine();
			bwServer.flush();
			
			s.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
