

#include <iostream.h>
#include <math.h>
#include <conio.h>

const int MaxRow = 10;
const int MaxCol = 10;
const double LIMIT = 0.01;

class Matrix
{
public:
    Matrix();
    int row() const {return rowNum;}
    int col() const {return colNum;}
    void setRow(const int newRow) { rowNum = newRow;}
    void setCol(const int newCol) { colNum = newCol;}
    void display();
    double& items(int r, int c);
    void setElements(int row, int col);
    void initialize();
    Matrix& operator +(Matrix &other);
    Matrix& operator -(Matrix &other);
    Matrix& operator *(double i);
    Matrix& operator *(Matrix &otherMatrix);
    Matrix& operator =(Matrix &other);
    Matrix& operator +=(Matrix &other);
    Matrix& operator -=(Matrix &other);
    friend Matrix transpose(Matrix &other);
private:
    int rowNum;
    int colNum;
    double lst[MaxRow][MaxCol];
};

void showmenu();
void waitpresskey();
void fun1(Matrix &a, Matrix &b, Matrix &c);
void fun2(Matrix &a, Matrix &b);
void fun3(Matrix &a, Matrix &b, Matrix &c);
void fun4(Matrix &a, Matrix &b);
void fun5(Matrix &a, Matrix &b, Matrix &c);
void fun6(Matrix &a, Matrix &b);
void fun7(Matrix &a, Matrix &b);

int main()
{
    Matrix a, b, c;
    char ch;
    while(1)
    {
		clrscr();
		showmenu();
		ch = getche();
		cout<<endl;
		switch(ch)
		{
			case '1':
				fun1(a, b, c);
				break;
			case '2':
				fun2(a, b);
				break;
			case '3':
				fun3(a, b, c);
				break;
			case '4':
				fun4(a, b);
				break;
			case '5':
				fun5(a, b, c);
				break;
			case '6':
				fun6(a, b);
				break;
			case '7':
				fun7(a, b);
				break;
			case '8':
				break;
			default:
				cout<<"Input error, please enter a correct choice!"<<endl;
				waitpresskey();
				break;
		}
		if(ch == '8')
			break;
    }
}

void waitpresskey()
{
    cout<<"Press any key to continue...";
    getch();
    cout<<endl;
}

void fun1(Matrix &a, Matrix &b, Matrix &c)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter row for matrix B: ";
    cin>>row;
    cout<<"Enter col for matrix B: ";
    cin>>col;
    b.setElements(row, col);
    cout<<"matrix B is:"<<endl;
    b.display();
    c = a + b;
    cout<<"matrix C = A + B"<<endl;
    cout<<"matrix C is:"<<endl;
    c.display();
    waitpresskey();
}

void fun2(Matrix &a, Matrix &b)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter row for matrix B: ";
    cin>>row;
    cout<<"Enter col for matrix B: ";
    cin>>col;
    b.setElements(row, col);
    cout<<"matrix B is:"<<endl;
    b.display();
    b+=a;
    cout<<"matrix B += A"<<endl;
    cout<<"matrix B is:"<<endl;
    b.display();
    waitpresskey();
}

void fun3(Matrix &a, Matrix &b, Matrix &c)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter row for matrix B: ";
    cin>>row;
    cout<<"Enter col for matrix B: ";
    cin>>col;
    b.setElements(row, col);
    cout<<"matrix B is:"<<endl;
    b.display();
    c = a - b;
    cout<<"matrix C = A - B"<<endl;
    cout<<"matrix C is:"<<endl;
    c.display();
    waitpresskey();
}

void fun4(Matrix &a, Matrix &b)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter row for matrix B: ";
    cin>>row;
    cout<<"Enter col for matrix B: ";
    cin>>col;
    b.setElements(row, col);
    cout<<"matrix B is:"<<endl;
    b.display();
    b-=a;
    cout<<"matrix B -= A"<<endl;
    cout<<"matrix B is:"<<endl;
    b.display();
    waitpresskey();
}

void fun5(Matrix &a, Matrix &b, Matrix &c)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter row for matrix B: ";
    cin>>row;
    cout<<"Enter col for matrix B: ";
    cin>>col;
    b.setElements(row, col);
    cout<<"matrix B is:"<<endl;
    b.display();
    c = a * b;
    cout<<"matrix C = A * B"<<endl;
    cout<<"matrix C is:"<<endl;
    c.display();
    waitpresskey();
}

void fun6(Matrix &a, Matrix &b)
{
    int row, col;
    double num;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    cout<<"Enter a double num: ";
    cin>>num;
    b = a * num;
    cout<<"matrix B = A * "<<num<<endl;
    cout<<"matrux B is:"<<endl;
    b.display();
    waitpresskey();
}

void fun7(Matrix &a, Matrix &b)
{
    int row, col;
    cout<<"Enter row for matrix A: ";
    cin>>row;
    cout<<"Enter col for matrix A: ";
    cin>>col;
    a.setElements(row, col);
    cout<<"matrix A is:"<<endl;
    a.display();
    b = transpose(a);
    cout<<"matrix B = transpose(A)"<<endl;
    cout<<"matrix B is:"<<endl;
    b.display();
    waitpresskey();
}

