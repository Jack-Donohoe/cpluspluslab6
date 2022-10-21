

/*
#include <iostream>

using namespace std;

//Static Critter
//Demonstrates static member variables and functions
class Critter
{
public:
    static int s_Total;     //static member variable declaration
                            //total number of Critter objects in existence

    int id;

    Critter(int hunger = 0);
    static int GetTotal();  //static member function prototype
    int GetId();

private:
    int m_Hunger;
};

int Critter::s_Total = 0;   //static member variable initialization

Critter::Critter(int hunger) :
    m_Hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_Total;

    id = s_Total;
    cout << "The critters unique id is: " << GetId() << endl;
}

int Critter::GetTotal()     //static member function definition
{
    return s_Total;
}

int Critter::GetId()
{
    return id;
}

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::s_Total << "\n\n";

    Critter crit1, crit2, crit3;

    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << "\n";

    return 0;
}
*/

//Critter Caretaker
//Simulates caring for a virtual pet

#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Condition();

private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    int GetHunger() const;
    int GetBoredom() const;
    void PassTime(int time = 1);

};

Critter::Critter(int hunger, int boredom) :
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

inline int Critter::GetHunger() const
{
    return m_Hunger;
}

inline int Critter::GetBoredom() const
{
    return m_Boredom;
}

void Critter::Condition() {
    cout << "The critters hunger is: " << GetHunger() << endl;
    cout << "The critters boredom is: " << GetBoredom() << endl;
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";

    int mood = GetMood();
    if (mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else
    {
        cout << "happy.\n";
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brruppp.\n";

    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}

int main()
{
    Critter crit;

    int choice = 1;  //start the critter off talking
    while (choice != 0)
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Good-bye.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Condition();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    }

    return 0;
}

