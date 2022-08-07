#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum Type {DOG, HUMAN};

Type parseType(string type) {
  if (type == "D") return Type::DOG;
  if (type == "H") return Type::HUMAN;
}


class Actor {
protected:
  string name;
  int age;
  Type type;
public:
  Actor(Type type, string name, int age):type(type), name(name), age(age){} 
  virtual void show() = 0;
};



class Dog : public Actor{
private:
  string owner;
public:
  Dog(Type type, string name, int age, string owner): Actor(type, name, age), owner(owner){}
  static Dog* buildDogFromAttributes(string attributes) {
    stringstream ss(attributes);
    string name; 
    int age;
    string owner; 

    // parsing
    ss >> name >> age >> owner;
    return new Dog(Type::DOG, name, age, owner);
  }

  void show() {
    std::cout << "Type: Dog" << ", Name: " << name << ", Age: " << age << ", Owner: " << owner << endl;
  }
};

class Human : public Actor{
private:
  map<string, string> family; // name -> relationship
public:
  Human(Type type, string name, int age, vector<pair<string, string>> fam):Actor(type, name, age){
    for (int i = 0; i < fam.size(); ++i) {
      string fam_name = fam[i].first;
      string relationship = fam[i].second;
      family[fam_name] = relationship;
    }
  }

  static Human* buildHumanFromAttributes(string attributes) {
    stringstream ss(attributes);
    string name;
    int age;
    vector<pair<string, string>> family;

    // parsing
    ss >> name >> age;
    while (ss.rdbuf()->in_avail() != 0) {
      string fam_name, relationship;  
      ss >> fam_name >> relationship;
      family.push_back({fam_name, relationship});
    }
    return new Human(Type::HUMAN, name, age, family);
  }

  void show() {
    cout << "Type: Human" << ", Name: " << name << ", Age: " << age << ", Family: " << endl;
    for (const auto& it: family) {
      cout << "\tName: " << it.first << ", Relationship: " << it.second << endl;
    }
  } 
};



/*************
 * Format
 * Dog -> "D Lucky 7 Richard"
 * Human -> "H Richard 23 Hillary Mom Betty Sister Quang Dad"
 *************/
Actor* parseActorFromString(string type_str, string attributes_str) { 
  Type type = parseType(type_str);
  switch(type) {
    case DOG:
      return Dog::buildDogFromAttributes(attributes_str);
      break;
    case HUMAN:
      return Human::buildHumanFromAttributes(attributes_str);
      break;
    default:
      throw "parseActorFromString() -> unknown actor error";
  }
  return nullptr;
}



int main() {
  fstream inFile;
  vector<Actor*> actors;
  inFile.open("data.txt", ios::in);
  if (!inFile.is_open()) {
    throw "data.txt could not be opened";
  }

  // read from file
  string type_str, attributes_str;
  while(inFile >> type_str) { 
    getline(inFile, attributes_str);
    Actor* actor = parseActorFromString(type_str, attributes_str);
    actors.push_back(actor);
  }

  inFile.close();

  // print all actors
  for (Actor* actor: actors) {
    actor->show();
  }
}