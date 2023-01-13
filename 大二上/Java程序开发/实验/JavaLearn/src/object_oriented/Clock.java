/*�α�P83 T2
  ����һ��ʱ���ࣺ
	1.�洢ʱ�ӵ�ʱhour(0~23)����minute(0~ 59)����second(0~59)
	2.�����¶���ʱĬ��Ϊ0ʱ0��0�롣
	3.����ʱ��Ϊָ����ʱ��
	4.ʹʱ��ǰ��1���ӵķ���incSecond()��
	5.�ԡ�ʱ:��:�롱����ʽ���ʱ�ӵ�ʱ�䡣
 */
package object_oriented;

public class Clock {
	public int hour=0;
	public int minute=0;
	public int second=0;
	Clock(int h,int m,int s){
		this.hour=h;
		this.minute=m;
		this.second=s;
	}
	public void incSecond() {
		if(second<59) {
			second++;
		}
		else if(minute<59) {
			second=0;
			minute++;
		}
		else if(hour<23) {
			minute=0;
			hour++;
		}
		else {
			hour=0;
		}
	}
	public void PrintClock() {
		String ho=String.format("%02d",hour);
		String mi=String.format("%02d",minute);
		String se=String.format("%02d",second);
		System.out.printf("��ǰʱ�䣺"+ho+":"+mi+":"+se);
	}
	public static void main(String args[]) {
		Clock clock=new Clock(12,58,59);
		clock.incSecond();
		clock.PrintClock();
	}
}
