#include<stdio.h>
 
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int l, int r)
{
    int pivot = arr[r];    // pivot
    int left = l;
    int right = r - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[l], arr[r]);
    return left;
}
 

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
       
        int pi = partition(arr, l, r);
 		// goi de qui s?p xep 2 mang con trai phai
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
 
// ham xuat mang
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
 
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Mang sau khi sap xep: \n");
    printArray(arr, n);
    return 0;
}
