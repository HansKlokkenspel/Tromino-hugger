#include <iostream>
#include <iomanip>
#include "Quadrant.h"

Orientation& operator++(Orientation& orientation) {
    switch (orientation) {
        case LTC:
            orientation = RTC;
            break;
        case RTC:
            orientation = LBC;
            break;
        case LBC:
            orientation = RBC;
            break;
        case RBC:
            orientation = LTC;
            break;
    }
    return orientation;
}

Orientation operator++(Orientation& orientation, int) {
    Orientation tmp(orientation);
    ++orientation;
    return tmp;
}

Quadrant::Quadrant(int row, int col, int range, const Orientation& orientation) :
        orientation(orientation) {
    range -= 1;
    switch (orientation) {
        case LTC:
            rowBegin = row;
            rowEnd = row + range;
            colBegin = col;
            colEnd = col + range;
            break;
        case RTC:
            rowBegin = row;
            rowEnd = row + range;
            colBegin = col + range + 1;
            colEnd = colBegin + range;
            break;
        case LBC:
            rowBegin = row + range + 1;
            rowEnd = rowBegin + range;
            colBegin = col;
            colEnd = col + range;
            break;
        case RBC:
            rowBegin = row + range + 1;
            rowEnd = rowBegin + range;
            colBegin = col + range + 1;
            colEnd = colBegin + range;
            break;
    }
}

void Quadrant::setQuadrantElement(int row, int col, bool* element) {
    quadrant[row][col] = element;
}

void Quadrant::fillIntersection() {
    *intersection = true;
    hasFill = true;
    printQuadrant();
}

void Quadrant::setIntersection() {
    switch (orientation) {
        case LTC:
            intersection = quadrant[rowEnd -1][colEnd - 1];
            break;
        case RTC:
            intersection = quadrant[rowEnd - 1][0];
            break;
        case LBC:
            intersection = quadrant[0][colEnd - 1];
            break;
        case RBC:
            intersection = quadrant[0][0];
            break;
    }
}

void Quadrant::setOrientation(const Orientation& orientation) {
    this->orientation = orientation;
}

int Quadrant::getColEnd() const {
    return colEnd - 1;
}

int Quadrant::getRowEnd() const {
    return rowEnd - 1;
}

int Quadrant::getColBegin() const {
    return colBegin - 1;
}

int Quadrant::getRowBegin() const {
    return rowBegin - 1;
}

bool Quadrant::checkBaseCase() {
    return hasFill && (rowEnd - rowBegin == 2);
}

bool Quadrant::setFill() {
    for (int row = 0; row <= (getRowEnd() - getRowBegin()); ++row) {
        for (int col = 0; col <= (getColEnd() - getColBegin()); ++col) {
            if (*quadrant[row][col]) {
                hasFill = true;
                return hasFill;
            }
        }
    }

    return false;
}

void Quadrant::printQuadrant() {
    std::cout << "--------------" << std::endl;
    for (int row = 0; row <= (getRowEnd() - getRowBegin()); ++row) {
        if (row) { std::cout << "--------------" << std::endl; }
        for (int col = 0; col <= (getColEnd() - getColBegin()); ++col) {
            if (col) { std::cout << "-"; }
            std::cout << *quadrant[row][col];
        }
        std::cout << std::endl;
    }

    std::cout << "End of quadrant: " << orientation << std::endl;
}

bool Quadrant::isFilledIn() {
    for (int row = 0; row <= (getRowEnd() - getRowBegin()); ++row) {
        for (int col = 0; col <= (getColEnd() - getColBegin()); ++col) {
            if (!*quadrant[row][col]) {
                return false;
            }
        }
    }

    return true;
}
