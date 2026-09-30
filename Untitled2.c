#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
    int n = 5;

    int choice;
    int value, pos, newValue, target;
    int i;
    int foundCount;

    do {
        printf("\n=====================================================\n");
        printf("        CHUONG TRINH QUAN LY TON KHO MINIMART\n");
        printf("=====================================================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);

        switch (choice) {

            /* CASE 1: THEM */
            case 1:
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }

                printf("Nhap gia tri can them: ");
                scanf("%d", &value);

                printf("Nhap vi tri can chen (1 - %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                    break;
                }

                for (i = n; i >= pos; i--) {
                    stock[i] = stock[i - 1];
                }

                stock[pos - 1] = value;
                n++;

                printf("Mang sau khi them: [");
                for (i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");

                break;

            /* CASE 2: SUA */
            case 2:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);

                printf("Nhap gia tri moi: ");
                scanf("%d", &newValue);

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                    break;
                }

                if (newValue < 0) {
                    printf("So luong ton kho khong hop le!\n");
                    break;
                }

                stock[pos - 1] = newValue;

                printf("Mang sau khi sua: [");
                for (i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");

                break;

            /* CASE 3: XOA */
            case 3:
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                    break;
                }

                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    stock[i] = stock[i + 1];
                }

                n--;

                printf("Mang sau khi xoa: [");
                for (i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");

                break;

            /* CASE 4: TIM KIEM */
            case 4:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);

                foundCount = 0;

                for (i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        if (foundCount == 0) {
                            printf("Tim thay tai vi tri: ");
                        }

                        printf("%d", i + 1);
                        foundCount++;

                        if (i < n - 1) {
                            printf(", ");
                        }
                    }
                }

                if (foundCount == 0) {
                    printf("Khong tim thay gia tri trong mang!\n");
                } else {
                    printf("\nTong so lan xuat hien: %d\n", foundCount);
                }

                break;

            /* THOAT */
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;

            /* LUA CHON SAI */
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}
