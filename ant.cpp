#include "ant.hpp"

Ant::Ant(int x, int y) : Organism(x, y) {
    lastMove = 0;
    lastBreed = 0;
    isDead = false;
    antType = WORKER; // 默认为工蚁，可以根据需要更改
}

Ant::~Ant() {
}

void Ant::move() {
    // 在这里实现移动逻辑
    // 更新 lastMove 属性
    lastMove++;
}

void Ant::breed() {
    // 检查是否满足繁殖条件
    if (antType == QUEEN && lastBreed >= 25) {
        // 在这里实现繁殖逻辑
        // 更新 lastBreed 属性
        lastBreed = 0;
    }
}

void Ant::starve() {
    if (antType != QUEEN && lastMove >= 5) {
        // 蚂蚁饿死
        isDead = true;
    }
}
