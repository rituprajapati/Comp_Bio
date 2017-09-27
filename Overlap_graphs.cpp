//
//  main.cpp
//  OverlapGraphs
//
//  Created by Ritu Prajapati on 9/9/17.
//  Copyright © 2017 Ritu Prajapati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[]) {
    ifstream input;
    vector<string> node;
    vector<string> nodeVal;
    vector<vector<string>> adjList;
    string line, value = "";
    
    input.open("data.txt");
    if(!input){
        cout << "error reading file \n";
        exit(1);
    }
    
    while(getline(input, line)){
        
        if(line[0] == '>'){
            node.push_back(line.substr(1));
        }
        else{
            value = line;
            line.clear();
            getline(input, line);
            value += line;
            nodeVal.push_back(value);
        }
        line.clear();
        value.clear();
    }
    
    string suffix, prefix;
    
    for(int i =0; i < nodeVal.size(); i++){
        for(int j = i+1; j < nodeVal.size(); j++){
            suffix = nodeVal[i].substr(nodeVal[i].length()-3);
            prefix = nodeVal[j].substr(0, 3);
            
             if(suffix.compare(prefix) == 0)
                adjList.push_back({node[i], node[j]});
            
            suffix = nodeVal[j].substr(nodeVal[j].length()-3);
            prefix = nodeVal[i].substr(0, 3);
            if(suffix.compare(prefix) == 0)
                adjList.push_back({node[j], node[i]});
            
        }
    }
    
    for(int i = 0; i < adjList.size(); i++){
        cout << adjList[i][0] << " " << adjList[i][1];
        cout << "\n";
    }
    return 0;
}
