#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void linearSearch(int arr[], int size, int key) {
    int found = 0;
    printf("Cac phan tu co gia tri bang %d la: ", key);
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay gia tri trong mang.\n");
    }
    printf("\n");
}
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
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
        printf("\nMENU\n");
        printf("1. In gia tri cac phan tu cua mang\n");
        printf("2. Tim kiem tuyen tinh\n");
        printf("3. Tim kiem nhi phan (yeu cau mang da duoc sap xep)\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Gia tri cac phan tu cua mang: ");
                printArray(arr, size);
                break;
            case 2: {
                int key;
                printf("Nhap gia tri can tim kiem: ");
                scanf("%d", &key);
                linearSearch(arr, size, key);
                break;
            }
            case 3: {
                int key;
                printf("Nhap gia tri can tim kiem (yeu cau mang da duoc sap xep): ");
                scanf("%d", &key);
                int result = binarySearch(arr, 0, size - 1, key);
                if (result != -1) {
                    printf("Gia tri %d tim thay tai vi tri %d trong mang.\n", key, result);
                } else {
                    printf("Gia tri %d khong tim thay trong mang.\n", key);
                }
                break;
            }

            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

