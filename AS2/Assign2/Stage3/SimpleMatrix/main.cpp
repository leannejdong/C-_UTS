// Code2F.cpp: Matrix algebra
//#include <fstream.h>
#include <iostream>
#include<string>
#include<cmath>
const int N=3;
using namespace std;

class matrix
{
public:
	matrix()	{ }
	~matrix()	{ }
	void getmatrix(double **);
	void getvector(double *);	
	void addmatrix(bool,double **,double **,double **);
	double minor(double **,double **, int ,int );//This is the minor matrix after deleting row i&col j,i.e. M_{i,j}
	double cofactor(double **,double **,int, int);
	double determinant(double a[N+1][N+1] );
	void transpose(double **,double **);
	void MatInverse(double **,double **);
	void MatMult(double **,double **,double **);
	void divmat(double **,double **,double);
	void getmatxcolvec(double *,double *,double **);
	void printmatrix(double **);
	void printvector(double *);
	void printminor(double **);
	void printname(string );
	void menu(int );
};

void menu()
{
	cout<<"Welcome to Basic Matrix Algebra Menu"<<endl<<endl;
	cout << "                ******************"<<endl;
	cout << endl<<endl;
	cout << "1-------> inverse of the matrix        "<<endl;
	cout << "2-------> Determinant of a matrix      "<<endl;
	cout << "3-------> Multiply 3 by 3 matrix      "<<endl;
	cout << "4-------> Solve set of simultaneous equations      "<<endl;
	cout << "5-------> Division of matrix     "<<endl;
	cout << "Quit           "<<endl;
	cout << "Enetr your choice(1-5): ";
}

	

void matrix::getmatrix(double **a)
{
	int i,j;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
		{
			cout<<"Enter the element a["<<i<<"]["<<j<<"] : ";
			cout<<endl;
			cin>>a[i][j];
		}
	}
}

void matrix::getvector(double *v)
{
	//const int size=3;
	//	int v[size];
	int i;
	for (i=1;i<=N;i++)
	{
		cout<<"Enter the element v["<<i<<"] : ";
		//cout<<endl;
		cin>>v[i];
	}
}

void matrix::addmatrix(bool flag,double **c,double **a,double **b)
{
	int i,j;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			c[i][j]=((flag)?a[i][j]+b[i][j]:a[i][j]-b[i][j]);
}
double matrix::minor(double **c_a,double **a,int i, int j)
{
	// This function reduces the matrix passed as input to it
	// The 'reduction' requirement is like this:
	// Eliminate the row i and column j from the given matrix to get the reduced matrix
	
	// This is done by the following logic:
	// a is given matrix. c_obj is desired reduced matrix
	// i. Using two for loops (iterating with p and q here) as usual, we scan the given matrix.
	// row and col represent the current location pointer of row and column of the required reduced matrix.
	// ii. All elements from given matrix are copied to reduced matrix except for those corresponding to
	// row i and column j
	// iii. The reduced matrix (minor) has its dimensions one less than that of given matrix
	
	
	int row=1, col=1;
	for(int p=1;p<=N;p++)
	{
		if(p!=i)
		{
			col=1;
			for(int q=1;q<=N;q++)
			{
				if(q!=j)
				{
					c_a[row][col]=a[p][q];
					col++;
				}
			}
			row++;
		}
	}
	return 1;
}

double matrix::cofactor(double **c_a,double **a,int i, int j)
/*{
 double cofact;
 cofact=int(pow(-1.0,(i+j)))*minor(cm,m,i,j);
 return cofact;
 }*/
{
	int row=1, col=1;
	for(int p=1;p<=N;p++)
	{
		if(p!=i)
		{
			col=1;
			for(int q=1;q<=N;q++)
			{
				if(q!=j)
				{
					c_a[row][col]=int(pow(-1.0,(i+j)))*a[p][q];
					col++;
				}
			}
			row++;
		}
	}
	return 1;
}
void matrix::transpose(double **ta,double **a)
{
	
	int i,j;
	for (i=1;i<=N;i++){
		for (j=1;j<=N;j++){
			ta[i][j]=a[j][i];
		}
	}
}

