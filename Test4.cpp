// Test4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void add_row_ins(int**& a, int n, int m, int k) {

	int** b = new int* [n];
	for (int i = 0; i < n; i++)
		b[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = a[i][j];

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	a = NULL;

	a = new int* [n - 1];
	for (int i = 0; i < (n - 1); i++) {
		a[i] = NULL;
	}
	for (int i = 0; i < (n - 1); i++) {
		a[i] = new int[m];
	}

	for (int i = 0; i < k; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];

	for (int j = 0; j < m; j++)
		a[k][j] = rand() % 100 + 1;

	for (int i = k; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i - 1][j] = b[i][j];

	for (int i = 0; i < n; i++)
		delete[] b[i];
	delete[] b;

}

void print(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n = 1;
	int m = 1;
	int k = 0;
	srand(time(NULL));
	int** a = NULL;
	setlocale(LC_ALL, "Russian");
	cout << "Введите размерность двумерного квадратного массива: " << endl;
	cin >> n;
	cout << "Введите k: " << endl;
	cin >> k;
	m = n;

	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 100 + 1;


	print(a, n, n);

	add_row_ins(a, n, n, k);

	print(a, n + 1, n);

	for (int i = 0; i < (n - 1); i++)
		delete[] a[i];
	delete[] a;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
