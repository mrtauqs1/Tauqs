#include "University.h"
using namespace std;

Course::Course()
{
    name = nullptr;
    credits_hours = 0;
}

int Course::getsize(char* t)
{
    int size=0;
    for(int i=0;t[i]!='\0';i++)
    {
        ++size;
    }
    return size;
}

Course::Course(char* name, int credits_hours)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';

    this->credits_hours = credits_hours;
}

Course::Course(const Course& other)
{
    int size = getsize(other.name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = other.name[i];
    }
    this->name[size] = '\0';

    this->credits_hours = other.credits_hours;
}

void Course::setName(char* name)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';
}

void Course::setCredits_hours(int credits_hours)
{
    this->credits_hours = credits_hours;
}

char* Course::getName()
{
    return name;
}

int Course::getCredits_hours()
{
    return credits_hours;
}



void Course::display()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "                   Course Details                        " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Name of Course " << name << endl;
    cout << "Credits Hours For Course " << credits_hours << endl;
}

Course::~Course()
{
    delete [] name;
}

Department::Department()
{
    name = nullptr;
    location = nullptr;
    size = 0;
}

int Department::getsize(char* t)
{
    int size = 0;
    for(int i = 0; t[i] != '\0'; i++)
    {
        ++size;
    }
    return size;
}

Department::Department(char* name, char* location, Course* course, int size)
{
    int name_size = getsize(name);
    this->name = new char[name_size + 1];
    for(int i = 0; i < name_size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[name_size] = '\0';
    
    int location_size = getsize(location);
    this->location = new char[location_size + 1];
    for(int i = 0; i < location_size; i++)
    {
        this->location[i] = location[i];
    }
    this->location[location_size] = '\0';

    // this->course = new Course[size];
    // for(int i = 0; i < size; i++)
    // {
    //     this->course[i] = course[i];
    // }
    // this->size = size;
    this->course=course;
}

Department::Department(const Department& other)
{
    int name_size = getsize(other.name);
    this->name = new char[name_size + 1];
    for(int i = 0; i < name_size; i++)
    {
        this->name[i] = other.name[i];
    }
    this->name[name_size] = '\0';
    
    int location_size = getsize(other.location);
    this->location = new char[location_size + 1];
    for(int i = 0; i < location_size; i++)
    {
        this->location[i] = other.location[i];
    }
    this->location[location_size] = '\0';

    // this->course = new Course[other.size];
    // for(int i = 0; i < other.size; i++)
    // {
    //     this->course[i] = other.course[i];
    // }
    // this->size = other.size;
    this->course=course;
}

void Department::setName(char* name)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';
}

void Department::setLocation(char* location)
{
    int size = getsize(location);
    this->location = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->location[i] = location[i];
    }
    this->location[size] = '\0';
}

void Department::setCourse(char* name, int credits_hours)
{
    Course* new_course = new Course[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_course[i] = course[i];
    }
    new_course[size] = Course(name, credits_hours);

    delete[] course;
    course = new_course;
    size++;
}

char* Department::getName()
{
    return name;
}

char* Department::getLocation()
{
    return location;
}

Course* Department::getCourse()
{
    return course;
}

void Department::addcourse(Course *course) {
    Course* new_courses = new Course[size + 1];
    for (int i = 0; i < size; i++) {
        new_courses[i] = this->course[i];
    }
    new_courses[size] = *course;
    size++;
    delete[] course;
    course = new_courses;
}

void Department::deletecourse(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    Course* new_courses = new Course[size - 1];
    for (int i = 0; i < index; i++) {
        new_courses[i] = this->course[i];
    }
    for (int i = index + 1; i < size; i++) {
        new_courses[i - 1] = this->course[i];
    }
    size--;
    delete[] course;
    course = new_courses;
}

void Department::Display()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "                       Department                        " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Name of the department" <<name << endl;
    cout << "Locations of the department" <<location << endl;
    cout << "Course Details" <<endl;
    //Course();
    cout << "Course Details:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i+1 << ". " << course[i].getName() << " (Credits: " << course[i].getCredits_hours() << ")" << endl;
    }

    //cout << "Add Course" <<endl;
    // addcourse(course);
    // cout << "Delete Course" <<endl;
    // deletecourse(index);
}

Department::~Department()
{
    delete [] name;
    delete [] location;
}

 Person::Person()
 {
    name=nullptr;
    age =0;
 }

 int Person::getsize(char* t)
{
    int size=0;
    for(int i=0;t[i]!='\0';i++)
    {
        ++size;
    }
    return size;
}

Person::Person(char* name, int age)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';

    this->age = age;   
}

Person::Person(const Person & other)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = other.name[i];
    }
    this->name[size] = '\0';

    this->age = other.age; 
}

