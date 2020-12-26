#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;

struct Verzekering{
    string naam;
    string product;
    double prijs;
};

struct Klant{
    string naam;
    string email;
    vector<Verzekering*> verzekeringen;
};

void print_klantenlijst(vector<Klant*> klantenlijst){
    for(int a = 0; a < klantenlijst.size(); a++){
        cout << (*klantenlijst.at(a)).naam << '\t' << (*klantenlijst.at(a)).email << '\t';
        vector<Verzekering*>& vect = (*klantenlijst.at(a)).verzekeringen;

        if (vect.size() == 0)
            cout << '/';

        for(int b = 0; b < vect.size(); b++) {
            if (vect.size() - b  > 1)
                cout << (*vect.at(b)).naam << '(' << to_string((*vect.at(b)).prijs) << ')' << ',' << ' ';
            else
                cout << (*vect.at(b)).naam << '(' << to_string((*vect.at(b)).prijs) << ')';
        }
        cout << endl;
    }
}

Klant* vindKlant(vector<Klant*> klantenlijst, string email){
    for(int a = 0; a < klantenlijst.size(); a++){
        if((*klantenlijst.at(a)).email == email)
            return klantenlijst.at(a);
    }
    return nullptr;
}

bool check_email_adres(string email, vector<Klant*> klantenlijst){
    int size = email.size();
    if (email.find("..") < size || email.find("-.") < size || email.find("-.") < size || email.find("--") < size)
        return false;
    else if (size > 64)
        return false;
    else if(email.find("@") > size)
        return false;
    else if (email.find(".") == 0 || email.find(".") == email.find("@")-1)
        return false;
    else if (vindKlant(klantenlijst, email) != 0)
        return false;

    for (std::string::size_type i = 0; i < email.size(); i++) {
        char c = email[i];
        if ((email[i]=='.')|| (email[i]=='-')|| (email[i]=='@'))
            continue;
        else if (isalpha(email[i]) || isdigit(email[i]))
            continue;
        else
            return false;
    }
    return true;
}

bool voeg_klant_toe(string naam, string email, vector<Klant*> &klantenlijst){
    if(!check_email_adres(email, klantenlijst))
        return false;

    Klant* nieuwe_klant = new Klant;
    (*nieuwe_klant).naam = naam;
    (*nieuwe_klant).email = email;
    klantenlijst.push_back(nieuwe_klant);


    return true;
}

bool voeg_verzekering_aan_klant_toe(string verzekering, double prijs, string email, vector<Klant*> &klantenlijst, map<string, Verzekering*> &verzekeringen){
    Klant* klant = vindKlant(klantenlijst, email);
    Verzekering* nieuwe_verzekering;
    double sum = 0;

    if (klant == 0 || prijs < 0)
        return false;

    for(int i = 0; i < (klant)->verzekeringen.size(); i++){
        sum += (klant)->verzekeringen.at(i)->prijs;
    }

    if(sum+prijs > 10000)
        return false;

    if (verzekeringen.count(verzekering) == 1)
        nieuwe_verzekering = verzekeringen[verzekering];
    else {
        nieuwe_verzekering = new Verzekering;
        (*nieuwe_verzekering).naam = verzekering;
        (*nieuwe_verzekering).prijs = prijs;
    }

    verzekeringen[verzekering] = nieuwe_verzekering;
    (*klant).verzekeringen.push_back(nieuwe_verzekering);
    return true;
}

bool verhoog_verzekerings_kosten(map<string, Verzekering*> &verzekeringen, string naam, double prijs){
    if (verzekeringen.count(naam) == 0)
        return false;

    (*verzekeringen[naam]).prijs = prijs;
}

int main() {
    vector<Klant*> klantenlijst;
    map<string, Verzekering*> verzekeringen;

    cout << voeg_klant_toe("Alice", "alice?smith@hotmail.be", klantenlijst) << endl ;
    print_klantenlijst(klantenlijst);

    cout << voeg_klant_toe("Alice", "alice.smith@hotmail.be", klantenlijst) << endl ;
    print_klantenlijst(klantenlijst);

    cout << voeg_verzekering_aan_klant_toe("levens", 1000, "alice.smith@hotmail.be", klantenlijst, verzekeringen) << endl;
    print_klantenlijst(klantenlijst);

    cout << voeg_klant_toe("John", "JohnDoe@gmail.com", klantenlijst) << endl ;
    print_klantenlijst(klantenlijst);

    cout << voeg_verzekering_aan_klant_toe("levens", 1000, "JohnDoe@gmail.com", klantenlijst, verzekeringen) << endl;
    print_klantenlijst(klantenlijst);

    cout << voeg_verzekering_aan_klant_toe("auto", 50, "JohnDoe@gmail.com", klantenlijst, verzekeringen) << endl;
    print_klantenlijst(klantenlijst);

    cout << voeg_verzekering_aan_klant_toe("brand", 9000, "JohnDoe@gmail.com", klantenlijst, verzekeringen) << endl;
    print_klantenlijst(klantenlijst);

    for(int i = 0; i < klantenlijst.size(); i++){
        delete klantenlijst.at(i);
    }

    for(auto verzekering : verzekeringen){
        delete verzekering.second;
    }

    //klantenlijst.~vector<Klant*>();
    //verzekeringen.~map<string, Verzekering*>();
    return 0;
}
