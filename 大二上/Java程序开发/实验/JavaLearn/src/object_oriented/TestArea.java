/*�α�P126 T3
 *�������½ӿڵ�����:
	pub1ic interface CalcArea{
		double getArea();
	}
1.����Բ��Cirele��ʵ�ֽӿ�CalcArea,Բ�����Ҫ��Ա����Ϊ�뾶�����췽���Ĳ������ڳ�ʼ���뾶��
2.���������Rectangle��ʵ�ֽӿ�CalcArea,���������Ҫ��Ա�����������Ϳ����췽���Ĳ������ڳ�ʼ����
  �Ϳ�
3.������TestArea,�书������洢��һ�������еĶ��ͼ�ε����֮�͡�
 */
package object_oriented;

interface CalcArea{
	double getArea();
}
class Circle implements CalcArea{
	private double r;
	private final static double PI=3.14;
	public Circle(double r) {
		this.r=r;
	}
	public double getArea() {
		return (PI*r*r);
	}
}
class Rectangle implements CalcArea{
	private double a;
	private double b;
	public Rectangle(double a,double b) {
		this.a=a;
		this.b=b;
	}
	public double getArea() {
		return (a*b);
	}
}

public class TestArea {
	//CalcArea shapes[]����static�ؼ����޷�����sumArea()����
	static CalcArea shapes[]= {new Circle(1.0),new Rectangle(3.0,4.0),new Circle(8.0)};
	public static void main(String args[]) {
		System.out.println("total area="+sumArea(shapes));
	}
	public static double sumArea(CalcArea[] shapes) {
		double areas=0;
		for(int i=0;i<shapes.length;i++) {
			areas+=shapes[i].getArea();
		}
		return areas;
	}
}
