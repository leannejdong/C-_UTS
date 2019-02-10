#include<iostream>
//#include<conio.h>
#include <stdio.h>
#include<string>

//#include <stdio.h>
#include<cmath>
using namespace std;
struct matrix
{
	double colvector[3];
	double mat[3][3];
	double determinant[2][2];
	string matname;
	
};

// Prototypes of the functions used in this program

//void getcolvector(matrix&);
void getvector(matrix,matrix&);
void getmatrix(matrix&);
void printname(matrix);
void printmatrix(matrix);
void printcolvector(matrix&);



// Begining of Main function

int main(void)
{
	struct matrix x,y;
	cout<<"Enter the name of matrix: ";
	cin>>y.matname;
	
	getmatrix(y); // call input function to input the matrix elements from the user
	printname(y);
	printmatrix(y); // display the matrix got as input now
	getvector(x,y);
	printcolvector(y);
	
	
	
	return 0;
}


void getvector(matrix p,matrix&m)
{
	//struct matrix p,m;
	p=m;
	/*cout<<"Enter the name of matrix: ";
	 cin>>p.matname;*/
	cout<<m.matname<<endl;
	int i;
	for ( i=1;i<=3;i++)
	{
		cout<<"Enter vector element of rhs equations colvector["<<i<<"]: ";
		cout<<endl;
		cin>>m.colvector[i];
	}
	cout<<"The rhs of matrix "<<p.matname<<" is "<<m.colvector[1]<<" "<<m.colvector[2]<<" "<<m.colvector[3]<<endl;
}


void getmatrix(matrix &m)
{
	
	/*cout<<"Enter the name of matrix: ";
	cin>>m.matname;*/
	cout<<m.matname<<endl;
	// This function gets elements of a matrix input by the user
	// Parameter is the structure object m (used throughout the program)
	// Parameter is "passed by reference" so as to reflect the changes made by this function, to other functions that call it
	
	int r,c;
	cout<<"Enter the matrix "<<endl;
	for (r=1;r<=3;r++)
	{
		for (c=1;c<=3;c++)
		{
			cout<<"Enter the element mat["<<r<<"]["<<c<<"] : ";
			cout<<endl;
			cin>>m.mat[r][c];
		}
	}
}

void printname(matrix m)
{
	
	if((m.matname).length()==0)
		cout<<"unnamed" <<endl;
	else
		cout<<m.matname<<endl;
	
}
void printmatrix(matrix m)
{
	// This function displays elements of a matrix passed to it as a parameter
	// Parameter is the structure object m (used throughout the program)
	// Parameter is "passed by reference" but may be "passed by value" also.
	//int r,c;
	//cout<<m.matname<<endl;
	if((m.matname).length()==0)
		return;
	else{
		cout<<"The matrix "<<m.matname<<" is: "<<endl;
		for (int r=1;r<=3;r++)
		{
			for (int c=1;c<=3;c++)
			{
				
				cout<<m.mat[r][c]<<" ";
			}
			cout<<endl;
		}
	}}

void printcolvector(matrix &m)
{
	double s1,s2,s3;
	s1=m.colvector[1];
	s2=m.colvector[2];
	s3=m.colvector[3];
	cout<<s1<<" "<<s2<<" "<<s3<<endl;
}


