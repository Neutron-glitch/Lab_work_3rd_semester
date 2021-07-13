#include <iostream>

using namespace std;

class Matrix3D
{
private:
    double det = 0;
    double a[3][3];

public:
    Matrix3D()
    {
        cout << "input the value of the matrix :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        }
    }
    Matrix3D(char x)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                a[i][j] = 0;
        }
    }
    Matrix3D(double arr[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                a[i][j] = arr[i][j];
        }
    }
    void display()
    {
        cout << "The matrix :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }
    ~Matrix3D()
    {
    }

    double determinant()
    {

        for (int i = 0; i < 3; i++)
            det = det + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));

        return det;
    }

    Matrix3D inverse()
    {
        det = determinant();

        double temp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                temp[i][j] = ((a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 1) % 3][(j + 2) % 3] * a[(i + 2) % 3][(j + 1) % 3])) / det;
        }

        Matrix3D tempo(temp);

        return tempo;
    }

    friend Matrix3D operator+(const Matrix3D &lop, const Matrix3D &rop);
    friend Matrix3D operator-(const Matrix3D &lop, const Matrix3D &rop);
    friend Matrix3D operator*(const Matrix3D &lop, const Matrix3D &rop);
};

Matrix3D operator+(const Matrix3D &lop, const Matrix3D &rop)
{
    Matrix3D temp('x');

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.a[i][j] = lop.a[i][j] + rop.a[i][j];
        }
    }

    return temp;
}

Matrix3D operator-(const Matrix3D &lop, const Matrix3D &rop)
{
    Matrix3D temp('x');

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.a[i][j] = lop.a[i][j] - rop.a[i][j];
        }
    }

    return temp;
}

Matrix3D operator*(const Matrix3D &lop, const Matrix3D &rop)
{
    Matrix3D temp('x');

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.a[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                temp.a[i][j] = temp.a[i][j] + lop.a[i][k] * rop.a[k][j];
            }
        }
    }

    return temp;
}

int main()
{
    Matrix3D sample, sample2, sample3('x');

    sample.display();
    cout << "determinant :" << sample.determinant() << endl;

    sample3 = sample + sample2;
    sample3.display();

    sample3 = sample * sample2;
    sample3.display();
}
