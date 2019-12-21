#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node *ln;
/////////////////////////////////////////////////////////////////////////////////
void create(ln &l)
{
	l=NULL;
}
/////////////////////////////////////////////////////////////////////////////////
int emp(ln list)
{
	if (list==NULL) return 1;
	else return 0;
}
/////////////////////////////////////////////////////////////////////////////////
ln insert_end(ln &l,int item)
{
	ln temp,pre;
	temp= (ln) malloc(sizeof(ln));
	temp->data=item;
	temp->next=NULL;
	if (l==NULL)
		l=temp;
	else
	{
		pre=l;
		while (pre->next!=NULL)
			pre=pre->next;
		pre->next=temp;
	}
}	
/////////////////////////////////////////////////////////////////////////////////
ln insert_home(ln &l,int x)
{
	ln temp;
	temp =(ln) malloc (sizeof(ln));
	temp->data=x;
	temp->next=l;
	l=temp;
	return l;
}
/////////////////////////////////////////////////////////////////////////////////
ln insert_after_pos(ln &l,int x,int n,int p)
{
	ln temp,pre;
	if (p>n) { printf("cannot");}
	else
	{ 
		temp= (ln) malloc (sizeof (ln));
		temp->data=x;
		pre=l;
		for (int i=1;i<p;i++) pre=pre->next;
		temp->next=pre->next;
		pre->next=temp;
	}
	return l;
}
/////////////////////////////////////////////////////////////////////////////////
void input(ln &l,int &n)
{
	int x;
	printf("n= ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		
		printf("gia tri thu %d= ",i);
		scanf("%d",&x);
		insert_end(l,x);
	}
}
/////////////////////////////////////////////////////////////////////////////////
ln del(ln &l,int n,int p)
{
	ln pre,temp;
	if (p==1) l=l->next;
	else
	{
		temp = (ln) malloc (sizeof(ln));
		pre  = (ln) malloc (sizeof(ln));
		pre=l;
		for (int i=1;i<p-1;i++) pre=pre->next;
		temp=pre->next;
		pre->next=temp->next;
	}
	//free(temp);
	return l;
}
////////////////////////////////////////////////////////////////////////////////////
void avg(ln l,int n)
{
	float t=0;
	ln temp;
	temp = (ln) malloc (sizeof(ln));
	temp=l;
	for (int i=1;i<=n;i++)
	{
		t+=float(temp->data);
		temp=temp->next;
	}
	printf("Gia tri trung binh cua danh sach= %f",t/float(n));
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////
void print(ln &l,int n)
{
	ln p1;
	p1=l;
		for (int i=1;i<=n;i++)
		{
			printf("%d   ",p1->data);
			p1=p1->next;
		}
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////
main()
{
	ln l,p1;
	int n,p,pp,x,sl,vt;
	create(l);
	printf("========================================\n");
	printf("\t\tXin chao\n");
	printf("Da khoi tao danh sach moc noi.\n");
	printf("\nMoi ban nhap danh sach dau vao.\n");
	input(l,n);
	
	do
	{
	
	system("cls");
	printf("danh sach: ");
	print(l,n);
	printf("\nMoi ban chon:\n");
	printf("1.Kiem tra rong.\n");
	printf("2.Chen them phan tu\n");
	printf("3.Xoa phan tu\n");
	printf("4.Tinh gia tri trung binh\n");
	printf("5.Exit\n");
	printf("What do u want: ");
	scanf("%d",&p);
	switch(p)
		{
			case 1: printf("%d\n",emp(l)); //Kiem tra rong
			getch();
					break;
			case 2: //Chen 
					printf("Chen them phan tu\n");
					printf("1.Chen 1 phan tu\n ");
					printf("2.Chen nhieu phan tu\n");
					printf("Moi ban nhap: ");
					scanf("%d",&pp);
					switch(pp)
					{
						case 1: //Chen 1 phan tu
							n++;
							printf("Moi ban nhap gia tri muon chen:");
							scanf("%d",&x);
							printf("\nBan muon chen gia tri %d vao dau? ",x);
							printf("\n1.Chen dau\n");
							printf("2.Chen cuoi\n");
							printf("3.Chen sau 1 vi tri nao do\n");
							printf("Moi ban nhap: ");
							scanf("%d",&pp);
							switch(pp)
							{
								case 1: insert_home(l,x); // chen 1 phan tu vao dau danh sach
										print(l,n);
										break;
								case 2: insert_end(l,x); // Chen 1 phan tu vao cuoi danh sach
										print(l,n);
										break;
								case 3: //chen 1 phan tu vao sau vi tri 'vt'
										printf("nhap vi tri ban muon chen sau ");
										scanf("%d",&vt);
										insert_after_pos(l,x,n,vt);
										print(l,n);
										break;	
							}
							break;
						case 2: //Chen nhieu phan tu
							printf("Nhap so luong phan tu ban muon chen them:");
							scanf("%d",&sl);
							n+=sl; 
							printf("\nBan muon chen %d phan tu do vao dau? ",sl);
							printf("\n1.Chen dau\n");
							printf("2.Chen cuoi\n");
							printf("3.Chen sau 1 vi tri nao do\n");
							printf("Moi ban nhap: ");
							scanf("%d",&pp);
							switch(pp)
							{
								case 1:  // Chen nhieu phan tu vao dau
									for (int i=1;i<=sl;i++)
									{
										printf("moi ban nhap gia tri chen thu %d: ",i);
										scanf("%d",&x);
										if (i==1) insert_home(l,x);
										else insert_after_pos(l,x,n,i-1);
									}
									print(l,n);
									break;
								case 2: //Chen nhieu phan tu vao cuoi
									for (int i=1;i<=sl;i++)
									{
										printf("moi ban nhap gia tri chen thu %d: ",i);
										scanf("%d",&x);
										insert_end(l,x);
									}
									print(l,n);
									break;
								case 3: //Chen nhieu phan tu vao sau vi tri 'vt'
									printf("Ban muon chen cac phan tu tren sau vi tri :");
									scanf("%d",&vt);
									for (int i=1;i<=sl;i++)
									{
										
										printf("Moi ban nhap gia tri chen thu %d: ",i);
										scanf("%d",&x);
										insert_after_pos(l,x,n,vt+i);
									}
									print(l,n);
									break;		
							}	
					}
					break;
			case 3: 	if (n==0) {printf("Danh sach rong khong the xoa");getch();}
						else{
			
						printf("\n1. Xoa 1 phan tu "); //Xoa phan tu
						printf("\n2. Xoa nhieu phan tu");
						printf("\nMoi ban chon: ");
						scanf("%d",&pp);
						switch(pp)
						{
						case 1: //Xoa 1 phan tu
								printf("Ban muon xoa vi tri : ");
								scanf("%d",&vt);
								if (vt>n) {printf("cannot");getch();}
								else {del(l,n,vt);
								n--;}
								print(l,n);
								break;
						case 2://Xoa nhieu phan tu
								printf("\n Ban muon xoa bao nhieu phan tu? ");
								scanf("%d",&sl);
								if (sl>n) {printf("cannot");getch();}
								else
								for (int i=1;i<=sl;i++)
									{
										printf("Nhap vi tri ban muon xoa lan thu %d:",i);
										scanf("%d",&vt);
										if (vt>n) {printf("cannot");getch();}
										else {del(l,n,vt);
										n--;}
										printf("Danh sach sau khi xoa lan thu %d:",i);
										print(l,n);
									}
								break;
						}}
						break;
			case 4:	avg(l,n);
					getch();
					break;
			case 5: printf("Thank for using");
					break;		
		}
	}
	 while (p!=5);
}


