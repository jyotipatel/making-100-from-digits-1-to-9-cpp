#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define print(a) printf("%d",a)
#define printl(a) printf("%lld",a)
#define fin(i,j,n) for(int i=j;i<n;i++)
#define f0n(i,n) fin(i,0,n)
#define MAX 100000
#define mod 10
using namespace std;

typedef pair<int,int>pii;
typedef long long LL;

bool cmp(const pii &left,const pii &right)
{
	return left.second<right.second;
}
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
		return gcd(b,a%b);
}
vector<string>v;
string findCombo(int input[],string combo,int requiredsum,int startindex,int lastnumber,int cursum)
{
	if(startindex==9) //to checkout all the combinations
	{
		//cout<<combo<<endl;
		//return combo;
	}
	if(startindex==9&&cursum==requiredsum) //if valid solution- store it in vector v
	{
		v.pb(combo);
		return "";
	}
	if(startindex==9&&cursum!=requiredsum) //if invalid solution i.e. all digits used but the sum is not 100 -the return empty
	{
		combo="";
		return combo;
	}
	// checkout the plus sign i.e add the next indexed number
	string result=findCombo(input,combo+'+'+char(input[startindex]+48),requiredsum,startindex+1,input[startindex],cursum+input[startindex]); 
	//cout<<result<<endl;
	if(result.length()>0)
	{
		return result;
	}
	//check for minus sign i.e subtract the next indexed number
	result=findCombo(input,combo+'-'+char(input[startindex]+48),requiredsum,startindex+1,-input[startindex],cursum-input[startindex]);
	if(result.length()>0)
	{
		return result;
	}
	//combine the digits if both plus and minus are checked out
	if(startindex>0)
	{
		//check if the last added number was put with minus sign or plus 
		if(lastnumber>0)
		{
			int newsum=cursum-lastnumber; //subtract the lastnumber added from current sum
			int newlastnumber=10*lastnumber+input[startindex]; //combine the last number and current number
			newsum+=newlastnumber;				//add the combined number to the current sum
			result=findCombo(input,combo+char(input[startindex]+48),requiredsum,startindex+1,newlastnumber,newsum); //recurse with this number for next digits left
			if(result.length()>0)
			{
				return result;
			}
		}
		else if(lastnumber<0)
		{
			int newlastnumber=abs(lastnumber); 
			int newsum=cursum+lastnumber;
			newlastnumber=newlastnumber*10+input[startindex];
			newsum-=newlastnumber;
			result=findCombo(input,combo+char(input[startindex]+48),requiredsum,startindex+1,-newlastnumber,newsum);
			if(result.length()>0)
			{
				return result;
			}
			
		}
	}
	combo="";
	return combo;
}
int main()
{
	int in[9]={1,2,3,4,5,6,7,8,9};
	string combo="1";
	int sum=100;
	
	combo=findCombo(in,combo,sum,1,in[0],in[0]);//(input array,combination,required sum,startindex,lastnumber, current sum)
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
}
