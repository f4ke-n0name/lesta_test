#include <iostream>
#include <vector>

void Merge(long long* a, long long left, long long right, long long mid) {
  long long res[right - left];
  long long i = 0, j = 0;
  while (left + i < mid && j + mid < right) {
    if (a[left + i] <= a[j + mid]) {
      res[i + j] = a[left + i];
      ++i;
    } else {
      res[i + j] = a[mid + j];
      ++j;
    }
  }
  while (left + i < mid) {
    res[i + j] = a[left + i];
    ++i;
  }
  while (mid + j < right) {
    res[i + j] = a[mid + j];
    ++j;
  }
  for (long long k = 0; k < i + j; ++k) {
    a[left + k] = res[k];
  }
}

void MergeSort(long long* a, long long left, long long right) {
  if (left + 1 >= right) {
    return;
  }
  long long mid = (left + right) / 2;
  MergeSort(a, left, mid);
  MergeSort(a, mid, right);
  Merge(a, left, right, mid);
}

/*
  Реализовал сортировку слиянием, которая всегда выполняется за O(n log n) и
  требует O(n). Она стабильная. В отличие от сортировки слиянием, где требуется
  O(k), где k размер диапозона, она экономичнее по памяти. В отличие от
  quick_sort, которая работает за O(n log n) в среднем, она стабильная и к этой
  сортировке невозможно придумать тесты, когда она работала за O(n^2).
  Единственный минус, это O(n) памяти. Можно реализовать эту сортировку и без
  доп. памяти, но я не умею.
*/