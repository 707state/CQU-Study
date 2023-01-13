/* �����������ڽ��棺
 * 1.�������ڶ��󣬲���ӹرռ�
 * 2.����һ��ScrollPane���󣨺���������������
 * 3.��ScrollPane���������
 * 4.��ScrollPane����Frame��
 * 5.ָ������λ�á���С
 * 6.���ô��ڶ���ɼ�
 * ע��������Frame������һ��ScrollPane����������������ScrollPane��������TextField��Button
 * 	  ScrollPane�޲ι���ʱĬ�ϷǱ�Ҫʱ�޹������������ݿ�������ʱ������ʾ�������������ݳ���windowʱ���Զ���ʾ������
 */
package container;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class ScrollPaneDemo {
	public static void main(String[] args) {
		Frame frame=new Frame("ScrollPaneDemo");
		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent arg0) {
				System.exit(0);
			}
		});
		
		//ScrollPane sp=new ScrollPane();		//�޲ι���Ĭ���޹�����
		ScrollPane sp=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);	//���ι���ָ����ʾ������
		sp.add(new TextField("TextField"));
		sp.add(new Button("Button"));
		frame.add(sp);
		
		frame.setBounds(100,50,500,300);
		frame.setVisible(true);

	}

}
