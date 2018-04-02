#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode
{
  char name[100];
  int flag;
  int roll;
  struct tnode *left;
  struct tnode *right;
};

int countS[10] ={10,10,10,10,10,10,10,10,10,10};

struct tnode *one ;
struct tnode *two ;
struct tnode *three;
struct tnode *four ;
struct tnode *five ;
struct tnode *six ;
struct tnode *seven ;
struct tnode *eight ;
struct tnode *nine ;
struct tnode *ten ;

void create();
void extract(FILE * , struct tnode **);
void insert(struct tnode**,struct tnode * );
void delete(struct tnode**, struct tnode *);
void mid_year();
struct tnode display(struct tnode *);
int search(struct tnode *, char* );
void inorder(struct tnode *);


void update_dataS();
int fee(struct tnode*,char*);
 void overdue(struct tnode*);

int main()

{

one = NULL;
two =NULL;
three = NULL;
four =NULL;
five =NULL;
six = NULL;
seven =NULL;
eight =NULL;
nine = NULL;
ten =NULL;

    char na[100];
    int ch,num,cla,class,no,i,k;
    char n[100],noo[100];
    struct tnode  *temp;
    temp=(struct tnode *)malloc(sizeof(struct tnode));

    create();

 while(1)
 {
        printf("\n1.Update Student Data"); 
		printf("\n2.Mid-Year Admission/Outgoing Students");  
		printf("\n3.Check if student has paid fees");
		printf("\n4.Display list of all students of a class");
		printf("\n5.Search for a student record");
		printf("\n6.Display a list of students with fee overdue");
		printf("\n7.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
 
       switch(ch)
       {
        case 1: update_dataS();
                 break;
        case 2: mid_year();
                 break; 
        case 3: printf("\nFee Details\n");
               printf("\nEnter class in which student is studying\n");
               scanf("%d",&class);
               //printf("Enter student's roll number");
               //scanf("%d",&no);
         printf("Enter the student's name");
         scanf("%s",na);
         struct tnode *temp;
               switch(class)
               {
                case 1: temp=one;
                  break;
                case 2: temp=two;
                  break;
                case 3: temp=three;
                  break;
                case 4: temp=four;
                  break;
                case 5: temp=five;
                  break;
                case 6: temp=six;
                  break;
                case 7: temp=seven;
                  break;
                case 8: temp=eight;
                  break;
                case 9: temp=nine;
                  break;
                case 10: temp=ten;
                  break;
                default: printf("Invalid Class");
              }   
                if(fee(temp,na))
          printf("Fees paid");
        else
          printf("Student not found");
                 break;
                 
                 break;

        case 4: printf("\nDisplay Student Details\n");
         printf("\nEnter which class\n");
         scanf("%d",&class);
         printf("Roll Number\tStudent's Name\n");
              switch(class)
              {
                case 1: display(one);
                  break;
                case 2: display(two);
                  break;
                case 3: display(three);
                  break;
                case 4: display(four);
                  break;
                case 5: display(five);
                  break;
                case 6: display(six);
                  break;
                case 7: display(seven);
                  break;
                case 8: display(eight);
                  break;
                case 9: display(nine);
                  break;
                case 10: display(ten);
                  break;
                default: printf("Invalid Class");
              }
              break;
			  
        case 5:  
               printf("\nSearch Student Details\n");
               printf("\nEnter class in which student is studying\n");
               scanf("%d",&class);
               printf("\nEnter student's name\n");
               scanf("%s",noo);
			         struct tnode *t;
               switch(class)
               {
                case 1: t=one;
                  break;
                case 2: t=two;
                  break;
                case 3: t=three;
                  break;
                case 4: t=four;
                  break;
                case 5: t=five;
                  break;
                case 6: t=six;
                  break;
                case 7: t=seven;
                  break;
                case 8: t=eight;
                  break;
                case 9: t=nine;
                  break;
                case 10: t=ten;
                  break;
                default: printf("Invalid Class");
              }   
			  if(search(t,noo))
					printf("Student found\n");
				else
					printf("Student not found\n");
                 break;
         
         case 6:
              printf("Enter which class");
              scanf("%d",&class);
              printf("Roll Number\tStudent's Name\n");
              switch(class)
              {
                case 1: overdue(one);
                  break;
                case 2: overdue(two);
                  break;
                case 3: overdue(three);
                  break;
                case 4: overdue(four);
                  break;
                case 5: overdue(five);
                  break;
                case 6: overdue(six);
                  break;
                case 7: overdue(seven);
                  break;
                case 8: overdue(eight);
                  break;
                case 9: overdue(nine);
                  break;
                case 10: overdue(ten);
                  break;
                default: printf("Invalid Class");
              }
              break;
         case 7: exit(0);
                 break;           
         
       }
    }

    return 0;
  }


  void insert(struct tnode **t,struct tnode *addnode)
  {
    struct tnode *temp,*prev,*curr;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    strcpy(temp->name,addnode->name) ;
    temp->roll=addnode->roll;
    temp->flag=addnode->flag;
    temp->left=temp->right=NULL;

    curr=*t;
    prev=NULL;
     if(curr==NULL)//first node
      *t=temp;
    else
    {
      while(curr!=NULL) 
      {
         prev=curr;
         if(strcmp(addnode->name,curr->name)<0)
           curr=curr->left;
         else
           curr=curr->right;
      }
      if(strcmp(addnode->name,prev->name)<0)
      prev->left=temp;
      else 
      prev->right=temp;

    }
  }

  void delete(struct tnode **t , struct tnode *ntodel)
   {
    struct tnode *temp,*curr, *prev, *q, *insucc;

    temp=(struct tnode*)malloc(sizeof(struct tnode));
    temp->roll=ntodel->roll;
    strcpy(temp->name,ntodel->name);
    temp->left=temp->right=NULL;

    printf("Delete function has started  ");
    printf("%s ",temp->name);
    printf("%d\n ",temp->roll);
    //preorder(ntodel);
     curr=*t;
     prev=NULL;

    //search for x
    while((curr!=NULL)&&(strcmp(ntodel->name,curr->name)!=0))
    {
      prev=curr;
     if(strcmp(ntodel->name,curr->name)<0)
           curr=curr->left;
         else
           curr=curr->right;
     }

    if(curr==NULL || strcmp(curr->name,temp->name)!=0)
     printf("Node not found...\n");
    else
      {
        if(curr->left==NULL)//no left sub tree
           q=curr->right;//get right subtree 
        else if(curr->right==NULL)//no right subtree
           q=curr->left;//get left subtree
        else
        {
          //both subtrees present
          //find inorder successor
          insucc=curr->right;
          while(insucc->left!=NULL)
             insucc=insucc->left;
          //inorder found(insucc)
          //attach left subtree of curr to left of inorder successor
          insucc->left=curr->left;
          q=curr->right;
        }
          if (prev==NULL) //deleting the root, return new root(q)
             *t = q;
          else if(prev->left==curr)
             prev->left=q; //attach q to the left of prev
          else
             prev->right=q;//attach q to the right of prev
     }
  }



int fee(struct tnode *tree, char *naa)
  {
  	if(!tree)
        return 0 ;
    if(strcmp(tree->name,naa)==0)
    {
    	tree->flag=1;
    	return 1;}
  
  
  if (fee(tree->left, naa)) return 1;
  if (fee(tree->right, naa)) return 1;
  return 0;

}
   


   void overdue(struct tnode *t)
  {
    if(t!=NULL)
    {
      overdue(t->left);

      if((t->flag)==0)
            printf("%d\t%s\n ",t->roll,t->name);

      overdue(t->right);
    }
  }
  

  int search(struct tnode *tree, char *nam)
  {
    if(!tree)
        return 0 ;
  if(strcmp(tree->name,nam)==0){
    	return 1;
  }
  
  if (search(tree->left, nam)) return 1;
  if (search(tree->right, nam)) return 1;
  return 0;
  } 


 struct tnode display(struct tnode *tree)
  {
    
    if (tree)
    {
        display(tree->left);
        printf("   %d\t   %s\n",tree->roll,tree->name);
        display(tree->right);
    }
    
  }


void mid_year()
{
int c=0;
int  num;
char n[100];
int class , i;
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));

