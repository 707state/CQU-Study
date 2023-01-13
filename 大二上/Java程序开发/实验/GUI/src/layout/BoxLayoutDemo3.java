/* ��������Ĭ�Ϻ��Ӳ���(Swing������µ�����)
 * 1.����һ��ˮƽ���������Box����hbox
 * 2.��hbox����Ӱ�ť�����ڶ����ť֮����ӷָ�
 * 3.����һ����ֱ���������Box����vbox
 * 4.��vbox����Ӱ�ť�����ڶ����ť֮����ӷָ�
 * 5.������Box������ӵ�Frame��չʾ
 */
package layout;
import javax.swing.*;
import java.awt.*;

public class BoxLayoutDemo3 {
	public static void main(String[] args) {
		Frame frame=new Frame("BoxLayout");
		
		Box hbox=Box.createHorizontalBox();
		hbox.add(new Button("hbutton1"));
		//�����˳������ң����hbutton1����������ӷָ������button2
		hbox.add(Box.createHorizontalGlue());
		//Box.createHorizontalGlue()�����ķָ���������������������
		hbox.add(new Button("hbutton2"));
		hbox.add(Box.createHorizontalStrut(30));
		//Box.createHorizontalStrut(30)�����ķָ�ָ����ȣ����ֻ���ڴ�ֱ����������
		hbox.add(new Button("hbutton3"));
		
		Box vbox=Box.createVerticalBox();
		vbox.add(new Button("vbutton1"));
		vbox.add(Box.createVerticalGlue());
		//Box.createVerticalGlue()�����ķָ���������������������
		vbox.add(new Button("vbutton2"));
		vbox.add(Box.createVerticalStrut(50));
		//Box.createVerticalStrut(30)�����ķָ�ָ���߶ȣ����ֻ����ˮƽ����������
		vbox.add(new Button("vbutton3"));
		
		frame.add(hbox,BorderLayout.NORTH);
		frame.add(vbox);
		
		frame.pack();
		frame.setVisible(true);
	}

}
