/*����һ��·�����ݹ������Ŀ¼���������� */
package file_processing;
import java.io.File;

public class TraverseDirectory {

	public static void main(String[] args) {
		File scrfile=new File("D:\\JAVA\\eclipse-workspace\\JavaLearn\\src\\file_processing");
		getAllFilePath(scrfile);
	}
	public static void getAllFilePath(File scrfile) {
		File[] fileArray=scrfile.listFiles();
		if(fileArray!=null) {
			for(File file:fileArray) {
				if(file.isDirectory()) {
					getAllFilePath(file);		//�ݹ����
				}
				else {
					System.out.println(file.getAbsolutePath());
				}
			}
		}
	}
}
