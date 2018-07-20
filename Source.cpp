#include <iostream>
using namespace std; 
int min(int a, int b){
	if (a < b)
	{
		return a;
	}
	return b; 
}
int FiboSearch(int arr[], int sopt, int num){
	//khai bao 2 so fibo1, fibo2; fibo = fibo1 + fibo2.
	int fibo1 = 0; // thu (sopt - 2);
	int fibo2 = 1; // thu (sopt - 1);
	int fibo = fibo1 + fibo2; 
	//xet dieu kien. 
	while (fibo < sopt)
	{
		fibo2 = fibo1; 
		fibo1 = fibo; 
		fibo = fibo2 + fibo1; 
	}
	// danh dau = -1;.
	int marked = -1; 
	// xet dieu kien. 
	while (fibo > 1)
	{
		//valid location;
		int i = min(marked + fibo2, sopt - 1);
		if (arr[i] < num)
		{
			fibo = fibo1; 
			fibo1 = fibo2; 
			fibo2 = fibo - fibo1;
			marked = i; 
		}
		else if (arr[i] > num)
		{
			fibo = fibo2; 
			fibo1 -= fibo2; 
			fibo2 = fibo - fibo1;
		}
		else
		{
			return i; 
		}

	}
	if (fibo1 == num && arr[marked+1] == num)
	{
		return marked + 1; 
	}
	return -1; 
}

int main(){
	int arr[100], i, sopt; 
	cout << "nhap so phan tu: "; cin >> sopt; 
	for (i = 0; i < sopt; i++)
	{
		cin >> arr[i];
	}
	int x; 
	cout << "nhap x"; cin >> x; 
	int located = FiboSearch(arr, sopt, x);
	if (located == -1)
	{
		cout << x << " khong thuoc mang" << "\n"; 

	}
	else
	{
		cout << x << " thuoc mang arr, co vi tri: " << located << "\n";
	}
	return 0; 
}