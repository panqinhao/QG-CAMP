#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct date)	 //定义LEN，其内存大小为一个结构体的内存大小 

//定义结构体 
struct date{
	int num;
	struct date*next; 
};

//创建链表的函数
int n=0;			//一个数n用于判断该结点是否为头结点，n=0表示头结点，其余不为头结点 
int y;				//y用于判断scanf的值，用于判断是否输入了错误类型的数据 
struct date * creat(){
	struct date*head,*p1,*p2;
	head=NULL;
	n=0;
	p1=p2=(struct date *)malloc(LEN);		//开辟一块空间
	printf("请输入数字(输入-1退出输入):");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	while(p1->num!=-1){						//如果数据为-1，则立刻退出输并返回head
		if(n==0){							//n=0，表示头结点，设置头结点 
			head=p1;
			p2->next=NULL;
		}else{								//n！=0，表示不是头结点，改变指向 
			p2->next=p1;					//后一结点的next指向新的结点 
			p2=p1;							//将新节点的值赋给P2 
			p2->next=NULL;					//使新节点的next==NULL 
		}	
		n++;
		p1=(struct date*)malloc(LEN);		//继续开辟空间 
		printf("请继续输入："); 
		y=0;
		y=scanf("%d",&p1->num);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	}
	 return head;
} 

//增加一条数据的函数
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
	if(count1<0||count1>n){				//判断count1的值，不能为负数(结点数不能为负数)，或大于总的结点数(即n的值)
		printf("您所输入的信息有误！");
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
	n++;
}

//删除一条数据
struct date * delete(struct date*head){
	if(head==NULL){
		return NULL;
	}
	int count1,count2=0;			//count1用于删除的数据大小，count2判断时候删除成功 
	struct date*p1,*p2;
	p1=head;
	printf("请输入要删除的结点数据:\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("您的输入有误！请重新输入！\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
		if(p1==head&&p1->num==count1){		//如果是头结点要删除，对应操作 
			p1=p1->next;
			head=p1;
			printf("删除成功！\n");
			n--;
			return head;
		} else{
			p2=head;
			p1=p1->next;
		}		
	while(p1!=NULL){						//判断头结点之后的数据是否要删除 
			if(p1->num==count1){
			p2->next=p1->next;
			p1=p1->next;
			count2=1;
		}else {
			p1=p1->next;
			p2=p2->next;
		}		
	}
	if(count2==0){							//输出删除信息 
		printf("找不到要删除的节点数据！\n");
	}else{
		printf("删除成功！\n");
		n--;
	}
	return head;
} 

//修改其中一条数据的函数
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
	if(count1<0||count1>n){			//判断count1的值，不能为负数(结点数不能为负数)，或大于总的结点数(即n的值)
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
//输出链表数据的函数
void print(struct date*head){
	if(head==NULL){
		printf("链表为空，请先创建链表！\n");
		return ;
	}
	struct date*p;
	p=head;
	if(p==NULL){
		printf("链表为空！\n");
		return ;
	}
	
	printf("链表数据如下：\n");
	do{									//通过！=NULL为条件，依次遍历链表并输出 
		printf("%d  ",p->num);
		p=p->next;
	}while(p!=NULL);
	p=head;
	printf("\n");
} 

//单链表奇偶调换（例： input: 1 -> 2 -> 3 -> 4  ，output: 2 -> 1 -> 4 -> 3 ）
struct date *exchange(struct date*head){
	if(head==NULL){
		return NULL;
	}
	struct date*p1,*p2,*p3;
	p3=head;
	p2=p3->next;
	p1=p2->next;
	if(p3->num%2==0&&p2->num%2!=0||p2->num%2==0&&p3->num%2!=0){ //头结点和第二结点交换 
				p3->next=p1;
				p2->next=p3;
				p3=p2;
				p2=p2->next;
				head=p3;
			}
	do{
			if(p1->num%2==0&&p2->num%2!=0||p2->num%2==0&&p1->num%2!=0){		//头结点之后的交换 
				p2->next=p1->next;
				p3->next=p1;
				p1->next=p2;
				p1=p2->next;
				p3=p3->next;
			}else{
				p1=p1->next;
				p2=p2->next;
				p3=p3->next;
			}
	}while(p1!=NULL);
	return head;
}
 
//2.找到单链表的中点
void middle(struct date*head){
	if(head==NULL){
		printf("链表为空，请先创建链表！\n");
		return ;
	}
	struct date*p1,*p2;			//定义两个链表，P1一次两格，P2一次走一格 
	p1=head;
	p2=head;
	do{							//当P1走完 ，P2自然就是中间位置了 
		p1=p1->next->next;
		p2=p2->next;
	}while(p1!=NULL&&p1->next!=NULL);
	printf("中间节点数据为：%d\n",p2->num);
}

// 3.判断链表是否成环
void annular(struct date*head){
	if(head==NULL){
		printf("链表为空，请先创建链表！\n");
		return ;
	}
	struct date*p1,*p2;  //定义两个链表，P1一次两格，P2一次走一格 
	int count=0;		//count记录是否成环，0为否，1为是 
	p1=head;
	p2=head;
	do{							
		p1=p1->next->next;
		p2=p2->next;
		if(p1==p2){     //如果p1走两格在不等于NULL的情况下能追到每次只走1格的P2，说明成环 
			count=1;
			break;
		}
	}while(p1->next!=NULL);
	if(count==1){				//输出是否成环信息 
		printf("该链表成环！\n");
	}else{
		printf("该链表不成环！\n");
	}
}

//4反转链表
struct date *reverse(struct date*head){		//判断传过来的head是否为空 
	if(head==NULL){
		return NULL;
	}
	struct date *p1,*p2;
	p1=head;
	p2=head;
	p1=head->next;
	head->next=NULL;
	do{
		p2=p1;					//让后一个指针的next指向前一个指针， 
		p1=p1->next;			//先让后一个指针往后一个 
		p2->next=head;			//前一个指针的next指向再前一个结点 
		head=p2;				
	}while(p1!=NULL); 
	printf("链表反转完成！\n");
	printf("\n");
	return head;
}


int main(){
	struct date*head;
	head=NULL;
	int x; 
	while(1){
		if(x==9){
			break;
		}
	printf("****************************************\n\n");
	printf("1.创建链表                  2.添加数据\n");
	printf("3.删除数据                  4.修改数据\n");
	printf("5.奇偶调换                  6.找链表中点\n");
	printf("7.反转链表                  8.判断是否成环\n");
	printf("9.exit\n\n");
	printf("****************************************\n\n");
	printf("请输入指令：\n");
	y=scanf("%d",&x);
	if(y==0){
		fflush(stdin);
		x=0;
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
		case 5:head=exchange(head);
				print(head);
				break;
		case 6:middle(head);
				break;
		case 7:head=reverse(head);
				print(head);
				break;
		case 8:annular(head);
				break;
		case 9:printf("退出成功！\n");
				break;
		default:printf("指令有误,请重新输入！\n");
		} 
		system("pause");
	} 
	return 0;		
}
