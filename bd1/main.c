#include <stdio.h>

int main() {
    int max_month = 1;
    int max_usage_month = 1;
    double total_cost = 0;
    double max_cost = 0;
    double max_kwh = -1;

    printf("=== ЦАХИЛГААНЫ ТӨЛБӨРИЙН ТООЦОО ===\n\n");

    printf("%-10s %-15s %-15s\n", "Сар", "Хэрэглээ (kWh)", "Төлбөр (MNT)");
    printf("------------------------------------------\n");
    for (int month = 1; month <= 12; month++) {
        double kwh;
        double cost;

        printf("%d-р сарын цахилгааны хэрэглээг оруулна уу (kWh): ", month);
        scanf("%lf", &kwh);

        if (kwh < 0) {
            printf("Хүчингүй оролт! 0 буюу түүнээс их тоо оруулна уу.\n");
            month--;
            continue;
        }

        if (kwh <= 150) {
            cost = kwh * 120;
        }
        else if (kwh <= 300) {
            cost = 150 * 120 + (kwh - 150) * 180;
        }
        else {
            cost = 150 * 120 + 150 * 180 + (kwh - 300) * 250;
        }

        printf("%-10d %-15.1f %-15.2f\n", month, kwh, cost);

        total_cost += cost;

        if (cost > max_cost) {
            max_cost = cost;
            max_month = month;
        }

        if (kwh > max_kwh) {
            max_kwh = kwh;
            max_usage_month = month;
        }
    }

    printf("------------------------------------------\n");
    printf("Жилийн нийт төлбөр: %.2f MNT\n", total_cost);
    printf("Хамгийн өндөр төлбөртэй сар: %d-р сар (%.2f MNT)\n",
           max_month, max_cost);
    printf("Хамгийн их цахилгаан хэрэглэсэн сар: %d-р сар (%.1f kWh)\n",
           max_usage_month, max_kwh);

    printf("\n=== ЦАХИЛГААН ХЭМНЭХ ЗӨВЛӨМЖ ===\n");
    printf("1. Ашиглаагүй гэрэл болон цахилгаан хэрэгслээ унтраах.\n");
    printf("2. Эрчим хүчний хэмнэлттэй LED гэрэл ашиглах.\n");
    printf("3. Цахилгаан хэрэгслийг ашиглахгүй байгаа үед залгуураас салгах.\n");
    printf("4. Цахилгааны хэрэглээгээ сар бүр хянаж, өндөр хэрэглээтэй саруудад анхаарах.\n");

    return 0;
}