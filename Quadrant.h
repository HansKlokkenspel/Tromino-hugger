#ifndef TROMINO_HUGGER_QUADRANT_H
#define TROMINO_HUGGER_QUADRANT_H

#include <vector>

enum Orientation : int {
    LTC, RTC, LBC, RBG
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

    int getColEnd();
    int getRowEnd();
    int getColBegin();
    int getRowBegin();

    bool checkBaseCase();

    bool hasFill;
    bool* quadrant[8][8];
    bool* intersection;
private:

    int rowBegin;
    int rowEnd;
    int colBegin;
    int colEnd;

    Orientation orientation;
};

#endif //TROMINO_HUGGER_QUADRANT_H
