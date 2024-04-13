#include <iostream>
#include "../View/MinesView.h"

void MinesView::showGrid(int grid[5][5]){
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            std::cout << grid[i][k] << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

std::pair<int, int> MinesView::getPrediction(){
    int x;
    int y;
    std::cout << "Please select a row then column." << std::endl;
    std::cin >> x;
    std::cin >> y;
    return std::make_pair(x, y);
}