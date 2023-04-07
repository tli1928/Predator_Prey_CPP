#include "organism.hpp"

class Ant : public Organism {
public:
    Ant();
    ~Ant();
    
    void move() override;
    void breed() override;
    void starve() override;

private:
    int lastMove;
    int lastBreed;
    bool isDead;
    enum AntType {QUEEN, MALE, WORKER} antType;
};
