#include<iostream>
#include<fstream>
#include<vector>
#include<cfloat>
#include<random>
using namespace std;

struct index_sum
{
	int max_left = -1;
	int max_right = -1;
	double sum = -DBL_MAX;
};

index_sum find_max_crossing_subarray(vector<double>& A, int low, int mid, int high);
index_sum find_max_subarray(vector<double>& A, int low, int high);

int main()
{
	default_random_engine e(0);
	uniform_real_distribution<double> u(-1000, 1000);
	vector<double> test_array(1000);
	for (double & i : test_array)
		i = u(e);
	ofstream array_bak(R"(C:\Users\Benson\Documents\code\Algorithms\Section-1\Chapter4\array_bak.txt)");
	if (array_bak.is_open())
	{
		cout << "txt file is open" << endl;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				array_bak << test_array[i * 10 + j] << "\t";
			}
			array_bak << endl;
		}

		//array_bak.clear();
		array_bak.close();
	}

	index_sum result = find_max_subarray(test_array, 0, test_array.size() - 1);

	cout << "The left index is " << result.max_left << " , the right index is " << result.max_right 
		<< " , the sum is " << result.sum << " ." << endl;
	return 0;
}

index_sum find_max_crossing_subarray(vector<double>& A, int low, int mid, int high)
{
	double left_sum = -DBL_MAX;
	double sum = 0;
	int max_left = -1;
	for (int i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	double right_sum = -DBL_MAX;
	sum = 0;
	int max_right = mid;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	index_sum result;
	result.max_left = max_left;
	result.max_right = max_right;
	result.sum = left_sum + right_sum;

	return result;
}

index_sum find_max_subarray(vector<double>& A, int low, int high)
{
	if (high == low)
	{
		index_sum result;
		result.max_left = low;
		result.max_right = high;
		result.sum = A[low];
		return result;
	}

	int mid = (low + high) / 2;
	index_sum left_result = find_max_subarray(A, low, mid);
	index_sum right_result = find_max_subarray(A, mid + 1, high);
	index_sum cross_result = find_max_crossing_subarray(A, low, mid, high);

	if (left_result.sum >= right_result.sum && right_result.sum >= cross_result.sum)
		return left_result;
	if (right_result.sum >= left_result.sum && right_result.sum >= cross_result.sum)
		return right_result;
	return cross_result;
}
