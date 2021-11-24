#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct note {
  int maximum_grad = 20;
  double value;
};

typedef note Note;

struct result {
  string nom_module;
  Note note;
};

typedef result Result;

struct student {
  string first_name;
  string last_name;
  vector<Result> results;
};

typedef student Student;

// avoir la valeur de la note
double getValue(Note note) { return note.value; }

// avoir la note moyenne
note noteMoyenne(vector<Note> notes) {
  note note_moy;
  double value_moy;
  for (int i = 0; i < notes.size(); i++) {
    value_moy += notes[i].value;
  }
  note_moy.value = value_moy / notes.size();
  return note_moy;
}

// avoir la note
Note getNote(Result res) { return res.note; }

// ajouter un resultat
void addResult(string module, Note note, vector<Result> &results) {
  Result current;
  current.nom_module = module;
  current.note.value = note.value;
  results.push_back(current);
}

// avoir un vecteur des notes
vector<Note> getNotes(Student student) {
  vector<Note> notes;
  for (int i = 0; i < student.results.size(); i++) {
    notes.push_back(student.results[i].note);
  }
  return notes;
}

// avoir la note moyenne
double averageNote(Student student) {
  Note note_moy = noteMoyenne(getNotes(student));
  return note_moy.value;
}

int main() {
  vector<Note> notes(3);
  notes[0].value = 15;
  notes[1].value = 9;
  notes[2].value = 5;
  cout << "La note moyenne est egale a " << noteMoyenne(notes).value << endl;
  return 0;
}
