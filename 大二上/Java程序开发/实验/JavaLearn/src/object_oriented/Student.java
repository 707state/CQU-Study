/* �α�P125 T2
  	��дһ����Student,����ӵ������:У����ѧ�š��Ա𡢳������ڡ������������������ͳɼ�(setName(),
  	setScore()),�ٱ�дStudent�������Undergraduate(��ѧ��)��Undergraduate���ӵ�и����
  	�������Ժͷ����⣬��ӵ�и��ӵ����Ժͷ���:���԰���ϵ(department)��רҵ(major);������������ϵ��
  	��רҵ(setDepartment(),setMajor())��
  	ע����public�������ֻ�ܽ���д�ڲ�ͬ��class�ļ���
 */
package object_oriented;

public class Student{
	protected String School;
	protected String Number;
	protected boolean Sex;		//�Ա�sex��trueΪ�У�falseΪŮ
	protected String Birth;
	protected String Name;
	protected int Score;
	public Student() {}			//�޲ι��캯��������ֵ������¶���Ϊ�������͵�Ĭ��ֵ
	
	public Student(String school,String number,boolean sex,String birth,String name,int score) {
		this.School=school;
		this.Number=number;
		this.Sex=sex;
		this.Birth=birth;
		this.Name=name;
		this.Score=score;
	}
	public void setName(String name) {
		this.Name=name;
	}
	public void setScore(int score) {
		this.Score=score;
	}
}