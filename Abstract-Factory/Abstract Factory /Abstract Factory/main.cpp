//
//  main.cpp
//  Abstract Factory
//
//  Created by Arina Nazarova on 04.04.2020.
//  Copyright © 2020 Arina Nazarova. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Абстрактные базовые классы всех видов бойцов
class General
{
public:
    virtual void info() = 0;
    virtual ~General() {}
};

class Soldier
{
public:
    virtual void info() = 0;
    virtual ~Soldier() {}
};

class Warlord
{
public:
    virtual void info() = 0;
    virtual ~Warlord() {}
};


// Классы всех войнов войска Эльфов
class ElfGeneral: public General
{
public:
    void info() {
        cout<<"ElfGeneral"<<endl;
    }
};

class ElfSoldier: public Soldier
{
public:
    void info() {
        cout<< "ElfSoldier" << endl;
    }
};

class ElfWarlord: public Warlord
{
public:
    void info() {
        cout << "ElfSoldier" << endl;
    }
};

// Классы всех войнов войска Орков
class OrcGeneral: public General
{
public:
    void info() {
        cout << "OrcGeneral" << endl;
    }
};

class OrcSoldier: public Soldier
{
public:
    void info() {
        cout << "OrcSoldier" << endl;
    }
};

class OrcWarlord: public Warlord
{
public:
    void info() {
        cout<<"OrcWarlord"<<endl;
    }
};


// Абстрактная фабрика - фабрика для производства войнов
class ArmyFactory
{
public:
    virtual General* createGeneral() = 0;
    virtual Soldier* createSoldier() = 0;
    virtual Warlord* createWarlord() = 0;
    virtual ~ArmyFactory() {}
};


// Фабрика для создания войска Эльфов
class ElfArmyFactory: public ArmyFactory
{
public:
    General* createGeneral() {
        return new ElfGeneral;
    }
    Soldier* createSoldier() {
        return new ElfSoldier;
    }
    Warlord* createWarlord() {
        return new ElfWarlord;
    }
};


// Фабрика для создания войска Орков
class OrcArmyFactory: public ArmyFactory
{
public:
    General* createGeneral() {
        return new OrcGeneral;
    }
    Soldier* createSoldier() {
        return new OrcSoldier;
    }
    Warlord* createWarlord() {
        return new OrcWarlord;
    }
};


// Класс, содержащий всех воинов той или иной армии
class Army
{
public:
    ~Army() {
        int i;
        for(i=0; i<vi.size(); ++i)  delete vi[i];
        for(i=0; i<va.size(); ++i)  delete va[i];
        for(i=0; i<vh.size(); ++i)  delete vh[i];
    }
    void info() {
        int i;
        for(i=0; i<vi.size(); ++i)  vi[i]->info();
        for(i=0; i<va.size(); ++i)  va[i]->info();
        for(i=0; i<vh.size(); ++i)  vh[i]->info();
    }
    vector <General*> vi;
    vector <Soldier*> va;
    vector <Warlord*> vh;
};


// Здесь создается армия той или иной стороны
class CreateArmy
{
public:
    Army* createArmy( ArmyFactory& factory ) {
        Army* p = new Army;
        p->vi.push_back( factory.createGeneral());
        p->va.push_back( factory.createSoldier());
        p->vh.push_back( factory.createWarlord());
        return p;
    }
};


int main()
{
    CreateArmy army;
     ElfArmyFactory elf_factory;
    OrcArmyFactory orc_factory;
    
    Army * elf = army.createArmy( elf_factory);
    Army * orc = army.createArmy( orc_factory);
    cout<<"Elf Army:" << endl;
    elf->info();
    cout << "\nOrc Army" << endl;
    orc->info();
    // ...
}
