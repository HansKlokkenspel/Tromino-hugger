#include <iostream>
#include <string>
#include "Quadrant.h"

void sickReference(bool* (& ref)[4][4]);

int main() {
    // Row/column
    bool** boolArray = new bool* [16]();

    for (int i = 0; i < 16; ++i) {
        boolArray[i] = new bool[16]();
    }

    // fixed starting point
    boolArray[7][7] = true;
    boolArray[7][8] = true;
    boolArray[8][7] = true;
    boolArray[8][8] = true;

    Quadrant q1(0, 1, 0, 1);

    for (int i = 0; i <= q1.getRowEnd(); ++i) {
        for (int j = 0; j <= q1.getColEnd(); ++j) {
            q1.setQuadrantElement(i, j, &boolArray[i][j]);
        }
    }

    q1.setOrientation(Quadrant::Orientation::LTC);
    q1.setIntersection();
}



