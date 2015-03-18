#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Entity {
  protected:
    string name;
    float speed;
    int index;
    bool active;
  public:
    virtual void deactivate() = 0;
    void print();
};

void Entity::print () {
  cout << name << "\t"
       << speed << "\t"
       << index << "\t"
       << boolalpha << active
       << endl;
}

class GameObject : public Entity {
  private:
    string player;
  public:
    GameObject (string p) { player = p; }
    void setvals(string n, float f, int i, bool a);
    virtual void deactivate() {}
    void print();
};

void GameObject::setvals (string n, float s, int i, bool a) {
  name = n;
  speed = s;
  index = i;
  active = a;
};

void GameObject::print () {
  cout << player << "\t";
  Entity::print();
};

int main () {
  ifstream file;
  file.open("data.txt");
  string line;
  string name;
  float speed;
  int index;
  bool active;
  int player = 1;

  vector<GameObject> objects;

  if (!file.good()) {
    throw invalid_argument("File 'data.txt' doesn't exist");
  }

  // Abstract test for Bonus
  // Entity *e = new Entity();

  while(getline(file, line)) {
    stringstream player_name;
    player_name << "Object" << player++;
    istringstream stream(line);
    stream >> name >> speed >> index >> boolalpha >> active;
    GameObject *e = new GameObject(player_name.str());
    e->setvals(name, speed, index, active);
    objects.push_back(*e);
  }

  for (unsigned i = 0; i < objects.size(); i++) {
    objects[i].print();
  }

  file.close();
  return 0;
}
