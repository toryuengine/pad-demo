#include <vector>
#include <array>
#include <iostream>
#include <random>


std::random_device seed_gen;
std::mt19937 engine(seed_gen());
std::uniform_int_distribution<int> dist(0, 6);

std::vector<std::vector<int>> createfield() {
    int h = 5; //高さの定義
    int w = 6; //横幅の定義
    std::vector<std::vector<int>> arr = {};//配列の定義    
    arr.push_back({9,9,9,9,9,9,9,9});
    for(int i = 1; i < h; i++) {
        arr.push_back({});
        arr[i].push_back(9);
        for(int t = 0; t < w; t++) {
            arr[i].push_back(dist(engine));
        }
        arr[i].push_back(9);
    }
    arr.push_back({9,9,9,9,9,9,9,9});
    return arr;
}

std::vector<std::vector<int>> findcomborow(std::vector<std::vector<int>> arr) {
    std::vector<std::vector<int>> combo = {};
    std::vector<std::vector<int>> confirmed;
    int point;
    for (int r=1; arr.size() > r & r<5; r++) {
        for (int c=0; arr[r].size() > c; c++) {
            if (point == arr[r][c]){
                combo.push_back({r, c});
            }else{
                if(combo.size() >= 3){
                    for (int t = 0; combo.size() > t; t++) {
                        for (int p = 0; combo[t].size() > p; p++) {
                            confirmed.push_back({t, p});
                        }
                    }
                    std::vector<std::vector<int>> combo = {};
                }
                point = arr[r][c];
            }
    }
    }

    return confirmed;
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
    arr = findcomborow(arr);
    int result2 = drawscreen(arr);
}