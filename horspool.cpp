#include<iostream>
#include<cstring>
#define max 40
using namespace std;

char* shiftTable(char [],char []);
int search(char [],char []);

int main(){
	char string[max],pattern[max];
	cout<<"enter the string: ";
	cin>>string;
	cout<<"enter the pattern to be searched: ";
	cin>>pattern;
	cout<<string<<" "<<pattern<<endl;
	int pos = search(string,pattern);	
	//cout<<(int)(string[2] - 'a');
	//int pos = 1;
	if(pos != -1){
		cout<<"patern found, starts at position: "<<pos+1<<endl;
	}
	else
		cout<<"the given string dose'nt contain pattern ";
	return 0;
}

int search(char string[],char pattern[]){
	char table[26];
	shiftTable(pattern,table);
	int m=strlen(pattern),n=strlen(string),i = m-1,k;
	while(i <= n-1){
		k=0;
		while(k <= m-1 && pattern[m-1-k] == string[i-k])
			k++;
		if(k==m)
			return i-m+1;
		else{
			int l =(int)(string[i] - 'a');
			i = i + table[l];
		}
	}
	return -1;
}

char* shiftTable(char pattern[],char table[]){
	int m = strlen(pattern),k=1,l;
	cout<<pattern[m-1]<<" ,";
	for(int i=0;i<26;i++){
		table[i] = m;
	}
	for(int j=0;j<=m-2;j++){
		l=(int)(pattern[j] - 'a');
		table[l] = m-1-j;
	}
	return table;
}   

/*output

enter the string: jim_saw_me
enter the pattern to be searched: saw
jim_saw_me saw
w ,patern found, starts at position: 5

enter the string: jim_saw_me_at_barber
enter the pattern to be searched: at
jim_saw_me_at_barber at
t ,patern found, starts at position: 12
*/

