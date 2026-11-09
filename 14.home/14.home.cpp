#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int age;
    string university;

public:
    Student()
    {
        name = "Unknown";
        age = 0;
        university = "Unknown";
    }

    Student(string name, int age, string university)
    {
        this->name = name;
        this->age = age;
        this->university = university;
    }

    void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university << endl;
    }
};

class Aspirant : public Student
{
private:
    string topic;
    int pages;
    bool defended;

public:
    Aspirant() : Student()
    {
        topic = "Unknown";
        pages = 0;
        defended = false;
    }

    Aspirant(string name, int age, string university,
        string topic, int pages)
        : Student(name, age, university)
    {
        this->topic = topic;
        this->pages = pages;
        defended = false;
    }

    void WriteDissertation(int count)
    {
        if (count <= 0 || defended)
        {
            cout << "Cannot add pages!" << endl;
            return;
        }

        pages += count;
        cout << "Added " << count << " pages." << endl;
    }

    void DefendDissertation()
    {
        if (defended)
        {
            cout << "Already defended!" << endl;
        }
        else if (pages >= 100)
        {
            defended = true;
            cout << "Dissertation defended!" << endl;
        }
        else
        {
            cout << "Not enough pages!" << endl;
        }
    }

    void Show()
    {
        Student::Show();
        cout << "Topic: " << topic << endl;
        cout << "Pages: " << pages << endl;
        cout << "Defended: "
            << (defended ? "Yes" : "No") << endl;
    }
};

int main()
{
    Aspirant a("Ivan Petrenko", 25, "Karazin University",
        "Artificial Intelligence", 80);

    a.Show();

    cout << "\nWriting dissertation:\n";
    a.WriteDissertation(30);

    cout << "\nDefending dissertation:\n";
    a.DefendDissertation();

    cout << "\nFinal information:\n";
    a.Show();

    return 0;
}






//2

class Passport
{
protected:
    string name;
    string surname;
    string birthDate;
    string passportNumber;

public:
    Passport()
    {
        name = "Unknown";
        surname = "Unknown";
        birthDate = "Unknown";
        passportNumber = "Unknown";
    }

    Passport(string name, string surname,
        string birthDate, string passportNumber)
    {
        this->name = name;
        this->surname = surname;
        this->birthDate = birthDate;
        this->passportNumber = passportNumber;
    }

    void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birth date: " << birthDate << endl;
        cout << "Passport number: " << passportNumber << endl;
    }
};

class ForeignPassport : public Passport
{
private:
    string foreignNumber;
    string visas[10];
    int visaCount;

public:
    ForeignPassport() : Passport()
    {
        foreignNumber = "Unknown";
        visaCount = 0;
    }

    ForeignPassport(string name, string surname,
        string birthDate, string passportNumber,
        string foreignNumber)
        : Passport(name, surname, birthDate, passportNumber)
    {
        this->foreignNumber = foreignNumber;
        visaCount = 0;
    }

    void AddVisa(string country)
    {
        if (visaCount < 10)
        {
            visas[visaCount] = country;
            visaCount++;
            cout << "Visa added!" << endl;
        }
        else
        {
            cout << "Visa list is full!" << endl;
        }
    }

    void Show()
    {
        Passport::Show();

        cout << "Foreign passport number: "
            << foreignNumber << endl;

        cout << "Visas:" << endl;

        if (visaCount == 0)
        {
            cout << "No visas" << endl;
        }
        else
        {
            for (int i = 0; i < visaCount; i++)
            {
                cout << i + 1 << ". "
                    << visas[i] << endl;
            }
        }
    }
};

int main()
{
    ForeignPassport p("Ivan", "Petrenko",
        "15.05.2000", "123456789",
        "FE123456");

    p.AddVisa("USA");
    p.AddVisa("Canada");
    p.AddVisa("Japan");

    cout << "\nPassport information:\n";
    p.Show();

    return 0;
}
