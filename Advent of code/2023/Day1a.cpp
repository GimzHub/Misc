#include <bits/stdc++.h>

int main(){
    std::ifstream input_file("input.txt");
    std::string line;
    int output{};

    if (input_file.is_open()){

        while (getline(input_file, line)){
            int num{};

            for (int i{}, ls{(int)line.size()}; i < ls; ++i){
                if (line[i] >= '0' &&  line[i] <= '9'){num += line[i] - '0'; break;}
            }

            num *= 10;

            for (int i{}, ls{(int)line.size()}; i < ls; ++i){
                if (line[ls-(i+1)] >= '0' && line[ls-(i+1)] <= '9'){num += line[ls-(i+1)] - '0' ; break;}
            }
            output += num;
        }

        input_file.close();
        std::cout << "-----------------------\n";
        std::cout << "output: " << output << '\n';
        std::cout << "-----------------------\n";
    }
    else {std::cout << "failed to open file!";}

    return 0;
}
