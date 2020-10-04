#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);

//void
int N;
int arr[110][110];
int arr2[110][110];
int ans;
int printMaxSubSquare(int M[110][110])  
{  
    int R=N;
    int C=N;
    int i,j;  
    int S[110][110];  
    int max_of_s, max_i, max_j;  
      
    /* Set first column of S[][]*/
    for(i = 0; i < R; i++)  
        S[i][0] = M[i][0];  
      
    /* Set first row of S[][]*/
    for(j = 0; j < C; j++)  
        S[0][j] = M[0][j];  
          
    /* Construct other entries of S[][]*/
    for(i = 1; i < R; i++)  
    {  
        for(j = 1; j < C; j++)  
        {  
            if(M[i][j] == 1)  
                S[i][j] = min(S[i][j-1],min( S[i-1][j],  
                                S[i-1][j-1])) + 1;  
            else
                S[i][j] = 0;  
        }  
    }  
      
    /* Find the maximum entry, and indexes of maximum entry  
        in S[][] */
    max_of_s = S[0][0]; max_i = 0; max_j = 0;  
    for(i = 0; i < R; i++)  
    {  
        for(j = 0; j < C; j++)  
        {  
            if(max_of_s < S[i][j])  
            {  
                max_of_s = S[i][j];  
                max_i = i;  
                max_j = j;  
            }  
        }              
    }  
  
   /* for(i = max_i; i > max_i - max_of_s; i--)  
    {  
        for(j = max_j; j > max_j - max_of_s; j--)  
        {  
            cout << M[i][j] << " ";  
        }  
        cout << "\n";  
    }  */
    return(max_i+1);
}  
void melt(int a[110][110], int n)
{
    int no=n;
    while(no>0)
    {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                int e=1;
                while(e<n)
                {
                    if(a[i+e][j]==1)
                    {
                        int temp=a[i][j];
                        a[i][j]=a[i+e][j];
                        a[i+e][j]=temp;
                    }
                    else if(a[i+e][j]==0)
                    {
                        break;
                    }
                    e++;
                }
            }
        }
    }
    no--;
    }
}
void func(int n)
{
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c;
            if(c=='C'||c=='c')
            {
                arr[i][j]=0;
            }
            else if(c=='D'||c=='d')
            {
                arr[i][j]=1;
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1,a=0;j>=0,a<n;j--,a++)
        {
            arr2[a][i]=arr[i][j];
        }
    }
    melt(arr,n);
    melt(arr2,n);
    //cout<<max(Maxsub(arr,n),Maxsub(arr2,n));
    //cout<<Maxsub(arr2,n);
    cout<<max(printMaxSubSquare(arr),printMaxSubSquare(arr2));
    /*cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
     cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr2[i][j];
        }
        cout<<endl;
    }*/
}
int main() {
    IOS;
    cin>>N;
    func(N);
}