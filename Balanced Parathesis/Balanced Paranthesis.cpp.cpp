#include<iostream>
#include<stack>
using namespace std;
int main() {

    string s;
    
    stack<char> st;

    cin>>s;

    bool check = 0;

    for(int i=0;i<s.length();i++){

	if(s[i]=='('||s[i]=='['||s[i]=='{')
	   st.push(s[i]);

	else{

	   if(!st.empty()){
			  
	     if(s[i]==')'&& st.top()=='(')
			 st.pop();

	     else if(s[i]==']'&& st.top()=='[')
			 st.pop();

	     else if(s[i]=='}'&&st.top()=='{')
			st.pop();

             else
		break;
			
	      }

	   else{
		check = 1;
		break;
	      }
			 
	}
    }

	if(st.empty()&&check==0)
	 cout<<"YES";
	 else
	 cout<<"NO";



	return 0;
}