void showmenu()
{
    cout<<"Welcome to use simple matrix program  v0.01"<<endl<<endl;
    cout<<"    1 -> C = A + B"<<endl;
    cout<<"    2 -> B += A"<<endl;
    cout<<"    3 -> C = A - B"<<endl;
    cout<<"    4 -> B -= A"<<endl;
    cout<<"    5 -> C = A * B"<<endl;
    cout<<"    6 -> B = A * num (e.g. num = 2)"<<endl;
    cout<<"    7 -> B = transpose(A)"<<endl;
    cout<<"    8 -> Exit"<<endl<<endl;
    cout<<"Enter your choice[1 - 8]: ";
}

void Matrix::initialize()
{
    for (int r=0; r < rowNum; r++)
    {
		for (int c=0; c< colNum; c++)
		{
			lst[r][c] = 0;
		}
    }
}
void Matrix::setElements(int row, int col)
{
    setRow(row);
    setCol(col);
    cout<<"Input "<<rowNum<<"X"<<colNum<<" matrix."<<endl;
    for (int r=0; r < rowNum; r++)
    {
		for (int c=0; c< colNum; c++)
		{
			cin>>lst[r][c];
		}
    }
}

Matrix::Matrix()
{
    rowNum = 3;
    colNum = 3;
    initialize();
}

double& Matrix::items(int r, int c)
{
    return lst[r][c];
}

Matrix& Matrix::operator +(Matrix &other)
{
    double total = 0;
    Matrix temp;
    temp.setRow(rowNum);
    temp.setCol(colNum);
    if (rowNum != other.row() || colNum != other.col())
    {
		cout<<"\nTwo matrixes have different row or col numbers!\n";
		return (*this);
    }
    else
    {
		for (int r = 0; r < rowNum; r++)
		{
			for (int c = 0; c < other.col(); c++)
			{
				total = lst[r][c] + other.items(r, c);
				temp.items(r, c) = total;
			}
		}
		*this = temp;
		return (*this);
    }
}

Matrix& Matrix::operator -(Matrix &other)
{
    double total = 0;
    Matrix temp;
    temp.setRow(rowNum);
    temp.setCol(colNum);
    if (rowNum != other.row() || colNum != other.col())
    {
		cout<<"\nTwo matrixes have different row or col numbers!\n";
		return (*this);
    }
    else
    {
		for (int r = 0; r < rowNum; r++)
		{
			for (int c = 0; c < other.col(); c++)
			{
				total = lst[r][c] - other.items(r, c);
				temp.items(r, c) = total;
			}
		}
		*this = temp;
		return (*this);
    }
}

Matrix& Matrix::operator *(double i)
{
    for (int r=0; r<rowNum; r++)
    {
		for (int c=0; c<colNum; c++)
		{
			lst[r][c] *= i;
		}
    }
    return (*this);
}

Matrix& Matrix::operator *(Matrix &other)
{
    double total = 0;
    Matrix temp;
    temp.setRow(rowNum);
    temp.setCol(other.col());
    if(colNum!=other.row())
    {
		cout<<"\nrow & col are not the same!\n";
    }
    else
    {
		for (int r = 0; r < rowNum; r++)
		{
			for (int c = 0; c<other.col(); c++)
			{
				total = 0;
				for (int i = 0; i<colNum; i++)
				{
					total += lst[r][i] * other.items(i, c);
				}
				temp.items(r, c) = total;
			}
		}
		*this = temp;
    }
    return (*this);
}

Matrix& Matrix::operator =(Matrix &other)
{
    setRow(other.row());
    setCol(other.col());
    for (int r=0; r < other.row(); r++)
    {
		for (int c=0; c < other.col(); c++)
		{
			lst[r][c] = other.items(r, c);
		}
    }
    return (*this);
}

Matrix& Matrix::operator +=(Matrix &other)
{
    if (rowNum!= other.row() || colNum!= other.col())
    {
		cout<<"\nTwo matrixes have different row or col numbers!\n";
		return (*this);
    }
    else
    {
		for (int r=0; r<rowNum; r++)
		{
			for (int c=0; c<colNum; c++)
			{
				lst[r][c]+=other.items(r, c);
			}
		}
		return (*this);
    }
}

Matrix& Matrix::operator -=(Matrix &other)
{
    if (rowNum != other.row() || colNum != other.col())
    {
		cout<<"\nTwo matrixes have different row or col numbers!\n";
		return (*this);
    }
    else
    {
		for (int r=0; r<rowNum; r++)
		{
			for (int c=0; c<colNum; c++)
			{
				lst[r][c]-=other.items(r, c);
			}
		}
		return (*this);
    }
}

void Matrix::display()
{
    cout<<"row\\col";
    for (int c=0; c< colNum; c++)
    {
		cout<<"\t"<<c;
    }
    cout<<"\n\n";
    for (int r = 0; r< rowNum; r++)
    {
		cout<<r;
		for (c = 0; c< colNum; c++)
		{
			cout<<"\t"<<(fabs(lst[r][c])<LIMIT?0:lst[r][c]);
		}
		cout<<endl;
    }
}

Matrix transpose(Matrix &other)
{
    double total = 0;
    Matrix temp;
    temp.setRow(other.colNum);
    temp.setCol(other.rowNum);
    for (int r = 0; r < other.rowNum; r++)
    {
		for (int c = 0; c < other.colNum; c++)
		{
			temp.lst[r][c] = other.lst[c][r];
		}
    }
    return (temp);
}