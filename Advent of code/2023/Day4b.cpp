#include <bits/stdc++.h>

bool is_digit(const char& c){return (c <= '9' && c >= '0');}

int main(){
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()){
        std::cout << "failed to open file!";
        return -1;
    }

    std::string line;
    long long output{};
    int line_num{};
    std::vector<int>vi(207, 1);
    
    while (getline(input_file, line)){
        std::vector<bool>vb(101, false);
        std::string temp{""};

        int i{8}, ls{(int)line.size()};
        for (; i < ls; ++i){ // input nums
            if (line[i] == '|'){++i; break;}
            else {
                if (is_digit(line[i])){temp += line[i];} 
                else if (temp.size()){
                    vb[stoi(temp)] = true;
                    temp.clear();
                }
            }
        } 
        
        int extra{};
        for (; i < ls; ++i){ // check
            if (is_digit(line[i])){temp += line[i];} 
            else if (temp.size() && vb[stoi(temp)]){
                ++extra;
                temp.clear();
            }
            else {temp.clear();}
        }
        if (temp.size() && vb[stoi(temp)]){++extra;}

        int idx{};
        while (idx < extra){
            vi[line_num+idx+1] += vi[line_num];
            ++idx;
        }

        ++line_num;
    }
    input_file.close();

    for (const auto& n : vi){
        output += n;
    }

    std::cout << "-----------------------\n";
    std::cout << "output: "<< output << '\n';
    std::cout << "-----------------------\n";

    return 0;
}
