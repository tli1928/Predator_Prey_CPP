#include "doodlebug.hpp"

Doodlebug::Doodlebug() : Organism() {
    lastMove = 0;
    lastBreed = 0;
    lastEat = 0;
    isDead = false;
}
std::pair<int, int> Doodlebug::findAdjacentAnt(Organism*** grid) {
    std::vector<std::pair<int, int>> adjacentAnts;

    int rowStart = (x > 0) ? x - 1 : x;
    int rowEnd = (x < GRID_SIZE - 1) ? x + 1 : x;
    int colStart = (y > 0) ? y - 1 : y;
    int colEnd = (y < GRID_SIZE - 1) ? y + 1 : y;

    for (int i = rowStart; i <= rowEnd; ++i) {
        for (int j = colStart; j <= colEnd; ++j) {
            if (i == x && j == y) continue;
            if (grid[i][j] != nullptr && dynamic_cast<Ant*>(grid[i][j])) {
                adjacentAnts.push_back({i, j});
            }
        }
    }

    if (!adjacentAnts.empty()) {
        int randomIndex = rand() % adjacentAnts.size();
        return adjacentAnts[randomIndex];
    }

    return {-1, -1};
}

Doodlebug::~Doodlebug() {
    // Destructor implementation
}

void Doodlebug::move(Organism*** grid) {
    // 假设 findAdjacentAnt 返回一个包含相邻蚂蚁位置的 std::pair<int, int>，
    // 如果没有找到蚂蚁，则返回 {-1, -1}
    std::pair<int, int> antPos = findAdjacentAnt(grid);
    
    if (antPos.first != -1 && antPos.second != -1) {
        // 吃掉蚂蚁
        delete grid[antPos.first][antPos.second];
        grid[antPos.first][antPos.second] = nullptr;

        // 将涂鸦虫移动到蚂蚁的位置
        grid[antPos.first][antPos.second] = grid[x][y];
        grid[x][y] = nullptr;

        // 更新涂鸦虫的位置
        x = antPos.first;
        y = antPos.second;

        // 重置 lastEat 计数器
        lastEat = 0;
    } else {
        // 移动涂鸦虫，这里需要实现涂鸦虫的移动逻辑，例如随机选择一个空位
        // 更新涂鸦虫的位置 x, y
    }

    lastMove++;
    lastEat++;
}


void Doodlebug::breed() {
    // 检查是否满足繁殖条件
    if (lastBreed >= 10) {
        // 在这里实现繁殖逻辑
        // 创建新的 Doodlebug
        // 更新 lastBreed 属性
        lastBreed = 0;
    }
}

void Doodlebug::starve() {
    if (lastEat >= 10) {
        // 涂鸦虫饿死
        isDead = true;
    }
}
