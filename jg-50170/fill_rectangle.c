#include "fill_rectangle.h"

void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill) {
    int flag = 1;
    for (int *i = upper_left; flag; i++) {
        for (int *j = i; j <= bottom_right; j += n_col) {
            *j = fill;
            if (j == bottom_right) {
                flag = 0;
            }
        }
    }
}

void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill) {
    int flag = 1;
    for (int *i = upper_right; flag; i--) {
        for (int *j = i; j - bottom_left < n_col; j += n_col) {
            *j = fill;
            if (j == bottom_left) {
                flag = 0;
            }
        }
    }
}