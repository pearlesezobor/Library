#include <chrono>
#include <iostream>
#include "sorting.h"
#include <vector>

using namespace std;

using std::chrono::system_clock;

using std::chrono::duration_cast;

using std::chrono::nanoseconds;

int main()

{
	vector<int> sizes = { 250000,500000,1000000 };
	cout << "Bubble Sort Results:" << endl;
	

	for (int size : sizes)
	{
		vector<int> data = random(size);
		// Get the current time in seconds.

		auto now = system_clock::now(); //current time
		bubbleSort(data, size);

		// Calculate the current time in nanoseconds.

		auto difference = duration_cast<nanoseconds>(now.time_since_epoch());

		// Store the result in a large integer (long long)

		long long current_time_nano = difference.count();
		long long current_time_seconds = current_time_nano / 1e9;

		cout << "->Size:\t " << size << "\tTime:\t " << current_time_nano << "ns\t" << "Time:\t " << current_time_seconds << " seconds\n";
		
	}
	cout << "\nQuick Sort\n";
	for (int size : sizes)
	{
		vector <int> data_quick = random(size);
		auto now_quick = system_clock::now();
		quickSort(data_quick,0, size - 1);
		auto difference_quick = duration_cast<nanoseconds>(now_quick.time_since_epoch());
		long long current_time_quick_nano = difference_quick.count();
		long long current_time_quick_seconds = current_time_quick_nano / 1e9;
		cout << "->Size:\t " <<  size << "\tTime: \t" << current_time_quick_nano << "ns\t" << "Time:\t " << current_time_quick_seconds << " seconds\n";
	}
	return 0;
}

