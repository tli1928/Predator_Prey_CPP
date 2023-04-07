#include <iostream>
#include <cstdlib>
#include <ctime>
#include "organism.hpp"
#include "ant.hpp"
#include "doodlebug.hpp" // 如果有涂鸦虫类，请包含它，否则删除此行
#include <unistd.h>

const int GRID_SIZE = 100;
const int NUM_ITERATIONS = 1000;

void placeOrganisms(Organism*** grid, int numAnts, int numDoodlebugs) {
    srand(time(0));
    int countAnts = 0, countDoodlebugs = 0;
    while (countAnts < numAnts || countDoodlebugs < numDoodlebugs) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == nullptr) {
            if (countAnts < numAnts) {
                grid[x][y] = new Ant(x, y);
                countAnts++;
            } else if (countDoodlebugs < numDoodlebugs) {
                grid[x][y] = new Doodlebug(x, y); // 如果有涂鸦虫类，请使用它，否则删除此行
                countDoodlebugs++;
            }
        }
    }
}
void displayGrid(Organism*** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                std::cout << "-";
            } else if (dynamic_cast<Ant*>(grid[i][j])) {
                std::cout << "A";
            } else if (dynamic_cast<Doodlebug*>(grid[i][j])) {
                std::cout << "D";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void simulate(Organism*** grid) {
    for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] != nullptr) {
                    grid[i][j]->move();
                    grid[i][j]->breed();
                    grid[i][j]->starve();
                    if (grid[i][j]->getIsDead()) {
                        delete grid[i][j];
                        grid[i][j] = nullptr;
                    }
                }
            }
        }
        displayGrid(grid);
        usleep(100000);  // 暂停100毫秒
    }
}

int main() {
    // 创建一个100x100的网格，每个元素都是Organism指针
    Organism*** grid = new Organism**[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = new Organism*[GRID_SIZE];
    }

    // 初始化网格为空（nullptr）
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    // 放置蚂蚁和涂鸦虫
    int numAnts = 50; // 可以根据需要调整
    int numDoodlebugs = 15; // 可以根据需要调整
    placeOrganisms(grid, numAnts, numDoodlebugs);

    // 执行模拟
    simulate(grid);

    // 释放内存
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}