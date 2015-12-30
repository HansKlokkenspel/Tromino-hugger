#include "Quadrant.h"

Quadrant::Quadrant(int rowBegin, int rowEnd, int colBegin, int colEnd) :
        rowBegin(rowBegin), rowEnd(rowEnd), colBegin(colBegin), colEnd(colEnd) {
}

void Quadrant::setQuadrantElement(int row, int col, bool* element) {
    quadrant[row][col] = element;
}

bool* Quadrant::getIntersection() {
    return intersection;
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

void Quadrant::setOrientation(const Quadrant::Orientation& orientation) {
    this->orientation = orientation;
}

int Quadrant::getColEnd() {
    return colEnd;
}

int Quadrant::getRowEnd() {
    return rowEnd;
}

bool Quadrant::checkBaseCase() {
    return hasFill && (rowEnd-rowBegin == 2);
}
