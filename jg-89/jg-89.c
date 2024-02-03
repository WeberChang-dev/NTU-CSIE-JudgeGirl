#include <stdio.h>

int main() {
    FILE *fin = fopen("test", "rb"), *fout = fopen("test.enc", "wb");
    int key, c;
    scanf("%d", &key);
    while ((c = fgetc(fin)) != EOF) {
        fputc(c ^ key, fout);
    }
    fclose(fin);
    fclose(fout);
}