double matrix::determinant(double a[N+1][N+1])
{
	double product,m;
	int i,j,k;
	
	for(k=1;k<=N-1;k++)
		for (i=k+1;i<=N;i++)
		{
			m=a[i][k]/a[k][k];
			for (j=1;j<=N;j++)
				a[i][j]-=m*a[k][j];
		}
	cout<<endl<<"matrix U: "<<endl;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	product=1;
	for (i=1;i<=N;i++)
		product *=a[i][i];
	
	return product;
}

void matrix::MatInverse(double **x,double **a)
{
   	int i,j,k;
    double Sum,m;
	double **b,**q;
	b=new double *[N+1];
	q=new double *[N+1];
	for (i=0;i<=N;i++)
	{
		b[i]=new double [N+1];
		q[i]=new double [N+1];
	}
	for (i=1;i<=N;i++)
    	for (j=1;j<=N;j++)
		{
			b[i][j]=0;
			q[i][j]=a[i][j];
			if (i==j)
				b[i][j]=1;
		}
	
	// Perform row operations
	for (k=1;k<=N-1;k++)
		for (i=k+1;i<=N;i++)
		{
			m=q[i][k]/q[k][k];
			for (j=1;j<=N;j++)
			{
				q[i][j]-=m*q[k][j];
				b[i][j]-=m*b[k][j];
			}
		}
	
	// Perform back substitution
    for (i=N;i>=1;i--)
		for (j=1;j<=N;j++)
		{
			Sum=0;
			x[i][j]=0;
			for (k=i+1;k<=N;k++)
				Sum += q[i][k]*x[k][j];
			x[i][j]=(b[i][j]-Sum)/q[i][i];
		}
	for (i=0;i<=N;i++)
		delete b[i],q[i];
	delete b,q;
}
void matrix::MatMult(double **c,double **a,double **b)
{
	int i,j,k;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			c[i][j]=0;
			for (k=1;k<=N;k++)
				c[i][j] += a[i][k]*b[k][j];
		}
}
void matrix::divmat(double **b, double **a,double det)
{
	int i,j;
	if (det!=0)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				b[i][j]= a[i][j]/det;
			}
	else{
		cout<<"Determinant is zero. Unable to divide into matrix"<<endl;
	}
}


