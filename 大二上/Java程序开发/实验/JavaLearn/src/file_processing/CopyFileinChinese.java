/*��ͨFileIn/OutputStream�����ļ�����ʱĬ�ϱ��룬���������ļ���Java���������뷽ʽ��ͻʱ(������txt
 * �ļ�����ΪUTF-8��eclipse����ΪGBK)����ȡ�����Ļ��������
 * �Ľ����������ַ���ָ�������ȡ
 */
package file_processing;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;

public class CopyFileinChinese {
	public static void main(String[] args) throws IOException{
		File dir=new File("src/file_processing");
		File f3=new File(dir,"test3.txt");
		System.out.println(f3.createNewFile());
		String content="";			//�ı�����
		FileInputStream fis=new FileInputStream(new File("D:/LKH/DerrickRose2.txt"));
		FileOutputStream fos=new FileOutputStream(new File("src/file_processing/test3.txt"));
		InputStreamReader isr=new InputStreamReader(fis,"UTF-8");	//ָ������
		BufferedReader br=new BufferedReader(isr);
		String line=null;			//ÿ������
		while((line=br.readLine())!=null) {
			content+=line;
			content+="\r\n";
		}
		OutputStreamWriter osw=new OutputStreamWriter(fos,"GBK");
		osw.write(content);
		isr.close();
		osw.close();
		fos.close();
		fis.close();
	}
}
