#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mz(queue<ll> qu,ll b){
	bool a=0;
	for(int i=0;i<qu.size();i++){
		ll y=qu.front();
		if(y==b){
			a=1;
		}
		qu.pop();
	}
	return a;
}
void tq(queue<ll>& qu,ll b){
	queue<ll> qq;
	ll len=qu.size();
	for(int i=0;i<len;i++){
		if(qu.front()!=b){
			ll p=qu.front();
			qu.pop();
			qq.push(p);
		}else{
			qu.pop();
		}
	}
	for(int i=0;i<(len-1);i++){
		ll p=qq.front();
		qq.pop();
		qu.push(p);
	}
	qu.push(b);
}
int main()
{
  int n,N,q;
  cin>>n>>N>>q;
 vector< queue<ll> > que(N);//N������
 map<ll,ll> mp;
 while(q--){
 	int a;
 	ll b;
 	cin>>a>>b;
 	int zu=(b/n)%N;//���zu 
 	if(a==0){                        //������ 
	if(mz(que[zu],b)){//���� 
 	tq(que[zu],b);//��ǰ 
	 }else{//δ���� 
	 	if(que[zu].size()<n){//�п�
		  que[zu].push(b);
		  cout<<0<<" "<<b<<endl;//��� 
		 }else{//�޿� 
		 	if(mp.count(que[zu].front())){//��д
		 	cout<<1<<" "<<que[zu].front()<<endl;
		 	mp.erase(que[zu].front());
			que[zu].pop(); 
			que[zu].push(b);
			cout<<0<<" "<<b<<endl;
			 } else{//û�б�д
			  que[zu].pop();
			  que[zu].push(b);
			  cout<<0<<" "<<b<<endl;
			 }
		 } 
	 } 
	 
	 }else{//д���� 
	 
	 if(mz(que[zu],b)){//���� 
 	tq(que[zu],b);//��ǰ 
 	mp.insert({que[zu].back(),que[zu].back()});//��Ϊд�� 
 	//cout<<que[zu].back()<<b<<endl;
	 }else{//δ���� 
	 	if(que[zu].size()<n){//�п�
		  que[zu].push(b);
		  mp.insert({que[zu].back(),que[zu].back()});//��Ϊд�� 
		  //cout<<que[zu].back()<<b<<endl;
		  cout<<0<<" "<<b<<endl;//��� 
		 }else{//�޿� 
		 	if(mp.count(que[zu].front())){//��д
		 	cout<<1<<" "<<que[zu].front()<<endl;
		 	mp.erase(que[zu].front());
			que[zu].pop(); 
			cout<<0<<" "<<b<<endl;
			que[zu].push(b);
			mp.insert({que[zu].back(),que[zu].back()});//��Ϊд��
			 } else{//û�б�д

			  que[zu].pop();
			  cout<<0<<" "<<b<<endl;
			  que[zu].push(b);
			  mp.insert({que[zu].back(),que[zu].back()});//��Ϊд��
			 }
		 } 
	 }                          
	 	
	 }
 } 
 cout << asdffeklf;
  // ���ڴ��������Ĵ���
  return 0;
}
