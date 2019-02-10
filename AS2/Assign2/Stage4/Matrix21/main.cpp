/*In this assignment, we focus on dynamic memory allocation for arrays
 This helps managing computer memory. Perhaps not as essential for small size array like we have here.
 But will certainly matter a lot when working with large size array.*/
#include <iostream>
#include<string>
#include<cmath>
const int N=3;
using namespace std;

class matrix
{
	int a[N][N];
	//double ** a[N][N];
public:
	
	double v[N];
	matrix()	{ }	 //Default constructor
	//matrix();
	~matrix()	{ } // Destructor
	void pause();
	void getmatrix(double **); //Data from users for matrices are read and passed into main() through this function
	void getmatrix1();
	void getvector(double *);//Data inputs from users for vectors are read and passed into main() through this function. 
	void getvector1();
	void addmatrix(bool,double **,double **,double **);
	double minor(double **,double **, int ,int );//This is the minor matrix after deleting row i&col j,i.e. M_{i,j}
	double cofactor(double **,double **,int, int);
	double determinant(double a[N+1][N+1] );
	void transpose(double **,double **);
	void MatInverse(double **,double **);
	void MatMult(double **,double **,double **);
	matrix operator*(matrix );
	void divmat(double **,double **,double);
	void getmatxcolvec(double *,double *,double **);
	void printmatrix(double **);
	void printmatrix1();
	void printvector(double *);
	void printvector1();
	void printminor(double **);
	void printname(string );
	void menu(int&);
	void doit();
	
	
};

/*matrix::matrix()//default constructor
 {
 int i,j;
 for( i=1;i<=N;i++)
 {
 for( j=1;j<=N;j++)
 {
 a[i][j]=0;
 }
 }
 }*/
void pause()
{
	char c;
	cout<<"Press return key to continue..."<<endl;
	cin>>c;
	cout<<endl;
}
void menu(int& decision)
{
	int x,option;
	cout<<"Welcome to Basic Matrix Algebra Menu"<<endl<<endl;
	cout << "                ******************"<<endl;
	cout << endl<<endl;
	cout << "1-------> inverse of the matrix        "<<endl;
	cout << "2-------> Determinant of a matrix      "<<endl;
	cout << "3-------> Multiply 3 by 3 matrix      "<<endl;
	cout << "4-------> Solve set of simultaneous equations      "<<endl;
	cout << "5-------> Division of matrix     "<<endl;
	cout << "6-------> Overload Multiply 3 by 3 matrix "<<endl;
	cout << "Quit           "<<endl;
	cout << "Enetr your choice(1-5): ";
	cin>>option;
	if (option>6) 
	{
		menu(x);
	}
	else 
	{
		decision=option;
	
	}
}



void matrix::getmatrix(double **a)//to set matrix elements
//void matrix::getmatrix()//to set matrix elements
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
void matrix::getmatrix1()
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
//void matrix::getvector()
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

/*the input matrices are a and b, which receive data from the calling function. The computed array is c, 
 which returns the value to the calling function in the program. The Boolean variable flag is introduced to
 the code to allow the function to support subtraction as well as addition. Addition is performed when flag=1(TRUE),
 whereas flag=0(FALSE) means subtraction. The use of flag is necessary to avoid the creation of another function specifically for, 
 subtraction, which proves to be redundant*/
void matrix::addmatrix(bool flag,double **c,double **a,double **b) 
{
	int i,j;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			c[i][j]=((flag)?a[i][j]+b[i][j]:a[i][j]-b[i][j]);
}


/*First, mathematical algorithms for how minor and cofactor computed in these codes
 can be found at purplemath.com/modules/minors.htm
 This function reduces the matrix passed as input to it
 The 'reduction' requirement is like this:
 Eliminate the row i and column j from the given matrix to get the reduced matrix
 This is done by the following logic:
 a is given matrix. c_a is desired reduced matrix
 i. Using two for loops (iterating with p and q here) as usual, we scan the given matrix.
 row and col represent the current location pointer of row and column of the required reduced matrix.
 ii. All elements from given matrix are copied to reduced matrix except for those corresponding to
 row i and column j
 iii. The reduced matrix (minor) has its dimensions one less than that of given matrix*/
double matrix::minor(double **c_a,double **a,int i, int j)
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
/*Instead of using the traditional cofactor expansion in computing determinant,
 here the determinant is computed in a new way, which is a fast algorithm in handling higher dimensionality.
 The idea of this way of computing determinant is to reduce the given matrix to its upper or lower triangle.
 More precisely, the following Theorem is used to work out the algorithm
 |Theorem 1|******************************************************************************************************************************************
 *****If a square matrix is reducible to its triangular matrix, the determinant of this matrix is the product of the diagonal elements of its
 reduced upper and lower triangular matrix
 *****************************************************************************************************************************************************
 The theorem states that if a square matrix if a square matrix A=a_{ij} of size N by N is reducible to its upper triangular matrix U=u_{ij},
 then the determinant of a matrix A is
 |A|=|U|=\product_{i=1}^N u_{ii} = u_{11}*u_{22}*...u_{NN}
 */
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

/*
 The maths of computing inverse is simply illustrated by the following Schematic flow
 A|I
 
 U|V
 
 I|A^{-1}
 Now look at the codes,
 MatInverse() requires 2 parameters, both 2D array. It receives data from matrix a, compute the inverse of a and store the computed values in x,
 the values in x are then passed to an array in the calling function*/