void Person::setName(char* name)
{
    int size = getsize(name);
    this->name = new char[size + 1];
    for(int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';
}

void Person::setAge(int age)
{
    this->age = age;
}

char* Person::getName()
{
    return name;
}
int Person::getAge()
{
    return age;
}
void Person::display()
{
    cout <<"----------------------------------------------------------------" << endl;
    cout <<"                          Person Details                         " << endl;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout <<" Age: " << age << endl;
}
Person::~Person()
{
    delete [] name;
}

Student::Student()
{
    name= nullptr;
    size=0;
}

Student::Student(int id, Course* course,char* name,int age) : Person(name,age)
{
    this->id=id;
    this->course=course;
}

Student::Student(const Student& other)
{
    this->id=other.id;
    this->course=other.course;
}

void Student::setId(int id)
{
    this->id=id;
}

void Student::setCourse(char* name, int credits_hours)
{
    // course.setName(name);
    // course.setCredits_hours(credits_hours);
    Course* new_course = new Course[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_course[i] = course[i];
    }
    new_course[size] = Course(name, credits_hours);

    delete[] course;
    course = new_course;
    size++;
}

int Student::getId()
{
    return id;
}

Course* Student::getCourse()
{
    return course;
}

void Student::addcourse(Course* course) {
    Course* new_courses = new Course[size + 1];
    for (int i = 0; i < size; i++) {
        new_courses[i] = this->course[i];
    }
    new_courses[size] = *course;
    size++;
    delete[] course;
    course = new_courses;
}
void Student::dropcourse(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    Course* new_courses = new Course[size - 1];
    for (int i = 0; i < index; i++) {
        new_courses[i] = this->course[i];
    }
    for (int i = index + 1; i < size; i++) {
        new_courses[i - 1] = this->course[i];
    }
    size--;
    delete[] course;
    course = new_courses;
}

void Student::display()
{
    cout <<"----------------------------------------------------------------" << endl;
    cout <<"                          Student Details                         " << endl;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "Id : " << id << endl;
    Course();
    addcourse(course);
    dropcourse(size);
}

Student::~Student()
{

}

Teacher::Teacher()
{
    id = 0;
    size=0;
}

Teacher::Teacher(int id, Course* course,char* name,int age) : Person(name,age)
{
    this->id = id;
    this->course = course;

}

void Teacher::setCourse(char* name, int credits_hours)
{
    // course.setName(name);
    // course.setCredits_hours(credits_hours);
    Course* new_course = new Course[size + 1];
    for(int i = 0; i < size; i++)
    {
        new_course[i] = course[i];
    }
    new_course[size] = Course(name, credits_hours);

    delete[] course;
    course = new_course;
    size++;
}

Course* Teacher::getCourse()
{
    return course;
}

void Teacher::setId(int id)
{
    this->id = id;
}

int Teacher::getId()
{
    return id;
}

void Teacher::choosecourse(Course* course) {
    Course* new_courses = new Course[size + 1];
    for (int i = 0; i < size; i++) {
        new_courses[i] = this->course[i];
    }
    new_courses[size] = *course;
    size++;
    delete[] course;
    course = new_courses;
}
void Teacher::leavecourse(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    Course* new_courses = new Course[size - 1];
    for (int i = 0; i < index; i++) {
        new_courses[i] = this->course[i];
    }
    for (int i = index + 1; i < size; i++) {
        new_courses[i - 1] = this->course[i];
    }
    size--;
    delete[] course;
    course = new_courses;
}

void Teacher::display()
{
    cout <<"----------------------------------------------------------------" << endl;
    cout <<"                        Teacher Details                         " << endl;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "Id : " << id << endl;
    Course();
    choosecourse(course);
    leavecourse(size);
}

Teacher::~Teacher()
{

}

University::University(Department* department, Student* student, Teacher* teacher)
{
    this->department = department;
    this->student = student;
    this->teacher = teacher;
}

void University::setDepartment(char* name, char* location, Course* course)
{
    department->setName(name);
    department->setLocation(location);
    department->addcourse(course);
}

void University::setStudent(int id, Course* course)
{
    student->setId(id);
    student->addcourse(course);
}

void University::setTeacher(int id, Course* course)
{
    teacher->setId(id);
    teacher->choosecourse(course);
}

Department* University::getDepartment()
{
    return department;
}

Student* University::getStudent()
{
    return student;
}

Teacher* University::getTeacher()
{
    return teacher;
}

void University::Display()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "                        University Details                      " << endl;
    cout << "----------------------------------------------------------------" << endl;
    department->Display();
    student->display();
    teacher->display();
}

University::~University()
{
    delete department;
    delete student;
    delete teacher;
}
