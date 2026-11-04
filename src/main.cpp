#include <iostream>
#include <string>
#include <vector>
using namespace std;



//breakfast brunch lunch dinner classes - holds functions that determine available menu items
class Breakfast {
  private:
  string openTime;
  string closeTime;
  string <vector> availableItems;
  public:
  Breakfast (string o, string c, vector <string> a) {
    openTime = o;
    closeTime = c;
    availableItems = a;
  }
};

class Brunch {
  private:
  string openTime;
  string closeTime;
  string <vector> availableItems;
  public:
  Brunch (string o, string c, vector <string> a) {
    openTime = o;
    closeTime = c;
    availableItems = a;
  }
};

class Lucnh {
  private:
  string openTime;
  string closeTime;
  string <vector> availableItems;
  public:
  Lunch (string o, string c, vector <string> a) {
    openTime = o;
    closeTime = c;
    availableItems = a;
  }
};

class Dinner {
  private:
  string openTime;
  string closeTime;
  string <vector> availableItems;
  public:
  Dinner (string o, string c, vector <string> a) {
    openTime = o;
    closeTime = c;
    availableItems = a;
  }
};


//Menu item class
class MenuItem {
  private:
  string name;
  string <vecotr> ingredients;
  int calories;
  
  public:
  MenuItem (string n, vector <string> i, int c) {
    name = n;
    ingredients = i;
    calories = c;
  }
  string GetName() {
    return name;
  }
  string GetIngredients() {
    return ingredients;
  }
  string GetCalories() {
    return calories;
  }
  void DisplayMenuItem() {
    cout << "Item is: " << GetName << "It has " << GetCalories << " calories" << endl << "It contains " << GetIngredients << "." <<endl;
  }

  
};

int main() {
    MenuItem burger("Cheeseburger", {"beef patty", "cheddar", "bun", "lettuce", "tomato"}, 650);
    MenuItem salad("Garden Salad", {"lettuce", "cucumber", "tomato"}, 120);
    MenuItem water("Water", {}, 0);

    burger.DisplayMenuItem();
    cout << endl;
    salad.DisplayMenuItem();
    cout << endl;
    water.DisplayMenuItem();

    // Test getters directly
    cout << endl << "Getter check: " << burger.GetName() << " / "
         << burger.GetCalories() << " / " << burger.GetIngredients().size()
         << " ingredients" << endl;
    return 0;
}
