// Code2F.cpp: Matrix algebra
//#include <fstream.h>
#include <iostream>
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
	void MatInverse(double **,double **);
	void MatMult(double **,double **,double **);
	//void printname(int n);
	//void printcolvector(double, double, double);
	//minor
	//transpose
	//divmat
	//getminor
	//get cofactor
	void getmatxcolvec(double *,double *,double **);
	//menu
	//case
	void printmatrix(double **);
	void printvector(double *);
};

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

void matrix::getmatxcolvec(double *r,double *c,double **m)
{
	int i;
	for (i=1; i<=N; i++) {
	//	r[i]=0;
		r[i]=m[i][1]*c[1]+m[i][2]*c[2]+m[i][3]*c[3];
	}
}
int main()
{
	
	
	
	int i;
	double **A,**B,*Q;
	double **P;
	matrix g;
	
	A=new double *[N+1];
	B=new double *[N+1];
	//C=new double [N+1];
	
	P=new double *[N+1];
	Q=new double[N+1];
	
	for (i=0;i<=N;i++)
	{
		A[i]=new double [N+1];
		
		B[i]=new double [N+1];
		
		P[i]=new double [N+1];
	}
	cout.setf(ios::fixed);
	cout.precision(12);
	g.getvector(*A);
	cout << "The vector is: \n";
	g.printvector(*A);
	g.getmatrix(A);
	cout << "The matrix is: \n";
	g.printmatrix(A);
	g.getmatxcolvec(Q,*A,A);
	cout << "The resultant vactor from getmatxcolvec is: \n";
	g.printvector(Q);
	g.getmatrix(B);
	cout << "The matrix we want to multiply with is: \n";
	g.printmatrix(B);
	g.MatMult(P,A,B);
	cout<<"The result matrix is: \n";
	g.printmatrix(P);
	
	for (i=0;i<=N;i++)
		delete A[i],B[i],P[i],Q[i];
	delete A,B,P,Q;
}
