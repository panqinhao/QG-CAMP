#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct date)
struct date{
	struct date*pre;
	int num;
	struct date*next;
};
int n;								//һ����n�����жϸý���Ƿ�Ϊͷ��㣬n=0��ʾͷ��㣬���಻Ϊͷ��� 
int y;								//y�����ж�scanf�����������Ƿ���ȷ			
//��������
struct date*creat(){
	struct date*head,*p1,*p2;
	p1=p2=(struct date*)malloc(LEN);    //����һ��ռ� 
	p1->pre=NULL; 
	printf("����������(����-1�˳�):");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	if(p1->num==-1){					//�����һ������Ϊ-1���������˳����������������NULL 
		return NULL;
	} 
	while(p1->num!=-1){
		if(n==0){						//n=0����ʾͷ��㣬����ͷ��� 
			head=p1;					
		}else{							//n��=0����ʾ����ͷ��㣬�ı�ָ�� 
			p1->pre=p2;					//��һ����preָ��ǰһ����� 
			p2->next=p1;				//ǰһ������nextָ���һ����� 
			p2=p1; 						 
		} 
		p1=(struct date*)malloc(LEN);	//���������½�������� 
		printf("���������:");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
		n++;
	}
	p2->next=NULL;						//�����һ������nextָ��NULL 
	return head;
} 
//����һ���ڵ�����
void add(struct date*head){
	if(head==NULL){
		return ;
	}
	struct date*p1,*p2;
	p1=head;
	int count1,count2=1;				//count1���ڼ�¼�������ݵ�λ�ã�count2ͨ��++������Ҫcount1��λ��(��Ҫ������ݵ�λ��) 
	printf("������Ҫ������ݵĽڵ�λ�ã�\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
	if(count1<0||count1>n){					 
		printf("�����������Ϣ����");	//�ж�count1��ֵ������Ϊ����(���������Ϊ����)��������ܵĽ����(��n��ֵ) 
		return ; 
	} 
	p2=(struct date*)malloc(LEN);
	printf("������Ҫ��ӵ�����:\n");
		y=scanf("%d",&p2->num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&p2->num);
}
	while(count2 < count1){
		p1=p1->next;					//count2ͨ��++������Ҫcount1��λ��(��Ҫ������ݵ�λ��) 
		count2++;
	} 									//����Ҫ���ӵ�λ�ú󣬸ı�ָ��
	p2->next=p1->next;					 //��������nextָ��count1��next 
	p1->next=p2;						//count1��nextָ��������� 
	p2->next->pre=p2;					//count1����һ������preָ��������� 
	p2->pre=p1;							//��������preָ��count1 
	n++;
}
//ɾ��һ����� 
struct date * delete(struct date*head){
	if(head==NULL){
		return NULL;
	}
	int count1,count2=0;				//count1����ɾ�������ݴ�С��count2�ж�ʱ��ɾ���ɹ� 
	struct date*p1,*p2;
	p1=head;
	printf("������Ҫɾ���Ľ������:\n");
			y=scanf("%d",&count1);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
		if(p1==head&&p1->num==count1){	//�����ͷ���Ҫɾ������Ӧ���� 
			p1=p1->next;
			p1->pre=NULL; 
			head=p1;
			printf("ɾ���ɹ���\n");
			n--;
			return head;
		} else{
			p2=head;
			p1=p1->next;
		}		
	while(p1->next!=NULL){		//�ж�ͷ���֮��β���֮ǰ�������Ƿ�Ҫɾ�� 
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
	if(p1->num==count1){		//�ж�β��������Ƿ�Ҫɾ�� 
		p2->next=NULL;			//ֱ���õ����ڶ�������next==NULL�Ϳ����� 
		count2=1;
	}
	if(count2==0){
		printf("�Ҳ���Ҫɾ���Ľڵ����ݣ�\n");
	}else{
		printf("ɾ���ɹ���\n");
		n--;
	}
	return head;
} 
//�޸�ָ���������
void revise(struct date*head){
		if(head==NULL){
		return ;
	}
	struct date*p1;
	p1=head;
	int count1,count2=1,num;		//count1���ڼ�¼�޸����ݵ�λ�ã�count2ͨ��++������Ҫcount1��λ��(��Ҫ�޸����ݵ�λ��)��numΪ�޸ĺ������ 
	printf("������Ҫ�޸����ݵĽڵ�λ�ã�\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
	if(count1<0||count1>n){				//�ж�count1��ֵ������Ϊ����(���������Ϊ����)��������ܵĽ����(��n��ֵ) 
		printf("�����������Ϣ����");
		return ; 
	} 
	printf("�������޸ĺ������:\n");
			y=scanf("%d",&num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&num);
}
	while(count2 < count1){			//�ҵ�count1��λ�� 
		p1=p1->next;
		count2++;
	} 
	p1->num=num;					//�޸���ֵ 
}  
//�������ĺ���
void print(struct date*head){
	if(head==NULL){
		printf("����Ϊ�գ����ȴ�������\n");
	}
	struct date*p;
	p=head;
	while(p!=NULL){
		printf("%d  ",p->num);				//ͨ����=NULLΪ���������α���������� 
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
	printf("1.��������                  2.�������\n");
	printf("3.ɾ������                  4.�޸�����\n");
	printf("5.exit\n\n");
	printf("****************************************\n\n");
	printf("������ָ�\n");
		y=scanf("%d",&x);
	while(y==0){
	printf("���������������������룡\n");
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
		case 5:printf("�˳��ɹ���\n");
				break;
		default:printf("ָ������,���������룡\n");
		} 
		system("pause");
	} 
	return 0;		
}

