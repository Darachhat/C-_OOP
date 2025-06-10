#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee { 
private:
    int tax = 10;
    string Company;
    int Age;
    int Salary;
protected:
    string Name;
public:
    void AskForPromotion(){
        if(Age>30)
            std::cout<<Name<<" got promotion!" <<std::endl;
        else
            std::cout<<Name<<" no promotion for you."<<std::endl;
        
    }
    void setCompany(string company) { Company = company; }
    string getCompany() { return Company; }

    void setName(string name) { Name = name; }
    string getName() { return Name; }

    void setAge(int age) { Age = age; }
    int getAge() { return Age; }

    void setSalary(int salary) { Salary = salary; }
    int getSalary() { return (Salary - (Salary * tax / 100)); }

    void Introduction() {
        std::cout << "My name is " << Name << std::endl;
        std::cout << "I work at " << Company << std::endl;
        std::cout << "I am " << Age << " years old" << std::endl;
        std::cout << "My salary is " << getSalary() << std::endl;
    }

    Employee(string company, string name, int age, int salary) {
        Company = company;
        Name = name;
        Age = age;
        Salary = salary;
    }
    virtual void work() {
        std::cout<<Name<<" is checking email, task backlog, performing task..."<<std::endl;
    }
};

class Developer : public Employee {
public:
    string Language;

    Developer(string company, string name, int age, int salary, string language)
        : Employee(company, name, age, salary) {
        Language = language;
    }

    void createApp() {
        std::cout << getName() << " is creating an app using " << Language << std::endl;
    }
    void work(){
        std::cout<< Name << " is work with " <<Language<< " language." << std::endl;
    }
};

class Teacher : public Employee {
public:
    string Subject;

    Teacher(string company, string name, int age, int salary, string subject)
        : Employee(company, name, age, salary) {
        Subject = subject;
    }

    void prepareLesson() {
        std::cout << Name<< " is preparing a " << Subject << " lesson" << std::endl;
    }
    void work(){
        std::cout<< Name << " is teaching " <<Subject << std::endl;
    }
};

int main() {
    Developer dev("ABA", "Darachhat", 19, 2000, "Laravel");

    Teacher teacher("ABA", "Darachhat", 19, 2000, "Web Development");

    Employee* e1 = &dev;
    Employee* e2 = &teacher;
    e1->work();
    e2->work();

}
