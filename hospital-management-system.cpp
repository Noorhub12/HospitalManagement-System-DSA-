#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FEE 500
#define FEE_EMERGENCY 2000
#define FEE_SAME_PATIENT 250

struct node {
    int key;
    int age;
    char gender[10];
    char bloodgroup[4];
    char name[50];
    char date[15];
    char phonenumber[15];
    char category[25];
    struct node *link;
};

struct node *start_normal = NULL;
struct node *start_emergency = NULL;

int keyupdate_normal = 0;
int keyupdate_emergency = 0;

struct node *createnode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void insert_normal_patient() {
    struct node *temp = createnode();
    temp->key = ++keyupdate_normal;
    temp->link = NULL;

    printf("Enter patient details (name, Gender, blood group, age):\n");
    scanf("%s %s %s %d", temp->name, temp->gender, temp->bloodgroup, &temp->age);

    printf("Enter appointment date (DD/MM/YYYY):\n");
    scanf("%s", temp->date);

    printf("Enter phone number:\n");
    scanf("%s", temp->phonenumber);

    printf("Choose doctor (1- General Physician MD, 2- Orthopaedician, 3- Paediatrician, 4- Ophthalmologist):\n");
    int option;
    scanf("%d", &option);
    switch(option) {
        case 1: strcpy(temp->category, "General Physician MD"); break;
        case 2: strcpy(temp->category, "Orthopaedician"); break;
        case 3: strcpy(temp->category, "Paediatrician"); break;
        case 4: strcpy(temp->category, "Ophthalmologist"); break;
        default: strcpy(temp->category, "Unknown");
    }

    if(start_normal == NULL) {
        start_normal = temp;
    } else {
        struct node *t = start_normal;
        while(t->link != NULL) {
            t = t->link;
        }
        t->link = temp;
    }

    printf("Normal patient added successfully.\n");
}

void insert_emergency_patient() {
    struct node *temp = createnode();
    temp->key = ++keyupdate_emergency;
    temp->link = NULL;

    printf("Enter emergency patient details (name, gender, blood group, age):\n");
    scanf("%s %s %s %d", temp->name, temp->gender, temp->bloodgroup, &temp->age);

    printf("Enter admission date (DD/MM/YYYY):\n");
    scanf("%s", temp->date);

    printf("Enter phone number:\n");
    scanf("%s", temp->phonenumber);

    printf("Choose specialist (1- Neurologist, 2- Cardiologist, 3- Gynaecologist):\n");
    int option;
    scanf("%d", &option);
    switch(option) {
        case 1: strcpy(temp->category, "Neurologist"); break;
        case 2: strcpy(temp->category, "Cardiologist"); break;
        case 3: strcpy(temp->category, "Gynaecologist"); break;
        default: strcpy(temp->category, "Unknown");
    }

    if(start_emergency == NULL) {
        start_emergency = temp;
    } else {
        struct node *t = start_emergency;
        while(t->link != NULL) {
            t = t->link;
        }
        t->link = temp;
    }

    printf("Emergency patient added successfully.\n");
}

void print_normal_patient_details() {
    int i = 1;
    struct node *t = start_normal;
    while(t != NULL) {
        printf("%d. %s\n", i, t->name);
        printf("   Gender: %s\n", t->gender);
        printf("   Age: %d\n", t->age);
        printf("   Blood Group: %s\n", t->bloodgroup);
        printf("   Appointment Date: %s\n", t->date);
        printf("   Phone Number: %s\n", t->phonenumber);
        printf("   Category: %s\n", t->category);
        printf(" ------------\n");
        t = t->link;
        i++;
    }
    printf("End of normal patient list.\n");
}

void print_emergency_patient_details() {
    int i = 1;
    struct node *t = start_emergency;
    while(t != NULL) {
        printf("%d. %s\n", i, t->name);
        printf("   Gender: %s\n", t->gender);
        printf("   Age: %d\n", t->age);
        printf("   Blood Group: %s\n", t->bloodgroup);
        printf("   Admission Date: %s\n", t->date);
        printf("   Phone Number: %s\n", t->phonenumber);
        printf("   Category: %s\n", t->category);
        printf(" ------------\n");
        t = t->link;
        i++;
    }
    printf("End of emergency patient list.\n");
}

