#include<iostream>
using namespace std;

int count=0;

bool is_possible(int row,int col,bool board[][11],int n){
 
  int i ,j;

  // check vertically
	for(int i=0;i<row;i++)
	{
		if(board[i][col])
		 return false;
	}

 // check left diagonal
   
    i = row-1;
    j = col-1;

	while(i>=0&&j>=0){
		if(board[i][j])
		 return false;
		 i = i-1;
		 j = j-1;
	}

// check right diagonal

  i = row-1;
  j = col +1;

   while(i>=0&&j<n){
	   if(board[i][j])
		 return false;
		 i = i-1;
		 j = j+1;
   }

	return true;

}

void No_of_Ways(bool board[][11],int row,int n){

 if(row==n){
     count++;
	 return;
 }

  for(int i=0;i<n;i++){

	  if(is_possible(row,i,board,n)){

	   board[row][i] = 1;
	   No_of_Ways(board,row+1,n);
	   board[row][i] = 0;

	  }
  }
	
}

int main() {

	int n; cin>>n;

	bool board[11][11] ={0};

	No_of_Ways(board,0,n);

	cout<<count;
	return 0;
}