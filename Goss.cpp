#include <iostream>
using namespace std;

void Gauss(double a[][10], int n);
void SelectColE(double a[][10], int n);
void swapRow(double a[][10], int m, int maxRowE, int n);
void printM(double a[][10], int n);




int main()
{
	double a[4][10];

	int i, n, j;

	a[1][1] = 0.001; a[1][2] = 2.000; a[1][3] = 3.000; a[1][4] = 1.000;
	a[2][1] = -1.000; a[2][2] = 3.712; a[2][3] = 4.623; a[2][4] = 2.000;
	a[3][1] = -2.000; a[3][2] = 1.070; a[3][3] = 5.643; a[3][4] = 3.000;
	Gauss(a, 3);
	for (i = 1; i <= 3; i++)
		printf("X%d=%f\n", i, a[i][4]);
	system("pause");
	return 0;
}
//输出矩阵  
void printM(double a[][10], int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			printf("%f ,", a[i][j]);
		}
		printf("\n");
	}
}

void Gauss(double a[][10], int n)
{
	int i, j;
	SelectColE(a, n);
	cout << "上三角的结果是:\n";
	printM(a, 3);
	for (int i = n; i >= 1; i--)
	{
		/* code */
		for (int j = i + 1; j <= n; j++)
		{
			/* code */
			a[i][n + 1] -= a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] /= a[i][i];
	}

}

void SelectColE(double a[][10], int n)
{
	int i, j, k, maxRowE;
	double temp; //用于记录消元时的因数  
	for (j = 1; j <= n; j++)
	{
		maxRowE = j;
		for (i = j; i <= n; i++)
			if (fabs(a[i][j])>fabs(a[maxRowE][j]))
				maxRowE = i;
		if (maxRowE != j)
			swapRow(a, j, maxRowE, n);   //与最大主元所在行交换  
										 //消元  
		for (i = j + 1; i <= n; i++)
		{
			temp = a[i][j] / a[j][j];
			for (k = j; k <= n + 1; k++)
				a[i][k] -= a[j][k] * temp;
		}
		printM(a, 3);
	}
}

void swapRow(double a[][10], int m, int maxRowE, int n)//函数重载，参数个数不一样
{
	int k;
	double temp;
	for (k = m; k <= n + 1; k++)
	{
		temp = a[m][k];
		a[m][k] = a[maxRowE][k];
		a[maxRowE][k] = temp;
	}
}