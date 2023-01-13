/*���������е��ļ����������ư�Σ�
ʵ�����ݣ�
1��ʵ���ļ��д�����ɾ�������룻
2��ʵ�ֵ�ǰ�ļ����µ��������У�
3��ʵ���ļ��������ļ��п������ļ��п���ָ��ȿ���������������Ŀ¼���ļ�����
4��ʵ��ָ���ļ��ļ��ܺͽ��ܡ�
 */
package file_processing;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileManager {
	public static void main(String[] args) throws IOException{
		//��Ϊ�ļ���������Ҫ���κε�����ͨ�ã���˲���ʹ�ñ����ľ���·��
		File dir=new File("src/file_processing");		//��ǰjava�ļ�����Ŀ¼
		File f1=new File(dir,"test1.txt");
		File f2=new File(dir,"test2.txt");
		File subdir=new File(dir,"subdir");
		f1.createNewFile();								//�����ļ�
		f2.createNewFile();
		subdir.mkdir();									//�����ļ���
		System.out.println(f1.exists());
		System.out.println("�г�Ŀ¼"+dir+"�е����ļ��У�");	//�г��ļ����µ����ļ���
		File[] fileArray=dir.listFiles();
		for(File f:fileArray) {
			if(f.isDirectory()) {
				System.out.println("�ļ��У�"+f.getName());
			}
		}
		System.out.println("�г�Ŀ¼"+dir+"�е��ļ���");		//�г��ļ����µ����ļ�
		for(File f:fileArray) {
			if(f.isFile()) {
				System.out.println("�ļ���"+f.getName());
			}
		}
		FileInputStream  fis=new FileInputStream(new File("D:/LKH/DerrickRose.txt"));	//�������ı�
		FileOutputStream  fos=new FileOutputStream(new File("src/file_processing/test1.txt"));	//�����ı�
		//�ļ�����
		int by;
		while((by=fis.read())!=-1) {
			fos.write(by);
		}
		fos.close();
		fis.close();
	}
}

