/* ���ڽ��棺
 * 1.�������ڶ���
 * 2.ָ������λ�á���С
 * 3.���ô��ڶ���ɼ�
 * ע���˴������ɵĴ��ڽ���������졢��С������󻯣����޷������ֻ�����ն��ֶ�����
 */
package container;
import java.awt.*;
public class WindowDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("WindowDemo");
//		frame.setLocation(100,50);			//�˴���λΪ����
//		frame.setSize(500,300);
		frame.setBounds(100,50,500,300);	//����ȡ����������
		frame.setVisible(true);				//����������
	}

}
