#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int k, N, total_sum = 0;

    cout << "threads: "; cin >> k;
    cout << "elements: "; cin >> N;

    int* numbers = new int[N];
    for (int i = 0; i < N; ++i) numbers[i] = i + 1;

#pragma omp parallel num_threads(k) reduction(+:total_sum)
    for (int i = 0; i < N; ++i)
        total_sum += numbers[i];

    delete[] numbers;

    cout << "Sum: " << total_sum << endl;

    return 0;
}
