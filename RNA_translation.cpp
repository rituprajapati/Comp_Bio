//
//  main.cpp
//  RNAtoProtein
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

unordered_map<string, char> map = {{"GCU",'A'},{"GCC",'A'},{"GCA",'A'},{"GCG",'A'},{"CGU",'R'},{"CGC",'R'},{"CGA",'R'},{"CGG",'R'},{"AGA",'R'},{"AGG",'R'},{"AAU",'N'},{"AAC",'N'},{"GAU",'D'},{"GAC",'D'},{"UGU",'C'},{"UGC",'C'},{"CAA",'Q'},{"CAG",'Q'},{"GAA",'E'},{"GAG",'E'},{"GGU",'G'},{"GGC",'G'},{"GGA",'G'},{"GGG",'G'},{"CAU",'H'},{"CAC",'H'},{"AUU",'I'},{"AUC",'I'},{"AUA",'I'},{"UUA",'L'},{"UUG",'L'},{"CUU",'L'},{"CUC",'L'},{"CUA",'L'},{"CUG",'L'},{"AAA",'K'},{"AAG",'K'},{"AUG",'M'},{"UUU",'F'},{"UUC",'F'},{"CCU",'P'},{"CCC",'P'},{"CCA",'P'},{"CCG",'P'},{"UCU",'S'},{"UCC",'S'},{"UCA",'S'},{"UCG",'S'},{"AGU",'S'},{"AGC",'S'},{"ACU",'T'},{"ACC",'T'},{"ACA",'T'},{"ACG",'T'},{"UGG",'W'},{"UAU",'Y'},{"UAC",'Y'},{"GUU",'V'},{"GUC",'V'},{"GUA",'V'},{"GUG",'V'},{"UAA",'/'},{"UGA",'/'},{"UAG",'/'}};



int main(int argc, const char * argv[]) {
    
    ifstream input;
    string RNA, protein = "";
    
    input.open("data.txt");
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    getline(input, RNA);
    
    for(int i = 0; i < RNA.length(); i+=3){
        string codon = RNA.substr(i,3);
        if(map.find(codon) != map.end()){
            if(map[codon] == '/') break;
            protein += map[codon];
        }
    }
    cout << protein << "\n";
    return 0;
}