printf("This function is to update the database in case of any mid year addmissions or deletions\n ");
printf("Choose if there is a new addition or there is a deletion of a student\n1.New Addmission 2.A student leaving school");
scanf("%d",&c);

if(c==1)
{
printf("Enter the data for the new student\n ");
printf("Enter name \n");
scanf("%s",n);
printf("Enter the class the student is joining.(1 to 10)");
scanf("%d",&class);
printf("Has the fee for the upcoming semester been paid???\n1.Yes   2.No");
scanf("%d",&i);
strcpy(temp->name,n);
temp->roll = ++(countS[class-1]);
switch(i)
{
  case 1:temp->flag = 1;break;
  case 2:temp->flag = 0;break;
}

switch(class)
       {
         case 1 :insert(&one , temp);
                 break;
        case 2:insert(&two , temp);
                 break; 
        case 3: insert(&three , temp);
                 break;
        case 4:insert(&four , temp);
                 break;
        case 5: insert(&five , temp);
                 break;
         case 6:insert(&six , temp);
                 break;
         case 7:insert(&seven , temp);
                 break;
         case 8:insert(&eight , temp);
                 break;
         case 9:insert(&nine, temp);
                break;
         case 10:insert(&ten , temp);
                  break;
       }
   }

else if(c==2)
{

printf("Enter the data for the  student leaving school\n ");
printf("Enter name \n");
scanf("%s",n);
printf("Enter the class the student belonged to:(1 to 10)");
scanf("%d",&class);
printf("Enter the roll no ");
scanf("%d",&num);
strcpy(temp->name,n);
temp->roll = 0;
(countS[class-1])--;


switch(class)
       {
         case 1 :delete(&one , temp);
                 break;
        case 2:delete(&two , temp);
                 break; 
        case 3: delete(&three , temp);
                 break;
        case 4:delete(&four , temp);
                 break;
        case 5: delete(&five , temp);
                 break;
         case 6:delete(&six , temp);
                 break;
         case 7:delete(&seven , temp);
                 break;
         case 8:delete(&eight , temp);
                 break;
         case 9:delete(&nine, temp);
                break;
         case 10:delete(&ten , temp);
                  break;
       }
}


}



