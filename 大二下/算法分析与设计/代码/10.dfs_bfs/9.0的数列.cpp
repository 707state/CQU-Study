/*������Ϊ0�����У�
��Ŀ���������У�1 2 3 ... N������������֮��������+��-��ո����С�+����ʾ�ӣ���-����ʾ����
	�ո�' '��ʾ��ϳɶ�λ���������硰2+3  4+5  6-7����ʾ��2+34+56-7����
	�ҳ����м�����Ϊ0�ĳ���Ϊ N �����С�
˼·������˳��̶�����û�����ţ����ֱ�����Ѽ���
*/
#include<iostream>
using namespace std;

int n,num;
char c0[50];
char c[3]= {' ','+','-'};

void dfs(int step) {
	if(step==n) {
		int sum=1,t=0;
		for(int i=1;i<=n-1;i++) {
			if(c0[i]==' '&&i==1) {
				t=1;
				while(c0[i]==' '&&i<=n-1){
					t*=10;
					t+=i+1;
					i++;
				}
 
				sum=t;
				i--;
				t=0;
				continue;
			}
			if(c0[i]=='+'&&c0[i+1]!=' ')
				sum+=i+1;
			else if(c0[i]=='-'&&c0[i+1]!=' ')
				sum-=(i+1);
			else if((c0[i]=='-'||c0[i]=='+')&&c0[i+1]==' ') {
				char s=c0[i++];
				while(c0[i]==' '&&i<=n-1) {
					t*=10;
					t+=i;
					i++;
				}
				t*=10;
				t+=i;
				if(s=='+')
					sum+=t;
				else
					sum-=t;
				i--;
				t=0;
			}
		}
		if(sum==0) {
			num++;
			for(int i=1; i<=n-1; i++)
				printf("%d%c",i,c0[i]);
			printf("%d\n",n);
		}
		return ;
	}
 
	for(int i=0;i<3;i++){
		c0[step]=c[i];
		dfs(step+1);
	}
 
 
}
int main() {
	cin>>n;
	for(int i=1;i<=n+2;i++){
		c0[i]='+';
	}
	dfs(1);

	return 0;
}