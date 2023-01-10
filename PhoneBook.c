#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50

int contact_number=0;

struct contact {
    char f_name[max];
    char l_name[max];
    int number;
    char email[max];
    char address[max];
    struct contact* next;

}*head = NULL;

void display() {
    struct contact* current;
    int i=1;
    printf("\n>>>Contracts to display<<<\n\n");
    if (head == NULL) {
        printf("No Contract has been added\n");
        return;
    }
    else {
        current = head;
        while (current != NULL) {
            printf("\nContract no. %d>>>\n\n",i);
            printf("Name : %s %s\n", current->f_name, current->l_name);
            printf("Phone Number : %d\n", current->number);
            printf("Email : %s\n", current->email);
            printf("Address : %s\n", current->address);
            current = current->next;
        i++;
        }
        printf("\n\n");
    }
}

void add()
{
    struct contact *new_contact, *current;
    int i,n;

    printf("Enter quantity of contact you want to add : ");
    scanf("%d", &n);
    if(head==NULL){
    for(i=1;i<=n;i++){
            contact_number++;
        new_contact = (struct contact*)malloc(sizeof(struct contact));
        printf("\n\nEnter info of contact no. %d\n\n", i);
        printf("Enter first name : ");
        scanf(" %[^\n]", new_contact->f_name);
        printf("Enter last name : ");
        scanf(" %[^\n]", new_contact->l_name);
        printf("Enter contract no: ");
        scanf("%d", &new_contact->number);
        printf("Enter email address : ");
        scanf(" %[^\n]", new_contact->email);
        printf("Enter address : ");
        scanf(" %[^\n]", new_contact->address);

        new_contact->next = NULL;
        if(head == NULL){
            head = new_contact;
            current = new_contact;
        }
        else{
            current->next = new_contact;
            current = new_contact;
        }
    }
    }
    else{
    for(i=1;i<=n;i++){
        contact_number++;
        new_contact = (struct contact*)malloc(sizeof(struct contact));
        printf("\n\nEnter info of contact no. %d\n\n", i);
        printf("Enter first name : ");
        scanf(" %[^\n]", new_contact->f_name);
        printf("Enter last name : ");
        scanf(" %[^\n]", new_contact->l_name);
        printf("Enter contract no: ");
        scanf("%d", &new_contact->number);
        printf("Enter email address : ");
        scanf(" %[^\n]", new_contact->email);
        printf("Enter address : ");
        scanf(" %[^\n]", new_contact->address);

        new_contact->next = NULL;
        current=head;

            while(current->next!=NULL){
                current=current->next;
            }

        current->next=new_contact;
        //current=new_contact;
    }
    }
    printf("%d contact(s) is created successfully\n", n);
}

int search_FN(){
    struct contact *current;
    int x=0,pos=0;
    char name[max];
    printf("Enter First Name: ");
    getchar();
    gets(name);

    current=head;
    while(current !=NULL){
        pos++;
        if((strcmp(current->f_name,name)==0)){

            printf("Name : %s %s\n", current->f_name, current->l_name);
            printf("Phone Number : %d\n", current->number);
            printf("Email : %s\n", current->email);
            printf("Address : %s\n", current->address);
            x++;
            return pos;
        }

        current=current->next;

    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }

}

int search_LN(){
    struct contact *current;
    int x=0,pos=0;
    char name[max];
    printf("Enter Last Name: ");
    getchar();
    gets(name);

    current=head;
    while(current!=NULL){
            pos++;
        if((strcmp(current->l_name,name)==0)){

            printf("Name : %s %s\n", current->f_name, current->l_name);
            printf("Phone Number : %d\n", current->number);
            printf("Email : %s\n", current->email);
            printf("Address : %s\n", current->address);
            x++;
            return pos;

        }

        current=current->next;
    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }


}

int search(int n){
    struct contact *current;
    int x=0,pos=0;
    current=head;
    while(current!=NULL){
            pos++;
        if(current->number==n){

            printf("Name : %s %s\n", current->f_name, current->l_name);
            printf("Phone Number : %d\n", current->number);
            printf("Email : %s\n", current->email);
            printf("Address : %s\n", current->address);
            x++;
            return pos;
        }

        current=current->next;
    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }
}

