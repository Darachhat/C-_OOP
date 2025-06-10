#include <iostream>
using std::string;

class Emplooyee {
    private:
        int tax = 10;
        string Company;
        string Name;
        int Age;
        int Salary;

        public:

        void Introduction(){
            std::cout<<"My name is " + Name << std::endl;
            std::cout<<"I work at " <<Company << std::endl;
            std::cout<<"I am "<<Age << " years old" << std::endl;
            std::cout<<"My salary is " << (Salary - (Salary*tax/100)) << std::endl;
        }

        Emplooyee (string company, string name, int age, int salary){
            Company = company;
            Name = name;
            Age = age;
            Salary = salary;
        }
};

int main()
{
    Emplooyee employ_1 = Emplooyee("ABA","Sothun Darachhat",19,1000);
    employ_1.Introduction();
}