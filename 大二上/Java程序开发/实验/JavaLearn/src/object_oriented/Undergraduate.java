/*�̳��Ը���Student*/
package object_oriented;

public class Undergraduate extends Student{
	public String Department;		//�������Ϊprivate�����޷���main���������
	public String Major;
	public Undergraduate(String school,String number,boolean sex,String birth,String name,int score,String department,String major) {
		super(school,number,sex,birth,name,score);
		this.Department=department;
		this.Major=major;
	}
	public void setDepartment(String department) {
		this.Department=department;
	}
	public void setName(String major) {
		this.Major=major;
	}
	
	public static void main(String[] args) {
		Student s1=new Student();
		Student s2=new Student("CQU","4165",true,"1125","lkh",98);
		//������ΪStudent s3������ʳ�Ա����ʱ�᷵�ظ���ĳ�Ա
		Undergraduate s3=new Undergraduate("CQU","4165",false,"0204","xql",99,"Computer","CS");
		System.out.println("s1.Birth:"+s1.Birth);
		System.out.println("s2.Number:"+s2.Number);
		System.out.println("s3.Major:"+s3.Major);
	}
}
