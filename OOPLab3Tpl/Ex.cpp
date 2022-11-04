#include <iostream>
#include <math.h>

using namespace std;

enum STATE {
	OK, BAD_INIT, BAD_DIV
};


class TicTacToe {
private:
	char table[3][3] = {'#','#','#','#','#','#','#','#','#' };

	void Menu() {
		cout << "Hello! Your started playing Tic-Tac-Toe\n" << endl;

		cout << "    012\n" << endl;
		cout << "0.  ###" << endl;
		cout << "1.  ###" << endl;
		cout << "2.  ###\n\n" << endl;
		cout << "\nYou and your oponent is needed to enter x's and y's positions of your turns in this table\n\n" << endl;
	}

	void printTable() {
		for (int i = 0; i < 3; i++)
		{
			cout << "\n";
			for (int j = 0; j < 3; j++)
			{
				cout << table[i][j];
			}
		}
		cout << "\n";
	}

	void xTurn() {
		int i, j;

		cout << "Now it's X's turn!\nEnter your position (x,y) : " << endl;

		while (true) {
        	cin >> i;
			cin >> j;

			if (i <= 1 && i >= 3 || j <= 1 && j >= 3) cout << "Input correct positions please\n";
			else if (table[i][j] != '#') cout << "This place is already occupied, choose another one please\n";
			else break;
		}
		table[i][j] = 'x';
	}

	void oTurn() {
		int i, j;

		cout << "Now it's O's turn!\nEnter your position (x,y) : " << endl;
		 
		while (true) {
			cin >> i;
			cin >> j;

			if (i <= 1 && i >= 3 || j <= 1 && j >= 3) cout << "Input correct positions please\n";
			else if (table[i][j] != '#') cout << "This place is already occupied, choose another one please\n";
			else break;
		}

		table[i][j] = 'o';
	}

	bool checkHorizontal(char symb) {
		bool statement = false;
		
		for (int i = 0; i < 3; i++)
		{
			if (statement) return true;
			for (int j = 0; j < 3; j++)
			{
				statement = table[i][j] == symb;
				
				if (!statement) break;
			}
		}

		return false;
	}

	bool checkVertical(char symb) {
		bool statement = false;

		for (int i = 0; i < 3; i++)
		{
			if (statement) return true;
			for (int j = 0; j < 3; j++)
			{
				statement = table[j][i] == symb;

				if (!statement) break;
			}
		}

		return false;
	}

	bool checkDiagonals(char symb) {
		bool firstDig = table[0][0] == symb && table[1][1] == symb && table[2][2] == symb;
		bool secondDig = table[0][2] == symb && table[1][1] == symb && table[2][0] == symb;
		return firstDig == true || secondDig == true ? true: false;
	}

	bool gameResult() {
		bool xStatement = checkHorizontal('x') || checkVertical('x') || checkDiagonals('x');
		bool oStatement = checkHorizontal('o') || checkVertical('o') || checkDiagonals('o');

		if (!xStatement && !oStatement || xStatement && oStatement) {
			cout << "Draw\n" << endl;
			return true;
		}
		else if (oStatement && !xStatement) {
			cout << "O is winner\n" << endl;
			return true;
		}
		else if (xStatement) {
			cout << "X is winner\n" << endl;
			return true;
		}
		return false;

		}
public:
	void startGame() {
		Menu();

		for (int turn = 0; turn < 9; turn++)
		{
			xTurn();
			oTurn();
			printTable();
			if (turn >= 2) {
				if (gameResult()) break;
			}
		}
	}
};

