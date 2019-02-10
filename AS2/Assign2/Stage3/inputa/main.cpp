#include <iostream> 
using namespace std;
void get_array(int[], int);
int calc_sum(int[], int);
void display_array(int[], int);
int main ()
{
	int num[1000]; int n;
	cout << "Enter size of array (must be < 1000):"; cin >> n;
	int sum;
	get_array(num, n); cout << endl;
	//display_array(num, n); cout << endl;
	//sum = calc_sum(num, n); cout << "The sum is " << sum << endl;
} 
void get_array(int arr[], int size)
{
	for (int k = 0; k < size; k++) { 
		cout << "Please enter value for arr[" << k << "]:";
		cin >> arr[k];
	}
}