void matrix::MatInverse(double **x,double **a)
{
   	int i,j,k;
    double Sum,m;
	double **b,**q; //declare a pointer to pointer of arrays p, q of type double
	b=new double *[N+1]; //allocate memory to the first parameter, i.e. size N+1 of the rows
	q=new double *[N+1];
	for (i=0;i<=N;i++)
	{
		b[i]=new double [N+1];  //allocate memory to the second parameter, i.e. size N+1 of the cols
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
		delete b[i],q[i];			//deallocate the colume array memory
	delete b,q;						//destroying the array
}
/*the maths about matrix multiplication is quite straight. Two matrices can only be multiplied
 if col/row dimensions matched, i.e. if 
 A=a_{ik},
 B=b_{kj} then AB is allowed
 The following codes demonstrate the full implementation of the dynamic memory allocation scheme for 2D arrays
 Note that multiplication problem has the complexity of O(MNP)*/


void matrix::MatMult(double **c,double **a,double **b)//perform multiplication of a and b, store result into c
{
	int i,j,k;  //3 loops with the iterators i,j,and k are required. 
	for (i=1;i<=N;i++) //The outermost loop then represents the row number of C, having i as the iterator
		for (j=1;j<=N;j++) //The middle loop has j as the iterator since it represents the col# of C
		{
			c[i][j]=0;
			for (k=1;k<=N;k++)//k is the common variable represents both the row# of A and the col# of B, ideally placed in the innermost loop
				c[i][j] += a[i][k]*b[k][j];
		}
}

matrix matrix::operator*(matrix x )
{
	//int a[N][N];
	matrix c;// this will hold our result
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			c.a[i][j]=0;
			for(int k=1;k<=N;k++)
			{
				c.a[i][j]=c.a[i][j]+ a[i][k]*x.a[k][j];        
			}
		}
	}
	return c;
	
}
void matrix::divmat(double **b, double **a,double det)
{
	int i,j;
	if (det!=0)  //a matrix is only divisible if noty singular
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				b[i][j]= a[i][j]/det;
			}
	else{
		cout<<"Determinant is zero. Unable to divide into matrix"<<endl;
	}
}


void matrix::printmatrix(double **a)//to show matrix elements
//void matrix::printmatrix()//to show matrix elements
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
void matrix::printmatrix1()
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
//void matrix::printvector()
{
	for (int i=1; i<=N; i++) {
		cout << v[i]<<" ";
	}
	cout << endl;
}
void matrix::printvector1()
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

void doit()
{
	int i,j,p,q;
	string A_str;
	double dmat;
	double **A,**B,*Q;//declare a pointer to 2D arrays A, B, 1D array Q, all of double precision type
	double A1[N+1][N+1]; //2D Array A1 with N+1 rows and N+1 cols is declared statically 
	
	double **P,**R,**S,**D,**O;
	matrix g;
	matrix a,b,c1;
	
	
	A=new double *[N+1]; //Alocate memory to the size N+1 rows
	
	B=new double *[N+1]; //Alocate memory to the size N+1 rows
	
	
	//Arrays that store result
	P=new double *[N+1];
	R=new double *[N+1];
	S=new double *[N+1];
	Q=new double  [N+1];
	D=new double *[N+1];
	O=new double *[N+1];
	
	
	
	for (i=0;i<N+1;i++)
	{
		A[i]=new double [N+1]; //alocate memory of size N+1 to the columns
		
		B[i]=new double [N+1];
		
		P[i]=new double [N+1];
		
		R[i]=new double [N+1];
		
		S[i]=new double [N+1];
		
		D[i]=new double [N+1];
		
		O[i]=new double [N+1];
		
	}
	cout.setf(ios::fixed);
	cout.precision(12);
	int choice=1;
	menu(choice);
	//int mygetch();
	//int ch=1;
	cout << "Enter your choice from 1-6: \n";
	cin>>choice;
	//ch=mygetch();
	cout<<endl;
	
	switch(choice)
	{
		case 1: 
			cout << "Let's get inverse: \n";
			cout<<" first enter matrix A: \n";
			g.getmatrix(A);
			cout << "Now, get inverse: \n";
			g.MatInverse(R, A);//Receives data from matrix A, compute the inverse of A
			cout << "The original matrix (A) is: \n";
			g.printmatrix(A);
			cout << "The inverse of matrix A is: \n";
			g.printmatrix(R);//Print the result from matrix inversion;
			pause();
			break;
			
		case 2:
			
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
			pause();
			break;
		case 3:
			cout<<"Enter the first matrix: \n";
			g.getmatrix(A);
			g.printmatrix(A);
			cout<<"Enter the matrix you want to multiply with: \n";
			g.getmatrix(B);
			g.printmatrix(B);
			cout<<"The product matrix is: \n";
			g.MatMult(P,A,B);
			g.printmatrix(P);
			pause();
			break;
		case 4:  //case 4: Solve equation using the idea AX=B->X=A^{-1}B
			
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
			pause();
			break;
		case 5:
			
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
			pause();
			break;
		case 6:
			a.getmatrix1();
			b.getmatrix1();
			c1=a*b;
			/*
			 note that compiler will break this statement as 
			 c=a.operator*(b);
			 this is how 2nd arg is passed.
			 and this is how object "a" acts as the calling object
			 */
			a.printmatrix1();
			cout<<endl;
			b.printmatrix1();
			c1.printmatrix1();
			break;
		default:
			cout << "Quit..."<<endl;
			break;
	}
	for (i=0;i<=N;i++)
		delete A[i],B[i],P[i],Q[i],R[i],S[i],D[i];  //deallocate the column array memory
	delete A,B,P,Q,R,S,D;	//automatically calls the destructor, to destoy the array
	
}	

int main()
{
	
	
	
	
	doit();
	
}

/*Note: in the above method, a double pointer to the variable is needed because the array is 2D.
 Memory is first allocated to the M+1 row vectors in q. Each row vector has N+1 columns, and thus, 
 another chunk of memory is allocated to each of these vector. Hence, a maximum total of [M+1][N+1]
 amount of memory is allocated to this array*/
