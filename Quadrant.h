#ifndef TROMINO_HUGGER_QUADRANT_H
#define TROMINO_HUGGER_QUADRANT_H

#include <vector>

class Quadrant {
public:
    Quadrant(const Quadrant&) = delete;
    Quadrant& operator=(const Quadrant&) = delete;
    Quadrant(int rowBegin, int rowEnd, int colBegin, int colEnd);

    enum Orientation : int {
        LTC, RTC, LBC, RBG
    };

    void setQuadrantElement(int row, int col, bool* element);
    void setOrientation(const Orientation& orientation);

    bool* getIntersection();
    void setIntersection();

    int getColEnd();
    int getRowEnd();

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
