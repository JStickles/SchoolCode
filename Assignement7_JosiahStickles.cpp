//Josiah Stickles

// Define a function that takes a partially filled array of doubles
// as one of two arguments (the other is the size), and returns the
// standard deviation of the numbers in the partially filled array.
// Embed in a program and test.

#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 10;

// Pre: size <= declared size of the array argument
// Post: return the standard deviation first size array elements
// Note: The divisor is the size, not size - 1 as some
// formulas call for.
double stdDev(const double s[], int size, double & avg);

// Pre: size <= declared size of the array argument
// Post: return the mean of the first size array elements
double average(const double s[], int size);

int main()
{
	double s[MAX_SIZE];
	double stdDeviation, avg;
	char ans;
	int i;

	do
	{
		cout << "Enter up to " << MAX_SIZE << " values\n";



		ans = 'y';
		i = 0;
		while (i < MAX_SIZE && ans == 'y')
		{
			cout << "Enter value #:" << (i + 1) << " ";
			cin >> s[i];
			i++;
			cout << "Do you have more numbers (y/n)? ";
			cin >> ans;
		}

		stdDeviation = stdDev(s, i, avg);

		cout << "\n\nThe Average is: "
			<< avg << endl;
		cout << "The Standard Deviation is: "
			<< stdDeviation << endl;
		cout << "Y/y continues, any other quits.\n";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}

double stdDev(const double s[], int size, double & avg)
{
	double sum = 0;
	double standardDev;
	avg = average(s, size);
	for (int i = 0; i < size; i++)
	{
		sum += pow((s[i] - avg), 2);
	}
	standardDev = sqrt(sum / size);
	return standardDev;
}

double average(const double s[], int size)
{
	double sum = 0;
	double average;
	for (int i = 0; i < size; i++)
	{
		sum += s[i];
	}
	average = sum / size;
	
	return average;
}
