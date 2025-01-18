#include <iostream>
using namespace std;

int binary_search(int target, int list[], int left, int right) {
    if(left < 0 || right > sizeof(list) || left > right) return -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == target) {
            return mid;
        } else if (list[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    bubbleSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    while (true) {
        int num;
        cout << "What number you want to find or input -99 to exit? ";
        cin >> num;
        if (num == -99) {
            break;
        }

        int left, right;
        cout << "Enter the range to search (left and right): ";
        cin >> left >> right;

        int result = binary_search(num, a, left, right);
        if (result != -1) {
            cout << "Number " << num << " is at index " << result << endl;
        } else {
            cout << "Number " << num << " is not found in the given range." << endl;
        }
    }
    return 0;
}
