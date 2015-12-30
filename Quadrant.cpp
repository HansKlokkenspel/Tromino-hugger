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
            orientation = RBG;
            break;
        case RBG:
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
            rowBegin = row + range;
            rowEnd = rowBegin + range;
            colBegin = col;
            colEnd = col + range;
            break;
        case RBG:
            rowBegin = row + range;
            rowEnd = rowBegin + range;
            colBegin = col;
            colEnd = colBegin + range;
            break;
    }
}

void Quadrant::setQuadrantElement(int row, int col, bool* element) {
    quadrant[row][col] = element;
}

void Quadrant::fillIntersection() {
    *intersection = true;
}

void Quadrant::setIntersection() {
    switch (orientation) {
        case LTC:
            intersection = quadrant[rowEnd][colEnd];
            break;
        case RTC:
            intersection = quadrant[rowEnd][colBegin];
            break;
        case LBC:
            intersection = quadrant[rowBegin][colEnd];
            break;
        case RBG:
            intersection = quadrant[rowBegin][colBegin];
            break;
    }
}

void Quadrant::setOrientation(const Orientation& orientation) {
    this->orientation = orientation;
}

int Quadrant::getColEnd() {
    return colEnd;
}

int Quadrant::getRowEnd() {
    return rowEnd;
}

bool Quadrant::checkBaseCase() {
    return hasFill && (rowEnd - rowBegin == 2);
}

int Quadrant::getColBegin() {
    return colBegin;
}

int Quadrant::getRowBegin() {
    return rowBegin;
}
