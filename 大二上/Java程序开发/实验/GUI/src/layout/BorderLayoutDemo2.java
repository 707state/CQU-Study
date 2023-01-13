/* �߿򲼾֣�
 * 1.ͨ��setLayout�������������Ĳ��ֹ�����
 * 2.��frameָ������������
 * 3.������Ѵ�С��pack() 
 */
package layout;
import java.awt.*;

public class BorderLayoutDemo2 {
	public static void main(String[] args) {
		Frame frame=new Frame("FlowLayoutDemo");
		
		frame.setLayout(new BorderLayout(30,10));
		frame.add(new Button("North"),BorderLayout.NORTH);
		frame.add(new Button("South"),BorderLayout.SOUTH);
		frame.add(new Button("Center"),BorderLayout.CENTER);
//		frame.add(new Button("East"),BorderLayout.EAST);
//		frame.add(new Button("West"),BorderLayout.WEST);	//û�д����Ĳ�λ�ᱻ����
		Panel p=new Panel();
		p.add(new Button("Center Button"));
		p.add(new TextField("TextField"));
		frame.add(p);
		
		frame.pack();
		frame.setVisible(true);

	}

}
