/*ʵ���ļ��ļ��������*/
package file_processing;
import java.io.IOException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileCoder {
	public static void main(String[] args) throws IOException{
		byte pwd=123;
		FileInputStream fis=new FileInputStream(new File("D:/LKH/DerrickRose.txt"));
		FileOutputStream fos=new FileOutputStream(new File("src/file_processing/test4.txt"));
		System.out.println("��ʼ���ܣ�");
		int n=fis.available()/5;
		byte buf[]=new byte[n];
		int cnt=0;
		while((cnt=fis.read(buf,0,n))!=-1) {
			for(int i=0;i<cnt;i++) {
				buf[i]=(byte)(buf[i]^pwd);
			}
			fos.write(buf,0,cnt);
		}
		System.out.println("��ɼ��ܡ�");
		fis.close();
		fos.close();
		
		System.out.println("��ʼ���ܣ�");
		fis=new FileInputStream("src/file_processing/test4.txt");
		fos=new FileOutputStream("src/file_processing/test5.txt");
		n=fis.available()/5;
		buf=new byte[n];
		cnt=0;
		while((cnt=fis.read(buf,0,n))!=-1) {
			for(int i=0;i<cnt;i++) {
				buf[i]=(byte)(buf[i]^pwd);
			}
			fos.write(buf,0,cnt);
		}
		System.out.println("��ɽ��ܡ�");
		fis.close();
		fos.close();
	}
}
