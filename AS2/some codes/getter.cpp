#include<iostream>
using namespace std;
struct matrix
{
	double colv[3];
	double a[3][3];
	int n;
};



void getmatrix(matrix &obj1); //Prototype of the functions used in this program
void getvector(matrix &obj2); //Prototype of the functions used in this program


void getmatrix(matrix &obj1)
{
//	fflush();
	cout<<"Enter the matrix "<<endl;
	for (int i=1; i<=obj.n,i++){
		for (int j=1; j<=obj1.n,j++){
			cout<<"Enter the element a["<<i<<"]["<<j<<"] : ";
			cout<<endl;
			cin>>obj.a[i][j];
		}
	}

}

void getvector(matrix &obj2)
{
	fflush();
	cout<<"Enter the matrix "<<endl;
	for (int i=1; i<=obj2.n,i++){
	
			cout<<"Enter the element colv["<<i<<"] : ";
			cout<<endl;
			cin>>obj.colv[i];
		
	}

}


int main(void)
{
	cout<< getmatrix(obj)<<endl;
}