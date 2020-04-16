#include "pch.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
}

void LinkedList::AddPatient(int patient_id, std::string patient_name, std::string address, short int age,
	std::string gender, std::string d_d, short int rn, std::string s_t, std::string dateofAdmitted)
{
	if (startNode == nullptr) {
		startNode = new Node(patient_id, patient_name, address, age, gender, d_d, rn, s_t, dateofAdmitted);
	}
	else {
		Node *newNode = startNode;

		while (newNode->GetPointer() != nullptr) {
			newNode = newNode->GetPointer();
		}

		Node *tempNode = new Node(patient_id, patient_name, address, age, gender, d_d, rn, s_t, dateofAdmitted);
		newNode->SetPointer(tempNode);
	}
}

std::string LinkedList::GetSearchResult(Node *node)
{
	std::string patient_data = "";
	
	if (node != nullptr) {
		patient_data = node->GetDataString();
		return patient_data;
	}
	return "Patient Record was not found!";
}

Node* LinkedList::DataExists(int patient_id)
{
	Node *searchNode = GetListNode();
	while (searchNode != nullptr) {
		if (patient_id == searchNode->GetPatientId()) {
			return searchNode;
		}
		searchNode->SetPointer(searchNode->GetPointer());
		searchNode = searchNode->GetPointer();
	}
	
	return nullptr;
}

std::string LinkedList::GetEditSearchResults(int patient_id, std::string patient_name, std::string address, 
	short int age, std::string gender, std::string d_d, short int rn, 
	std::string s_t, std::string dateofAdmitted, Node* reference)
{
	reference->SetPatientName(patient_name);
	reference->SetAddress(address);
	reference->SetAge(age);
	reference->SetGender(gender);
	reference->SetDiseaseDescription(d_d);
	reference->SetRoom_no(rn);
	reference->SetServiceType(s_t);
	reference->SetDateOfAdmitted(dateofAdmitted);
	return GetSearchResult(reference);
}

/*void LinkedList::SetArrangeNode()
{
	// Arrange list in Alphabetical Order
	Node *tempNode = GetListNode();

	while (tempNode != nullptr) {
		if ((int)tempNode->GetPatientName()[0] > (int)tempNode->GetPointer()->GetPatientName()[0]) {
			// Logic undefined 
			
		}
		// move to next Node 
		tempNode = tempNode->GetPointer();
	}
}*/

Node * LinkedList::GetListNode()
{
	return startNode;
}
