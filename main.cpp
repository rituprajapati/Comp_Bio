//
//  main.cpp
//  DNACounting
//
//  Created by Ritu Prajapati on 9/9/17.
//  Copyright © 2017 Ritu Prajapati. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input;
    string DNA;
    unordered_map<char, int> count = {{'A',0},{'C',0},{'G',0},{'T',0}};
    input.open("data.txt");
    
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    getline(input, DNA);
    
    for(int i = 0; i < DNA.size(); i++){
            count[DNA[i]]++;
    }
    
    cout << count['A'] << "  " << count['C'] << "  " << count['G'] << "  " << count['T'];
    return 0;
}
