/* �α�P168 T5
 * ����һ������-1234567��������Ķ����ơ��˽��ƺ�ʮ�����Ʊ�ʾ��ʽ
 */
package exercise;

public class J13_Radix {
	public static void main(String[] args) {
		int num=-1234567;
		String sb=Integer.toString(num,2);			//������
		String usb=Integer.toBinaryString(num);		//��������
		String so=Integer.toString(num,8);
		String uso=Integer.toOctalString(num);
		String sh=Integer.toString(num,16);
		String ush=Integer.toHexString(num);
		System.out.println("�����ƣ�"+sb);
		System.out.println("�˽��ƣ�"+so);
		System.out.println("ʮ�����ƣ�"+sh);
		System.out.println("�޷��Ŷ����ƣ�"+usb);
		System.out.println("�޷��Ű˽��ƣ�"+uso);
		System.out.println("�޷���ʮ�����ƣ�"+ush);
	}
}
