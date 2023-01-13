/* ��Ƭ���֣���ʱ����������ֻ������������(�������)�ɼ�
 * 1.����һ��Panel p1�������洢���ſ�Ƭ
 * 2.����CardLayout���󣬲����ö������ø�p1����
 * 3.��p1�����д洢������
 * 4.��p1�ŵ�Frame�м�����
 * 5.������һ��Panel p2�������洢�����ť
 * 6.����5����ť���
 * 7.����һ���¼���������������������ť�ĵ������
 * 8.����ǰ���¼��������Ͷ����ť��
 * 9.����ť��ӵ�p2��
 * 10.��p2�ŵ�Frame��
 */
package layout;
import java.awt.*;
import java.awt.event.*;

public class CardLayoutDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("CardLayout");
		
		Panel p1=new Panel();				//�洢���ſ�Ƭ
		CardLayout cardlayout=new CardLayout();
		p1.setLayout(cardlayout);
		String[] cards= {"1st","2nd","3rd","4th","5th"};
		//�����е��first��ʾ�Ľ�����"1st"�����޹أ�ֻ�����˳���й�
		for(int i=0;i<cards.length;i++) {
			p1.add(cards[i],new Button(cards[i]));	//��һ������Ϊ��������ڶ�������Ϊ���
		}
		//frame.add(p1,BorderLayout.NORTH);
		frame.add(p1);		//window����ȫ��Ĭ��BorderLayout���֣���д��һ������ռ��û��ʹ�õĲ���
		
		Panel p2=new Panel();				//�洢�����ť
		Button b1=new Button("previous");
		Button b2=new Button("next");
		Button b3=new Button("first");
		Button b4=new Button("last");
		Button b5=new Button("3rd");
		
		ActionListener listener=new ActionListener() {		//�¼�������������ÿ������
			@Override
			public void actionPerformed(ActionEvent e) {
				String actionCommand=e.getActionCommand();	//���ַ�����Ϊ��ť������
				switch(actionCommand) {
					case "previous":
						cardlayout.previous(p1);
						break;
					case "next":
						cardlayout.next(p1);
						break;
					case "first":
						cardlayout.first(p1);
						break;
					case "last":
						cardlayout.last(p1);
						break;
					case "3rd":
						cardlayout.show(p1,"3rd");
						break;
				}
			}
		};
		
		b1.addActionListener(listener);
		b2.addActionListener(listener);
		b3.addActionListener(listener);
		b4.addActionListener(listener);
		b5.addActionListener(listener);
		
		p2.add(b1);
		p2.add(b2);
		p2.add(b3);
		p2.add(b4);
		p2.add(b5);
		
		frame.add(p2,BorderLayout.SOUTH);
		
		frame.pack();
		frame.setVisible(true);
	}
}
