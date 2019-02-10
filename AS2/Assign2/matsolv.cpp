
#include<iostream>
#include<stdio.h>
//#include<conio.h>
//#include<process.h>
#include<cmath>
#include<string>
using namespace std;

// NOTES:
// 1. float datatype has been used for matrix, determinant.
// 2. To have consistency between mathematics and C++, this program considers a[1][1] as the first element
// i.e row and column indices begin with 1 same as mathematics.


// Define a structure matrix with a matrix (2D array of type float) and size n
// Declare the objects of this structure used in this program 

struct matrix
{
	double colvector[4];
	double mat[4][4];
	double determinant[2][2];
	string matname;
	int n;
}
m,c_m,trans_m,m_inv,m_adj,m_cof;

// Prototypes of the functions used in this program
void getvector(matrix,matrix&);
void getmatrix(matrix&);
void printname(matrix);//no good
void printmatrix(matrix&);
void printcolvector(matrix&);
matrix minor(matrix &, int ,int );
matrix transpose(matrix);
double getdeterminant(matrix);
double evaldeterminant(matrix );
matrix adjoint(matrix m);
matrix getinverse(matrix m);
double cofactor(matrix, int , int );
//void mult3by3(matrix&,matrix );


// Begining of Main function

int main(void)
{
	// Getting dimensions input by the user
	int r,c;
again:
	cout<<"Enter the order of the matrix: "<<endl;
	cout<<"Enter Row dimension: ";
	cin>>r;
	cout<<"Enter Column dimension: ";
	cin>>c;
	
	
	if(r!=c)
	{
		char ans;
		cout<<"Inverse can be found out only for a square matrix. Enter same dimension for row and column. Do you want to enter the dimensions again? Press Y for yes"<<endl;
		cin>>ans;
		if(ans=='y')
			goto again;
		else
			cout<<"Program exit";
//		getch();
		exit(0);
	}
	
	// If it's a square matrix, proceed
	
	else if(r==c)
	{
		
		m.n=r;}
	
	cout<<endl;
	//
	getmatrix(m); // call input function to input the matrix elements from the user
	printmatrix(m); // display the matrix got as input now
	cout<<"Enter the name of matrix: "<<endl;
	cin>>m.matname;
	printname(m);
	matrix p;
	getvector(p,m);
	printcolvector(m);
	
	//Matrix multiplication
	int i,j,k;
	
	getmatrix(p);
	printmatrix(m);
	printmatrix(p);
	
	matrix R;
	//double sum=0.0;
	for (i=1; i<=m.n; i++) {
		for (j=1; j<=m.n; j++) {
			for (k=1;k<=m.n;k++)
				R.mat[i][j]+=m.mat[i][k]*p.mat[k][j];

		}
		
	}
	cout<<endl<<endl;
	for (i=1; i<=m.n; i++) {
		//cout << endl;
		for (j=1; j<=m.n; j++) {
			//cout<<" C["<<i<<"]["<<j<<"]= "<< R.mat[i][j];
			cout<< R.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	//printmatrix(R);//This function will not work in displaying R since we didnot use & pass by value
	

	
	
// Following lines were used to test parts/sections/segments of the code and hence commented
	
	char ans2;
	cout<<"do u want to check reduce matrix? Press y to check reduce matrix and press any char to skip this"<<endl;
	cin>>ans2;
	if(ans2=='y')
	{
		int i,j;
		cout<<"Enter row i and col j to get reduced matrix"<<endl;
		cin>>i>>j;
		// i=i-1;
		// j=j-1;
		c_m=minor(m,i,j);
		char ans1;
		cout<<"Do you want to display the reduced matrix? If yes, Press y "<<endl;
		cin>>ans1;
		if(ans1=='y')
		{
			cout<<"Displaying reduced matrix..."<<endl;
			printmatrix(c_m);
			
			cout<<"The determinant of the minor is "<<evaldeterminant(c_m)<<endl;
		}
	}
	
		 
	 //find transpose
	matrix trans1;
	trans1=transpose(m);
	printmatrix(trans1);
	
	//Find Determinant
	
	cout<<"Finding determinant......"<<endl;
	cout<<"The determinant is"<<getdeterminant(m)<<endl;
	
	//Find Cofactor if user wishes to
	char ans3;
	cout<<"Do you want to find cofactor? Press y if yes"<<endl;
	cin>>ans3;
	while(ans3=='y')
	{
		int i,j;
		cout<<"Finding cofactor. Enter row and column"<<endl;
		cin>>i>>j;
		cout<<"Cofactor of a["<<i<<"]["<<j<<"] is "<<cofactor(m,i,j)<<endl;
		cout<<"want of find cofactor of another element? Press y for yes"<<endl;
		cin>>ans3;
		// Find Inverse
		
		cout<<"\n\n\n Finding Inverse. . .\n\n";
		matrix m_inv2;
		m_inv2=getinverse(m);
		printmatrix(m_inv2); // Display the matrix inverse
	}
return 0;
}
void getmatrix(matrix &m)
{
	// This function gets elements of a matrix input by the user
	// Parameter is the structure object obj (used throughout the program)
	// Parameter is "passed by reference" so as to reflect the changes made by this function, to other functions that call it
	int r;
	cout<<"Enter dimension: ";
	cin>>r;
	m.n=r;
	cout<<"Enter the matrix "<<endl;
	for (int i=1;i<=m.n;i++)
	{
		for (int j=1;j<=m.n;j++)
		{
			cout<<"Enter the element a["<<i<<"]["<<j<<"] : ";
			cout<<endl;
			cin>>m.mat[i][j];
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
void printmatrix(matrix &m)
{
	// This function displays elements of a matrix passed to it as a parameter
	// Parameter is the structure object obj (used throughout the program)
	// Parameter is "passed by reference" but may be "passed by value" also.
	
	if(m.n==0)
		return;
	else{
		cout<<"The matrix is: "<<endl;
		for (int i=1;i<=m.n;i++)
		{
			for (int j=1;j<=m.n;j++)
			{
				
				cout<<m.mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}}

void getvector(matrix p,matrix&m)
{
	
	cout<<m.matname<<endl;
	int i;
	for ( i=1;i<=m.n;i++)
	{
		cout<<"Enter vector element of rhs equations colvector["<<i<<"]: ";
		cout<<endl;
		cin>>m.colvector[i];
	}
	cout<<"The rhs of matrix "<<p.matname<<" is "<<m.colvector[1]<<" "<<m.colvector[2]<<" "<<m.colvector[3]<<endl;
}

void printcolvector(matrix &m)
{
	double s1,s2,s3;
	s1=m.colvector[1];
	s2=m.colvector[2];
	s3=m.colvector[3];
	cout<<s1<<" "<<s2<<" "<<s3<<endl;
}
matrix minor(matrix &m, int i,int j)
{
	
	int row=1,col=1;
	for(int p=1;p<=m.n;p++) // outer loop traverses through rows as usual
	{
		for(int q=1;q<=m.n;q++) // inner loop traverses through columns as usual
		{
			if((p!=i)&&(q!=j)) // Skip the elements corresponding to row i OR column j of the given matrix
			{
				c_m.mat[row][col]=m.mat[p][q];
				col=col+1;
			}
			if(col>=m.n) // When column 'col' of reduced matrix reaches (or exceeds n), reset it to 1
			{ // and increment 'row'. This means current row of reduced matrix got filled and
				// we need to begin filling a new row.
				col=1;
				row=row+1;
				
				if (row>=m.n) //This represents the case when both 'col' and 'row of reduce matrix reach (or
					// exceed) n. This means the reduced matrix has been filled up.Break out of the loops.
					break;
			}
		}
		
	}
	c_m.n=m.n-1; // Fix the dimension of the reduced matrix one less than the given input matrix
	
	return c_m; // Return the reduced matrix to the calling function.
	
}
matrix transpose(matrix m)
{
	int i,j;
	trans_m.n=m.n;//this is very important, without this won't display tran1
	for (i=1; i<=m.n; i++){
		for (j=1;j<=m.n;j++){
			trans_m.mat[i][j]=m.mat[j][i];
		}
	}
	return trans_m;
}

double evaldeterminant(matrix mm)
{
	return mm.mat[1][1]*mm.mat[2][2]-mm.mat[1][2]*mm.mat[2][1];
}

double getdeterminant(matrix m)
{
	double det=0;
	if(m.n==1)
		return m.mat[1][1];
	else
		for (int scan =1; scan<=m.n; scan++){
			det=det+m.mat[1][scan]*int(pow(-1.0,(1+scan)))*getdeterminant(minor(m,1,scan));
		}
	return det;
}
matrix adjoint(matrix m)
{
	m_adj.n=m.n;
	m_cof.n=m.n;
	
	for (int r=1;r<=m.n;r++){
		for(int c=1;c<=3;c++){
			m_cof.mat[r][c]=cofactor(m,r,c);
		}
	}
	m_adj=transpose(m_cof);
	return m_adj;
}

matrix getinverse(matrix m)
{
	double det=getdeterminant(m);
	matrix m_null;
	m_null.n=0;
	
	if(det==0){
		cout<<"Inverse can be found only if the determinant of the matrix is non zero"<<endl;
		return m_null;
	}
	else{
		matrix m_adj1=adjoint(m);
		m_adj1.n=m.n;
		m_inv.n=m.n;
		for(int r=1;r<=3;r++){
			for(int c=1;c<=3;c++){
				m_inv.mat[r][c]=(m_adj1.mat[r][c])/det;
			}
		}
		return m_inv;
	}
}

double cofactor(matrix m, int r, int c)
{
	double cofact;
	if(m.n==1)
		return m.mat[1][1];
	else
		cofact=int(pow(-1.0,(r+c)))*getdeterminant(minor(m,r,c));
	
	return cofact;
}




