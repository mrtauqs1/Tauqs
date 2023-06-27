#include "University.cpp"

int main()
{
    char arr[]="C++";
    char str[]="Java";
    char str2[]="Phthon";
    // Create courses
    Course course1(arr, 3);
    Course course2(str, 4);
    Course course3(str2, 3);
    char str3[]="IT";
    char str4[]="Building A";
    // Create department
    Department department(str3, str4, &course1, 1);

    char name[]="Tauqir";
    char str99[]="OOP";
    char str22[]="IT";
    // Create student
    Student student(1, &course1, name, 20);
    student.setCourse(str99, 4);
    student.setCourse(str22, 3);
    char name1[]="ALi";
    // Create teacher
    Teacher teacher(1, &course1, name1, 35);
    teacher.setCourse(str2, 4);

    // Create university
    University university(&department, &student, &teacher);

    // Display university details
    university.Display();

    return 0;
}


// int main() {
//     char arr[]="C++";
//     char str[]="Java";
//     char str2[]="Phthon";
//     // Create instances of courses
//     Course course1(arr, 3);
//     Course course2(str, 4);
//     Course course3(str2, 3);

//     char dep[]="Computer Science";
//     char loc[]="Block A";
//     char name[]="Tauqir Hayat";
//     char name2[]="Ali Usman";
//     // Create instances of department, student, and teacher
//     Department department(dep,loc, nullptr, 0);
//     Student student(1, nullptr, name, 20);
//     Teacher teacher(100, nullptr, name2, 35);

//     // Set courses for the department, student, and teacher
//     department.setCourse(course1.getName(), course1.getCredits_hours());
//     department.setCourse(course2.getName(), course2.getCredits_hours());
//     department.setCourse(course3.getName(), course3.getCredits_hours());

//     student.setCourse(course1.getName(), course1.getCredits_hours());
//     student.setCourse(course2.getName(), course2.getCredits_hours());

//     teacher.setCourse(course3.getName(), course3.getCredits_hours());

//     // Create the university instance
//     University university(&department, &student, &teacher);

//     // Display university details
//     university.Display();

//     return 0;
// }



// int main() {
//     char arr[]="C++";
//     char str[]="Java";
//     char str2[]="Phthon";
//     // Create courses
//     Course c1 (arr, 4);
//     Course c2(str, 3);
//     Course c3(str2, 3);
    
//     char dep[]="Computer Science";
//     char loc[]="Block A";
//     // Create department
//     Department d1(dep, loc, c1, 1);
    
//     // Add more courses to department
//     d1->addcourse(c2);
//     d1->addcourse(c3);
//     char name[]="Tauqir Hayat";
//     // Create student
//     Student* s1 = new Student(101, c1, name, 20);
//     s1->addcourse(c2);
//     char name1[]="Hira Naveed";
//     // Create teacher 
//     Teacher* t1 = new Teacher(501, c3, name1, 35);
    
//     // Create university
//     University* u1 = new University(d1, s1, t1);
    
//     // Add student and teacher to university
//     u1->setStudent(102, c2);
//     u1->setTeacher(502, c1);
    
//     // Display university details
//     u1->Display();
    
//     delete u1;
//     return 0; 
// }


// Creates 3 courses
// Creates a Computer Science department and adds 3 courses to it
// Creates a student John enrolled in 2 courses
// Creates a teacher Mark handling 1 course
// Creates a University with the department, student and teacher
// Adds another student and teacher to the university
// Displays details of the university
// Deletes the university