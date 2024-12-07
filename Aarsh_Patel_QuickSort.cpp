#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

// Swap function to swap two elements
void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

// Function to find the median-of-three as pivot
int medianOfThree(vector<float>& arr, int left, int right) {
    int mid = left + ((right - left) / 2);

    if (arr[left] > arr[mid]) {
        swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (arr[mid] > arr[right]) {
        swap(arr[mid], arr[right]);
    }

    return mid;  // Return the index of the median
}

// Partition function using median-of-three pivot selection
int partition(vector<float>& arr, int left, int right) {
    int s = medianOfThree(arr, left, right);
    swap(arr[left], arr[s]);  // Move pivot to the beginning
    float pivot = arr[left];
    int i = left + 1;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[left], arr[i - 1]);
    return i - 1;  // Return pivot index
}

// Quick Sort function
void quickSort(vector<float>& arr, int left, int right) {
    if (left < right) {
        int s = partition(arr, left, right);
        quickSort(arr, left, s - 1);
        quickSort(arr, s + 1, right);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./Patel_Aarsh_QuickSort input.txt output.txt\n";
        return 1;
    }

    string input = argv[1];
    string output = argv[2];

    ifstream inFile(input);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    vector<float> arr;
    float num;
    while (inFile >> num) {
        arr.push_back(num);
    }

    inFile.close();

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    ofstream outFile(output);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open output file.\n";
        return 1;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        outFile << arr[i];
        if (i != arr.size() - 1) {
            outFile << " ";
        }
    }
    outFile.close();

    ofstream timeFile("executionTime.txt");
    if (!timeFile.is_open()) {
        cerr << "Error: Could not open execution time file.\n";
        return 1;
    }
    timeFile << "Execution Time (microseconds): " << duration.count() << "\n";
    timeFile.close();

    cout << "Sorting complete. Results written to output files.\n";
    return 0;
}
