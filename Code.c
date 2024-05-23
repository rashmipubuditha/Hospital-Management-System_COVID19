/*
* Name : Pubuditha M.R.
* E No : E/18/268
* Project title: Covid-19 Patient Management System
* Date: 20/01/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to store a patient record
struct covid_ManagementSystem
{
    char fullName[50];
    char NIC[20];
    char gender[10];
    int phone,age;
    char admissionDate[15];

} patient_t[100];

int i,j,update=0,patient_total;

void add_newPatient();
void view_patientRecords();
void search_patientInfo();
void edit_patientRecords();
void del_patientRecods();

int main()
{
    int choice;
    //startup pattern
    printf("\n");
    printf(" ****************************************\n");
    printf(" *  COVID-19 PATIENT MANAGEMENT SYSTEM  *\n");
    printf(" *  ----------------------------------  *\n");
    printf(" ****************************************\n");

    while(choice!=6)
    {
        printf("\n\n");
        printf(" Select Your Option\n\n 1. Add New Patient\n 2. View All Information\n 3. Search Patients\n 4. Edit Information\n 5. Delete Patient Records\n 6. Exit\n\n Option = ");
        scanf("%d",&choice);//Select choice

        if(choice==1)//Add new patient
        {
            system("cls");
            add_newPatient();
        }
        else if(choice==2)//View patient records
        {
            system("cls");
            view_patientRecords();
        }
        else if(choice==3)//Search patient Information
        {
            system("cls");
            search_patientInfo();
        }
        else if(choice==4)//Edit patient records
        {
            system("cls");
            edit_patientRecords();
        }
        else if(choice==5)//Delete patient records
        {
            system("cls");
            del_patientRecods();
        }
        else if(choice==6)//Exit from the system
        {
            system("cls");
            exit(1);
        }
        else
        {
            system("cls");// Invalid input
            printf("\n\nInvalid input , try again !!!");
        }
        printf("\n\n");
    }
}

//Function for add new patient
void add_newPatient()
{
    printf("\n");
    printf("Number Of Existing Covid Patients - %d\n\n",patient_total);
    printf("Enter the details of the patient\n");
    printf("--------------------------------\n\n");
    printf("Patient Number = %d\n",patient_total+1);

    update = patient_total+1;  //Update the total patients

    for(i = patient_total; i<update; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Full Name = ");
        gets(patient_t[i].fullName);
        fflush(stdin);
        printf("NIC number = ");
        scanf("%s",patient_t[i].NIC);
        fflush(stdin);
        printf("Age = ");
        scanf("%d",&patient_t[i].age);
        fflush(stdin);
        printf("Gender = ");
        scanf("%s",patient_t[i].gender);
        fflush(stdin);
        printf("Telephone Number = ");
        scanf("%d",&patient_t[i].phone);
        fflush(stdin);
        printf("Admission Date [DD/MM/YYYY] = ");
        scanf("%s",patient_t[i].admissionDate);
        fflush(stdin);
        printf("\n");
        patient_total++;
    }
}
//Function for view patients record
void view_patientRecords()
{
    printf("\n");
    printf("Records Of All the Covid Patients\n");
    printf("---------------------------------\n\n");

    for(i=0; i<patient_total; i++)
    {
        printf("Patient Number   = %d\n",i+1);
        printf("Full Name        = ");
        puts(patient_t[i].fullName);
        printf("NIC number       = %s\n",patient_t[i].NIC);
        printf("Age              = %d\n",patient_t[i].age);
        printf("Gender           = %s\n",patient_t[i].gender);
        printf("Telephone number = 0%d\n",patient_t[i].phone);
        printf("Admission Date   = %s\n",patient_t[i].admissionDate);
        printf("\n\n");
    }
}
//Function for edit patients records
void edit_patientRecords()
{
    int option,num;
    printf("\n");
    fflush(stdin);
    printf("Edit patient records\n");
    printf("--------------------\n\n");
    printf("Enter the No of the patient - ");
    scanf("%d",&num);

    if (num<=patient_total)
    {
        //Display patient record
        printf("\n");
        printf("Patient Number   = %d\n",num);
        printf("Full Name        = ");
        puts(patient_t[num-1].fullName);
        printf("NIC number       = %s\n",patient_t[num-1].NIC);
        printf("Age              = %d\n",patient_t[num-1].age);
        printf("Gender           = %s\n",patient_t[num-1].gender);
        printf("Telephone number = 0%d\n",patient_t[num-1].phone);
        printf("Admission Date   = %s\n",patient_t[num-1].admissionDate);
        printf("\n\n");

        printf(" 1.Full Name\n 2.NIC Number\n 3.Age\n 4.Gender\n 5.Telephone No:\n\n");
        printf("Enter the option needs to be changed = ");
        scanf("%d",&option);

        if(option<=5)
        {
            if(option==1)
            {
                fflush(stdin);
                printf("Enter The New Name = ");  //Edit name
                gets(patient_t[num-1].fullName);
            }
            else if(option==2)
            {
                fflush(stdin);
                printf("Enter The New NIC Number = ");  //Edit NIC
                scanf("%s",patient_t[num-1].NIC);
            }
            else if(option==3)
            {
                fflush(stdin);
                printf("Enter The New Age = ");   //Edit age
                scanf("%d",&patient_t[num-1].age);
            }

            else if(option==4)
            {
                fflush(stdin);
                printf("Enter Gender = ");   //Edit gender
                scanf("%s",patient_t[num-1].gender);
            }

            else if(option==5)
            {
                fflush(stdin);
                printf("Enter The New Telephone No = ");  //Edit telephone number
                scanf("%d",&patient_t[num-1].phone);
            }

            printf("Done!");
        }
        else
        {
            printf("\n\nInvalid Option\nTry Again!!!\n\n"); //Invalid option
        }
    }
    else
    {
         printf("\n\nInvalid Number \nTry Again !!!\n\n");  //Invalid patient number
    }
}
//Function for search patient information
void search_patientInfo()
{
    int search,k;
    char search_NIC[100];
    char search_Name[100];
    printf("   Search Patients\n");
    printf("  -----------------\n\n");
    printf("1.NIC Number\n2.Full Name\n\nOption = ");
    scanf("%d",&search);

    if(search==1)  //Search by NIC
    {
        k=1;
        fflush(stdin);
        printf("Enter NIC Number = ");
        gets(search_NIC);
        fflush(stdin);
        for(i=0; i<patient_total; i++)
        {
            if(strcmp(search_NIC,patient_t[i].NIC)==0)
            {
                printf("\n");
                printf("Patient Number=%d\n",i+1);
                printf("Full Name = ");
                puts(patient_t[i].fullName);
                printf("NIC Number = ");
                puts(patient_t[i].NIC);
                printf("Gender = %s\nAge = %d\nTelephone number = 0%d\nAdmission Date = %s",patient_t[i].gender,patient_t[i].age,patient_t[i].phone,patient_t[i].admissionDate);
                printf("\n\n");
                k=0;
            }

        }
        if(k==1)
            printf("\nNot Available!\n\n");  //Invalid NIC

    }
    else if(search==2) //Search by full name
    {
        int k=1;
        fflush(stdin);
        printf("Enter Your Full Name = ");
        gets(search_Name);
        fflush(stdin);
        for(j=0; j<patient_total; j++)
        {
            if(strcmp(search_Name,patient_t[j].fullName)==0)
            {
                printf("\n");
                printf("Patient Number = %d\n",j+1);
                printf("Full Name = ");
                puts(patient_t[j].fullName);
                printf("NIC Number = ");
                puts(patient_t[j].NIC);
                printf("Gender = %s\nTelephone number = 0%d\nAge = %d\nAdmission Date = %s",patient_t[j].gender,patient_t[j].phone,patient_t[j].age,patient_t[j].admissionDate);
                printf("\n\n");
                k=0;

            }
        }
        if(k==1)
            printf("\nNot Available!\n");  //Invalid name

    }
    else
    {
        printf("\n\nInvalid input!\n\n");  //Invalid search option
    }
}
//Function for delete patient records
void del_patientRecods()
{
    int delNum,delOption;
    printf(" Delete Records\n");
    printf("----------------\n");
    printf("Number of the patient need to be deleted = "); //Number of the patient
    scanf("%d",&delNum);

    if(delNum <= patient_total)
    {
        //Display patient record
        printf("\n");
        printf("Patient Number   = %d\n",delNum);
        printf("Full Name        = ");
        puts(patient_t[delNum-1].fullName);
        printf("NIC number       = %s\n",patient_t[delNum-1].NIC);
        printf("Age              = %d\n",patient_t[delNum-1].age);
        printf("Gender           = %s\n",patient_t[delNum-1].gender);
        printf("Telephone number = 0%d\n",patient_t[delNum-1].phone);
        printf("Admission Date   = %s\n",patient_t[delNum-1].admissionDate);
        printf("\n\n");


        printf("1.Remove The Whole Record\n2.Remove Name\n3.Remove NIC Number\n4.Remove Age\n5.Remove Gender\n6.Remove Telephone Number\n\nOption = ");
        scanf("%d",&delOption);

        if(delOption==1) //Delete whole record
        {
            while(delNum <= patient_total)
            {
                strcpy(patient_t[delNum-1].fullName,patient_t[delNum].fullName);
                strcpy(patient_t[delNum-1].NIC,patient_t[delNum].NIC);
                patient_t[delNum-1].age=patient_t[delNum].age;
                strcpy(patient_t[delNum-1].gender,patient_t[delNum].gender);
                patient_t[delNum-1].phone=patient_t[delNum].phone;
                strcpy(patient_t[delNum-1].admissionDate,patient_t[delNum].admissionDate);
                delNum++;
            }
            patient_total--;
        }
        else if(delOption==2)  //Remove name
        {
            strcpy(patient_t[delNum-1].fullName,"Removed");

        }
        else if(delOption==3)  //Remove NIC
        {
            strcpy(patient_t[delNum-1].NIC,"Removed");
        }
        else if(delOption==4)  //Remove age
        {
            patient_t[delNum-1].age=0;
        }
        else if(delOption==5)  //Remove gender
        {
            strcpy(patient_t[delNum-1].gender,"Removed");
        }
        else if(delOption==6)  //Remove telephone number
        {
            patient_t[delNum-1].phone=0;
        }
        else
        {
            printf("\nInvalid Option!\n\n"); //Invalid option
        }
        printf("\nRemoved!\n");
    }
    else
    {
        printf("\n\nInvalid Number!\n"); //Invalid patient number
    }

}