void ll_delete(){
    struct contact *current,*temp,*temp2;
    int key,pos,i;
    printf("\nEnter 1 to Delete by First Name\n\nEnter 2 to Delete by Last Name\n\nEnter 3 to Delete by number\n\nEnter 4 to delete by Position\n\nYour choice: ");
    scanf("%d",&key);
    if(key==4){
            printf("\nEnter Position: ");
            scanf("%d",&pos);
    if(contact_number<pos||pos<0){
            printf("\n\nWrong Input\n\n");
                return;
            }
    else{
        current=head;
        for(i=0;i<pos-1;i++){
            current=current->next;
        }
        if(current==head){
                head=current->next;
                contact_number--;
            }
        else if(current->next==NULL){
                    current=head;
                for(i=0;i<pos-2;i++){
                    current=current->next;
                }
                current->next=NULL;
                contact_number--;
            }
        else{
        temp=current->next;
        current=head;
        for(i=0;i<pos-2;i++){
            current=current->next;
        }
        temp2=current;
        temp2->next=temp;
        contact_number--;

            }

        printf("\n\n%d no contact deleted successfully\n\n",pos);

            }
        }
        else if(key==1||key==2||key==3){

        if(pos==-1){
            printf("\n\nNot Found\n\n");
            return;
        }

        current=head;
        for(i=0;i<pos-1;i++){
            current=current->next;
        }
        if(current==head){
                head=current->next;
                contact_number--;
            }
        else if(current->next==NULL){
                    current=head;
                for(i=0;i<pos-2;i++){
                    current=current->next;
                }
                current->next=NULL;
                contact_number--;
            }
        else{
        temp=current->next;
        current=head;
        for(i=0;i<pos-2;i++){
            current=current->next;
        }
        temp2=current;
        temp2->next=temp;
        contact_number--;

            }

        printf("\n\n%d no contact deleted successfully\n\n",pos);

    }
    else{
        printf("\n\nWrong Input\n\n");
    }

}

int d_search(int key){
    if(key==1){
    struct contact *current;
    int x=0,pos=0;
    char name[max];
    printf("Enter First Name: ");
    getchar();
    gets(name);

    current=head;
    while(current !=NULL){
        pos++;
        if((strcmp(current->f_name,name)==0)){
            x++;
            return pos;
        }

        current=current->next;

    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }
    }
    else if(key==2){
    struct contact *current;
    int x=0,pos=0;
    char name[max];
    printf("Enter Last Name: ");
    getchar();
    gets(name);

    current=head;
    while(current !=NULL){
        pos++;
        if((strcmp(current->l_name,name)==0)){
            x++;
            return pos;
        }

        current=current->next;

    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }
    }
    else if(key==3){
                    struct contact *current;
    int x=0,pos=0;
    int number;
    printf("Enter Number: ");
    scanf("%d",&number);

    current=head;
    while(current !=NULL){
        pos++;
        if(current->number==number){
            x++;
            return pos;
        }

        current=current->next;

    }
    if(x==0){
        printf("\n\n-->No Result<--\n\n");
    return -1;
    }
    }

}



int main() {
    printf("\n*** >->-> P H O N E B O O K <-<-< ***\n\n\n");
    int x,y;
    do{
        printf("Press 1 to Add\nPress 2 to Delete\nPress 3 to Search\nPress 4 to view\nPress 5 to Speed Dial\nPress 6 to Exit\n\nYour Choice: ");
        scanf("%d",&x);
        if(x==1){
            add();
            main();
        }
        if(x==2){
        ll_delete();
        main();
        }
        if(x==3){
        int a,b;

        do{
        printf("\nPress 1 to search by First name\n\nPress 2 to search by Last name\n\nPress 3 to search by Phone number\n\nPress 4 to cancel\n\n");
        scanf("%d",&a);
        if(a==1){

            search_FN();
            main();

        }
        else if(a==2){

            search_LN();
            main();
        }
        else if(a==3){
            int n;
            printf("Enter Phone Number: ");
            scanf("%d",&n);
            search(n);
            main();
        }
        else{
            b=1;
        }
    }while(b!=1);
}
        else if(x==4){
            display();
            main();
        }
        else if(x=6){
        printf("\n\nSure to Exit?\nEnter 1 to cancel\nPress any key to exit\n\nYour Choice: ");
        scanf("%d",&y);
    }
    }while(y==1);

return 0;
}
