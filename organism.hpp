#pragma once

class Organism {
public:
    Organism(int x, int y);
    virtual ~Organism();

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual void starve() = 0;

protected:
    int x;
    int y;
};
