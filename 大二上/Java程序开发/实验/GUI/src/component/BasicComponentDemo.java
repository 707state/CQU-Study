/* ���Ի�������а������ı���(TextArea)������ѡ���(Choice)������ѡ��(Checkbox+CheckBoxGroup)��
 * �����ı���(TextField)����ť(Button)���б��(List)�Ȼ��������
 */
package component;
import java.awt.*;

import javax.swing.Box;

public class BasicComponentDemo {
	Frame frame=new Frame("BasicComponent");
	
	TextArea ta=new TextArea(5,20);		//5��20�е��ı���
	
	Choice colorChooser=new Choice();	//����ѡ���
//	colorChooser.add("red");
//	colorChooser.add("blue");
//	colorChooser.add("green");			//�����ں����в��ܶԶ�����в�����������ֻ�ܶ������
	
	
	CheckboxGroup cbg=new CheckboxGroup();				//���ɵ�ѡ��ĸ�ѡ��(ֻ����ѡ������һ��ѡ��)
	Checkbox male=new Checkbox("male",cbg,true);		//��ѡ��ѡ��
	Checkbox female=new Checkbox("female",cbg,false);	//ûѡ��
	
	Checkbox Marriage=new Checkbox("Married");			//��ѡ��
	
	TextField tf=new TextField(50);		//50�еĵ����ı���
	Button ok=new Button("ok");
	
	List colorlist=new List(6);			//�б��Ĭ�ϵڶ�������Ϊfalse��ʾ��ѡ
	//List colorlist=new List(6,true);	//��ѡ
	
	public void init() {				//��װ������в���
		//��װ�²���
		Box bottom=Box.createHorizontalBox();
		bottom.add(tf);
		bottom.add(ok);
		frame.add(bottom,BorderLayout.SOUTH);
		
		//��װ���²���
		Box leftbottom=Box.createHorizontalBox();
		colorChooser.add("red");
		colorChooser.add("blue");
		colorChooser.add("green");
		leftbottom.add(colorChooser);
		leftbottom.add(male);
		leftbottom.add(female);
		leftbottom.add(Marriage);
		
		//��װ���������ϲ���
		Box topleft=Box.createVerticalBox();
		topleft.add(ta);
		topleft.add(leftbottom);
		
		//��װ����������
		Box top=Box.createHorizontalBox();
		colorlist.add("red");
		colorlist.add("blue");
		colorlist.add("green");
		top.add(topleft);
		top.add(colorlist);
		
		frame.add(top);
		frame.pack();
		frame.setVisible(true);
	}
	
	public static void main(String[] args) {
		new BasicComponentDemo().init();

	}

}
