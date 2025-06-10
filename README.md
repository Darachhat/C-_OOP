# Review: Object-Oriented Programming (OOP) in C++

## Overview

**Object-oriented Programming (OOP)** គឺជាគំរូនៃ Programming ដែលជាសំណុំនៃច្បាប់និងគំនិត សម្រាប់ដោះស្រាយបញ្ហាជាក់លាក់។ ក្រៅពី OOP មានគំរូ Programming ផ្សេងៗទៀតផង។ OOP ជួយសម្រួលដល់ការដោះស្រាយបញ្ហា ដោយបែងចែកកូដជាបន្ទប់តូចៗដែលងាយស្រួលថែរក្សា និងកែប្រែ។

---

## Key Concepts in OOP

### 1. Class

- **Class** គឺជា user-defined type, គំរូ (blueprint) ឬ template សម្រាប់បង្កើត Object។
- Class កំណត់ attributes និង methods ដែល Object មួយនឹងមាន។
- **Example**:
    ```cpp
    class Car {
    public:
        string color;
        int speed;
        void drive() {
            cout << "Driving..." << endl;
        }
    };
    ```

### 2. Object

- **Object** គឺជាឧទាហរណ៍នៃ class ដែលមាន data តំណាងអោយ real-world object (ឧ. Car)។
- Object មាន attributes និង methods ដែលកំណត់ដោយ class។
- **Example**:
    ```cpp
    Car myCar;
    myCar.color = "Red";
    myCar.speed = 100;
    myCar.drive();
    ```

### 3. Attributes

- **Attributes** តំណាងឲ្យស្ថានភាពរបស់ Object (ឧ. Weight, Color)។
- គេហៅថា member variables ឬ data members។
- **Example**:
    ```cpp
    class Student {
    public:
        string name;
        int age;
    };
    Student s;
    s.name = "Dara";
    s.age = 20;
    ```

### 4. Method

- **Methods** គឺជា function ដែល Object អាចធ្វើបាន (ឧ. brake, accelerate)។
- Methods គេហៅថា member functions។
- **Example**:
    ```cpp
    class Light {
    public:
        void turnOn() {
            cout << "Light is ON" << endl;
        }
    };
    Light l;
    l.turnOn();
    ```

### 5. Constructor

- **Constructor** គឺជា special method ដែលត្រូវបានហៅដោយស្វ័យប្រវត្តិនៅពេល Object ត្រូវបានបង្កើត។
- Constructor មានឈ្មោះដូចទៅនឹង class, មិនមាន return type ហើយប្រើសម្រាប់ initialize Object។
- **Example**:
    ```cpp
    class Book {
    public:
        string title;
        Book(string t) {
            title = t;
        }
    };
    Book b("C++ OOP");
    ```

### 6. Access Specifiers

- ប្រើដើម្បីគ្រប់គ្រងពីរបៀបដែល members (attributes និង methods) អាចចូលប្រើបាន។
- បីប្រភេទ៖
    - **public**: អាច access ពីក្រៅ class។
    - **private**: មិនអាច access ពីក្រៅ class។
    - **protected**: មិនអាច access ពីក្រៅ class តែអាច access បានក្នុង inherited class។
- **Example**:
    ```cpp
    class Account {
    private:
        double balance;
    public:
        void setBalance(double b) { balance = b; }
        double getBalance() { return balance; }
    };
    Account acc;
    acc.setBalance(100.50);
    cout << acc.getBalance();
    ```

---

## Four Main Pillars of OOP

### 1. Encapsulation

- បង្ហាញថា sensitive data ត្រូវបានលាក់ពី user ដោយប្រើ private attributes។
- ចង់ access private members ត្រូវមាន public getter/setter methods។
- **Example**:
    ```cpp
    class Person {
    private:
        string password;
    public:
        void setPassword(string pw) { password = pw; }
        string getPassword() { return password; }
    };
    ```

### 2. Abstraction

- Object បង្ហាញតែអ្វីដែលចាំបាច់សម្រាប់ការប្រើប្រាស់ (ឧ. បង្ហាញ speed, មិនបង្ហាញរបៀបគណនា)។
- បង្កើត interface ដែលលាក់ details ខាងក្នុង។
- **Example**:
    ```cpp
    class Remote {
    public:
        void pressPowerButton() {
            turnOnDevice();
        }
    private:
        void turnOnDevice() {
            cout << "Device is ON" << endl;
        }
    };
    ```

### 3. Inheritance

- អនុញ្ញាតឲ្យ class មួយ reuse attribute និង method ពី class ផ្សេងទៀត។
- ជៀសវាងការសរសេរ code ស្ទួន។
- មាន
    - **Base class (parent)**: class ដែលត្រូវបាន inherit។
    - **Derived class (child)**: class ដែល inherit ពី class ផ្សេងទៀត។
- **Example**:
    ```cpp
    class Animal {
    public:
        void eat() { cout << "Eating..." << endl; }
    };

    class Dog : public Animal {
    public:
        void bark() { cout << "Woof!" << endl; }
    };

    Dog d;
    d.eat();  // inherited
    d.bark(); // own
    ```

### 4. Polymorphism

- មានន័យថា "many forms" (ច្រើនទម្រង់)។
- អាចប្រើ method ឬ function ដូចគ្នា តែកាន់តែ object ផ្សេងៗ (ឧ. parent reference → child object)។
- ជួយឲ្យ code មាន flexibility និង scalability។
- **Compile-time Polymorphism (Function Overloading/Operator Overloading)**
    ```cpp
    class Print {
    public:
        void show(int i) { cout << "Int: " << i << endl; }
        void show(string s) { cout << "String: " << s << endl; }
    };
    Print p;
    p.show(10);
    p.show("Hello");
    ```
- **Run-time Polymorphism (Virtual Functions)**
    ```cpp
    class Base {
    public:
        virtual void display() { cout << "Base class" << endl; }
    };
    class Derived : public Base {
    public:
        void display() override { cout << "Derived class" << endl; }
    };
    Base *bptr;
    Derived d;
    bptr = &d;
    bptr->display(); // Output: Derived class
    ```

---

## Why OOP?

- ងាយស្រួលថែរក្សា និងពង្រីក (maintainable & scalable)
- បែងចែកច្បាស់លាស់ (modular)
- Promote code reuse
- ជួយបង្កើតកម្មវិធីធំៗដោយមានរចនាសម្ព័ន្ធល្អ

---
