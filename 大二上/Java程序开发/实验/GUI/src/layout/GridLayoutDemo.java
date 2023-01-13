/* ���񲼾֣��������ָ���ݺ��߷ָ������ÿ�������С��ͬ��������ʱĬ�ϴ����ҡ����ϵ�����ÿ������Զ��������������
 * ������GridLayout����һ��������ҳ��
 * 1.����Panel1������TextField���
 * 2.��Panel1������ӵ�Frame��NORTH����PanelĬ��FlowLayout���֣�
 * 3.����Panel2�������ò��ֹ�����ΪGridLayout
 * 4.��Panel2���������
 * 5.��Panel2��ӵ�Frame��
 */
package layout;

import java.awt.*;

public class GridLayoutDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("Calculator");
		
		Panel p1=new Panel();
		p1.add(new TextField(30));
		frame.add(p1,BorderLayout.NORTH);
		
		Panel p2=new Panel();
		//p2.setLayout(new GridLayout(3,5,4,4));	//�汾��֧��
		
		for(int i=0;i<10;i++) {
			p2.add(new Button(i+""));	//i+""��intת��ΪString
		}
		p2.add(new Button("+"));
		p2.add(new Button("-"));
		p2.add(new Button("*"));
		p2.add(new Button("/"));
		p2.add(new Button("."));
		frame.add(p2);
		
		frame.pack();
		frame.setVisible(true);
	}

}
