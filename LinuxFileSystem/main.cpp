#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

struct File
{
    string name;
    int size;
};

struct Folder {
    string name;
    map<string, File*> files;
    map<string, Folder*> folders;
    Folder* parent;
};

void print(const vector<string> &v) {
    if(v.empty()){
        cout << "[]" << endl;
    }else {
        cout << "[";
        for (int i = 1; i < v.size(); i++) {
            cout << v[i - 1] << ",";
        }
        cout << v.back() << "]" << endl;
    }
}

vector<string>parsePath(string path) {
    stringstream ss(path);
    string item;
    char delimeter = '/';
    vector<string> splittedStrings;

    while (getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

Folder* cd(Folder* folder, vector<string> path)
{
    for(int i=0; i < path.size(); i++){
        if (path[i] == "..")
            folder = folder->parent;
        else if (folder->folders[path[i]])
            folder = folder->folders[path[i]];
        else
            cout << "Folder "+ path[i] + " not found" << endl;
    }
    return (folder);
}

Folder* mkdir(Folder* folder, string name)
{
    if (folder->folders.count(name) > 0)
    {
        cout << "Folder with the same name already exists";
        return folder;
    }

    if (folder->files.count(name) > 0)
    {
        cout << "File with the same name already exists";
        return folder;
    }

    Folder *new_folder = new Folder { .name = name, .parent = folder};

    folder->folders.insert(make_pair(name, new_folder));
    cout << "Folder "+ name +" successfully created!" << endl;
    return new_folder;
}

Folder* touch(Folder* folder, string name)
{
    if (folder->folders.count(name) > 0)
    {
        cout << "Folder with the same name already exists";
        return folder;
    }

    if (folder->files.count(name) > 0)
    {
        cout << "File with the same name already exists";
        return folder;
    }

    File *new_file = new File { .name = name};

    folder->files.insert(make_pair(name, new_file));
    cout << "File "+ name +" successfully created!" << endl;
    return folder;
}

void ls(Folder* folder, int check = 0)
{
    for (auto const& element : folder->folders) {
        for (int i=0; i<check; ++i) {
            cout << "|---";
        }
        cout << element.first << endl;
        ls(element.second, check + 1);
    }

    for (auto const& element : folder->files) {
        for (int i=0; i<check; ++i) {
            cout << "|---";
        }
        cout << element.first;
        cout << " (";
        cout << element.second->size;
        cout << ")" << endl;
    }
}

Folder* mv(Folder* folder, string name, Folder* destination, string destination_name)
{
    if (folder->folders.count(name) > 0)
    {
        destination->folders.insert(make_pair(destination_name, folder->folders[name]));
        folder->folders.erase(name);
    }
    else
    {
        destination->files.insert(make_pair(destination_name, folder->files[name]));
        folder->files.erase(name);
    }
}

Folder* cp(Folder* folder, string name, Folder* destination, string destination_name)
{
    if (folder->folders.count(name) > 0)
    {
        destination->folders.insert(make_pair(destination_name, folder->folders[name]));
    }
    else
    {
        destination->files.insert(make_pair(destination_name, folder->files[name]));
    }
}

Folder* rm(Folder* folder, string name)
{
    if (folder->folders.count(name) > 0)
    {
        folder->folders.erase(name);
    }
    else
    {
        folder->files.erase(name);
    }
}

Folder* controller(Folder* folder, string instruction, vector<string> path)
{
    if (instruction == "cd")
    {
        Folder* temp = cd(folder, parsePath(path[0]));
        return temp;
    }
    else if (instruction == "mkdir")
    {
        vector<string> pad = parsePath(path[0]);
        string naam = pad.back();
        pad.pop_back();

        Folder* temp = cd(folder, pad);
        mkdir(temp, naam);

        return folder;
    }
    else if (instruction == "touch")
    {
        vector<string> pad = parsePath(path[0]);
        string naam = pad.back();
        pad.pop_back();

        Folder* temp = cd(folder, pad);
        touch(temp, naam);

        return folder;
    }
    else if (instruction == "ls")
    {
        vector<string> pad = parsePath(path[0]);
        cd(folder, pad);
        ls(folder);
        return folder;
    }
    else if (instruction == "mv")
    {
        vector<string> pad1 = parsePath(path[0]);
        vector<string> pad2 = parsePath(path[1]);
        Folder* destination = folder;
        string naam = pad1.back();
        pad1.pop_back();
        Folder* temp = cd(folder, pad1);

        for(int i=0; i < pad2.size()-1; i++)
            destination = destination->folders[pad2[i]];

        mv(temp, naam, destination , pad2.back());

        return folder;
    }
}

int main() {
    Folder *folder = new Folder;
    folder->name = "Downloads";
    Folder* pwd = controller(folder,"mkdir",{"movies"});
    pwd = controller(pwd,"mkdir",{"movies/thematrix"});
    pwd = controller(pwd,"touch",{"movies/thematrix/subs.srt"});
    pwd = controller(pwd,"ls",{""});
    pwd = controller(pwd,"ls",{"movies/thematrix"});
    pwd = controller(pwd,"mv",{"movies/thematrix/subs.srt","movies/ondertitels.srt"});
    pwd = controller(pwd,"ls",{""});
    pwd = controller(pwd,"cd",{"movies"});
    pwd = controller(pwd,"ls",{""});
    return 0;
}
