#include "stationDistance.h"
#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))

int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]) {
    int cnt[3] = {}, ans = 0;
    cnt[startStation[0]]++; cnt[endStation[0]]++;
    if (cnt[0] == 2) {
        for (int i = min(startStation[1], endStation[1]) - 1; i < max(startStation[1], endStation[1]) - 1; i++) {
            ans += R_distance[i];
        }
    } else if (cnt[1] == 2) {
        for (int i = min(startStation[1], endStation[1]) - 1; i < max(startStation[1], endStation[1]) - 1; i++) {
            ans += G_distance[i];
        }
    } else if (cnt[2] == 2) {
        for (int i = min(startStation[1], endStation[1]) - 1; i < max(startStation[1], endStation[1]) - 1; i++) {
            ans += B_distance[i];
        }
    } else if (cnt[0] == 1 && cnt[1] == 1) {
        int R, G;
        if (startStation[0] == 0) {
            R = startStation[1];
            G = endStation[1];
        } else {
            R = endStation[1];
            G = startStation[1];
        }
        for (int i = min(R, G_origin) - 1; i < max(R, G_origin) - 1; i++) {
            ans += R_distance[i];
        }
        for (int i = 0; i < G - 1; i++) {
            ans += G_distance[i];
        }
    } else if (cnt[1] == 1 && cnt[2] == 1) {
        int B, G;
        if (startStation[0] == 1) {
            G = startStation[1];
            B = endStation[1];
        } else {
            G = endStation[1];
            B = startStation[1];
        }
        for (int i = min(B, G_destination) - 1; i < max(B, G_destination) - 1; i++) {
            ans += B_distance[i];
        }
        for (int i = G - 1; G_distance[i]; i++) {
            ans += G_distance[i];
        }
    } else if (cnt[2] == 1 && cnt[0] == 1) {
        int R, B;
        if (startStation[0] == 0) {
            R = startStation[1];
            B = endStation[1];
        } else {
            R = endStation[1];
            B = startStation[1];
        }
        for (int i = min(R, G_origin) - 1; i < max(R, G_origin) - 1; i++) {
            ans += R_distance[i];
        }
        for (int i = 0; G_distance[i]; i++) {
            ans += G_distance[i];
        }
        for (int i = min(B, G_destination) - 1; i < max(B, G_destination) - 1; i++) {
            ans += B_distance[i];
        }
    }
    return ans;
}