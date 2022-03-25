#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int longestConsecutive(vector<int>v){
	unordered_set<int>s;

	for(int i=0;i<v.size();i++){
		s.insert(v[i]);
	}

	int ans=0;

	for(auto i:s){
		int current=i;
		int len=1;
		if(s.find(current-1)==s.end()){
			while(s.find(current+1)!=s.end()){
				len++;
				current++;
			}
		}
		ans=max(ans,len);
	}

	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(auto &i:v){
		cin>>i;
	}
	cout<<longestConsecutive(v);
	return 0;
}