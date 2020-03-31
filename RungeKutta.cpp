// C++ program to implement Runge Kutta method
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
# include <omp.h>
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

// A sample differential equation "dy/dx = (x - y)/3"
float dydx(float x, float y)
{
    return((x - y)/3);
}

float rungeKutta(float x0, float y0, float x, float h)
{
    int n = (int)((x - x0) / h);

    float k1, k2, k3, k4, k5;

    float y = y0;
    for (int i=1; i<=n; i++)
    {
        k1 = h*dydx(x0, y);
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*dydx(x0 + h, y + k3);

        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        x0 = x0 + h;
    }
    return y;
}

int main()
{
	timespec time1, time2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    float x0 = 0, y = 1, x = 2, h = 0.2;
    cout << "The value of y at x is: " << rungeKutta(x0, y, x, h)<<endl;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    cout<<"The time taken to execute is:" << diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;
    return 0;
}
