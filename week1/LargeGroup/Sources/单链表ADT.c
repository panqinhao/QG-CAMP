#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct date)	 //����LEN�����ڴ��СΪһ���ṹ����ڴ��С 

//����ṹ�� 
struct date{
	int num;
	struct date*next; 
};

//��������ĺ���
int n=0;			//һ����n�����жϸý���Ƿ�Ϊͷ��㣬n=0��ʾͷ��㣬���಻Ϊͷ��� 
int y;				//y�����ж�scanf��ֵ�������ж��Ƿ������˴������͵����� 
struct date * creat(){
	struct date*head,*p1,*p2;
	head=NULL;
	n=0;
	p1=p2=(struct date *)malloc(LEN);		//����һ��ռ�
	printf("����������(����-1�˳�����):");
	y=scanf("%d",&p1->num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	while(p1->num!=-1){						//�������Ϊ-1���������˳��䲢����head
		if(n==0){							//n=0����ʾͷ��㣬����ͷ��� 
			head=p1;
			p2->next=NULL;
		}else{								//n��=0����ʾ����ͷ��㣬�ı�ָ�� 
			p2->next=p1;					//��һ����nextָ���µĽ�� 
			p2=p1;							//���½ڵ��ֵ����P2 
			p2->next=NULL;					//ʹ�½ڵ��next==NULL 
		}	
		n++;
		p1=(struct date*)malloc(LEN);		//�������ٿռ� 
		printf("��������룺"); 
		y=0;
		y=scanf("%d",&p1->num);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&p1->num);
}
	}
	 return head;
} 

//����һ�����ݵĺ���
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
	if(count1<0||count1>n){				//�ж�count1��ֵ������Ϊ����(���������Ϊ����)��������ܵĽ����(��n��ֵ)
		printf("�����������Ϣ����");
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
	n++;
}

//ɾ��һ������
struct date * delete(struct date*head){
	if(head==NULL){
		return NULL;
	}
	int count1,count2=0;			//count1����ɾ�������ݴ�С��count2�ж�ʱ��ɾ���ɹ� 
	struct date*p1,*p2;
	p1=head;
	printf("������Ҫɾ���Ľ������:\n");
		y=scanf("%d",&count1);
	while(y==0){
	printf("���������������������룡\n");
	fflush(stdin);
	y=scanf("%d",&count1);
}
		if(p1==head&&p1->num==count1){		//�����ͷ���Ҫɾ������Ӧ���� 
			p1=p1->next;
			head=p1;
			printf("ɾ���ɹ���\n");
			n--;
			return head;
		} else{
			p2=head;
			p1=p1->next;
		}		
	while(p1!=NULL){						//�ж�ͷ���֮��������Ƿ�Ҫɾ�� 
			if(p1->num==count1){
			p2->next=p1->next;
			p1=p1->next;
			count2=1;
		}else {
			p1=p1->next;
			p2=p2->next;
		}		
	}
	if(count2==0){							//���ɾ����Ϣ 
		printf("�Ҳ���Ҫɾ���Ľڵ����ݣ�\n");
	}else{
		printf("ɾ���ɹ���\n");
		n--;
	}
	return head;
} 

//�޸�����һ�����ݵĺ���
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
	if(count1<0||count1>n){			//�ж�count1��ֵ������Ϊ����(���������Ϊ����)��������ܵĽ����(��n��ֵ)
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
//����������ݵĺ���
void print(struct date*head){
	if(head==NULL){
		printf("����Ϊ�գ����ȴ�������\n");
		return ;
	}
	struct date*p;
	p=head;
	if(p==NULL){
		printf("����Ϊ�գ�\n");
		return ;
	}
	
	printf("�����������£�\n");
	do{									//ͨ����=NULLΪ���������α���������� 
		printf("%d  ",p->num);
		p=p->next;
	}while(p!=NULL);
	p=head;
	printf("\n");
} 

//��������ż���������� input: 1 -> 2 -> 3 -> 4  ��output: 2 -> 1 -> 4 -> 3 ��
struct date *exchange(struct date*head){
	if(head==NULL){
		return NULL;
	}
	struct date*p1,*p2,*p3;
	p3=head;
	p2=p3->next;
	p1=p2->next;
	if(p3->num%2==0&&p2->num%2!=0||p2->num%2==0&&p3->num%2!=0){ //ͷ���͵ڶ���㽻�� 
				p3->next=p1;
				p2->next=p3;
				p3=p2;
				p2=p2->next;
				head=p3;
			}
	do{
			if(p1->num%2==0&&p2->num%2!=0||p2->num%2==0&&p1->num%2!=0){		//ͷ���֮��Ľ��� 
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
 
//2.�ҵ���������е�
void middle(struct date*head){
	if(head==NULL){
		printf("����Ϊ�գ����ȴ�������\n");
		return ;
	}
	struct date*p1,*p2;			//������������P1һ������P2һ����һ�� 
	p1=head;
	p2=head;
	do{							//��P1���� ��P2��Ȼ�����м�λ���� 
		p1=p1->next->next;
		p2=p2->next;
	}while(p1!=NULL&&p1->next!=NULL);
	printf("�м�ڵ�����Ϊ��%d\n",p2->num);
}

// 3.�ж������Ƿ�ɻ�
void annular(struct date*head){
	if(head==NULL){
		printf("����Ϊ�գ����ȴ�������\n");
		return ;
	}
	struct date*p1,*p2;  //������������P1һ������P2һ����һ�� 
	int count=0;		//count��¼�Ƿ�ɻ���0Ϊ��1Ϊ�� 
	p1=head;
	p2=head;
	do{							
		p1=p1->next->next;
		p2=p2->next;
		if(p1==p2){     //���p1�������ڲ�����NULL���������׷��ÿ��ֻ��1���P2��˵���ɻ� 
			count=1;
			break;
		}
	}while(p1->next!=NULL);
	if(count==1){				//����Ƿ�ɻ���Ϣ 
		printf("������ɻ���\n");
	}else{
		printf("�������ɻ���\n");
	}
}

//4��ת����
struct date *reverse(struct date*head){		//�жϴ�������head�Ƿ�Ϊ�� 
	if(head==NULL){
		return NULL;
	}
	struct date *p1,*p2;
	p1=head;
	p2=head;
	p1=head->next;
	head->next=NULL;
	do{
		p2=p1;					//�ú�һ��ָ���nextָ��ǰһ��ָ�룬 
		p1=p1->next;			//���ú�һ��ָ������һ�� 
		p2->next=head;			//ǰһ��ָ���nextָ����ǰһ����� 
		head=p2;				
	}while(p1!=NULL); 
	printf("����ת��ɣ�\n");
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
	printf("1.��������                  2.�������\n");
	printf("3.ɾ������                  4.�޸�����\n");
	printf("5.��ż����                  6.�������е�\n");
	printf("7.��ת����                  8.�ж��Ƿ�ɻ�\n");
	printf("9.exit\n\n");
	printf("****************************************\n\n");
	printf("������ָ�\n");
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
		case 9:printf("�˳��ɹ���\n");
				break;
		default:printf("ָ������,���������룡\n");
		} 
		system("pause");
	} 
	return 0;		
}
