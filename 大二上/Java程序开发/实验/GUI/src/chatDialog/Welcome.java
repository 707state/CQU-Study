package chatDialog;
import java.awt.*;

public class Welcome {
	public static void main(String[] args) {
		Panel p=new Panel();
		p.add(new Button("����"),BorderLayout.CENTER);
		Frame frame=new Frame("������");
		
		frame.add(new TextField("��ӭ����������"),BorderLayout.NORTH);
		ScrollPane sp=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);	//���ι���ָ����ʾ������
		sp.add(new TextArea(""));
		frame.add(sp);
		frame.add(p,BorderLayout.SOUTH);
		
		frame.setBounds(100,50,500,300);
		frame.setVisible(true);

	}

}
