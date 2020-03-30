#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include<stdio.h>
#include <time.h>
using namespace std;

timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}


// Dynamically Allocate Memory for 2D Array in C++
int main()
{
  int M = 0;
  int N = 0;
  cout << "Enter the number of rows and columns for the first matrix: ";
  cin >> M >> N;

  int P = 0;
  int Q = 0;
  cout << "Enter the number of rows and columns for the second matrix: ";
  cin >> P >> Q;

	timespec time1, time2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);

	// dynamically allocate memory of large size
	int *Arr1 = new int[100000000];

	// assign values to first matrix
  srand (time(NULL));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			Arr1[i*N+j]= rand() % 10;

	// print the 2D array
  cout << "The elements of the first matrix are:" <<"\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Arr1[i*N+j] << "\t";

		cout << endl;
	}

  int sum=0,dsum=0;
  for (int i = 0; i < M; i++)
  {
  for (int j = 0; j < N; j++)
  {
    sum += Arr1[i*N+j];
    if(i==j)
    {
      dsum += Arr1[i*N+j];
    }
  }
  }
  cout << "The sum of the elements of first matrix is: " << sum << "\n" << "The sum of element of diagonal elements of first matrix is: " << dsum << "\n";

  int *Arr2 = new int[100000000];

	// assign values to 2nd matrix
	for (int i = 0; i < P; i++)
		for (int j = 0; j < Q; j++)
			Arr2[i*Q+j]= rand() % 10;

  cout << "The elements of the second matrix are:" <<"\n";

	// print the 2D array
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < Q; j++)
			cout << Arr2[i*Q+j] << "\t";

		cout << endl;
	}

  int *Arr3 = new int[100000000];

  // Initializing elements of matrix Arr3 to 0.
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < Q; ++j)
        {
            Arr3[i*Q+j]=0;
        }

// Check if the matrix multiplication condition is satisfied, perform matrix multiplication.
if(N == P){
  for (int i = 0; i < M; ++i)
  {
 		for (int j = 0; j < Q; ++j)
    {
     for(int k =0; k < N; ++k)
     {
 			Arr3[i*Q+j] += Arr1[i*N+k] * Arr2[k*Q+j];
    }
  }
}
cout << "The elements of the resultant matrix are:" <<"\n";

for (int i = 0; i < M; i++)
{
  for (int j = 0; j < Q; j++)
    cout << Arr3[i*Q+j] << "\t";

  cout << endl;
}
}
else{
  cout << "The number of rows of first matrix and the number of columns of second matrix ane unequal. Hence, multiplication cannot be performed." << "\n";
}

	// deallocate memory
	delete[] Arr1;
  delete[] Arr2;
  delete[] Arr3;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout<<"The time taken to execute is:" << diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	return 0;
	}
