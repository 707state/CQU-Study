package chatDialog;

import java.awt.*;

public class Login {
	public static void main(String[] args) {
		Frame frame=new Frame("�����ҵ�¼����");
		
		Panel p1=new Panel();
		p1.add(new Button("��¼"),BorderLayout.CENTER);
		Panel p2=new Panel();
		p2.add(new Button("ע��"),BorderLayout.CENTER);
		Panel p3=new Panel();
		p3.add(p1);
		p3.add(p2);
		frame.add(p3,BorderLayout.SOUTH);
		
		Panel p4=new Panel();
		p4.add(new Button("�û���"),BorderLayout.WEST);
		p4.add(new TextField("�������û���"));
		Panel p5=new Panel();
		p5.add(new Button("����"),BorderLayout.WEST);
		p5.add(new TextField("����������"));
		Panel p6=new Panel();
		p6.add(p4,BorderLayout.NORTH);
		p6.add(p5,BorderLayout.SOUTH);
		frame.add(p6,BorderLayout.CENTER);
		
		frame.add(new TextField("                                   ��½����"),BorderLayout.NORTH);
//		ScrollPane sp=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);	//���ι���ָ����ʾ������
//		sp.add(new TextArea(""));
//		frame.add(sp);
		//frame.add(p3,BorderLayout.SOUTH);
		
		frame.setBounds(100,50,500,300);
		frame.setVisible(true);

	}
}
