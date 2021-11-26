#include <iostream>
#include <vector>

using namespace std;
/* Definition des differentes structures */
// note
struct note {
  int MAXIMUM_GRADE = 20;
  double value;
};

typedef note Note;

// resultat
struct result {
  string module;
  Note lanote;
};

typedef result Result;

// student
struct student {
  string firstName;
  string lastName;
  vector<Result> results;
};

typedef student Student;

// promotion
struct promotion {
  string name;
  vector<Student> students;
};

typedef promotion Promotion;

/* Fonctions */
// fonction sur la structure Note
double getValue(Note note) { return note.value; }

Note note_moyeene(vector<Note> notes) {
  Note noteMoyenne;
  double somme;
  for (int i = 0; i < notes.size(); i++) {
    somme += notes[i].value;
  }
  noteMoyenne.value = somme / notes.size();
  return noteMoyenne;
}

Note getNote(Result res) { return res.lanote; }

// fonctions sur la structure Resultat
void addResult(string module, Note note, vector<Result> &results) {
  Result newRes;
  newRes.module = module;
  newRes.lanote = note;
  results.push_back(newRes);
}

// fonction sur la structure student
vector<Note> getNotes(Student student) {
  vector<Note> notes;
  for (int i = 0; i < student.results.size(); i++) {
    notes.push_back(student.results[i].lanote);
  }
  return notes;
}

double averageNote(Student student) {
  return note_moyeene(getNotes(student)).value;
}

void printResult(Student student) {
  cout << student.lastName + " " + student.firstName << endl;
  for (int i = 0; i < student.results.size(); i++) {
    cout << student.results[i].module << " : "
         << student.results[i].lanote.value << endl;
  }
  cout << "La note moyenne est : " << averageNote(student) << endl;
}

// fonction sur la structure promotion
void addStudent(promotion &promo, Student student) {
  promo.students.push_back(student);
}

vector<Student> getStudents(Promotion promo) { return promo.students; }

void printStudentResults(Promotion promo) {
  cout << promo.name << endl;
  for (int i = 0; i < promo.students.size(); i++) {
    printResult(promo.students[i]);
    cout << endl;
  }
}

// main function
int main() {

  Promotion promo;
  vector<Student> students;
  Student student1;
  student1.firstName = "Ouassim Abdelmalek";
  student1.lastName = "Ghribi";
  Note note11;
  note11.value = 16;
  Note note12;
  note12.value = 13;
  addResult("math", note11, student1.results);
  addResult("info", note12, student1.results);
  Student student2;
  student2.firstName = "Paul";
  student2.lastName = "Calcul";
  Note note21;
  note21.value = 12;
  Note note22;
  note22.value = 17;
  addResult("Programmation 2", note21, student2.results);
  addResult("TNS", note22, student2.results);
  addStudent(promo, student1);
  addStudent(promo, student2);
  printStudentResults(promo);
  return 0;
}