void update_dataS()
{
int c=0;
int  num;
char n[100];
int class , i;
struct tnode *temp;
temp=(struct tnode *)malloc(sizeof(struct tnode));
 
ten=nine;//Promotion of students
nine=eight;
eight=seven;
seven=six;
six=five;
five=four;
four=three;
three=two;
two=one;
one=NULL;
 
printf("Choose if there is a 1.New Addmission \n 2.Deletion of a student\n");
scanf("%d",&c);
 
if(c==1)//To add a newly addmitted student
{
 
printf("Enter the name of the student\n");
scanf("%s",n);
printf("Enter the class the student is joining.(1 to 10)");
scanf("%d",&class);
strcpy(temp->name,n);
temp->roll = 0;
 
 
switch(class)
       {
         case 1 :insert(&one , temp);
                 break;
        case 2:insert(&two , temp);
                 break;
        case 3: insert(&three , temp);
                 break;
        case 4:insert(&four , temp);
                 break;
        case 5: insert(&five , temp);
                 break;
         case 6:insert(&six , temp);
                 break;
         case 7:insert(&seven , temp);
                 break;
         case 8:insert(&eight , temp);
                 break;
         case 9:insert(&nine, temp);
                break;
         case 10:insert(&ten , temp);
                  break;
       }
   }
 
 
else if(c==2)//To delete a student
{
 
printf("Enter the name of the student to be deleted\n");
scanf("%s",n);
printf("Enter the class the student\n");
scanf("%d",&class);
printf("Enter the roll no ");
scanf("%d",&num);
strcpy(temp->name,n);
temp->roll = 0;
 
 
switch(class)
       {
         case 1 :delete(&one , temp);
                 break;
        case 2:delete(&two , temp);
                 break;
        case 3: delete(&three , temp);
                 break;
        case 4:delete(&four , temp);
                 break;
        case 5: delete(&five , temp);
                 break;
         case 6:delete(&six , temp);
                 break;
         case 7:delete(&seven , temp);
                 break;
         case 8:delete(&eight , temp);
                 break;
         case 9:delete(&nine, temp);
                break;
         case 10:delete(&ten , temp);
                  break;
       }
}
 
 
 
/*Displaying the list of students after promotion and insertion or deletion*/ 
inorder(ten);
printf("Students of tenth standard\n");
display(ten);
 
 
 
inorder(nine);
printf("Students of ninth standard\n");
display(nine);
 
inorder(eight);
printf("Students of eighth standard\n");
display(eight);
 
inorder(seven);
printf("Students of seventh standard\n");
display(seven);
 
inorder(six);
printf("Students of sixth standard\n");
display(six);
 
inorder(five);
printf("Students of fifth standard\n");
display(five);
 
inorder(four);
printf("Students of fourth standard\n");
display(four);
 
inorder(three);
printf("Students of third standard\n");
display(three);
 
inorder(two);
printf("Students of second standard\n");
display(two);

inorder(one);
printf("Students of first standard\n");
display(one);
 
 
}






