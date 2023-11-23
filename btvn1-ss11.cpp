#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);
    int arr[size];
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int choice;
    do {
        // In menu
        printf("\nMENU\n");
        printf("1. In gia tri cac phan tu cua mang\n");
        printf("2. Su dung Insertion Sort sap xep mang giam dan va in ra\n");
        printf("3. Su dung Selection Sort sap xep mang tang dan va in ra\n");
        printf("4. Su dung Bubble Sort sap xep mang giam dan va in ra\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Gia tri cac phan tu cua mang: ");
                printArray(arr, size);
                break;

            case 2:
                insertionSortDescending(arr, size);
                printf("Mang sau khi su dung Insertion Sort sap xep giam dan: ");
                printArray(arr, size);
                break;

            case 3:
                selectionSortAscending(arr, size);
                printf("Mang sau khi su dung Selection Sort sap xep tang dan: ");
                printArray(arr, size);
                break;

            case 4:
                bubbleSortDescending(arr, size);
                printf("Mang sau khi su dung Bubble Sort sap xep giam dan: ");
                printArray(arr, size);
                break;

            case 5:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

