#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct date)
struct date{
	struct date*pre;
	int num;
	struct date*next;
};
int n;								//一个数n用于判断该结点是否为头结点，n=0表示头结点，其余不为头结点 
int y;								//y用于判断scanf的输入类型是否正确			
//创建链表
struct date*creat(){
	struct date*head,*p1,*p2;
	p1=p2=(struct date*)malloc(LEN);    //开辟一块空间 
	p1->pre=NULL; 
	printf("请输入数据(输入-1退出):");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	if(p1->num==-1){					//如果第一个数据为-1，则立刻退出输出函数，并返回NULL 
		return NULL;
	} 
	while(p1->num!=-1){
		if(n==0){						//n=0，表示头结点，设置头结点 
			head=p1;					
		}else{							//n！=0，表示不是头结点，改变指向 
			p1->pre=p2;					//后一结点的pre指向前一个结点 
			p2->next=p1;				//前一个结点的next指向后一个结点 
			p2=p1; 						 
		} 
		p1=(struct date*)malloc(LEN);	//继续开辟新结点存放数据 
		printf("请继续输入:");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
		n++;
	}
	p2->next=NULL;						//将最后一个结点的next指向NULL 
	return head;
} 
//增加一个节点数据
void add(struct date*head){
	if(head==NULL){
		return ;
	}
	struct date*p1,*p2;
	p1=head;
	int count1,count2=1;				//count1用于记录新增数据的位置，count2通过++来到达要count1的位置(即要添加数据的位置) 
	printf("请输入要添加数据的节点位置：\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
	if(count1<0||count1>n){					 
		printf("您所输入的信息有误！");	//判断count1的值，不能为负数(结点数不能为负数)，或大于总的结点数(即n的值) 
		return ; 
	} 
	p2=(struct date*)malloc(LEN);
	printf("请输入要添加的数据:\n");
		y=scanf("%d",&p2->num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&p2->num);
}
	while(count2 < count1){
		p1=p1->next;					//count2通过++来到达要count1的位置(即要添加数据的位置) 
		count2++;
	} 									//到达要增加的位置后，改变指向
	p2->next=p1->next;					 //新增结点的next指向count1的next 
	p1->next=p2;						//count1的next指向新增结点 
	p2->next->pre=p2;					//count1的下一个结点的pre指向新增结点 
	p2->pre=p1;							//新增结点的pre指向count1 
	n++;
}
//删除一个结点 
struct date * delete(struct date*head){
	if(head==NULL){
		return NULL;
	}
	int count1,count2=0;				//count1用于删除的数据大小，count2判断时候删除成功 
	struct date*p1,*p2;
	p1=head;
	printf("请输入要删除的结点数据:\n");
			y=scanf("%d",&count1);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
		if(p1==head&&p1->num==count1){	//如果是头结点要删除，对应操作 
			p1=p1->next;
			p1->pre=NULL; 
			head=p1;
			printf("删除成功！\n");
			n--;
			return head;
		} else{
			p2=head;
			p1=p1->next;
		}		
	while(p1->next!=NULL){		//判断头结点之后，尾结点之前的数据是否要删除 
			if(p1->num==count1){	
			p2->next=p1->next;
			p1->next->pre=p2;
			p1->pre=NULL;
			p1=p1->next;
			count2=1;
		}else {
			p1=p1->next;
			p2=p2->next;
		}		
	}
	if(p1->num==count1){		//判断尾结点数据是否要删除 
		p2->next=NULL;			//直接让倒数第二个结点的next==NULL就可以了 
		count2=1;
	}
	if(count2==0){
		printf("找不到要删除的节点数据！\n");
	}else{
		printf("删除成功！\n");
		n--;
	}
	return head;
} 
//修改指定结点数据
void revise(struct date*head){
		if(head==NULL){
		return ;
	}
	struct date*p1;
	p1=head;
	int count1,count2=1,num;		//count1用于记录修改数据的位置，count2通过++来到达要count1的位置(即要修改数据的位置)，num为修改后的数据 
	printf("请输入要修改数据的节点位置：\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
	if(count1<0||count1>n){				//判断count1的值，不能为负数(结点数不能为负数)，或大于总的结点数(即n的值) 
		printf("您所输入的信息有误！");
		return ; 
	} 
	printf("请输入修改后的数据:\n");
			y=scanf("%d",&num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&num);
}
	while(count2 < count1){			//找到count1的位置 
		p1=p1->next;
		count2++;
	} 
	p1->num=num;					//修改其值 
}  
//输出链表的函数
void print(struct date*head){
	if(head==NULL){
		printf("链表为空，请先创建链表！\n");
	}
	struct date*p;
	p=head;
	while(p!=NULL){
		printf("%d  ",p->num);				//通过！=NULL为条件，依次遍历链表并输出 
		p=p->next;
	}
	printf("\n");
} 

int main(){
	struct date*head;
	head=NULL;
	int x; 
	while(1){
		if(x==5){
			break;
		}
	printf("****************************************\n\n");
	printf("1.创建链表                  2.添加数据\n");
	printf("3.删除数据                  4.修改数据\n");
	printf("5.exit\n\n");
	printf("****************************************\n\n");
	printf("请输入指令：\n");
		y=scanf("%d",&x);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&x);
}
	switch(x) {
		case 1:head=creat();
				print(head);
				break;
		case 2:add(head);
				print(head);
				break;
		case 3:head=delete(head);
				print(head);
				break;
		case 4:revise(head);
				print(head);
				break;
		case 5:printf("退出成功！\n");
				break;
		default:printf("指令有误,请重新输入！\n");
		} 
		system("pause");
	} 
	return 0;		
}

