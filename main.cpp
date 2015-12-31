#include <iostream>
#include <string>
#include "Quadrant.h"

void divide(bool** board, int rowBegin, int colBegin, int range);

int main() {
    // Row/column
    bool** board;
    board = new bool* [16]();

    for (int i = 0; i < 16; ++i) {
        board[i] = new bool[16]();
    }

    // fixed starting point
    board[1][1] = true;

    divide(board, 0, 0, 7);

    std::cout << "First quadrant is finished!" << std::endl;

}

void divide(bool** board, int rowBegin, int colBegin, int range) {
    Orientation orientation = Orientation::LTC;
    int rowCount = 0;
    int colCount = 0;

    for (int i = 0; i < 4; ++i) {
        Quadrant quadrant(rowBegin, colBegin, range, orientation);
        for (int row = quadrant.getRowBegin(); row <= quadrant.getRowEnd(); ++row) {
            for (int col = quadrant.getColBegin(); col <= quadrant.getColEnd(); ++col) {
                quadrant.setQuadrantElement(rowCount, colCount, &board[row][col]);
                ++colCount;
            }
            colCount = 0;
            ++rowCount;
        }

        rowCount = 0;

        orientation++;
        quadrant.setIntersection();

        // If a filled in element has not been found, fill in the intersection with the other quadrants
        if(!quadrant.setFill()){
            quadrant.fillIntersection();
        }
    }
}

