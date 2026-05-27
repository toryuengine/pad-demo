#include <vector>
#include <array>
#include <iostream>

std::vector<std::vector<int>> createfield() {
    int h = 5; //高さの定義
    int w = 6; //横幅の定義
    std::vector<std::vector<int>> arr = {};//配列の定義    

    for(int i = 0; i < h; i++) {
        arr.push_back({});
        for(int t = 0; t < w; t++) {
            arr[i].push_back(0);
        }
    }
        return arr;
}

int drawscreen(const std::vector<std::vector<int>>& arr) {
    for (int k = 0; k < arr.size(); k++) {
        for (int j = 0; j < arr[k].size(); j++) {
            std::cout << arr[k][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}


int main() {
    std::vector<std::vector<int>> arr;
    arr = createfield();
    int result = drawscreen(arr);
}