void total_fee_collected() {
    int total = (keyupdate_emergency * FEE_EMERGENCY) + (keyupdate_normal * FEE) + (keyupdate_emergency * FEE_SAME_PATIENT);
    printf("Total fees collected: %d\n", total);
}

void total_patient_count() {
    int total = keyupdate_normal + keyupdate_emergency;
    printf("Total number of patients: %d\n", total);
}

struct node *search_patient_by_name(char *name, struct node *start) {
    struct node *t = start;
    while(t != NULL) {
        if(strcmp(t->name, name) == 0) {
            return t;
        }
        t = t->link;
    }
    return NULL;
}

void update_patient_details() {
    char name[50];
    printf("Enter patient name to update details:\n");
    scanf("%s", name);

    struct node *found = search_patient_by_name(name, start_normal);
    if(found == NULL) {
        found = search_patient_by_name(name, start_emergency);
    }

    if(found != NULL) {
        printf("Enter updated details (gender, blood group, age):\n");
        scanf("%s %s %d", found->gender, found->bloodgroup, &found->age);

        printf("Details updated successfully.\n");
    } else {
        printf("Patient '%s' not found.\n", name);
    }
}

void sort_patients_by_key() {
     // This example uses a simple bubble sort for demonstration purposes
    struct node *current, *next;
    int swapped;

    if(start_normal == NULL && start_emergency == NULL) {
        printf("No patients to sort.\n");
        return;
    }

    do {
        swapped = 0;
        current = start_normal;
        while(current->link != NULL) {
            next = current->link;
            if(current->key > next->key) {
                // Swap nodes
                int temp_key = current->key;
                current->key = next->key;
                next->key = temp_key;
                swapped = 1;
            }
            current = current->link;
        }
    } while(swapped);

    printf("Patients sorted by key.\n");
}

void save_patient_details(FILE *fp, struct node *start) {
    struct node *t = start;
    while(t != NULL) {
        fprintf(fp, "********** Patient Details **********\n");
        fprintf(fp, "Name: %s\n", t->name);
        fprintf(fp, "Phone Number: %s\n", t->phonenumber);
        fprintf(fp, "Doctor Referred: %s\n", t->category);
        fprintf(fp, "Age: %d\n", t->age);
        fprintf(fp, "Blood Group: %s\n", t->bloodgroup);
        fprintf(fp, "Appointment/Admission Date: %s\n", t->date);
        fprintf(fp, "------------------------------------\n\n");
        t = t->link;
    }
}

void save_all_patient_details() {
    FILE *fp;
    fp = fopen("patient_details.txt", "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    save_patient_details(fp, start_normal);
    save_patient_details(fp, start_emergency);

    fclose(fp);
    printf("Patient details saved to 'patient_details.txt'.\n");
}

int main() {
    int choice;

    printf("**************** SHAHEED BENAZIR BHUTTO TEACHING HOSPITAL *******************\n\n");

    do {
        printf("Main Menu:\n");
        printf("1. Add Normal Patient\n");
        printf("2. Add Emergency Patient\n");
        printf("3. Print Normal Patient Details\n");
        printf("4. Print Emergency Patient Details\n");
        printf("5. Update Patient Details\n");
        printf("6. Sort Patients by Key\n");
        printf("7. Calculate Total Fees\n");
        printf("8. Count Total Patients\n");
        printf("9. Save Patient Details to File\n");
        printf("10. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert_normal_patient(); break;
            case 2: insert_emergency_patient(); break;
            case 3: print_normal_patient_details(); break;
            case 4: print_emergency_patient_details(); break;
            case 5: update_patient_details(); break;
            case 6: sort_patients_by_key(); break;
            case 7: total_fee_collected(); break;
            case 8: total_patient_count(); break;
            case 9: save_all_patient_details(); break;
            case 10: 
                save_all_patient_details();
                printf("Exiting program.\n");
                exit(0);
                break;
            default: printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 10);

    return 0;
}

