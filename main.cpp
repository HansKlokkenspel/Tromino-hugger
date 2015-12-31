#include <iostream>
#include <string>
#include "Quadrant.h"

void divide(bool** board, int range);
void divide(const Quadrant& otherQuadrant, int range);

int main() {
    // Row/column
    bool** board;
    board = new bool* [16]();

    for (int i = 0; i < 16; ++i) {
        board[i] = new bool[16]();
    }

    // fixed starting point
    board[1][1] = 1;

    divide(board, 8);

    std::cout << "First quadrant is finished!" << std::endl;
}

void divide(bool** board, int range) {
    Orientation orientation = Orientation::LTC;
    int rowCount = 0;
    int colCount = 0;

    for (int i = 0; i < 4; ++i) {
        // Init quadrant
        Quadrant quadrant(1, 1, range, orientation);
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

        // End init

        //Update quadrant
        if (!quadrant.setFill()) {
            // If a filled in element has not been found, fill in the intersection with the other quadrants
            quadrant.fillIntersection();
        }

        //Check quadrant
        if (!quadrant.isFilledIn() && !quadrant.checkBaseCase()) {
            divide(quadrant, range / 2);
            return;
        }

    }
}


void divide(const Quadrant& otherQuadrant, int range) {
    Orientation orientation = Orientation::LTC;

    int rowCount = 0;
    int colCount = 0;

    for (int i = 0; i < 4; ++i) {
        // Init quadrant
        Quadrant quadrant(otherQuadrant.rowBegin, otherQuadrant.colBegin, range, orientation);
        for (int row = quadrant.getRowBegin(); row <= quadrant.getRowEnd(); ++row) {
            for (int col = quadrant.getColBegin(); col <= quadrant.getColEnd(); ++col) {
                quadrant.setQuadrantElement(rowCount, colCount, otherQuadrant.quadrant[row][col]);
                ++colCount;
            }
            colCount = 0;
            ++rowCount;
        }

        rowCount = 0;

        orientation++;
        quadrant.setIntersection();

        // End init

        //Update quadrant
        if (!quadrant.setFill()) {
            // If a filled in element has not been found, fill in the intersection with the other quadrants
            quadrant.fillIntersection();
        }

        //Check quadrant
        if (!quadrant.isFilledIn() && !quadrant.checkBaseCase()) {
            divide(quadrant, range / 2);
        } else {
            quadrant.fillQuadrant();
        }

    }
}