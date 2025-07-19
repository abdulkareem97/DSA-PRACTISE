#include<iostream>
using namespace std;


int main(){
    int age = 19;
    age = 17;
    if(age>18){
        cout<<" You can drive a car"<<endl;
    }else{
        cout<<" You cant drive a car"<<endl;
    }

     int marks = 54;
    char grade;

    if (marks < 25) {
        grade = 'F';
    } else if (marks <= 44) {
        grade = 'E';
    } else if (marks <= 49) {
        grade = 'D';
    } else if (marks <= 59) {
        grade = 'C';
    } else if (marks <= 69) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'A';
    } else {
        grade = 'X'; // Use 'X' to indicate invalid marks
    }

    std::cout << "Grade: " << grade << std::endl;
    
}