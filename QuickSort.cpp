#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

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
}

int partition(vector<float>& arr, int left, int right) {
    int s = medianOfThree(arr, left, right);
    swap(arr[left], arr[s]);
    float pivot = arr[left];
    int i = left + 1;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[left], arr[i - 1]);
    return i - 1;
}