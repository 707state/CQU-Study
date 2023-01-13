/*��ָ��·��������ɾ���ļ�/�ļ��в����ļ������ݽ������� */
package file_processing;
import java.io.File;
import java.io.IOException;
import java.io.FileFilter;
import java.io.FilenameFilter;

public class FileConstructor {
	public static void main(String[] args) throws IOException{
		File f_dir=new File("D:/LKH","new_dir");			//ֻ���ڱ���ָ��·�������ļ�
		File f1=new File("D:/LKH/new_dir","test1.txt");
		File f2=new File("D:/LKH/new_dir","test2.txt");
		File f_dir2=new File("D:/LKH/new_dir","subdir");
		File f_dir4=new File("D:/LKH/new_dir3","subdir");
		f_dir.mkdir();
		f1.createNewFile();
		f2.createNewFile();
		f_dir2.mkdir();
		f_dir4.mkdirs();		//�����༶Ŀ¼
		System.out.println("�г�Ŀ¼"+f_dir+"�е����ļ��У�");
		DirFilter filter1=new DirFilter();
		File fs1[]=f_dir.listFiles(filter1);
		display(fs1);
		System.out.println("�г�Ŀ¼"+f_dir+"�е�txt�ļ���");
		Filter filter2=new Filter("txt");
		File fs2[]=f_dir.listFiles(filter2);
		display(fs2);
		f2.delete();
	}
	public static void display(File[] fs) {
		for(int i=0;i<fs.length;i++) {
			if(fs[i].isDirectory()) {
				System.out.println("Ŀ¼��"+fs[i]);
			}
			else {
				System.out.println("�ļ���"+fs[i]);
			}
		}
	}

}
class Filter implements FilenameFilter{				//�Զ�����������������խ
	String extent;
	Filter(String extent){
		this.extent=extent;
	}
	public boolean accept(File dir,String name) {
		return name.endsWith("."+extent);
	}
}
class DirFilter implements FileFilter{
	public boolean accept(File path) {
		return path.isDirectory();
	}
}
