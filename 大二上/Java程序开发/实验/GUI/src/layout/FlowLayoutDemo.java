/* �����֣�
 * 1.ͨ��setLayout�������������Ĳ��ֹ�����
 * 2.��Ӷ����ť��frame��
 * 3.������Ѵ�С��pack() 
 */
package layout;
import java.awt.*;

public class FlowLayoutDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("FlowLayoutDemo");
		
		//frame.setLayout(new FlowLayout(FlowLayout.LEFT,20,20));
		frame.setLayout(new FlowLayout(FlowLayout.CENTER,20,20));
		for(int i=1;i<=100;i++) {
			frame.add(new Button("Button"+i));
		}
		frame.pack();		//������Ѵ�С
		
		frame.setVisible(true);
	}
}
