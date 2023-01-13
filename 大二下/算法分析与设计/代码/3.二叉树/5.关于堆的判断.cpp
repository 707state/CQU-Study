/*���ڶѵ��жϣ�
��Ŀ����һϵ�и�������˳�����һ����ʼΪ�յ�С����H[]������ж�һϵ����������Ƿ�Ϊ�档
	��������м��֣�
	1.x is the root��x�Ǹ���㣻
	2.x and y are siblings��x��y���ֵܽ�㣻
	3.x is the parent of y��x��y�ĸ���㣻
	4.x is a child of y��x��y��һ���ӽ�㡣
���룺ÿ����Ե�1�а���2��������N���� 1000����M���� 20�����ֱ��ǲ���Ԫ�صĸ������Լ���Ҫ�жϵ�
	����������һ�и�������[-10000,10000]�ڵ�N��Ҫ������һ����ʼΪ�յ�С���ѵ�������֮��M�У�
	ÿ�и���һ�����⡣��Ŀ��֤�����еĽ���ֵ���Ǵ��ڵġ�
������������ÿ�����⣬�����Ϊ�棬����һ�������T���������F��

link�����������ǳ����һ�����κ��ӽڵ��⣬����ÿһ���ϵ����н�㶼�������ӽ�㡣
	����k�㹲��2**k-1����Ҷ��
	  ��ȫ�������������Ϊh��������h���⣬��������Ľ�������ﵽ���������ҵ�h�����еĽ�㶼
	��������������ߡ�
	  �ѿ��Ա�����һ����ȫ����������������ȫ�������Ľṹ��ά����һά���顣
	  �󶥶ѣ�ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ��arr[i]>=arr[2i+1]&&arr[i]>=arr[2i+2]��
	  С���ѣ�ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ��arr[i]<=arr[2i+1]&&arr[i]<=arr[2i+2]��
	����arr[2i+1]����ڵ� arr[2i+2]���ҽڵ�
*/
#include <iostream>
using namespace std;

int a[1002];
int n,m;

int find(int x){					//�ҵ��ڵ�λ�ã��������±�
	for (int i=1;i<=n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return 0;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
//����С���ѵĹ��̣���������˳��Ԫ�������룬����������С�ڵ����������ӽ�㣬�򽻻�
		cin>>a[i];
		int k=i;
		while(k>1 && a[k]<a[k/2]){		//��������arr[i]<=arr[2i+1]&&arr[i]<=arr[2i+2]
			swap(a[k],a[k/2]);
			k/=2;
		}
	}
	for(int j=0;j<m;j++){
		int x;
		cin>>x;
		string s;
		cin>>s;
		if(s=="is"){
			string ss;
			cin>>ss;
			if(ss=="the"){
				string sss;
				cin>>sss;
				if(sss=="root"){
					if(a[1]==x){
						cout<<"T"<<endl;		//a[1]���Ǹ��������ǲ������
					}
					else{
						cout<<"F"<<endl;
					}
				}
				else{
					string s1;
					int xx;
					cin>>s1>>xx;
					if(find(x)==find(xx)/2){	//���׵��±���ڶ��ӵ��±���Զ�
						cout<<"T"<<endl;
					}
					else{
						cout<<"F"<<endl;
					}
				}
			}
			else if(ss=="a"){
				string s1,s2;
				int xx;
				cin>>s1>>s2>>xx;
				if(find(x)/2==find(xx)){		//���ӵ��±���Զ����ڸ��׵��±�
					cout<<"T"<<endl;
				}
				else{
					cout<<"F"<<endl;
				}
			}
		}
		else if(s=="and"){
			int xx;
			string s1,s2;
			cin>>xx>>s1>>s2;
//���׵��±���ڶ��ӵ��±������Զ��������������ӵĸ����Ƿ���ȣ����ж��������ǲ���siblings
			if(find(x)/2==find(xx)/2){
				cout<<"T"<<endl;
			}
			else{
				cout<<"F"<<endl;
			}
		}
	}
	return 0;
} 