class Vec {
private:
	double array[3];
	int state;

public:
	Vec() {
		array[0] = 0; array[1] = 0; array[2] = 0;
		state = OK;
	}
	Vec(double value) {
		array[0] = value; array[1] = value; array[2] = value;
		state = OK;
	}
	Vec(double *v) {
		if (v == nullptr) {
			state = BAD_INIT;
			array[0] = 0; array[1] = 0; array[2] = 0;
		}
		else {
			array[0] = v[0]; array[1] = v[1]; array[2] = v[2];
			state = OK;
		}
	}
	~Vec() {
		cout << "Vector status " << state << endl;
	}
	void PrintArray() {
		for (int i = 0; i < 3; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n";
	}
	void DefineArray(double a) {
		array[0] = a; array[1] = a; array[2] = a;
	}
	void GetElement(int elementNum) {
		cout << array[elementNum] << endl;
	}
	double PlusElements(int first, int second) {
		return array[first] + array[second];
	}
	double MinusElements(int first, int second) {
		return array[first] - array[second];
	}
	double MultiplyElements(int first, int second) {
		return array[first] * array[second];
	}
	double DivideElement(int arrayElementNumber, short value) {
		if (value != 0) return array[arrayElementNumber] / value;
		else state = BAD_INIT;
	}
	bool Higher(int first, int second) {
		return array[first] > array[second] ? true : false;
	}
	bool Lower(int first, int second) {
		return array[first] < array[second] ? true : false;
	}
	bool Equal(int first, int second) {
		return array[first] == array[second] ? true : false;
	}

};

class Mat {
private:
	long* value;
	long** pValue = &value;
	int state;

public:
	int n, m;
	~Mat() {
		for (int i = 0; i < n; i++)
		{
			free(pValue[i]);
		}
		n = 0, m = 0;
		cout << "Matrix has been cleared" << endl;
	}
	Mat() {
		n = 5, m = 5;
		
		pValue = new long* [n];
		for (int i = 0; i < n; i++)
		{
			pValue[i] = new long[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				pValue[i][j] = 0.0;
			}
		}
	}
	Mat(int n) {
		this->n = n, m = n;

		pValue = new long* [n];
		for (int i = 0; i < n; i++)
		{
			pValue[i] = new long[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				pValue[i][j] = 0.0;
			}
		}
	}
	Mat(int n, int m, long value) {
		this->n = n, this->m = m;
		
		pValue = new long* [n];
		for (int i = 0; i < n; i++)
		{
			pValue[i] = new long[m];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				pValue[i][j] = value;
			}
		}
	}
	Mat(Mat &object) {
		n = object.n, m = object.m;
		pValue = object.pValue;
	}
	void PrintMat() {
		for (int i = 0; i < n; i++)
		{
			cout << "\n";
			for (int j = 0; j < m; j++)
			{
				cout << pValue[i][j] << " ";
			}
		}
		cout << "\n";
	}
	void SetValueToElement(int first, int second, long value) {
		pValue[first][second] = value;
	}
	long GetElement(int i, int j) {
		return pValue[i][j];
	}
	long PlusElements(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] + pValue[firstI][firstJ];
	}
	long MinusElements(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] - pValue[firstI][firstJ];
	}
	long MultiplyElements(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] * pValue[firstI][firstJ];
	}
	long DivideElements(int firstI, int firstJ, long value) {
		if (value == 0) {
			state = BAD_INIT; 
			cout << "Your state " << state << "\hResult will be -1\n" << endl;;
			return -1;
		}
		else return pValue[firstI][firstJ] / value;
	}
	bool Higher(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] > pValue[firstI][firstJ] ? true: false;
	}
	bool Lower(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] < pValue[firstI][firstJ] ? true : false;
	}
	bool Equal(int firstI, int firstJ, int secondI, int secondJ) {
		return pValue[firstI][firstJ] == pValue[firstI][firstJ] ? true : false;
	}


};

int Ex1() {
	TicTacToe Game1;

	Game1.startGame();

	return 0;
}
int Ex2() {

	Vec myVector;

	Vec myVector1(2);

	double* v = nullptr, v2[] = { 1.2, 3.3, 4.4 };

	Vec myVector3(*v2);

	myVector3.PrintArray();

	myVector3.GetElement(1);

	myVector3.DefineArray(2);

	myVector3.PrintArray();

	double plus, minus, divide, multiply;

	plus = myVector3.PlusElements(0, 1);

	minus = myVector3.MinusElements(0, 1);

	divide = myVector3.DivideElement(1, 2);

	multiply = myVector3.MultiplyElements(1, 2);

	bool higher, lower, equal;

	higher = myVector3.Higher(0, 1);

	lower = myVector3.Lower(0, 1);

	equal = myVector3.Equal(0, 1);

	cout << "Plus:     " << plus << endl;
	cout << "Minus:    " << minus << endl;
	cout << "Divide:   " << divide << endl;
	cout << "Multiply: " << multiply << "\n" << endl;

	cout << "Higher:   " << higher << endl;
	cout << "Lower:    " << lower << endl;
	cout << "Equal:    " << equal << endl;
	
	return 0;
}
int Ex3() {
	Mat arr;

	arr.PrintMat();
	
	Mat arr1(2, 2, 2);

	Mat arr2(arr1);

	arr2.SetValueToElement(1, 1, 5);

	arr2.PrintMat();

	long element = arr.GetElement(0, 0);
	long plus = arr2.PlusElements(0, 0, 1, 1);
	long minus = arr2.MinusElements(0, 0, 1, 1);
	long multiply = arr2.MultiplyElements(0, 0, 0, 0);
	long divide = arr2.DivideElements(1, 1, 2);
	bool equal = arr2.Equal(0, 0, 0, 1);

	cout << "Received Element    : " << element << endl;
	cout << "Plused Elements     : " << plus << endl;
	cout << "Minused Elements    : " << minus << endl;
	cout << "Multiplied Elements : " << multiply << endl;
	cout << "Divided Elements    : " << divide << endl;
	cout << "Equal Elements      : " << equal << "\n" << endl;

	return 0;
}