#include <iostream>
#include <string>
#include <forward_list>
#include "Quadrant.h"

void divide(bool** board, int range);
void divide(const Quadrant& otherQuadrant, int range, bool** board);

int main() {
    // Row/column
    bool** board;
    board = new bool* [16]();

    for (int i = 0; i < 16; ++i) {
        board[i] = new bool[16]();
    }

    // fixed starting point
    board[5][7] = 1;

    divide(board, 8);

    std::cout << "--------------" << std::endl;
    for (int i = 0; i < 16; ++i) {
        if (i) { std::cout << "--------------" << std::endl; }
        for (int j = 0; j < 16; ++j) {
            if (j) { std::cout << "-"; }
            std::cout << board[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
}

void divide(bool** board, int range) {
    Orientation orientation = Orientation::LTC;
    std::forward_list<Quadrant> quadrants;
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
        quadrant.setIntersection(range);
        quadrants.push_front(quadrant);
        // End init
    }

    for (Quadrant& q : quadrants) {
        if (!q.setFill()) {
            q.fillIntersection();
        }
    }

    for (Quadrant& q : quadrants) {
        if (!q.isFilledIn() && !q.checkBaseCase()) {
            divide(q, range / 2, board);
        }
    }
}


void divide(const Quadrant& otherQuadrant, int range, bool** board) {
    Orientation orientation = Orientation::LTC;
    std::forward_list<Quadrant> quadrants;

    int rowCount = 0;
    int colCount = 0;

    for (int i = 0; i < 4; ++i) {
        // Init quadrant
        Quadrant quadrant(otherQuadrant.rowBegin, otherQuadrant.colBegin, range, orientation);
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
        quadrant.setIntersection(range);
        quadrants.push_front(quadrant);
        // End init
    }

    for (Quadrant& q : quadrants) {
        if (!q.setFill()) {
            q.fillIntersection();
        }
    }

    for (Quadrant& q : quadrants) {
        if (!q.isFilledIn() && !q.checkBaseCase()) {
            divide(q, range / 2, board);
        } else {
            q.fillQuadrant();
        }
    }
}

