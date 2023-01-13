/*����java�ļ�
 *Ϊ��ʹ��InputStreamReader��OutputStreamWriter������෽ʽ������P206 FileReader��FileWriter
 */
package file_processing;
import java.io.*;

/*��Ϊ������ֱ�Ӹ��ƹ����ģ����������ͬ�������������ļ������Ǻϡ��˴���Ϊ��������*/
//public class CopyDemo {
public class CopiedDemo {
	public static void main(String[] args) throws IOException{
		InputStreamReader isr=new InputStreamReader(new FileInputStream("src/file_processing/CopyDemo.java"));
		OutputStreamWriter osw=new OutputStreamWriter(new FileOutputStream("src/file_processing/CopiedDemo.java"));
		int ch;
		while((ch=isr.read())!=-1) {
			osw.write(ch);
		}
		osw.close();
		isr.close();
	}
}
