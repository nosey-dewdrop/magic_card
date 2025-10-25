
int main(){
      Player p1(10, "damla");

      string name = p1.getUserName();
      string* name2 = &name;

      cout<< "\nname is: " << name << endl;
      cout<< "&name  is: " << &name << endl;
      cout<< "*&name  is: " << *&name << endl;

      cout<< "\nname2 is: " << name2 << endl;
      cout<< "*name2  is: " << *name2 << endl;

      cout<< "\n&*name2  is: " << &*name2 << endl;
      cout<< "*&*name2  is: " << *&*name2 << endl;
      cout<< "&name2  is: " << &name2 << endl;

      return 0;
}
