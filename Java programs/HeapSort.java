package com.company;

public class HeapSort {

    public void sort(int[] arr) {
        int input = arr.length;

        for (int i = input / 2 - 1; i >= 0; i--) {
            heapSort(arr, input, i);
        }

        for (int i = input - 1; i >= 0; i--) {
            int length = arr[0];
            arr[0] = arr[i];
            arr[i] = length;
            heapSort(arr, i, 0);
        }
    }

    void heapSort(int[] arr, int n, int i) {
        int max = i;
        int a = 2 * i + 1;
        int b = 2 * i + 2;

        if (a < n && arr[a] > arr[max])
            max = a;

        if (b < n && arr[b] > arr[max])
            max = b;

        if (max != i) {
            int swap = arr[i];
            arr[i] = arr[max];
            arr[max] = swap;

            heapSort(arr, n, max);
        }
    }

    void printArray(int[] arr) {
        System.out.print("Heap Sort : ");
        for (int value : arr) System.out.print(value + " ");
        System.out.println();
    }
}
public class Main {
    public static void main(String[] args) {
        HeapSort heapSort = new HeapSort();
        int[] array = {23, 43, 12, 50, 5, 17, 8, 60, 11, 3};
        heapSort.sort(array);
        heapSort.printArray(array);
    }
}
