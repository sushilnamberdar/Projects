#include <stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
struct address
{
    int pin_no;
    char state[15];
    char city[15];
    int house_no;
};

struct employees
{
    int emplyess_id;
    char employees_name[50];
    char employe_department[15];
    int employees_salary;

    int contect_no;
    struct date d1;
    struct address a1;
} e1;
void add_employees_record();
void Display_record();
void Serach_employee_record();
void update_employee_record();
void delete_employee_record();

FILE *f;
int ch;
int main()
{
    int choice;

    do
    {
        printf("1. Add a Employee\n");
        printf("2. Display\n");
        printf("3. Serach Employee\n");
        printf("4. Update Employee Record \n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter Your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_employees_record();
            break;
        case 2:
            Display_record();
            break;
        case 3:
            Serach_employee_record();
            break;
        case 4:
            update_employee_record();
            break;
        case 5:
            delete_employee_record();
            break;
        case 6:
            printf("Exiting the Program. \n");
            break;
        default:
            printf("Invalied ! Entery \n");
            break;
        }

    } while (choice != 6);
}
void add_employees_record()
{
    char c;
    f = fopen("employees.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file for append!\n");
        return;
    }
    do
    {

        printf("Enter employe Id \n");
        scanf("%d", &e1.emplyess_id);

        printf("Enter employe Name  \n");
        scanf("%s", &e1.employees_name);

        printf("Employees Department \n");
        scanf("%s", &e1.employe_department);

        printf("Enter employe Salary \n");
        scanf("%d", &e1.employees_salary);

        printf("Enter employe Contact No. \n");
        scanf("%d", &e1.contect_no);

        printf("Enter Employee Joining Day \n");
        scanf("%d", &e1.d1.day);

        printf("Enter  Joining Month \n");
        scanf("%d", &e1.d1.month);

        printf("Enter Joining  Year \n");
        scanf("%d", &e1.d1.year);

        printf("Enter  Post PIN no. \n");
        scanf("%d", &e1.a1.pin_no);

        printf("Enter  state \n");
        scanf("%s", &e1.a1.state);

        printf("Enter City \n");
        scanf("%s", &e1.a1.city);

        printf("Enter House no. \n");
        scanf("%d", &e1.a1.house_no);

        printf("Do you want to continue enter y/n ");
        scanf("%s", &c);

    } while (c == 'y' || c == 'Y');
    fwrite(&e1, sizeof(e1), 1, f);
    fclose(f);
    printf("\n\n");
    printf("Record Added successful\n\n\n");
}
void Display_record()
{
    f = fopen("employees.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file for append!\n");
        return;
    }

    printf("Employee_Id\t      Name\t      Department\t    Salary\t     Contact No.\t       Joining day month year\t      PIN no.\t       State\t    City\t     House no\t\n");
    while (fread(&e1, sizeof(e1), 1, f) == 1)
    {
      printf("     %d\t              %s\t           %s\t            %d\t      %d\t             %d - %d - %d\t      %d\t         %s\t    %s\t      %d\t\n", e1.emplyess_id, e1.employees_name, e1.employe_department, e1.employees_salary, e1.contect_no, e1.d1.day, e1.d1.month, e1.d1.year, e1.a1.pin_no, e1.a1.state, e1.a1.city, e1.a1.house_no);

    }

    fclose(f);
}
void Serach_employee_record()
{
    printf("Enter Employee Id \n");
    int employeeid;
    scanf("%d", &employeeid);
    f = fopen("employees.txt", "r");

    if (f == NULL)
    {
        printf("Error opening file for reading !");
    }
    while (fread(&e1, sizeof(e1), 1, f) == 1)
    {
        if (e1.emplyess_id == employeeid)
        {
            printf("Employee_Id\t      Name\t    Department\t      Salary\t      Contact No.\t       Joining-day-month-year\t      PIN no.\t       State\t    City\t     House no\t\n");
            printf("     %d\t              %s\t       %s\t      %d\t      %d\t            %d - %d - %d\t      %d\t         %s\t    %s\t      %d\t\n", e1.emplyess_id, e1.employees_name,e1.employe_department, e1.employees_salary, e1.contect_no, e1.d1.day, e1.d1.month, e1.d1.year, e1.a1.pin_no, e1.a1.state, e1.a1.city, e1.a1.house_no);
        }
    }
    fclose(f);
}
void update_employee_record()
{
    printf("********Update**********\n");
    int update;
    printf("Enter the Employee_id for update record \n");
    scanf("%d", &update);
    f = fopen("employees.txt", "r+");
    if (f == NULL)
    {
        printf("Error opening file for reading ! \n");
        return;
    }

    while (fread(&e1, sizeof(e1), 1, f) == 1)
    {
        if (e1.emplyess_id == update)
        {
            printf("Employee_Id\t      Name\t    Department\t    Salary\t      Contact No.\t       Joining-day-month-year\t      PIN no.\t       State\t    City\t     House no\t\n");
            printf("     %d\t              %s\t      %s\t     %d\t      %d\t                  %d - %d - %d\t               %d\t         %s\t    %s\t      %d\t\n", e1.emplyess_id, e1.employees_name,e1.employe_department, e1.employees_salary, e1.contect_no, e1.d1.day, e1.d1.month, e1.d1.year, e1.a1.pin_no, e1.a1.state, e1.a1.city, e1.a1.house_no);
        }
    }
    printf("\n\n\n");
    char fullsingle;
    printf("Single item Update = 'Y' / Full record Update = 'N'\n");
    printf("Enter Y/N\n");
    scanf(" %c", &fullsingle);
    printf("\n\n\n");
    if (fullsingle == 'y' || fullsingle == 'Y')
    {

        printf("Enter Your choice \n");
        printf("1.Employee_id\n");
        printf("2.Name \n");
        printf("3.Department\n");
        printf("4.Salary\n");
        printf("5.Contact No.\n");
        printf("6.Joining Date\n");
        printf("7.PIN no.\n");
        printf("8.State\n");
        printf("9.City\n");
        printf("10.House no.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Employee_id\n");
            scanf("%d", &e1.emplyess_id);
            break;
        case 2:
            printf("Enter Name\n");
            scanf("%s", &e1.employees_name);
            break;
        case 3:
            printf("Enter Department\n");
            scanf("%s", &e1.employe_department);
            break;
        case 4:
            printf("Enter Salary\n");
            scanf("%d", &e1.employees_salary);
            break;
        case 5:
            printf("Enter Contact No.\n");
            scanf("%d", &e1.contect_no);
            break;
        case 6:
            printf("Enter Joining Day \n");
            scanf("%d", &e1.d1.day);
            printf("Enter Month \n");
            scanf("%d", &e1.d1.month);
            printf("Enter Year \n");
            scanf("%d", &e1.d1.year);
            break;
        case 7:
            printf("Enter PIN no.\n");
            scanf("%d", &e1.a1.pin_no);
            break;
        case 8:
            printf("Enter State\n");
            scanf("%s", &e1.a1.state);
            break;
        case 9:
            printf("Enter City \n");
            scanf("%s", &e1.a1.city);
            break;
        case 10:
            printf("Enter House no.\n");
            scanf("%d", &e1.a1.house_no);
            break;
        default:
            printf("!Invalied input \n");
            break;
        }
        fseek(f, -sizeof(e1), SEEK_CUR);
        fwrite(&e1, sizeof(e1), 1, f);
    }
    else if (fullsingle == 'n' || fullsingle == 'N')

    {
        printf("Enter Employee_id\n");
        scanf("%d", &e1.emplyess_id);
        printf("Enter Name\n");
        scanf("%s", &e1.employees_name);
        printf("Enter Salary\n");
        printf("Enter Department\n");
        scanf("%s", &e1.employe_department);
        scanf("%d", &e1.employees_salary);
        printf("Enter Contact No.\n");
        scanf("%d", &e1.contect_no);
        printf("Enter Joining Day \n");
        scanf("%d", &e1.d1.day);
        printf("Enter Month \n");
        scanf("%d", &e1.d1.month);
        printf("Enter Year \n");
        scanf("%d", &e1.d1.year);
        printf("Enter PIN no.\n");
        scanf("%d", &e1.a1.pin_no);
        printf("Enter State\n");
        scanf("%s", &e1.a1.state);
        printf("Enter City \n");
        scanf("%s", &e1.a1.city);
        printf("Enter House no.\n");
        scanf("%d", &e1.a1.house_no);
        fseek(f, sizeof(e1), SEEK_CUR);
        fwrite(&e1, sizeof(e1), 1, f);
        printf("\n\n");
        
    }
    else
    {
        printf("!Invalid Input ");
    }
    fclose(f);
    printf("Record Updated successful \n\n\n");
}
void delete_employee_record()
{
    FILE *temp;
    int delete_id;
    printf("Enter Employee_id for update\n");
    scanf("%d",&delete_id);
    f= fopen("employees.txt","r");
    temp = fopen("temp.txt","w");
    if(f == NULL || temp == NULL){
        printf("Error opening file for Deletion!\n");
        return ;
    }
    int found = 0;
    while (fread(&e1,sizeof(e1),1,f)==1)
    {
        if(e1.emplyess_id!=delete_id){ // for comping all employess data into temp.txt file
            fwrite(&e1,sizeof(e1),1,temp);
        }else{
            found = 1;
        }
    }
    fclose(f);
    fclose(temp);
    remove("employees.txt");
    rename("temp.txt","employees.txt");
    if(found){
        printf("Employees Data deleted Successful!\n\n");
    }else{
        printf("Employees With Id %d not found \n",delete_id);
    }

    


}