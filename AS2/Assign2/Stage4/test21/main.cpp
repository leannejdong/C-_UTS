#include<iostream>
const int N=3;
using namespace std;

class matrix
{
    
public:
    int a[N][N];
    
    matrix()//default constructor
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                a[i][j]=0;
            }
        }
    }
    void set()// to set matrix elements
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cout<<"\n Enter "<<i<<","<<j<<" element=";
                cin>>a[i][j];
            }
        }
    }
    void show()// to show matrix elements
    {
        cout<<"\n Matrix is=\n";
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                
                cout<<a[i][j]<<",";
            }
            cout<<"\n";
        }
    }
    /*
	 binary * operator will require one more arg, since it is a binary operator
	 one arg is the object itself that will call it, other will be passed as arg(in this case x). also this will return a matrix object
	 */
    matrix operator*(matrix x)// overloading * for multiplication
    {
        matrix c;// this will hold our result
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                c.a[i][j]=0;
                for(int k=1;k<=N;k++)
                {
                    c.a[i][j]=c.a[i][j]+a[i][k]*x.a[k][j];        
                }
            }
        }
        return(c);
        
    }
};

int main()
{
    matrix a,b,c;
    a.set();
    b.set();
    c=a*b;
    /*
	 note that compiler will break this statement as 
	 c=a.operator*(b);
	 this is how 2nd arg is passed.
	 and this is how object "a" acts as the calling object
	 */
    
    a.show();
    b.show();
    c.show();
}