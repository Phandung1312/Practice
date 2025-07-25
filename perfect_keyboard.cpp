#include<bits/stdc++.h>
// #include "debug.h"  

using namespace std;
bool insertSecondChar(vector<char>& kb, char first, char second){
      auto fpointer = find(kb.begin(), kb.end(), first);
     int index = fpointer - kb.begin();
    if(index == 0){
        kb.insert(kb.begin(), second);
    }
   else if(index == kb.size() - 1){
                    kb.push_back(second);
                }
    else return false;
    return true;
}
bool isNeighbor(vector<char>& kb, char first, char second){
    auto fpointer = find(kb.begin(), kb.end(), first);
    auto spointer = find(kb.begin(), kb.end(), second);
    if (fpointer != kb.end() && spointer != kb.end()) {
        int fIndex = fpointer - kb.begin();
        int sIndex = spointer - kb.begin();
        return abs(fIndex - sIndex) == 1; 
    }
    return false;
}
void process(string &s){
    map<char, bool> az;
    for(int i = 97; i <= 122; i++){
        az[i] = false;
    }
    // DBG(s);
    int first = 0;
    int second = 1;
    vector<char> kb;
    for(int i = 0; i < s.length() - 1; i++){
        // DBGV(kb);
        int index = -1;
        auto fpointer = find(kb.begin(), kb.end(), s[first]);
        if(fpointer != kb.end()){
            index = fpointer - kb.begin();
        } 
        if(index != -1){
            if(find(kb.begin(), kb.end(), s[second]) == kb.end()){
                if(!insertSecondChar(kb, s[first], s[second])){
                    cout << "NO" << endl;
                    return;
                }
            }
            else{
                if(!isNeighbor(kb, s[first], s[second])){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else{
            auto spointer = find(kb.begin(), kb.end(), s[second]);
            if(spointer != kb.end()){
                if(!insertSecondChar(kb, s[second], s[first])){
                    cout << "NO" << endl;
                    return;
                };
            }
            else{
                kb.push_back(s[first]);
                kb.push_back(s[second]);
            }

        }
        az[s[first]] = true; 
        az[s[second]] = true; 
        first++;
        second++;
    }
    cout << "YES" << endl;
    for(int i = 97; i <= 122; i++){
        if(az[i] == false){
            kb.push_back(i);
        }
    }
    for(int i = 0; i < kb.size(); i++){
        cout<< kb[i];
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        string s;
        getline(cin, s);
        // DBG(s);
        process(s);
    }
    return 0;
}