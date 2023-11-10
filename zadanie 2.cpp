#include <iostream>
#include <random>
using namespace std;
struct Matrix {
	int** data_ = nullptr;
	size_t n_ = 0u;
	size_t m_ = 0u;
};
void Construct(Matrix& out, size_t n, size_t m) {
	out.n_ = n;
	out.m_ = m;
	out.data_ = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		out.data_[i] = new int[m];
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			out.data_[i][j] = 0;
		}
	}
}
void Destruct(Matrix& matr) {
	for (size_t i = 0; i < matr.n_; ++i) {
		delete[]matr.data_[i];
	}
	matr.n_ = 0;
	matr.m_ = 0;
	delete[]matr.data_;
}
Matrix Copy(const Matrix& matr) {
	Matrix copy;
	copy.n_ = matr.n_;
	copy.m_ = matr.m_;
	copy.data_ = new int* [matr.n_];
	for (size_t i = 0; i < matr.n_; ++i) {
		copy.data_[i] = new int[matr.m_];
	}
	for (size_t i = 0; i < matr.n_; ++i) {
		for (size_t j = 0; j < matr.m_; ++j) {
			copy.data_[i][j] = matr.data_[i][j];
		}
	}
	return copy;
}
Matrix Add(const Matrix& matr, const Matrix& matr1) {
	Matrix zero;
	if ((matr.n_ != matr1.n_) or (matr.m_ != matr1.m_)) {
		return zero;
	}
	Matrix add;
	add.data_ = new int* [matr.n_];
	for (size_t i = 0; i < matr.n_; ++i) {
		add.data_[i] = new int[matr.m_];
	}
	for (size_t i = 0; i < matr.n_; ++i) {
		for (size_t j = 0; j < matr.m_; ++j) {
			add.data_[i][j] = matr.data_[i][j] + matr1.data_[i][j];
		}
	}
	return add;
}
Matrix Sub(const Matrix& matr, const Matrix& matr1) {
	Matrix zero;
	if ((matr.n_ != matr1.n_) or (matr.m_ != matr1.m_)) {
		return zero;
	}
	Matrix sub;
	sub.data_ = new int* [matr.n_];
	for (size_t i = 0; i < matr.n_; ++i) {
		sub.data_[i] = new int[matr.m_];
	}
	for (size_t i = 0; i < matr.n_; ++i) {
		for (size_t j = 0; j < matr.m_; ++j) {
			sub.data_[i][j] = matr.data_[i][j] - matr1.data_[i][j];
		}
	}
	return sub;
}
Matrix Mult(const Matrix& matr, const Matrix& matr1) {
	Matrix zero;
	if ((matr.n_ != matr1.m_) or (matr.m_ != matr1.n_)) {
		return zero;
	}
	Matrix mult;
	mult.data_ = new int* [matr.n_];
	for (size_t i = 0; i < matr.n_; ++i) {
		mult.data_[i] = new int[matr.m_];
	}
	for (size_t i = 0; i < matr.n_; ++i) {
		for (size_t j = 0; j < matr.m_; ++j) {
			for (size_t k = 0; k < matr.m_; ++k) {
				mult.data_[i][j] = matr.data_[i][k] - matr1.data_[k][j];
			}
		}
	}
	return mult;
}
void Transposition(Matrix& matr) {
	Matrix trans;
	trans.data_ = new int* [matr.n_];
	for (size_t i = 0; i < matr.n_; ++i) {
		trans.data_[i] = new int[matr.m_];
	}
	for (size_t i = 0; i < matr.n_; ++i) {
		for (size_t j = 0; j < matr.m_; ++j) {
			trans.data_[i][j] = matr.data_[j][i];
		}
	}
	Destruct(matr);
	matr = trans;
}
int main()
{
	int n, m;
	cin >> n >> m;
	Matrix matr;
	Matrix matr1;
	Matrix out;
	matr.n_ = n;
	matr.m_ = m;
	matr1.n_ = n;
	matr1.m_ = m;
	matr.data_ = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		matr.data_[i] = new int[m];
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			matr.data_[i][j] = rand() % 50;
			cout << matr.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	matr1.data_ = new int* [n];
	for (size_t i = 0; i < n; ++i) {
		matr1.data_[i] = new int[m];
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			matr1.data_[i][j] = rand() % 50;
			cout << matr1.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Construct(out, n, m);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cout << out.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Matrix add = Add(matr, matr1);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cout << add.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Matrix sub = Sub(matr, matr1);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cout << sub.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Matrix mult = Mult(matr, matr1);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cout << mult.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Transposition(matr);
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cout << matr.data_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Destruct(out);
	Destruct(add);
	Destruct(sub);
	Destruct(mult);
	Destruct(matr);
	return 0;
}