#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//#include "print.h"

using namespace std;

//geeft random getal dat voldoet aan abs(pannenkoeken[i]-correctepannenkoeken[i]) >= 100 (ik denk dat de fout hier zit?)
int random(int number)
{
  int num = 0;
  while(num < (number-99))
  {
    num += rand() % 100;
  }
  return num;
}

//vraag2
vector<int> bakPannenkoeken(int aantalPannenkoeken){
  vector<int> pannekoeken;
  int time = 0;

 while(pannekoeken.size() < aantalPannenkoeken)
  {
    if((time+1) % 2 == 0)
      pannekoeken.push_back(random(100));
    
    if(pannekoeken.size() == aantalPannenkoeken)
      break;

    if((time+1)%3==0)
      pannekoeken.push_back(random(200));

    if(pannekoeken.size() == aantalPannenkoeken)
      break;

    if((time+1)%4 == 0)
      pannekoeken.push_back(random(300));

    time++;
  }
  return pannekoeken;
}

//zelfgemaakte printVector om code te testen
void printVector(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
  cout << endl;
}

// vraag 5
vector<int> sorteerPannenkoeken(vector<int> pannenkoeken){
    vector<int> vec = pannenkoeken;
    int a = 0;

    while(true)
    {
      int max = 0;
      int p;
      for(int i = a; i < vec.size(); i++)
      {
        if(vec[i] > max)
        {
          max = vec[i];
          p = i;
        }
      }
      if(max == 0)
        break;
      vec.erase(vec.begin() + p);
      vec.push_back(max);
      printVector(vec);
      reverse(vec.begin()+a, vec.end());
      printVector(vec);
      a++;
    }
    return vec;
}

int gewicht(vector<int> pannenkoeken)
{
  int weight = 0;
  for(int i = 0; i < pannenkoeken.size(); i++)
    weight += pannenkoeken[i];

  return weight;
}

void printify(string persoon, vector<int> pannenkoeken)
{
  cout << persoon << ": ";
  printVector(pannenkoeken);
}

map<string,vector<int>> verdeelPannenkoeken(vector<int> pannenkoeken, vector<string> personen){
    map<string,vector<int>> verdeling;
    int count = personen.size();
    reverse(pannenkoeken.begin(), pannenkoeken.end());

    for(int i = 0; i < count; i++)
    {
      verdeling[personen[i]].push_back(pannenkoeken[i]);
      printify(personen[i], verdeling[personen[i]]);
    }

    while(count < pannenkoeken.size())
    {
      string min = personen[0];
      for(int i = 1; i < personen.size(); i++)
        if(gewicht(verdeling[personen[i]]) < gewicht(verdeling[min]))
        {
          min = personen[i];
        }
      verdeling[min].push_back(pannenkoeken[count]);
      printify(min, verdeling[min]);
      count ++;
    }
    return verdeling;
}

// vul de ... zelf in
void printVerdeling(map<string,vector<int>> verdeling){
    for(auto persoon : verdeling){
        cout << persoon.first << " heeft in totaal " << persoon.second.size() << " pannenkoeken met een totaal gewicht van " << gewicht(persoon.second) << "g." << endl;
    }
    cout << endl;
}