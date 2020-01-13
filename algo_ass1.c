//code to create calendar

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * right;
	struct node* down;
	int date;
};

struct node* newNode( ) 
{ 
	struct node* temp =(struct node *)malloc(sizeof(struct node));
	temp->date = 0; 
	temp->right=NULL;
	temp->down = NULL; 
        return temp; 
} 

struct node* initcal(int row,int col)
{
	struct node * mainhead=NULL;
	
	struct node *head[row];
	struct node *temp1,*temp;

	for(int i=0;i<row;i++)
	{
		head[i]=NULL;
		
		

		for(int j=0;j<col;j++)
		{	
			temp=newNode();

			if(!mainhead)
				mainhead=temp;

			if(!head[i])
				head[i]=temp;
			else
				temp1->right=temp;


			temp1=temp;
		}
		
	}
	for(int i=0;i<(row-1);i++){
		struct node *temp2,*temp3;
		temp2=head[i];
		temp3=head[i+1];
		int j=0;
		while(temp1 && temp2){
			temp2->down=temp3;
			temp2=temp2->right;
			temp3=temp3->right;
			j=j+1;
		}
	}
	return mainhead;
}

void display(struct node* head) 
{ 
	 struct node* rt;                                                             // pointer to move right 
	
	struct node* dn = head;                                                      // pointer to move down 
	int j=0;
	while (dn) {                                                   // loop till node->down is not NULL 
		rt = dn; 
		int i=0;
		while (rt) {                                               // loop till node->right is not NULL 
			printf("%2d  ",rt->date);
			rt = rt->right; 
			i++;
		} 
		printf("\n");
		dn = dn->down; 
		j++;
	} 
} 

int storemonth(struct node * head,int day,int month,int leap)
{
	int a=0;
	int i,j,k,l;
	if( (month==0) ||(month==2)||(month==4)||(month==6)||(month==7)||(month==9)||(month==11))
		a=31;
	else if(month==1 && leap==1)
		a=29;
	else if(month==1)
		a=28;
	else
		a=30;

	if(month<=2)
		i=0;
	else if(month<=5)
		i=5;
	else if(month<=8)
		i=10;
	else
		i=15;

	if(((month+1)%3)==1)
		j=0;
	else if(((month+1)%3)==2)
		j=7;
	else
		j=14;

	struct node *head1=head;
	
	for(k=0;k<i;k++){
		
		head1=head1->down;}
	for(k=0;k<j;k++){
		head1=head1->right;
		}
	struct node * temp=head1;
	struct node * temp1=head1;
	for(k=0;k<day;k++){
		
		temp=temp->right;}

	j=01;
	for(l=0;l<=4;l++)
	{
		
		for(i=k;(i<=6) && (j<=a);i++)
		{
			temp->date=j;
			temp=temp->right;
			j++;
		}
		k=0;
		temp1=temp1->down;
		temp=temp1;

	}
	if(j<=a)
	{	i=0;
		while(j<=a){
			head1->date=j;
			head1=head1->right;
			j++;
			i++;
		}
	}
	return i;
	
}

int main(){
	int row=20;
	int col=21;
	int year,leap,day;
	struct node *C=initcal(row,col);

	printf("enter the year: ");
	scanf("%d",&year);
	printf("\n enter 1 for leap and zero otherwise: ");
	scanf("%d",&leap);
	printf("\n enter the day of january: ");
	scanf("%d",&day);

	for(int i=0;i<12;i++)
	{
		day=storemonth(C,day,i,leap);
		if(day==7)
			day=0;
	}
	display(C);
	return 0;
}





































