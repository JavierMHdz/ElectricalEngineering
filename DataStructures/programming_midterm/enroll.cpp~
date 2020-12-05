//Javier Jesus Macossay-Hernandez

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
// You can add other libraries if you like


using namespace std;

class Student {
public:
  Student();
  Student(std::string name);
  void addCourse(std::string course, int units);
  int getUnits();
  //return the courses
  std::vector<std::string> &get_courses() {return courses_;}
private:
  std::string name_;
  std::vector<std::string> courses_;
  int units_;
};

Student::Student()
{
  // add code if you want to use this class
}
Student::Student(std::string name)
{
  // add code if you want to use this class
  name_ = name;
  units_ = 0;
}
void Student::addCourse(std::string course, int units)
{
  // add code if you want to use this class
  courses_.push_back(course);
  units_ += units;
}
int Student::getUnits()
{
  // add code if you wnat to use this class

  return units_;  // change this return statement
}

int main(int argc, char* argv[])
{
  if(argc < 4){
    cout << "Please enter a student file";
    cout << "and enrollment file and desiredCourse" << endl;
    return 1;
  }
  
  //variables
  int N, units;
  string student, course;
  map<string, Student> stumap;
  
  ifstream sfile(argv[1]);
  if(sfile.fail()){
    cout<<"Invalid student file"<<endl;
    sfile.close();
    return 1;
  }
  
  sfile>>N;
  
  while(1){
      sfile>>student;
      
      if(sfile.fail()){
         break;
      }
      //adding them to the map
      Student s(student);
      stumap.insert(make_pair(student,s));
  }
  
  ifstream cfile(argv[2]);
  if(cfile.fail()){
    cout<<"Invalid enrollment file"<<endl;
    cfile.close();
    sfile.close();
    return 1;
  }
  
  while(1){
      cfile>>student>>course>>units;
      
      if(cfile.fail()){
         break;
      }
      
      stumap[student].addCourse(course,units);
  
  }
  
  //more variables
  string desiredClass = argv[3];
  string studentMostUnits;
  int prevUnits = 0;
  vector<string> my_vec(0);
  vector<string> moreUnits(0);
  bool courseExist = false;
  
  map<string, Student>::iterator it;
  for (it = stumap.begin(); it != stumap.end(); ++it){
      vector<string> names = (it->second).get_courses();
      for(int i = 0; i < names.size(); i++){
         if(desiredClass.compare(names[i]) == 0){
            my_vec.push_back(names[i]);
            courseExist = true;
         }
         //I used this format to avoid the error of line
         //with more than 80 characters
         if(desiredClass.compare(names[i]) == 0){
            if((it->second).getUnits() >= 16){
               moreUnits.push_back((it->first));
            }
         }
         if(desiredClass.compare(names[i]) == 0){
            if((it->second).getUnits() > prevUnits){
               prevUnits = (it->second).getUnits();
               studentMostUnits = (it->first);
            }
         }
      }
  }

  //check if the course exists
  if(courseExist ==  false){
      cout<<"Invalid course"<<endl;
      cfile.close();
      sfile.close();
      return 1;
  }
  
  cout<<desiredClass<< " total students: "<<my_vec.size()<<endl;;
  for(int i = 0; i < moreUnits.size(); i++){
      cout<<moreUnits[i]<<endl;
  
  }
  cout<<studentMostUnits<<" has max units: "<<prevUnits<<endl;
  
  sfile.close();
  cfile.close();
  return 0;
}
