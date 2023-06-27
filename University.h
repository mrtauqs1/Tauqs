#include <iostream>
using namespace std;
class Course {
protected:
    char* name;
    int credits_hours;
public:
    Course();
    int getsize(char* t);
    Course(char* name, int credits_hours);
    Course(const Course& other);
    void setName(char* name);
    void setCredits_hours(int credits_hours);
    char* getName();
    int getCredits_hours();
    // void addcourse(Course *course);
    // void deletecourse(int index);
    void display();
    ~Course();
};

class Department {
protected:
    char* name;
    char* location;
    Course* course;
    int size;
public:
    Department();
    int getsize(char* t);
    Department(char* name, char* location, Course* course,int size);
    Department(const Department& other);
    void setName(char* name);
    void setLocation(char* location);
    void setCourse(char* name, int credits_hours);
    char* getName();
    char* getLocation();
    Course* getCourse();
    void addcourse(Course* course);
    void deletecourse(int index);
    void Display();
    ~Department();
};

class Person {
protected:
    char* name;
    int age;
public:
    Person();
    int getsize(char* t);
    Person(char* name, int age);
    Person(const Person & other);
    void setName(char* name);
    void setAge(int age);
    char* getName();
    int getAge();
    void display();
    ~Person();
};

class Student : public Person
{
protected:
    int id;
    int size;
    Course* course;
public:
    Student();
    Student(int id, Course* course,char* name,int age);
    Student(const Student& other);
    void setId(int id);
    void setCourse(char* name, int credits_hours);
    int getId();
    Course* getCourse();
    void addcourse(Course* course);
    void dropcourse(int index);
    void display();
    ~Student();
};

class Teacher : public Person 
{
protected:
    int id;
    int size;
    Course *course;
public:
    Teacher();
    Teacher(int id, Course* course,char* name,int age);
    void setCourse(char* name, int credits_hours);
    void setId(int id);
    int getId();
    Course* getCourse();
    void choosecourse(Course* course);
    void leavecourse(int index);
    void display();
    ~Teacher();
};

class University {
protected:
    Department* department;
    Student* student;
    Teacher* teacher;
public:
    
    University(Department* department,Student* student,Teacher* teacher);
    void setDepartment(char* name, char* location, Course *course);
    void setStudent(int id,Course *course);
    void setTeacher(int id,Course *course);
    Department* getDepartment();
    Student* getStudent();
    Teacher* getTeacher();
    void Display();
    ~University();
};