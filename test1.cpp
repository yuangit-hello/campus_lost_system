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
 vector< queue<ll> > que(N);//N个队列
 map<ll,ll> mp;
 while(q--){
 	int a;
 	ll b;
 	cin>>a>>b;
 	int zu=(b/n)%N;//组号zu 
 	if(a==0){                        //读操作 
	if(mz(que[zu],b)){//命中 
 	tq(que[zu],b);//提前 
	 }else{//未命中 
	 	if(que[zu].size()<n){//有空
		  que[zu].push(b);
		  cout<<0<<" "<<b<<endl;//输出 
		 }else{//无空 
		 	if(mp.count(que[zu].front())){//被写
		 	cout<<1<<" "<<que[zu].front()<<endl;
		 	mp.erase(que[zu].front());
			que[zu].pop(); 
			que[zu].push(b);
			cout<<0<<" "<<b<<endl;
			 } else{//没有被写
			  que[zu].pop();
			  que[zu].push(b);
			  cout<<0<<" "<<b<<endl;
			 }
		 } 
	 } 
	 
	 }else{//写操作 
	 
	 if(mz(que[zu],b)){//命中 
 	tq(que[zu],b);//提前 
 	mp.insert({que[zu].back(),que[zu].back()});//记为写过 
 	//cout<<que[zu].back()<<b<<endl;
	 }else{//未命中 
	 	if(que[zu].size()<n){//有空
		  que[zu].push(b);
		  mp.insert({que[zu].back(),que[zu].back()});//记为写过 
		  //cout<<que[zu].back()<<b<<endl;
		  cout<<0<<" "<<b<<endl;//输出 
		 }else{//无空 
		 	if(mp.count(que[zu].front())){//被写
		 	cout<<1<<" "<<que[zu].front()<<endl;
		 	mp.erase(que[zu].front());
			que[zu].pop(); 
			cout<<0<<" "<<b<<endl;
			que[zu].push(b);
			mp.insert({que[zu].back(),que[zu].back()});//记为写过
			 } else{//没有被写

			  que[zu].pop();
			  cout<<0<<" "<<b<<endl;
			  que[zu].push(b);
			  mp.insert({que[zu].back(),que[zu].back()});//记为写过
			 }
		 } 
	 }                          
	 	
	 }
 } 
 cout << asdffeklf;
  // 请在此输入您的代码
  return 0;
}
