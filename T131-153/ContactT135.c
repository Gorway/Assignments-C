#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* phone_number;
    char* email;
} Contact;

void display_menu();
void add_contact(Contact** contacts, int* contactCount, char* name, char* phone_number, char* email);
void display_All_contacts(Contact* contacts, int contactCount);
void search_contact(Contact* contacts, int contactCount, char* searchName);
void delete_contact(Contact** contacts, int* contactCount, char* searchName);
void free_contacts(Contact* contacts, int contactCount);

int main() {

    int contactCount = 0;
    Contact* contacts = NULL;
    
    printf("Enter the number of contacts: ");
    scanf("%d", &contactCount);

    int choice;
    char name[50];
    char phone_number[15];
    char email[50];
    
    do{
        display_menu();
        scanf("%d",&choice);

        switch(choice) {
            case 1:
            printf("Enter Name: ");
            scanf("%s",name);
            printf("Enter Phone number: ");
            scanf("%s", phone_number);
            printf("Enter Email: ");
            scanf("%s", email);
            add_contact(&contacts, &contactCount, name, phone_number, email);
            break;
            case 2:
            display_All_contacts(contacts, contactCount);
            break;
            case 3:
            printf("Enter Name for Search: ");
            scanf("%s",name);
            search_contact(contacts, contactCount, name);
            break;
            case 4:
            printf("Enter Name for Delete: ");
            delete_contact(&contacts, &contactCount, name);
            break;
            case 5:
            printf("Program End\n");
            break;
            default:
            printf("Wrong Action, Please enter Accurrate action.\n");
        }
    } while(choice != 5);

    free_contacts(contacts, contactCount);

    return 0;
}

void display_menu() {

    printf("\nSelect an action:\n");
    printf("1. Add contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search contact by name\n");
    printf("4. Delete contact by name\n");
    printf("5. Exit\n");
    printf("Select Action Number:");
}

void add_contact(Contact** contacts, int* contactCount, char* name, char* phone_number, char* email) {
   
   (*contactCount)++;

    Contact* temp = realloc(*contacts, (*contactCount) * sizeof(Contact));
    if(temp  == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    *contacts = temp;

    Contact newContact;
    newContact.name = strdup(name);
    newContact.phone_number = strdup(phone_number);
    newContact.email = strdup(email);

    if(newContact.name == NULL || newContact.phone_number == NULL ||
        newContact.email == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    (*contacts)[*contactCount - 1] = newContact;

    printf("Contact Added Successfully\n");
    printf("Name: %s\n", newContact.name);
    printf("Phone number: %s\n", newContact.phone_number);
    printf("Email: %s\n", newContact.email);
}

void display_All_contacts(Contact* contacts, int contactCount) {
        
        if(contactCount == 0) {
            printf("No contact available\n");
            return;
        }

        printf("\nAll Contacts\n");
        for(int i = 0; i < contactCount; i++) {
            printf("Contact #%d: \n", i + 1);
            printf("Name: %s\n",contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone_number);
            printf("Email: %s\n", contacts[i].email);
        }
}

void search_contact(Contact* contacts, int contactCount, char* searchName) {
    int found = 0;

    for(int i = 0; i < contactCount; i++) {
        if(strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Foudn\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone_number);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
   if(!found) {
       printf("Contact with name %s, not founded.\n\n", searchName);
   }
}
void delete_contact(Contact** contacts, int* contactCount, char* delName) {
    int foundIndex = -1;

    for(int i = 0; i < *contactCount; i++) {
        if(strcmp(contacts[i]->name, delName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex != - 1) {
        free((*contacts)[foundIndex].name);
        free((*contacts)[foundIndex].phone_number);
        free((*contacts)[foundIndex].email);

        for(int i = foundIndex; i < *contactCount - 1; i++) {
            (*contacts)[i] = (*contacts)[i + 1];
        }
        
        (*contactCount)--;

        *contacts = realloc(*contacts, sizeof(Contact) * (*contactCount));

        printf("Contact %s, Succsessfully deleted:\n", delName);
    } else {
        printf("Contact %s, Not founded:\n",delName);
    }
}

void free_contacts(Contact* contacts, int contactCount) {
    for(int i = 0; i < contactCount; i++) {
        free(contacts[i].name);
        free(contacts[i].phone_number);
        free(contacts[i].email);
    }
    free(contacts);
}
