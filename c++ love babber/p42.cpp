// class

#include <iostream>
using namespace std;

/*

when constructor is created manually default constructor is deleted


*/
class player
{
    int health = 202;

public:
    player(int health)
    {
        this->health = health;
    }
    int getHealth()
    {
        return this->health;
    }
    void setHealth(int health)
    {
        this->health = health;
    }
};

int main()
{

    // player p; // gives error
    // player p = {100,50};
    // player p = 100;
    player p(40);
    player z(p);

    cout << " " << p.getHealth() << endl;
    cout << " " << z.getHealth() << endl;

    z.setHealth(50);

    cout << " " << p.getHealth() << endl;
    cout << " " << z.getHealth() << endl;

    return 0;
}
