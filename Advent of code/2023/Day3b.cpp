#include <bits/stdc++.h>

bool is_digit(const char& c){return (c <= '9' && c >= '0');}

struct S{int i, j, n, ss;};
void scan(const std::vector<std::string>& vs, int i, int j, const int& ss, std::map<std::pair<int, int>, std::vector<int>>& starred, const int& n){
    int ls{(int)vs[i].size()};
    if (j < ls-1 && vs[i][j+1] == '*'){
        starred[std::pair{i, j+1}].push_back(n);
    }
    else if (j-ss >= 0 && vs[i][j-ss] == '*'){
        starred[std::pair{i, j-ss}].push_back(n);
    }

    if (i){
        for (int k{-1}; k < ss+1; ++k){
            if (j-k >= 0 && j-k < ls-1 && vs[i-1][j-k] == '*'){
                starred[std::pair{i-1, j-k}].push_back(n);
            }
        }
    }
    if (i+1 < (int)vs.size()){
        for (int k{-1}; k < ss+1; ++k){
            if (j-k >= 0 && j-k < ls-1 && vs[i+1][j-k] == '*'){
                starred[std::pair{i+1, j-k}].push_back(n);
            }
        }
    }
}

int main(){
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()){
        std::cout << "failed to open file!";
        return -1;
    }

    std::string line;
    int output{};
    std::vector<std::string>vs;
    std::vector<S>custom;
    std::map<std::pair<int, int>, std::vector<int>>starred;

    int i{};
    while (getline(input_file, line)){
        vs.emplace_back(line);

        std::string temp;
        for (int j{}, ls{(int)line.size()}; j < ls; ++j){
            if (is_digit(line[j])){temp += line[j];}
            else if (temp.size()){
                custom.emplace_back(S{i, j-1, stoi(temp), (int)temp.size()}); 
                temp.clear();
            }
        } if (temp.size()){custom.emplace_back(S{i, (int)line.size()-1, stoi(temp), (int)temp.size()});}

        ++i;
    }
    input_file.close();

    for (const auto& [k, j, n, ss] : custom){
        scan(vs, k, j, ss, starred, n);
    }

    for (const auto& p : starred){
        if (p.second.size() == 2){
            output += p.second[0] * p.second.back();
        }
    }

    std::cout << "-----------------------\n";
    std::cout << "output: "<< output << '\n';
    std::cout << "-----------------------\n";

    return 0;
}
