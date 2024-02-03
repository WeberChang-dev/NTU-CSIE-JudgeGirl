#include "payment.h"

double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]) {
    double ret = 0;
    for (int i = 0; onSaleItemID[i]; i++) {
        for (int j = 0; itemID[j]; j++) {
            if (itemID[j] == onSaleItemID[i]) {
                price[j] *= 0.8;
                break;
            }
        }
    }
    for (int i = 0; orderItemID[i]; i++) {
        for (int j = 0; itemID[j]; j++) {
            if (itemID[j] == orderItemID[i]) {
                ret += price[j] * orderQuantity[i];
                break;
            }
        }
    }
    if (ret < 490.0) ret += 80;
    return ret;
}