/*��Ŀ����дð�������㷨
1 ���㷨д�ɺ����������ź��������
2 ��д��һ����������30��50��������ȷ�����������ÿһ������0��100֮�䣬���ش�����
2 ��main������
   ������������ɺ���
   ����������
   ��ӡ�ź��������ÿ��10��������֮�����Ʊ��������
 */
package exercise;
import java.util.*;

public class J11_BubbleSort {
	public static int[] ProRan() {
		int len=new Random().nextInt(20)+30;	//����30��50����������Ϊ���鳤��
		int res[]=new int[len];
		for(int i=0;i<len;i++) {
			int tmp=new Random().nextInt(100);
			res[i]=tmp;
		}
		return res;
	}
	public static int[] BubbleSort(int[] a) {
		for(int i=0;i<a.length-1;i++) {
			for(int j=0;j<a.length-1-i;j++) {
				if(a[j]>a[j+1]) {
					int tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
				}
			}
		}
		return a;
	}
	public static void main(String[] args) {
		int a[]=ProRan();					//aΪ�����������
		int b[]=BubbleSort(a);				//bΪ�ź��������
		for(int i=0;i<b.length;i++) {
			if(i!=0 && i%10==0) {
				System.out.println();
			}
			System.out.print(b[i]+"\t");
		}
	}

}
