/* ���ڽ�����Ƕ��ť���ı���
 * 1.�������ڶ�������������������window���ڣ����ܵ���ʹ�ã�
 * 2.����һ��Panel������Ƕ������
 * 3.����һ���ı���TextField��һ����ťButton�����������Panel������
 * 4.��Panel����Window��
 * 5.ָ������λ�á���С
 * 6.���ô��ڶ���ɼ�
 * ע��������Frame��������������һ��Panel��Ƕ��������Panel����������ͨ���TextField�ı����Button��ť
 */
package container;
import java.awt.*;

public class PanelDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("panel on window");
		
		Panel p=new Panel();
		p.add(new TextField("TextField"));
		p.add(new Button("Button"));
		frame.add(p);
		
		frame.setBounds(100,50,500,300);
		frame.setVisible(true);

	}

}
