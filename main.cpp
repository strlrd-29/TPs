#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* Definition des differentes structures */
// note

class Note {

  int MAXIMUM_GRADE = 20;
  double value;

public:
  double getValue() { return value; };
  void setValue(double val) { value = val; }
  Note note_moyeene(vector<Note> notes) {
    Note noteMoyenne;
    double somme;
    for (int i = 0; i < notes.size(); i++) {
      somme += notes[i].getValue();
    }
    noteMoyenne.setValue(somme / notes.size());
    return noteMoyenne;
  }
};

class Result {
  string module;
  Note lanote;

public:
  void setModule(string p_module) { module = p_module; };
  string getModule() { return module; }
  Note getNote() { return lanote; }
  void setNote(Note note) { lanote = note; }
};

class Student {
  string firstName;
  string lastName;
  vector<Result> results;

public:
  void setFirstName(string fn) { firstName = fn; }
  void setLastName(string ln) { lastName = ln; }
  string getFirstName() { return firstName; }
  string getLastName() { return lastName; }
  vector<Result> getResults() { return results; }
  vector<Note> getNotes() {
    vector<Note> notes;
    for (int i = 0; i < results.size(); i++) {
      notes.push_back(results[i].getNote());
    }
    return notes;
  }

  void addResult(string pModule, Note note) {
    Result newRes;
    newRes.setModule(pModule);
    newRes.setNote(note);
    results.push_back(newRes);
  }

  double averageNote() {
    Note note;
    return note.note_moyeene(getNotes()).getValue();
  }

  void printResult() {
    vector<Result> res = getResults();
    cout << getLastName() + " " + getFirstName() << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].getModule() << " : " << res[i].getNote().getValue()
           << endl;
    }
    cout << "La note moyenne est : " << averageNote() << endl;
  }
};

class Promotion {
  string name;
  vector<Student> students;

public:
  string getName() { return name; }
  vector<Student> getStudents() { return students; }
  void addStudent(Student student) { students.push_back(student); }

  void printStudentResults() {
    cout << getName() << endl;
    vector<Student> students = getStudents();

    for (int i = 0; i < students.size(); i++) {
      students[i].printResult();
      cout << endl;
    }
  }
};

// main function
int main() {

  Promotion promo;
  vector<Student> students;
  Student student1;
  student1.setFirstName("Ouassim Abdelmalek");
  student1.setLastName("Ghribi");
  Note note11;
  note11.setValue(13.4);
  Note note12;
  note12.setValue(15.2);
  student1.addResult("math", note11);
  student1.addResult("info", note12);
  Student student2;
  student2.setFirstName("Paul");
  student2.setLastName("Calcul");
  Note note21;
  note21.setValue(12.75);
  Note note22;
  note22.setValue(17.1);
  student2.addResult("Programmation 2", note21);
  student2.addResult("TNS", note22);
  promo.addStudent(student1);
  promo.addStudent(student2);
  promo.printStudentResults();
  return 0;
}
