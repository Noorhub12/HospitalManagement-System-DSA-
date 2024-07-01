# HospitalManagement-System-DSA-

This Hospital Management System is a console-based application written in C. It manages patient records for a hospital, including both normal and emergency patients. The system allows the addition, updating, sorting, and displaying of patient details, as well as calculating the total fees collected and counting the total number of patients.

## Features

- **Add Normal Patient**: Insert details of a normal patient including name, gender, blood group, age, appointment date, phone number, and doctor category.
- **Add Emergency Patient**: Insert details of an emergency patient including name, gender, blood group, age, admission date, phone number, and specialist category.
- **Print Normal Patient Details**: Display details of all normal patients.
- **Print Emergency Patient Details**: Display details of all emergency patients.
- **Update Patient Details**: Update the gender, blood group, and age of a patient by searching for their name.
- **Sort Patients by Key**: Sort patients by their unique key (ID) in ascending order.
- **Calculate Total Fees**: Calculate the total fees collected based on normal, emergency, and repeated patient fees.
- **Count Total Patients**: Count the total number of patients in the system.
- **Save Patient Details to File**: Save all patient details to a text file.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Installation

1. Clone the repository:

    git clone https://github.com/Noorhub12/hospital-management-system.git

2. Navigate to the project directory:

    cd hospital-management-system

### Menu Options

- **1. Add Normal Patient**: Prompts for patient details and adds a new normal patient to the system.
- **2. Add Emergency Patient**: Prompts for patient details and adds a new emergency patient to the system.
- **3. Print Normal Patient Details**: Displays all normal patient details.
- **4. Print Emergency Patient Details**: Displays all emergency patient details.
- **5. Update Patient Details**: Prompts for a patient name and updates their details if found.
- **6. Sort Patients by Key**: Sorts all patients by their unique key (ID).
- **7. Calculate Total Fees**: Displays the total fees collected.
- **8. Count Total Patients**: Displays the total number of patients.
- **9. Save Patient Details to File**: Saves all patient details to `patient_details.txt`.
- **10. Exit Program**: Saves all patient details to `patient_details.txt` and exits the program.

### Data Structure

- The system uses a linked list data structure for managing patient records.
- Each patient record (node) contains:
  - `key`: Unique identifier for the patient
  - `age`: Age of the patient
  - `gender`: Gender of the patient
  - `bloodgroup`: Blood group of the patient
  - `name`: Name of the patient
  - `date`: Appointment/Admission date
  - `phonenumber`: Phone number of the patient
  - `category`: Doctor/Specialist category
  - `link`: Pointer to the next node in the list

### Fee Structure

- **Normal Patient Fee**: $500
- **Emergency Patient Fee**: $2000
- **Fee for Same Patient**: $250

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgements

This project was created as part of a Data Structures and Algorithms course.
