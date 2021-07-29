#include <bits/stdc++.h>
using namespace std;

int main() {
	fstream f;
	f.open("new_file.txt", ios::out);
	f << "Learning File Handling\n";
	f << "Learning File Handling\n";
	f << "Learning File Handling\n";
	f.close();
}

int main() {
	fstream f;
	f.open("new_file.txt", ios::in);
	string str;
	while (!f.eof()) {
		getline(f, str);
		cout << str << '\n';
	}
	f.close();
}

//    Learning File Handling
//    Learning File Handling
//    Learning File Handling

int main() {
	fstream f;
	f.open("new_file.txt", ios::app);
	f << "Learning File Handling\n";
	f << "Learning File Handling\n";
	f << "Learning File Handling\n";
	f.close();
}

int main() {
	fstream f;
	f.open("new_file.txt", ios::in);
	string str;
	while (!f.eof()) {
		getline (f, str);
		cout << str << '\n';
	}
	f.close();
}

//    Learning File Handling
//    Learning File Handling
//    Learning File Handling
//    Learning File Handling
//    Learning File Handling
//    Learning File Handling

int main() {
	int n = 5;
	int arr[n] = {1, -3, 2, 7, -4};
	fstream f;
	f.open("new_file.txt", ios::out);
	f << n << '\n';
	for (int i = 0; i < n; i++)
		f << arr[i] << ' ';
	f.close();
}

int main() {
	fstream f;
	f.open("new_file.txt", ios::in);
	int n;
	f >> n;
	cout << n << '\n';
	int arr[n];
	for (int i = 0; i < n; i++) {
		f >> arr[i];
		cout << arr[i] << ' ';
	}
	f.close();
}

//    5
//    1 -3 2 7 -4

int main() {
	int n = 2, m = 3;
	int arr[n][m] = {{1, -3, 5}, {2, 7, -4}};
	fstream f;
	f.open("new_file.txt", ios::out);
	f << n << ' ' << m << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			f << arr[i][j] << ' ';
		f << '\n';
	}
	f.close();
}

int main() {
	fstream f;
	f.open("new_file.txt", ios::in);
	int n, m;
	f >> n >> m;
	cout << n << ' ' << m << '\n';
	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> arr[i][j];
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	f.close();
}

//    2 3
//    1 -3 5
//    2 7 -4
