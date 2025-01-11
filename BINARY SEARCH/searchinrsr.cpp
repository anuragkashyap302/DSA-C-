#include<iostream>
using namespace std;

int getpivot(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int mid;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

int binarySearch(int arr[], int start, int end, int target) {
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;  // Element not found
}

int search(int arr[], int size, int pivot, int target) {
    if (target >= arr[pivot] && target <= arr[size - 1]) {
        return binarySearch(arr, pivot, size - 1, target);
    } else {
        return binarySearch(arr, 0, pivot - 1, target);
    }
}

int main() {
    int odd[5] = {8, 10, 17, 1, 3};
    int pivot = getpivot(odd, 5);
    cout << "Pivot is at index: " << pivot << endl;
    int key = 10;
    int targetIndex = search(odd, 5, pivot, key);
    if (targetIndex != -1) {
        cout << "Element found at index: " << targetIndex << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
