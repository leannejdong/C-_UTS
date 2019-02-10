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

double det;
int current;
//double matrix::mat m,n,o,minv;


// Prototypes of the functions used in this program


void getvector(matrix,matrix&);
void printname(matrix);
void printcolvec(matrix);
void getmatrix(matrix&);
void printmatrix(matrix);
//void printcolvec(matrix&);

// Begining of Main function

int main(void)
{
	/*try to 
	 translate 
	 m,n,o,minv : matrix;
	 v, xyz : colvector;*/
	struct matrix x,y;
	/*double v=y.colvector[3];
	 double xyz=y.colvector[3];
	 double m=y.mat[3][3];
	 double n=y.mat[3][3];
	 double o=y.mat[3][3];
	 double minv=y.mat[3][3];*/
	
	cout<<"Enter the name of matrix: ";
	cin>>y.matname;
	
	getvector(x,y);
	printcolvec(y);
	printname(y);
	getmatrix(y);
	printmatrix(y); // display the matrix got as input now
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
		cout<<"Enter vector element of rhs equations colvec["<<i<<"]: ";
		cout<<endl;
		cin>>m.colvector[i];
	}
	cout<<"The rhs of matrix "<<p.matname<<" is "<<m.colvector[1]<<" "<<m.colvector[2]<<" "<<m.colvector[3]<<endl;
}

void printname(matrix m)
{
	/*cout<<"Enter the name of matrix: ";
	 cin>>m.matname;*/
	if((m.matname).length()==0)
		cout<<"unnamed" <<endl;
	else
		cout<<"The name of matrix you have entered is "<<m.matname<<endl;
	
}

void printcolvec(matrix m)
{
	string s1="column vector one";
	cout<<"The right handside of  "<<s1<<"is "<< m.colvector[1]<<endl;
	string s2="column vector two";
	cout<<"The right handside of  "<<s2<<"is "<< m.colvector[2]<<endl;
	string s3="column vector three";
	cout<<"The right handside of  "<<s3<<"is "<< m.colvector[3]<<endl;
}
void getmatrix(matrix &m)
{
	cout<<"Enter the name of matrix: ";
	cin>>m.matname;
	cout<<m.matname<<endl;
	
	// This function gets elements of a matrix input by the user
	// Parameter is the structure object obj (used throughout the program)
	// Parameter is "passed by reference" so as to reflect the changes made by this function, to other functions that call it
	string mname;
	cout<<"Enter name of matrix: ";
	getline(cin,mname);
	m.matname=mname;
	cout<<"Enter the matrix "<<endl;
	for (int r=1;r<=3;r++){
		
		for (int c=1;c<=3;c++){
			cout<<"Enter the element mat["<<r<<"]["<<c<<"] : ";
			cout<<endl;
			cin>>m.mat[r][c];
		}
	}
}

void printmatrix(matrix m)
{
	// This function displays elements of a matrix passed to it as a parameter
	// Parameter is the structure object obj (used throughout the program)
	// Parameter is "passed by reference" but may be "passed by value" also.
	//int r,c;
	//cout<<obj.matname<<endl;
	int r,c;
	if((m.matname).length()==0)
		return;
	else{
		cout<<"The matrix "<<m.matname<<" is: "<<endl;
		for (r=1;r<=3;r++)
		{
			for (c=1;c<=3;c++)
			{
				
				cout<<m.mat[r][c]<<" ";
			}
			cout<<endl;
		}
	}
	
}


