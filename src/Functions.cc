#include "Functions.hh"
#include <stdio.h>
#include <sstream>
#include <iostream>

extern int m;
extern double TOLERANCE;

using namespace std;

// Chop functions returns 0 if the arg is below a certain tolerance 

double chop (double x){

  double chopped;
  if(abs(x) < TOLERANCE){
    chopped = 0;
  }
  else{
    chopped = x;
  }
  return chopped;
}

double Squared(double x){ return (x*x);}

double SquareRoot(double x){return pow(x,0.5);}

// Hermite function for eigenfunctions

double Hermite(const int& n, const double& x){

    double result=0,a,b;
    int i;

    // Prepare A and B
    a = 1;
    b = 2*x;

    // Special cases: N=0 or N=1
    if(n==0){
       result = a;
       return result;
    }
    if(n==1){
       result = b;
       return result;
    }

    // General case: N>=2
    for(i = 2; i <= n; i++){
       result = 2*x*b-2*(i-1)*a;
       a = b;
       b = result;
    }
    return result;

}

double Factorial(double x){

  double answer = 1, current = 1;

  while (current <= x){
    answer *= current;
    current++;
  }
  return answer;
}

// Converts the partition function to free energy in dimensionless form

double Free_Energy(double x){ return -log(x);}

string intToString(int x){

    stringstream ss;
    std::string s;
    ss << x;
    s = ss.str();
    return s;
}

int r(int i,int j){
	return (i-1)*(2*m+1)+j;
}

void CheckNegative(double x){
	if(x < 0){
		cout << "\n WARNING!!! NEGATIVE NUMBER DETECTED \n";
		//exit(0);
	}
}



