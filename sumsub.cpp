#include<iostream>
#include<vector>
using namespace std;
vector<int> a;	
int nsol=0,d;	
		
void with(vector<int> sub,int sr,int sc,int i);
void without(vector<int> sub,int sr,int sc,int i);
int sum(vector<int> sub);
int main()
{
    int n,i,val;	
    vector<int> sub;	
    cout<<"Enter the number of elements in the set:";
    cin>>n;
    cout<<"\nEnter the elements:";
    for(i=0;i<n;i++)
    {
        cin>>val;
        a.push_back(val);
    }
    cout<<"\nEnter the maximum sum of the subsets:";
    cin>>d;
    with(sub,sum(a),0,0);	
    without(sub,sum(a),0,0);  
    cout<<"\nTotal number of possible subsets: "<<nsol;
    return 0;
}

void with(vector<int> sub,int sr,int sc,int i)
{
    if(sr+sc<d || i>=a.size())
        return;
    int j;
    sr=sr-a[i];
    sc=sc+a[i];
    sub.push_back(a[i]);
    if(sum(sub)==d)
    {
        cout<<"\nSubset "<<++nsol<<":\n";
        for(j=0;j<sub.size();j++)
            cout<<sub[j]<<" ";
        return;
    }
    with(sub,sr,sc,i+1);	
    without(sub,sr,sc,i+1);  

}
void without(vector<int> sub,int sr,int sc,int i)
{
    if(sr+sc<d || i>=a.size())
        return;
    if(sc>d)
        return;
    int j;
    sr=sr-a[i];
    sc=sc+a[i];
    if(sum(sub)==d)
    {
        cout<<"\nSubset "<<++nsol<<":\n";
        for(j=0;j<sub.size();j++)
            cout<<sub[j]<<" ";
        return;
    }
    with(sub,sr,sc,i+1);	
    without(sub,sr,sc,i+1);	
}
int sum(vector<int> sub)	
{
    int sum=0,i;
    for(i=0;i<sub.size();i++)
        sum+=sub[i];
    return sum;
}

Output:

student@rvce-HP-280-G3-MT:~/irfan$ ./a.out
Enter the number of elements in the set:4

Enter the elements:3 5 6 7

Enter the maximum sum of the subsets:15

Subset 1:
3 5 7 
Total number of possible subsets: 1
student@rvce-HP-280-G3-MT:~/irfan$



