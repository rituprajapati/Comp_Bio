//
//  main.cpp
//  randomStrings
//
//  Created by Ritu Prajapati on 9/10/17.
//  Copyright © 2017 Ritu Prajapati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;


int main(int argc, const char * argv[]) {
    ifstream input;
    input.open("data.txt");
    string DNA, content;
    
    vector<float> A, B;
    int cgContent = 0, atContent;
    
    
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    getline(input, DNA);
    getline(input, content);
    stringstream s(content);
    float num;
    while(s >> num){
        A.push_back(num);
    }
    
    for(int i = 0; i < DNA.length(); i++){
        if(DNA[i] == 'C' || DNA[i] == 'G')
            cgContent++;
    }
    
    atContent = DNA.size()-cgContent;
    
    for(int i = 0; i < A.size(); i++){
        float m = log10(pow(A[i]/2, cgContent) * pow((1 - A[i])/2, atContent));
        B.push_back(m);
    }
    
    for(int i = 0; i < B.size(); i++){
        cout << setprecision(3) << fixed << B[i] << " ";
    }
    cout << "\n";
    return 0;
}