void matrix::printmatrix(double **a)
{
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j++)
		{
			
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void matrix::printvector(double *v)
{
	for (int i=1; i<=N; i++) {
		cout << v[i]<<" ";
	}
	cout << endl;
}
void matrix::printminor(double **m)
{
	for (int i=1;i<=N-1;i++)
	{
		for (int j=1;j<=N-1;j++)
		{
			
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
void matrix::getmatxcolvec(double *r,double *c,double **m)
{
	int i;
	for (i=1; i<=N; i++) {
		//	r[i]=0;
		r[i]=m[i][1]*c[1]+m[i][2]*c[2]+m[i][3]*c[3];
	}
}

void matrix::printname(string matname )
{
	if(matname.length()==0)
		cout<<"unnamed" <<endl;
	else
		cout<<matname<<endl;
	
}

int main()
{
	
	
	
	int i,j,p,q;
	string A_str;
	double dmat;
	double **A,**B,*Q;
	double A1[N+1][N+1];
	
	double **P,**R,**S,**D,**O;
	matrix g;
	
	A=new double *[N+1];
	
	B=new double *[N+1];
	//C=new double [N+1];
	
	//Arrays that store result
	P=new double *[N+1];
	R=new double *[N+1];
	S=new double *[N+1];
	Q=new double[N+1];
	D=new double*[N+1];
	O=new double*[N+1];
	
	
	for (i=0;i<N+1;i++)
	{
		A[i]=new double [N+1];
		
		B[i]=new double [N+1];
		
		P[i]=new double [N+1];
		
		R[i]=new double [N+1];
		
		S[i]=new double [N+1];
		
		D[i]=new double [N+1];
		
		O[i]=new double [N+1];
	}
	cout.setf(ios::fixed);
	cout.precision(12);
	menu();
	//int mygetch();
	int ch;
	cout << "Enter your choice from 1-6: \n";
	cin>>ch;
	//ch=mygetch();
	cout<<endl;
	
	if (ch==1) {
		cout << "Let's get inverse: \n";
		cout<<" first enter matrix A: \n";
		g.getmatrix(A);
		cout << "Now, get inverse: \n";
		g.MatInverse(R, A);
		cout << "The original matrix (A) is: \n";
		g.printmatrix(A);
		cout << "The inverse of matrix A is: \n";
		g.printmatrix(R);
	}
	else if (ch==2)
	{
		cout << "Let's get minor: \n";
		g.getmatrix(A);
		g.minor(R,A,1,2);
		cout<<"The minor is: \n";
		g.printminor(R);
		
		cout << "Let's get cofactor: \n";
		g.cofactor(S,A,1,2);
		cout<<"The cofactor of A is: \n";
		g.printminor(S);
		
		cout << "Let's get determinant: \n";
		cout<<"Assume input the same matrix, A1=A, please type in according to above matrix "<<endl;
		g.printmatrix(A);
		for (p=1;p<=N;p++)
		{
			for (q=1;q<=N;q++)
			{
				cin>>A1[p][q];
				//cout<<A1[p][q]<<" ";
			}
			cout<<endl;
		}
		cout<<"So matrix A1 is: \n";
		g.printmatrix(A);
		cout << "The determinant of the matrix A1 is "<<g.determinant(A1)<<endl;
	}
	else if(ch==3)
	{
		cout<<"Enter the first matrix: \n";
		g.getmatrix(A);
		g.printmatrix(A);
		cout<<"Enter the matrix you want to multiply with: \n";
		g.getmatrix(B);
		g.printmatrix(B);
		cout<<"The product matrix is: \n";
		g.MatMult(P,A,B);
		g.printmatrix(P);
	}
	else if(ch==4)
	{
		cout<<" Now enter matrix coefficient A: \n";
		g.getmatrix(A);
		cout << "Enter the rhs column vector: \n";
		g.getvector(*A);
		cout << "The vector is: \n";
		g.printvector(*A);
		cout << "Now, get inverse: \n";
		g.MatInverse(R, A);
		g.printmatrix(R);
		cout << "Now multiply the matrix by a vector: \n";
		g.getmatxcolvec(Q,*A,R);
		cout << "The resultant vactor from getmatxcolvec is: \n";
		g.printvector(Q);
	}
	else if(ch==5)
	{
		
		//test divmat method;
		g.getmatrix(A);
		g.printmatrix(A);
		cout<<"Assume input the same matrix, A1=A, please type in according to above matrix "<<endl;
		g.printmatrix(A);
		for (p=1;p<=N;p++)
		{
			for (q=1;q<=N;q++)
			{
				cin>>A1[p][q];
				//cout<<A1[p][q]<<" ";
			}
			cout<<endl;
		}
		cout<<"So matrix A1 is: \n";
		g.printmatrix(A);
		cout << "The determinant of the matrix A1 is "<<g.determinant(A1)<<endl;
		
		cout<<"Now let test our divmat method, use result above to enter the determinant of A: \n"<<endl;
		cin>>dmat;
		g.divmat(D,A,dmat);
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=N;j++)
				cout<<D[i][j]<<" ";
			cout<<endl;
		}
	}
	else {
		cout << "Quit..."<<endl;
	}


	for (i=0;i<=N;i++)
		delete A[i],B[i],P[i],Q[i],R[i],S[i],D[i];
	delete A,B,P,Q,R,S,D;
}
