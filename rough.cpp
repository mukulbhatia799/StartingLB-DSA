#include <iostream> 
using namespace std; 
class Complex { 
private: 
	int Student1_marks, Student2_marks; 

public: 
	Complex(int stu1marks = 0, int stu2marks = 0) 
	{ 
		Student1_marks = stu1marks; 
		Student2_marks = stu2marks; 
	} 
    void display()
    {
        cout << "Student 1 marks is: " << Student1_marks << endl;
        cout << "Student 2 marks is: " << Student2_marks << endl;

        cout << "Sum of both students marks is: " << Student1_marks + Student2_marks << endl;
    }
	friend Complex operator+(Complex const& c1, Complex const& c2); 
	friend Complex operator>(Complex const& c1, Complex const& c2); 
};
Complex operator+(Complex const& stu1, Complex const& stu2) 
{ 
	return Complex(stu1.Student1_marks + stu2.Student1_marks, stu1.Student2_marks + stu2.Student2_marks); 
} 
Complex operator>(Complex const& stu1, Complex const& stu2) 
{ 
    cout << "Student 1 marks: " << stu1.Student1_marks << endl;
    cout << "Student 2 marks: " << stu2.Student2_marks << endl;
    if(stu1.Student1_marks > stu2.Student2_marks) 
        cout << "Student 1 marks is greater than student 2";
        else 
            cout << "Student 2 marks is greater than student 1 marks";
} 
int main() 
{ 
	Complex student1(10, 5), student2(2, 4); 
	Complex sumOfStudentsMarks = student1 + student2; 
	sumOfStudentsMarks.display();

    
	return 0; 
}
