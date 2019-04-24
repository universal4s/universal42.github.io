/******************************************
    > File Name: source/test.cpp
    > Author: universal42
    > Mail: universal42@163.com 
    > Created Time: 2019年04月24日 星期三 12时19分52秒
 ******************************************/

#include<bits/stdc++.h>
#define ll long long int
#define inf 0x3f3f3f3f
#define LOCAL
using namespace std;
const int maxn=1e5+5;

struct trie{
	trie* next[26];
	int num;
	trie(){

		for(int i=0;i<26;i++){
			next[i]=NULL;
		}
		num = 0;
	}
}root;
void _insert(char *s){
	trie *p = &root;
	for(int i=0;s[i]!='\0';i++)
	{
		if(p->next[s[i]-'a']==NULL)
			p->next[s[i]-'a']=new trie;
		p=p->next[s[i]-'a'];
		p->num++;
	}
}
int find(char *s){
	trie *p=&root;
	for(int i=0;s[i]!='\0';i++)
		if(p->next[s[i]-'a']==NULL)
			return 0;
		else p=p->next[s[i]-'a'];
	return p->num;
}
void solve(){
	char s[5][20];
	char ans[20];
	for(int i=0;i<3;i++){
		scanf("%s",s[i]);
		_insert(s[i]);
	}
	scanf("%s",ans);
	printf("%d",find(ans));
}
int main(){
#ifdef LOCAL
   // freopen(":in.in","r",stdin);
#endif
    solve();
    return 0;
}
