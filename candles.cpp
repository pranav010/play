#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int cnt[10],minm=INT_MAX,pos = -1;
	    for(int i=0;i<10;i++){
	        cin>>cnt[i];
	        if(cnt[i]<minm){
	            minm=cnt[i];
	            pos = i;
	        }
	    }
	    int i=-1;
	    if(pos==0)
	    {
	        
	        for(i=1;i<10;i++)
	        {
	            if(cnt[i]==minm)
	            {
	                pos=i;
	                i=-1;
	                break;
	            }
	        }
	        if(i==10)
	        cout<<"1";

	    }
	   cnt[pos]++;
	   while((cnt[pos]--))cout<<pos;
	   cout<<endl;
	   
	}
	return 0;
}
