#include <iostream>
#include <string>
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

class Emplooyee:AbstractEmployee { 
    private:
        int tax = 10;
        string Company;
        string Name;
        int Age;
        int Salary;

    public:
    void AskForPromotion(){
        if(Age>30)
            cout<<Name<<" got promotion!" <<endl;
        else
            cout<<Name<<" no promotion for you." <<endl;
        
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }
    void setSalary(int salary){
        Salary = salary;
    }
    int getSalary(){
        return (Salary - (Salary*tax/100));
    }

};

int main()
{
    Emplooyee employ_1;
    employ_1.AskForPromotion();
    employ_1.setName("Darachhat");
    employ_1.setCompany("ABA");
    employ_1.setAge(31);
    employ_1.setSalary(1000);
    cout<<"My name is " <<employ_1.getName() << endl;
    cout<<"I work at " <<employ_1.getCompany() <<endl;
    cout<<"I am "<<employ_1.getAge()<<" years old" << endl;
    cout<<"My salary is "<<employ_1.getSalary() << "$ \n";
    employ_1.AskForPromotion();
    
}