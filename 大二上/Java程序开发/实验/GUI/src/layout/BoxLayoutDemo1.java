/* ���Ӳ��֣���ˮƽ����ֱ���������ϰڷ����(Swing������µĲ��ֹ�����)
 * 1.����BoxLayout���󣬸ö���������Ǵ�ֱ���
 * 2.��BoxLayout�������ø�Frame
 * 3.��Frame�����������ť���
 */
package layout;
import javax.swing.*;
import java.awt.*;

public class BoxLayoutDemo1 {
	public static void main(String[] args) {
		Frame frame=new Frame("BoxLayout");
		
		//BoxLayout boxlayout=new BoxLayout(frame,BoxLayout.Y_AXIS);	//���򲼾�
		BoxLayout boxlayout=new BoxLayout(frame,BoxLayout.X_AXIS);		//���򲼾�
		frame.setLayout(boxlayout);
		frame.add(new Button("Button1"));
		frame.add(new Button("Button2"));
		
		frame.pack();
		frame.setVisible(true);
	}

}
