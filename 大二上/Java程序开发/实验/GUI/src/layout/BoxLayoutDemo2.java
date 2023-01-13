/* ��������Ĭ�Ϻ��Ӳ���(Swing������µ�����)
 * 1.����һ��ˮƽ���������Box����
 * 2.�ڵ�ǰ���������������ť
 * 3.����һ����ֱ���������Box����
 * 4.�ڵ�ǰ���������������ť
 * 5.������Box������ӵ�Frame��չʾ
 */
package layout;
import javax.swing.*;
import java.awt.*;

public class BoxLayoutDemo2 {
	public static void main(String[] args) {
		Frame frame=new Frame("BoxLayout");
		
		//Box�����������
		Box hbox=Box.createHorizontalBox();
		hbox.add(new Button("hbutton1"));
		hbox.add(new Button("hbutton2"));
		
		Box vbox=Box.createVerticalBox();
		vbox.add(new Button("vbutton1"));
		vbox.add(new Button("vbutton2"));
		
		frame.add(hbox,BorderLayout.NORTH);
		frame.add(vbox);
		
		frame.pack();
		frame.setVisible(true);
	}

}