void extract(FILE *fp , struct tnode **class)
{

  struct tnode  *temp;
  temp=(struct tnode *)malloc(sizeof(struct tnode));

 const char s[2] = ", ";
    char *token , *tp;
    int i , k;
    if(fp != NULL)
    {
        char line[20];
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(i=0;i<2;i++)
            {
                if(i==0)
                {   
                    //printf("%s\t",token);
                    //tp=token;
                    for(k=0;(k<100  &&  *(token+k)!=',');k++ )
                      temp->name[k]  = *(token+k);
                    token = strtok(NULL,s);
                } else {
                    //printf("%d\n",atoi(token));
                    temp->roll=atoi(token);
                }    
            }
            temp->flag=0;
            insert(class , temp); 
        }
    } 
}

void create()
{
  FILE *filep = fopen("one.txt", "r");
    extract(filep,&one);
    printf("\nClass 1 :\n");
    display(one);
    fclose(filep);

    filep = fopen("two.txt", "r");
    extract(filep,&two);
    printf("\nClass 2 :\n");
    display(two);
    fclose(filep);

    filep = fopen("three.txt", "r");
    extract(filep,&three);
    printf("\nClass 3 :\n");
    display(three);
    fclose(filep);

    filep = fopen("four.txt", "r");
    extract(filep,&four);
    printf("\nClass 4 :\n");
    display(four);
    fclose(filep);

    filep = fopen("five.txt", "r");
    extract(filep,&five);
    printf("\nClass 5 :\n");
    display(five);
    fclose(filep);

    filep = fopen("six.txt", "r");
    extract(filep,&six);
    printf("\nClass 6 :\n");
    display(six);
    fclose(filep);

    filep = fopen("seven.txt", "r");
    extract(filep,&seven);
    printf("\nClass 7 :\n");
    display(seven);
    fclose(filep);

    filep = fopen("eight.txt", "r");
    extract(filep,&eight);
    printf("\nClass 8 :\n");
    display(eight);
    fclose(filep);

    filep = fopen("nine.txt", "r");
    extract(filep,&nine);
    printf("\nClass 9 :\n");
    display(nine);
    fclose(filep);


    filep = fopen("ten.txt", "r");
    extract(filep,&ten);
    printf("\nClass 10 :\n");
    display(ten);
    fclose(filep);

}


void inorder(struct tnode *t)
{
if(t!=NULL)
{
inorder(t->left);
t->flag=0;
inorder(t->right);
}
}