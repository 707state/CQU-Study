/*�α�P83 T3
  ��д������Complex��֤��������1+2i��3+4i��Ӳ���1���µĸ���4+6i��Ҫ�����£�
	1.������Complex��������:
	  RealPart:int��,��������ʵ������
	  ImaginPart:int�ͣ�����������������
	2.������Complex�ķ�����:
	  Complex():���캯������������ʵ�����鲿����0��
	  Complex(int r,int i):���캯��,�β�rΪʵ���ĳ�ֵ,iΪ�鲿�ĳ�ֵ��
	  Complex complexAdd(Complex a):����ǰ�����������βθ���������ӣ����õĽ������һ������ֵ,���ظ��˷����ĵ����ߡ�
  	  String ToString():�ѵ�ǰ���������ʵ�����鲿��ϳ�a+bi���ַ�����ʽ������a��b�ֱ�Ϊʵ�����鲿�����ݡ�
*/
package object_oriented;

public class Complex {
	int RealPart;
	int ImaginPart;
	public Complex(){
		this.RealPart=0;
		this.ImaginPart=0;
	}
	public Complex(int r,int i){
		this.RealPart=r;
		this.ImaginPart=i;
	}
	public void complexAdd(Complex a) {
		RealPart+=a.RealPart;
		ImaginPart+=a.ImaginPart;
	}
	String Tostring() {
		String s=RealPart+"+"+ImaginPart+"i";
		return s;
	}
	public static void main(String[] args) {
		Complex a=new Complex(5,2);
		Complex b=new Complex(3,1);
		a.complexAdd(b);
		System.out.println(a.Tostring());
	}

}
