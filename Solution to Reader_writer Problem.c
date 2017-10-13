#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>

//structure of a process
struct sema{		
	int p_id;
    char name;
    struct sema *next;
};

struct sema *front=NULL,*rear=NULL,*head=NULL;

int wait(struct sema *s){		//checks whether the process needs to wait
	struct sema *P=head,*pp=front,*b=NULL;
	if(s->name=='w'){       //checks whether the process is writer process
		if(!head)return 0;
		else{
			if(front){
				rear->next=s;rear=s;s->next=NULL;}
			else{
				rear=front=s;s->next=NULL;}
			return 1;
		}
	}
	else{
		if(head&&head->name=='w'){
			if(!front){
				rear=front=s;s->next=NULL;}
			else{
				rear->next=s;
				rear=s;s->next=NULL;}
			return 1;
		}
		else{
			pp=front;
			while(pp){
				if(pp->name=='w')break;
				pp=pp->next;
			}
			if(pp){
				if(!front){
					rear=front=s;
					s->next=NULL;}
				else{
					rear->next=s;
					rear=s;s->next=NULL;}
			return 1;
			}
		}
	}
	return 0;
}

// function to decide processes follows the running process 
void signal(struct sema *PP){
	struct sema *p=head,*b=NULL;
	if(!head){
		head=PP,PP->next=NULL;}
	else{
		while(p){
			b=p;
			p=p->next;
		}
		b->next=PP; 
		PP->next=NULL;
	}
}


void finish(){
	int id; struct sema *p=head,*pre=NULL;
	printf("\nenter the process id:");       // enter the process id to stop the process
    scanf("%d",&id);
    while(p){
        if(p->p_id==id)
            break;
        pre=p;
        p=p->next;
    }
    if(!p){
		printf("\nno such process is running");getch();}
    else{
		if(!pre){
			head=head->next;
			p->next=NULL;
			p=NULL;
		}
		else{
			pre->next=p->next;
			p->next=NULL;p=NULL;
		}
    }
    if(front){
        if(!head&&front->name=='w'){
			p=front;
			front=front->next;
			signal(p);
		}
		else{
            p=front;
            while(front&&p->name!='w'){
				p=front;
				front=front->next;
				signal(p);
				p=front;
			}
        }
   if(!front)rear=NULL; 
   }
}

//funtion to print the current running process
void printlist(){
    struct sema *p=head;
    printf("\nCurrent running Operations\n");

    while(p){
        printf("%c:%d  ",p->name,p->p_id);
        p=p->next;
    }
}

//function to show the waiting processes in the queue
void printqueue(){
    struct sema *p=front;
    printf("\nQueued Operations\n");
     while(p)
    {
        printf(" %c:%d  ",p->name,p->p_id);
        p=p->next;
    }
}


void main(){
	struct sema *PP;
    struct sema *P;
    char ch=0;
    int x=0,p_id=0;
	srand((unsigned int)NULL);

	do{
		system("cls");
		printlist();
		printf("\n");
		printqueue();printf("\n");
		printf("(w/r) for next process \n(n) for finishing a process\n(ENTER) for exit\nenter your choice:");

		ch=getch();
		if(ch=='w'||ch=='r'){
			PP=(struct sema*)malloc(sizeof(struct sema));
			PP->name=ch;x=0;
			PP->p_id=(p_id++)+2134;
			PP->next=NULL;

			x=wait(PP);
			if(x==0){
				signal(PP);
			}
		}
		
		else if(ch=='n')
			finish();
		
    }while(ch!=100);
}