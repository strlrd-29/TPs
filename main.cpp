#include <iostream>
#include <string>
#include <vector>

using namespace std;

// definitions des differentes class

// la classe Note
class Note {
  int MAXIMUM_GRADE = 20;
  double value;

public:
  // methodes

  // avoir la valeur
  double getValue() { return value; };

  // modifier la valeur
  void setValue(double val) { value = val; }

  // retourner la note moyenne d'une liste de notes
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

// classe result
class Result {
  string module;
  Note lanote;

public:
  // methodes

  // avoir le nom du module
  string getModule() { return module; }

  // modifier le nom du module
  void setModule(string p_module) { module = p_module; };

  // avoir la note
  Note getNote() { return lanote; }

  // modifier la note
  void setNote(Note note) { lanote = note; }
};

// classe Student
class Student {
  string firstName;
  string lastName;
  vector<Result> results;

public:
  // methodes
  // lastName
  void setFirstName(string fn) { firstName = fn; }
  void setLastName(string ln) { lastName = ln; }
  // lastName
  string getFirstName() { return firstName; }
  string getLastName() { return lastName; }

  // Retourner une liste de tous les resultats de l'etudiant
  vector<Result> getResults() { return results; }

  // avoir toutes la liste des note de l'etudiant
  vector<Note> getNotes() {
    vector<Note> notes;
    for (int i = 0; i < results.size(); i++) {
      notes.push_back(results[i].getNote());
    }
    return notes;
  }

  // ajouter un resultat a la liste des resultat
  void addResult(string pModule, Note note) {
    Result newRes;
    newRes.setModule(pModule);
    newRes.setNote(note);
    results.push_back(newRes);
  }

  // avoir la note moyenne
  double averageNote() {
    Note note;
    return note.note_moyeene(getNotes()).getValue();
  }

  // affichage des resultats de l'etudiant
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

// clasee Promotion
class Promotion {
  string name;
  vector<Student> students;

public:
  // methodes

  // avoir le nom du dpt
  string getName() { return name; }

  // avoir la liste des etudiants
  vector<Student> getStudents() { return students; }

  // ajouter un etudiant aux dpt
  void addStudent(Student student) { students.push_back(student); }

  // afficher les resultat de tous les etudiants
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
