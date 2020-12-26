#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    vector<string> woorden = {"dit","is","een","dit","een","dit","hallo"};
    map<string, int> freq;
    
    for (int i = 0; i < woorden.size(); i++)
    {
      freq[woorden[i]] += 1;
    }
   
   for (int i = 0; i < woorden.size(); i++)
  {
    cout << woorden[i] << " " << freq[woorden[i]] << endl;
  } 
}