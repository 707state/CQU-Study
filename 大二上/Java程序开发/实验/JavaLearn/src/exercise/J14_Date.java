/*���ڼ���(�ư��)
����1 �����¸��µڶ������ڶ������ڣ���2021-10-14�����ĸ�ʽ��ʾ���Ȱѹ���д�ɺ��������������������á�
����2 �����ڵ�ʱ�任���������ձ���ʱ�䣬����ISO��ʽ��ʾ��
 */
package exercise;
import java.util.Date;
import java.util.Calendar;

public class J14_Date {
	public static void NextMonth2ndTue(Calendar c) {
		int CurrMonth=c.get(Calendar.MONTH);
		int NextMonth=(CurrMonth+1)%12;				//����12��
		while(c.get(Calendar.MONTH)!=NextMonth) {	//ѭ�������������������¸���
			c.add(Calendar.DATE,1);
		}
		c.add(Calendar.DATE,7);						//����ڶ���
		while(c.get(Calendar.DAY_OF_WEEK)!=3) {		//ѭ���������������ܶ���Calendar.DAY_OF_WEEK��Ϊ3��
			c.add(Calendar.DATE,1);
		}
		FormatPrint(c);
		CHNTime(c);			//�й�ʱ��
		USATime(c);			//����ʱ��
		JAPTime(c);			//�ձ�ʱ��
	}
	
	public static void FormatPrint(Calendar c) {	//��ʽ���������(�·ݴ�0��ʼ)
		System.out.print(c.get(Calendar.YEAR)+"-"+(c.get(Calendar.MONTH)+1)+"-");
		System.out.println(c.get(Calendar.DATE));
	}
	
	public static void CHNTime(Calendar c) {
		System.out.print(c.get(Calendar.YEAR)+"-"+(c.get(Calendar.MONTH)+1)+"-");
		System.out.print(c.get(Calendar.DATE)+" T ");
		System.out.print(c.get(Calendar.HOUR_OF_DAY)+":");
		System.out.print(c.get(Calendar.MINUTE)+":"+c.get(Calendar.SECOND));
		System.out.println(" +08");
	}
	public static void USATime(Calendar c) {
		c.add(Calendar.HOUR_OF_DAY,-13);			//�й���������13h���Ӹ�������
		System.out.print(c.get(Calendar.YEAR)+"-"+(c.get(Calendar.MONTH)+1)+"-");
		System.out.print(c.get(Calendar.DATE)+" T ");
		System.out.print(c.get(Calendar.HOUR_OF_DAY)+":");
		System.out.print(c.get(Calendar.MINUTE)+":"+c.get(Calendar.SECOND));
		System.out.println(" -05");
	}
	public static void JAPTime(Calendar c) {
		c.add(Calendar.HOUR_OF_DAY,1);
		System.out.print(c.get(Calendar.YEAR)+"-"+(c.get(Calendar.MONTH)+1)+"-");
		System.out.print(c.get(Calendar.DATE)+" T ");
		System.out.print(c.get(Calendar.HOUR_OF_DAY)+":");
		System.out.print(c.get(Calendar.MINUTE)+":"+c.get(Calendar.SECOND));
		System.out.println(" +09");
	}
	
	public static void main(String[] args) {
		Calendar c1=Calendar.getInstance();
		NextMonth2ndTue(c1);
	}

}
