#include <iostream>
using namespace std;
//Chris Devito
//250957375
//1037 Assignment 1
//October 2nd 2018

double calcAverage(char * values[], int sz);//these are my function prototypes
double calcMedian(char * values[], int sz);
double calcSum(char * values[]);
void selectionSort(double arr[], int sz);


void selectionSort(double arr[], int sz) { //selection sort 
	for (int x = 0; x < sz - 1; x++) 
	{
		int min = x;//sets min to initial array element 
		for (int y = x + 1; y < sz; y++) {
			if (*(arr+y) < *(arr+min)) min = y; //if an element in array is less than x, that element becomes y
		}
		if (min != x) {
			double temp = *(arr+min);//code to swap 2 elements in the array
			*(arr+min) = *(arr+x);
			*(arr+x) = temp;
		}
	}

	


}


	

double calcAverage(char * values[], int sz)
{
	cout << "AVERAGE" << endl;
	
	double *arr;
	arr = new double[sz];
	for (int i = 0; i < sz; i++) {
		arr[i] = atof(values[i]);
	}
	double average;
	double numerator(0);
	for (int j = 0; j < sz; j++)
	{
		numerator = numerator + arr[j];
	}

	average = numerator / sz;//average is the sum of all elements in array divided by total number of array elements
	return average;

	delete[]arr;
}

double calcMedian(char * values[], int sz)
{
	cout << "MEDIAN" << endl;
	double *arrPtr = new double[sz];
	
	for (int i = 0; i < sz; i++) {
		*(arrPtr + i) = atof(*(values+i));
	}
	
	selectionSort(arrPtr, sz);//calls selection sort function
	double median(0);
	if (sz % 2 != 0)
	{
		
		median = *(arrPtr+ (sz / 2));//if array has a odd number of integers, the median is the middle number in array
	}
	
	if (sz % 2 == 0)
	{
		median = (*(arrPtr + (sz / 2)) + *(arrPtr + (sz / 2 - 1))) / 2;//if array has even total integers the median is the average of the middle 2 numbers
	}

	return median;
	delete [] arrPtr;
}
double calcSum(char * values[])
{
	static double array[3];
	for (int i = 0; i < 3; i++) {
		array[i] = atof(values[i]);//changes array values to doubles
	}
	double sum = 0;
	
	for (int x = 0; x < 3; x++)
	{
		sum = sum + array[x];//sum equals the sum plus the value of each element in array
	}
	
	
	cout << "SUM" << endl;
	return sum;
}

int main(int argc, char *argv[]) {
	
	
	if (*argv[1] == 'F')// if first thing user enters on command line is F then the following occurs
	{
		cout << endl;
		
		double sum = calcSum(&argv[2]);//calls sum function
		for (int x = 2; x < argc; x++)
		{
			cout << argv[x]<< " ";
		}
		cout << endl;
		cout << sum<<endl;
	}
	
	else if (*argv[1] == 'M')//if users enters M first on command line
	{
		double median = calcMedian(&argv[2], argc - 2);//calls median function
		for (int x = 2; x < argc; x++)
		{
			cout << argv[x] << " ";
		}
		cout << endl;
		cout << median << endl;
	
	
	}
	
	else if (*argv[1] == 'A')//if user enters A first on command line
	{
		double avg = calcAverage(&argv[2], argc - 2);//average function is called
		for (int x = 2; x < argc; x++)
		{
			cout << argv[x] << " ";
		}
		cout << endl;
		cout << avg << endl;
	}
	
}
