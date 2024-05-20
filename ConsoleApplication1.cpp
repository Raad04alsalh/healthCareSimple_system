#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }
};
class Patient : public Person{
    int patientID;
public:
    Patient(string n, int a, int id) : Person(n, a), patientID(id) {}
    int getPatientID() const{
        return patientID;
    }
};
class Doctor : public Person {
    int doctorID;
public:
    Doctor(string n, int a, int id) : Person(n, a), doctorID(id) {}
    int getDoctorID() const{
        return doctorID;
    }
};
class Appointment {
    string date;
    Patient& patient;
    Doctor& doctor;
public:
    Appointment(string d, Patient& p, Doctor& doc) : date(d), patient(p), doctor(doc) {}
    string getDate() const {
        return date;
    }
    Patient& getPatient() const {
        return patient;
    }
    Doctor& getDoctor() const {
        return doctor;
    }
};
class Hospital {
    string name;
    vector<Doctor*> doctors;
    vector<Patient> patients;
public:
    Hospital(string n) : name(n) {}
    void addDoctor(Doctor* doc) {
        doctors.push_back(doc);
    }
    void addPatient(const Patient& pat) {
        patients.push_back(pat);
    }
    const vector<Doctor*>& getDoctors() const {
        return doctors;
    }
    const vector<Patient>& getPatients() const {
        return patients;
    }
    string getName() const {
        return name;
    }
};
int main() {
    Doctor doc1("Dr. Smith", 45, 101);
    Doctor doc2("Dr. Jones", 50, 102);
    Patient pat1("John Doe", 30, 201);
    Patient pat2("Jane Roe", 25, 202);
    Hospital hospital("City Hospital");
    hospital.addDoctor(&doc1);
    hospital.addDoctor(&doc2);
    hospital.addPatient(pat1);
    hospital.addPatient(pat2);

    Appointment app1("2023-05-01", pat1, doc1);
    Appointment app2("2023-05-02", pat2, doc2);
    cout << "Hospital: " << hospital.getName() << endl;
    cout << "Doctors: " << endl;
    for (const auto& doc : hospital.getDoctors()) {
        cout << "  " << doc->getName() << " (ID: " << doc->getDoctorID() << ")" << endl;
    }
    cout << "Patients: " << endl;
    for (const auto& pat : hospital.getPatients()) {
        cout << "  " << pat.getName() << " (ID: " << pat.getPatientID() << ")" << endl;
    }
    cout << "Appointments: " << endl;
    cout << "  Date: " << app1.getDate() << ", Patient: " << app1.getPatient().getName() << ", Doctor: " << app1.getDoctor().getName() << endl;
    cout << "  Date: " << app2.getDate() << ", Patient: " << app2.getPatient().getName() << ", Doctor: " << app2.getDoctor().getName() << endl;

    return 0;
}

