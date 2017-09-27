//
//  main.cpp
//  RNASplicing
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


void KMP(string & text, string patt){
    
    //Declare partial match table as table and //
    //indexes of all the successfull matches   //
    vector<int> table(patt.length(), 0);
    vector<int> index;
    
    //Generate partial match table             //
    for(int i = 1, j = 0; i < table.size(); i++){
        while(j > 0 && patt[j] != patt[i])
            j = table[j-1];
        if(patt[i] == patt[j]) j += 1;
        table[i] = j;
    }
    
    //Use Partial Match Table to find the index //
    //of successfull matches                    //
    for(int k = 0, l = 0; k < text.length();){
        if(text[k] == patt[l]){
            k++;
            l++;
            if(l == patt.length()){
                index.push_back(k-l);
                l = 0;
            }
        }
        else{
            if(l == 0) k += 1;
            else l = table[l-1];
        }
    }
    
    //Remove the Introns from the DNA          //
    for(int m = 0, back = 0; m < index.size(); m++){
        text.erase(index[m] - back, patt.length());
        back += patt.length();  //Once a pattern deleted the text length has chaged
    }
    
};

int main(int argc, const char * argv[]) {
    
    ifstream input;
    string content, DNA = "", protein = "";
    
    input.open("data.txt");
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    
    // Get DNA and Introns one by one together with //
    // Removing the occurences of Inrons in DNA     //
    while(getline(input, content)){
        
        if(content[0] == '>');
        else if(DNA.empty()){
            DNA = content;
            content.clear();
            while(getline(input, content) && content[0] != '>'){
                DNA += content;
            }
        }
        else{
            KMP(DNA, content);
        }
        content.clear();
    }
    
    //Replace T with U for the RNA strand //
    for(int i = 0; i < DNA.length(); i++)
        if(DNA[i] == 'T') DNA[i] = 'U';
    
    //Replace the codons with their       //
    //Corresponding Amino Acids           //
    for(int i = 0; i < DNA.length(); i+=3){
        string codon = DNA.substr(i,3);
        if(map.find(codon) != map.end()){
            if(map[codon] == '/') break;
            protein += map[codon];
        }
    }
    
    cout << protein << "\n";
    return 0;
}








