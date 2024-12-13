#include <stdio.h>
#include <string.h>
#define MAX_PATIENT 100
struct Patient
{
    int id;
    char name[100];
    int age;
    char disease[100];
    char doctor[100];
};

struct Patient hospital[MAX_PATIENT];
int patientCount = 0;

// Function to add patients
void addpatient()
{
    if (patientCount >= MAX_PATIENT)
    {
        printf("Hospital is full");
        return;
    }
    struct Patient newpatient;
    // id
    printf("Patient ID: ");
    scanf("%d", &newpatient.id);
    getchar();
    // name
    printf("Enter patient name: ");
    gets(newpatient.name);
    // age
    printf("Enter patient age: ");
    scanf("%d", &newpatient.age);
    getchar();
    // disease
    printf("Enter patient disease: ");
    gets(newpatient.disease);
    // doctor
    printf("Enter assigned doctor name: ");
    gets(newpatient.doctor);
    // patient number in hospital
    hospital[patientCount++] = newpatient;
    printf("Patient added successfully!\n");
}
// Function to display patients details
void display()
{
    if (patientCount == 0)
    {
        printf("No patient in Hospital");
        return;
    }
    printf("List of patients\n");
    printf("ID\tName\t\tAge\tDisease\t\tDoctor\n");
    for (int i = 0; i < patientCount; i++)
    {
        printf("%d\t%s\t%d\t%s\t%s\n", hospital[i].id, hospital[i].name, hospital[i].age, hospital[i].disease, hospital[i].doctor);
    }
}
void search()
{
    char search[100];
    printf("Enter patient name: ");
    gets(search);
    int found = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(hospital[i].name, search) == 0)
        {
            printf("Patient found\n");
            printf("ID\tName\tAge\tDisease\tDoctor");
            printf("%d\t%s\t%d\t%s\t%s", hospital[i].id, hospital[i].name, hospital[i].age, hospital[i].disease, hospital[i].doctor);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Patient not found!!");
    }
}
void delete()
{
    int id;
    printf("Enter the patient ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (hospital[i].id == id)
        {
            for (int j = i; j < patientCount; j++)
            {
                hospital[j] = hospital[j + 1];
                //hospital[j].id++;
            }
            patientCount--;
            printf("Patients data deleted");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Patient not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addpatient();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}