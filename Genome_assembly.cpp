//
//  main.cpp
//  genomeAssembly
//
//  Created by Ritu Prajapati on 9/11/17.
//  Copyright © 2017 Ritu Prajapati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <fstream>
using namespace std;

string overlaps(vector<string> sub, string result){
    
    if(sub.size() == 0)
        return result;
    
    if(result.length() == 0){
        result = sub[0];
        sub.erase(sub.begin());
        return overlaps(sub, result);
    }
    
    for(int i = 0; i < sub.size(); i++){
            
        int len = sub[i].length();
            
        for(int j = 0; j < len/2; j++){
            int k = len - j;
            string overlap1 = sub[i].substr(j);
            string overlap2 = sub[i].substr(0, k);
            
            if(overlap1.size() <= result.size() && overlap1.compare(result.substr(0, len-j)) == 0){
                
                result = sub[i].substr(0, j) + result;
                sub.erase(sub.begin()+i);
                return overlaps(sub, result);
            }
            else if( overlap2.size() <= result.size() && overlap2.compare(result.substr(result.size()-k, k)) == 0){
                result = result+sub[i].substr(k);
                sub.erase(sub.begin()+i);
                return overlaps(sub, result);
            }
                
        }
    }
    return "";
};



int main(int argc, const char * argv[]) {
    ifstream input;
    vector<string> sub;
    string temp, subI, result;
    input.open("data.txt");
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    
    while(getline(input, temp)){
        
        if(temp[0] != '>'){
            subI = temp;
            temp.clear();
            
            while(getline(input, temp) && temp[0] != '>'){
                subI += temp;
                temp.clear();
            }
            sub.push_back(subI);
        }
        
        temp.clear();
        
    }
    
    result =  overlaps(sub, "");
    
    cout << result << "\n";
    return 0;
}




