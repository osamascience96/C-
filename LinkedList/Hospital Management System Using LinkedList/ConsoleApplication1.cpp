#include "pch.h"
#include <iostream>
#include "LinkedList.h"

int main()
{
	bool flag = false;

	short int choice = 0;
	int patient_id;
	std::string patient_name;
	std::string address;
	short int age;
	std::string gender;
	std::string disease_description;
	short int room_no;
	std::string service_type;
	std::string dateofAdmitted;

	// init the object to linkedlist 
	LinkedList *linklist = new LinkedList();

	do {
		// clear screen 
		system("cls");
		// console interface 
		std::cout << "\t\t\t Hospital Management System \n";
		// user input 
		std::cout << "\t\t Press 1 2 3 to select the following functions \n ";
		std::cout << "\t\t 1) Enter the New Patient Record \n ";
		std::cout << "\t\t 2) Search or Edit the  Patient Record \n ";
		std::cout << "\t\t 3) List Patient Records \n ";
		std::cout << "\t\t Enter: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			// clear the screeen 
			system("cls");
			// enter data to list 
			std::cout << "\t\t\t Hospital Data Entry \n";
			std::cout << "\t\t Enter the Patient_Id: ";
			std::cin >> patient_id;
			std::cout << "\t\t Enter the Patient Name: ";
			std::cin >> patient_name;
			std::cout << "\t\t Enter the Patient Address: ";
			std::cin >> address;
			std::cout << "\t\t Enter the Service Type: ";
			std::cin >> service_type;
			std::cout << "\t\t Enter the Patient Age: ";
			std::cin >> age;
			std::cout << "\t\t Enter the Patient Gender: ";
			std::cin >> gender;
			std::cout << "\t\t Enter the Patient Room No: ";
			std::cin >> room_no;
			std::cout << "\t\t Enter the Disease Description: ";
			std::cin >> disease_description;
			std::cout << "\t\t Enter the Date of Patient Admitted: ";
			std::cin >> dateofAdmitted;

			// Pass the data to the Params 
			linklist->AddPatient(patient_id, patient_name, address, age, gender, disease_description, room_no, service_type, dateofAdmitted);
			break;
		case 2:
			// clear the screeen 
			system("cls");
			// search and edit data to list 
			std::cout << "\t\t\t Search and Edit Hospital Data \n";
			std::cout << "\t\t Enter 1 for Search Data or 0 for Search and Edit Patient Data \n";
			std::cout << "\t\t Enter: ";
			std::cin >> flag;

			if (flag == 1) {
				// search the data only
				std::cout << "\t\t Enter Patient Id to Search: ";
				std::cin >> patient_id;
				Node *node = linklist->DataExists(patient_id);

				std::cout << linklist->GetSearchResult(node) << std::endl;
			}
			else {
				// search and edit the data only 
				std::cout << "\t\t Enter Patient Id to Edit: ";
				std::cin >> patient_id;
				// if data does exits, return pointer to node else not found
				Node *node = linklist->DataExists(patient_id);
				if (node != nullptr) {
					// clear screen 
					system("cls");
					std::cout << linklist->GetSearchResult(node) << std::endl;
					std::cout << "\t\t Enter the Data to edit!" << std::endl;

					std::cout << "\t\t Enter the Patient Name: ";
					std::cin >> patient_name;
					std::cout << "\t\t Enter the Patient Address: ";
					std::cin >> address;
					std::cout << "\t\t Enter the Service Type: ";
					std::cin >> service_type;
					std::cout << "\t\t Enter the Patient Age: ";
					std::cin >> age;
					std::cout << "\t\t Enter the Patient Gender: ";
					std::cin >> gender;
					std::cout << "\t\t Enter the Patient Room No: ";
					std::cin >> room_no;
					std::cout << "\t\t Enter the Disease Description: ";
					std::cin >> disease_description;
					std::cout << "\t\t Enter the Date of Admitted: ";
					std::cin >> dateofAdmitted;

					std::cout << linklist->GetEditSearchResults(patient_id, patient_name, address, age, gender,
						disease_description, room_no, service_type, dateofAdmitted, node) << std::endl;
				}
				else {
					std::cout << "The data does not exists in the list to edit!";
				}
			}
			break;
		case 3:
			// clear the screeen 
			system("cls");
			// Display all from the list 
			std::cout << "\t\t\t List the Hospital Data \n";

			std::cout << "\t\t 1) Enter 1 to list the Patients Records in Alphabetical Order \n";
			std::cout << "\t\t 2) Enter 2 to list the Patients Records of Emergency Type \n";
			std::cout << "\t\t 3) Enter 3 to list the Patients Records of OPD Type \n";
			std::cout << "\t\t 4) Enter 4 to list the Patients Records wrt particular date \n";

			std::cout << "\t\t Enter: ";
			std::cin >> choice;

			if (choice == 1) {
				// code undefined
			}else if (choice == 2) {
				Node *node = linklist->GetListNode();

				while (node != nullptr) {
					if (node->GetCharOfServiceType() == 'E' || node->GetCharOfServiceType() == 'e') {
						std::cout << node->GetDataString() << std::endl;
					}

					std::cout << "\t\t ------------------------- \n";
					// move to next node
					node = node->GetPointer();
				}
			}else if (choice == 3) {
				Node *node = linklist->GetListNode();

				while (node != nullptr) {
					if (node->GetCharOfServiceType() == 'O' || node->GetCharOfServiceType() == 'o') {
						std::cout << node->GetDataString() << std::endl;
					}

					std::cout << "\t\t ------------------------- \n";
					// move to next node
					node = node->GetPointer();
				}
			}
			else if (choice == 4) {
				Node *node = linklist->GetListNode();
				std::cout << "\t\t Enter the Date: ";
				std::cin >> dateofAdmitted;

				while (node != nullptr) {
					if (dateofAdmitted == node->GetDateofAdmitted()) {
						std::cout << node->GetDataString() << std::endl;
					}

					std::cout << "\t\t ------------------------- \n";
					// move to next node
					node = node->GetPointer();
				}
			}

			break;
		default:
			// other key pressed 
			std::cout << "Enter the Prescribed Button!" << std::endl;
			break;
		}
		// enter again (user input)
		std::cout << "\t\t\t\t Enter Data Again(1 from yes and 0 for No): ";
		std::cin >> flag;

	} while (flag == true);


	return 0;
}
