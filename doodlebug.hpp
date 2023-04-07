#include "organism.hpp"

class Doodlebug : public Organism {
public:
    Doodlebug();
    ~Doodlebug();

    void move() override;
    void breed() override;
    void starve() override;

private:
    int lastMove;
    int lastBreed;
    int lastEat;
    bool isDead;

    // 添加 findAdjacentAnt 方法声明
    std::pair<int, int> findAdjacentAnt(Organism*** grid);
};
