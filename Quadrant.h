#ifndef TROMINO_HUGGER_QUADRANT_H
#define TROMINO_HUGGER_QUADRANT_H

#include <vector>

enum Orientation : int {
    LTC, RTC, LBC, RBC
};

Orientation& operator++(Orientation& orientation);

Orientation operator++(Orientation& orientation, int);

class Quadrant {
public:
    Quadrant(const Quadrant&) = delete;
    Quadrant& operator=(const Quadrant&) = delete;
    Quadrant(int row, int col, int range, const Orientation& orientation);

    void setQuadrantElement(int row, int col, bool* element);
    void setOrientation(const Orientation& orientation);

    void fillIntersection();
    void setIntersection();

    int getColEnd() const;
    int getRowEnd() const;
    int getColBegin() const;
    int getRowBegin() const;

    bool checkBaseCase();
    bool isFilledIn();
    bool setFill();

    bool hasFill = false;
    bool* quadrant[8][8];
    bool* intersection;

    void printQuadrant();
    void fillQuadrant();
    int rowBegin;
    int rowEnd;
    int colBegin;
    int colEnd;

private:

    Orientation orientation;
};

#endif //TROMINO_HUGGER_QUADRANT_H
