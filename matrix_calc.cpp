//------------------------------------------
// Author:
//    Jusin Angra
//
// Program takes in matrix dimension, matrix and operation relevate to matrix
//   or matrices. Matrix/matrices are then added, subtracted, multipied,
//   incremented, or decremented and then outputted, all through overloaded
//   operations. 
//------------------------------------------

#include<iostream>
#include <iostream>
#include <cstdio>

using namespace std;

// Global variable for dimension
int dim;

class matrix
{
private:
  int a[1000][1000];

public:

  matrix()//default constructor
  {
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    a[i][j]=0;
	  }
      }
  }

  // set matrix elemets
  void set()
  {
    int n;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim && cin >> n;++j)
	  {
	    a[j][i] = n;
	  }
      }
  }

  // overloading << for output
  friend ostream &operator<<(ostream &cout, const matrix &m)
  {
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    cout<<m.a[i][j]<<" ";
	  }
	cout<<"\n";
      }
    cout << "\n";
    return cout;
  }

  // overloading * for multiplication
  matrix operator*(matrix x)
  {
    matrix c;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    c.a[i][j]=0;
	    for(int k=0;k<dim;++k)
	      {
		c.a[i][j]=c.a[i][j]+a[i][k]*x.a[k][j];
	      }
	  }
      }
    return(c);

  }

  // overloading + for addition
  matrix operator+(matrix x)
  {
    matrix c;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    c.a[i][j]=a[i][j]+x.a[i][j];
	  }
      }
    return(c);
  }

  // overloading - for subtraction
  matrix operator-(matrix x)
  {
    matrix c;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    c.a[i][j]=a[i][j]-x.a[i][j];
	  }

      }
    return(c);
  }

  // overloading ++ for increment
  matrix operator++()
  {
    matrix c;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    // Increment each element
	    c.a[i][j]=a[i][j]++;
	  }
      }
    return(c);
  }

  // overloading -- for decrement
  matrix operator--()
  {
    matrix c;
    for(int i=0;i<dim;++i)
      {
	for(int j=0;j<dim;++j)
	  {
	    // Decrement each element
	    c.a[i][j]=a[i][j]--;
	  }
      }
    return(c);
  }
};

int main()
{
  matrix a,b,c;

  // Take in dimension
  cin >> dim;

  // Input first matrix
  a.set();

  // Input and check operation
  char ch;
  int op;

  // Determine operation
  for (int i=0;i<3;++i)
    {
      cin >> ch;
    }

  // Convert char into integer
  op = ch - '0';
  switch(op) {
  case 1:
    {
      b.set();
      c = a+b;
      cout << c << endl;
    }
    break;
  case 2:
    {
      b.set();
      c = a-b;
      cout << c << endl;
    }
    break;
  case 3:
    {
      b.set();
      c = a*b;
      cout << c << endl;
    }
    break;
  case 4:
    {
      ++a;
      cout << a << endl;
    }
    break;
  case 5:
    {
      --a;
      cout << a << endl;
    }
    break;
  }
  return 0;
}
