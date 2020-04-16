#include "pch.h"
#include <string>

class Node {
private:
	int patient_id;
	std::string patient_name;
	std::string address;
	short int age;
	std::string gender;
	std::string disease_description;
	short int room_no;
	std::string service_type;
	std::string dateofAdmitted;
	Node *nextPointer;
public:
	Node(int patient_id, std::string patient_name, std::string address, short int age, 
		std::string gender, std::string d_d, short int rn, std::string service_type, std::string dateofAdmitted) {
		// init the values 
		this->patient_id = patient_id;
		this->patient_name = patient_name;
		this->address = address;
		this->age = age;
		this->gender = gender;
		this->disease_description = d_d;
		this->room_no = rn;
		this->service_type = service_type;
		this->dateofAdmitted = dateofAdmitted;
	}

	void SetPatientName(std::string patient_name) {
		this->patient_name = patient_name;
	}

	std::string GetPatientName() {
		return patient_name;
	}

	void SetAddress(std::string address) {
		this->address = address;
	}

	void SetAge(int age) {
		this->age = age;
	}

	void SetGender(std::string gender) {
		this->gender = gender;
	}

	void SetDiseaseDescription(std::string disease_description) {
		this->disease_description = disease_description;
	}

	void SetRoom_no(int room_no) {
		this->room_no = room_no;
	}

	void SetServiceType(std::string service_type) {
		this->service_type = service_type;
	}

	char GetCharOfServiceType() {
		return service_type[0];
	}

	void SetDateOfAdmitted(std::string dateofAdmitted) {
		this->dateofAdmitted = dateofAdmitted;
	}

	std::string GetDateofAdmitted() {
		return dateofAdmitted;
	}

	void SetPointer(Node *ptr) {
		nextPointer = ptr;
	}

	Node* GetPointer() {
		return nextPointer;
	}

	int GetPatientId() {
		return patient_id;
	}

	std::string GetDataString() {
		std::string output = " Patient_Id: ";
		output = output + std::to_string(patient_id) + "\n"
			+ " Patient Name: " + patient_name + "\n Patient Address: " + address +
			"\n Patient Age: " + std::to_string(age) + "\n Patient Gender: " + gender +
			"\n Disease Description: " + disease_description + "\n Room No: " + std::to_string(room_no)
			+ "\n Service Type: " + service_type + "\n Date of Admitted: " + dateofAdmitted + "\n";
		return output;
	}

};