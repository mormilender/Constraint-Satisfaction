#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
#define days 5
#define hours 8
#define P 21

typedef struct course
{
	string name;
	int type;
	int num;
	int pro_num;
	int start;
	int end;
	int day;
	int prac[3];
	int prev_cource[3];
	int must;
	int points;
	int rel;
	int rel2;
	bool taken;
}cource;


course* cal[8][5]={NULL};
course clist[55]={"c#",4,1,36,8,11,3,49,50,51,26,34,25,0,3,0,0,0,
"java",4,2,35,13,16,1,45,46,47,34,26,6,0,3,0,0,0,
"math1_p1",2,3,1,12,13,1,0,0,0,0,0,0,0,0,4,5,0,
"math1_p2",2,4,28,15,16,2,0,0,0,0,0,0,0,0,3,5,0,
"math1_p3",2,5,3,15,16,0,0,0,0,0,0,0,0,0,3,4,0,
"ai",4,6,37,8,11,3,53,54,55,35,37,26,0,4,0,0,0,
"alg_p1",2,7,5,11,12,1,0,0,0,0,0,0,0,0,8,9,0,
"alg_p2",2,8,29,10,11,4,0,0,0,0,0,0,0,0,7,9,0,
"alg_p3",2,9,6,8,9,2,0,0,0,0,0,0,0,0,7,8,0,
"math2",4,10,12,9,12,3,17,18,19,35,37,26,0,3,14,0,0,
"lin_p1",2,11,5,8,9,3,0,0,0,0,0,0,0,0,12,13,0,
"lin_p2",2,12,8,9,10,3,0,0,0,0,0,0,0,0,11,13,0,
"lin_p3",2,13,9,15,16,3,0,0,0,0,0,0,0,0,11,12,0,
"math2",4,14,20,12,15,4,17,18,19,35,37,26,0,3,10,0,0,
"auto",1,15,13,14,16,4,27,28,29,0,0,0,1,3,16,0,0,
"auto",1,16,18,11,13,1,27,28,29,0,0,0,1,3,15,0,0,
"math2_p1",2,17,21,13,15,3,0,0,0,0,0,0,0,0,18,19,0,
"math2_p2",2,18,22,12,14,4,0,0,0,0,0,0,0,0,17,19,0,
"math2_p3",2,19,16,10,12,1,0,0,0,0,0,0,0,0,17,18,0,
"log",1,20,20,8,12,2,22,23,24,0,0,0,1,4,21,0,0,
"log",1,21,21,12,16,2,22,23,24,0,0,0,1,4,20,0,0,
"log_p1",2,22,23,12,14,2,0,0,0,0,0,0,0,0,23,24,0,
"log_p2",2,23,31,10,12,2,0,0,0,0,0,0,0,0,22,24,0,
"log_p3",2,24,31,10,12,0,0,0,0,0,0,0,0,0,22,23,0,
"alg",1,25,4,12,15,3,7,8,9,36,0,0,1,3,0,0,0,
"b.d",4,26,24,10,12,0,31,32,33,0,0,0,0,2,0,0,0,
"auto_p1",2,27,15,13,15,1,0,0,0,0,0,0,0,0,28,29,0,
"auto_p2",2,28,9,10,12,3,0,0,0,0,0,0,0,0,27,29,0,
"auto_p3",2,29,25,14,16,2,0,0,0,0,0,0,0,0,27,28,0,
"phil",3,30,10,12,14,2,0,0,0,0,0,0,0,2,0,0,0,
"b.d_p1",2,31,17,12,13,0,0,0,0,0,0,0,0,0,32,33,0,
"b.d_p2",2,32,32,13,14,0,0,0,0,0,0,0,0,0,31,33,0,
"b.d_p3",2,33,26,13,14,1,0,0,0,0,0,0,0,0,31,32,0,
"apps",4,34,34,8,10,1,41,42,43,0,0,0,0,4,0,0,0,
"math1",1,35,27,14,16,0,3,4,5,0,0,0,1,4,37,0,0,
"lin",4,36,7,8,10,4,11,12,13,0,0,0,0,3,0,0,0,
"math1",1,37,2,8,10,0,3,4,5,0,0,0,1,4,35,0,0,
"culture",3,38,12,8,10,3,0,0,0,0,0,0,0,2,0,0,0,
"met",3,39,11,10,12,4,0,0,0,0,0,0,0,2,0,0,0,
"ant",3,40,10,8,10,4,0,0,0,0,0,0,0,2,0,0,0,
"apps_p1",2,41,15,10,12,4,0,0,0,0,0,0,0,0,42,43,0,
"apps_p2",2,42,16,12,14,1,0,0,0,0,0,0,0,0,41,43,0,
"apps_p3",2,43,17,14,16,0,0,0,0,0,0,0,0,0,41,42,0,
"yoga",3,44,12,9,11,1,0,0,0,0,0,0,0,2,0,0,0,
"java_p1",2,45,13,11,13,1,0,0,0,0,0,0,0,0,46,47,0,
"java_p2",2,46,16,8,10,2,0,0,0,0,0,0,0,0,45,47,0,
"java_p3",2,47,18,14,16,3,0,0,0,0,0,0,0,0,45,46,0,
"history",3,48,10,11,13,0,0,0,0,0,0,0,0,2,0,0,0,
"c#_p1",2,49,18,8,10,2,0,0,0,0,0,0,0,0,50,51,0,
"c#_p2",2,50,17,9,11,0,0,0,0,0,0,0,0,0,49,51,0,
"c#_p3",2,51,19,13,15,3,0,0,0,0,0,0,0,0,49,50,0,
"crime",3,52,10,14,16,2,0,0,0,0,0,0,0,2,0,0,0,
"ai_p1",2,53,14,10,11,4,0,0,0,0,0,0,0,0,54,55,0,
"ai_p2",2,54,19,11,12,1,0,0,0,0,0,0,0,0,53,55,0,
"ai_p3",2,55,23,12,13,4,0,0,0,0,0,0,0,0,53,54,0,
};

int must=4;
int f_end=0;
int l=0;
void show()
{
	cout<<"sunday                monday               tuesday                wednesday               thursday       "<<endl;
	for(int i=0;i<hours;i++)
	{
		for(int j=0;j<days;j++)
		{
			if(cal[i][j]!=NULL)
			{
				cout<<cal[i][j]->name<<" "<<cal[i][j]->start<<" "<<cal[i][j]->end<<"             ";
			}
			else cout<<"   X                 ";
		}
		cout<<endl;
	}
	cout<<endl;			
}
void unplace(course* c)
{
	for(int i=c->start-8;i<c->end-8;i++)
	    cal[i][c->day]=NULL;
}
void place(course* c)
{
	for(int i=c->start-8;i<c->end-8;i++)
	    cal[i][c->day]=c;
	if(c->rel>0)
	clist[c->rel-1].taken=1;
	if(c->rel2>0)
		clist[c->rel2-1].taken=1;
	if(c->must>=1) must--;
	c->taken=1;	
	for(int i=0;i<3;i++)
	{
		if(c->prev_cource[i]>0)
		{
		   if(clist[c->prev_cource[i]-1].taken==0 && clist[c->prev_cource[i]-1].must==0)
		   {
			   clist[c->prev_cource[i]-1].must=c->num+1;
			   must++;
		   }
		}
	}
}

bool fit(course c)
{
	for(int i=c.start-8;i<c.end-8;i++)
	{
		if(cal[i][c.day]!=NULL)
			return 0;
	}
	return 1;
}

bool req(course c,vector <int> &prof)
{
	vector <int>::iterator i;
	for(i=prof.begin();i<prof.end();i++)
	{
		if(c.pro_num==*i) return 0;
	}
	return 1;
}

int for_check(vector <int> &prof,int *arr)
{
	int sum=0;
	for(int j=0;j<55;j++)
	{
		if(clist[j].taken==1)
			arr[j]=0;
		else arr[j]=1;
		if(arr[j]!=0)
		{
			if(fit(clist[j]) && req(clist[j],prof))
			   arr[j]=1;
			else arr[j]=0;
			if(arr[j]!=0)sum++;
		}
	}
		if(sum==0)
			return 0;
		else return 1;
}

int find_max(int *eur2)
{
	int j,max=-1;
	for(int i=0;i<55;i++)
	{
		if(eur2[i]>max)
		{
			max=eur2[i];
			j=i;
		}
	}
	if(max==-1) return -1;
	else return j;
}

void eur_2(int *arr,int *eur2)
{
	int j=0;
	for(int i=0;i<55;i++)
	{
		if(arr[i]!=0 && clist[i].type!=2) eur2[i]=0;
		else eur2[i]=-1;	    
	}

	for(int i=0;i<55;i++)
	{
		if(eur2[i]==0)
		{
			for(int j=0;j<55;j++)
			{
				if(i!=j && arr[j]==1)
				{
				if(clist[i].pro_num==clist[j].pro_num)
					eur2[i]++;
				else
					if(clist[i].day==clist[j].day)
						if((clist[i].start>clist[j].start && clist[i].start<clist[j].end) ||  (clist[i].end>clist[j].start && clist[i].end<clist[j].end) || (clist[i].start<=clist[j].start && clist[i].end>=clist[j].end))
							eur2[i]++;
				}
			}
		}
	}
	
}
bool build(int points,int num_gen,vector <int> &prof)
{
    int i,result=0,f=0;
	int arr[55],eur2[55];
	if(points==P && must==0 && num_gen>0)
      {
         show();
		f_end=1;
		return 1;
      }
	if(for_check(prof,arr)==0)return 0;
	eur_2(arr,eur2);
        while((i=find_max(eur2))!=-1)
        {	
			place(&clist[i]);
			points+=clist[i].points;
			prof.push_back(clist[i].pro_num);
			if(clist[i].type==3)num_gen++;
			if(clist[i].type==1 || clist[i].type==4)
			{
				for(int j=0;j<3;j++)
				{ 
						if(fit(clist[clist[i].prac[j]-1])&& req(clist[clist[i].prac[j]-1],prof))
						{
							place(&clist[clist[i].prac[j]-1]);
							prof.push_back(clist[clist[i].prac[j]-1].pro_num);
							result=build(points,num_gen,prof);
							if(result==0)
							{
								unplace(&clist[clist[i].prac[j]-1]);
								clist[clist[i].prac[j]-1].taken=0;
								prof.pop_back();
								f=1;
							}
							else 
							{
								f=1;
								break;
							}
						}
						else f=1;
				}	
			}
            if(points==P && must==0 && num_gen>0 && f!=1)
        {
            show();
			f_end=1;
			return 1;
        }
			if(f_end==0)
            if(f!=1)result=build(points,num_gen,prof);
		f=0;
        unplace(&clist[i]);
		eur2[i]=-1;
		points-=clist[i].points;
		prof.pop_back();
			if(clist[i].rel>0)
				clist[clist[i].rel-1].taken=0;
			if(clist[i].rel2>0)
				clist[clist[i].rel2-1].taken=0;
			if(clist[i].type==3)num_gen--;
		for(int j=0;j<3;j++)
			{
				if(clist[i].prev_cource[j]>0)
				{
					if(clist[clist[i].prev_cource[j]-1].taken==0 && clist[clist[i].prev_cource[j]-1].must==clist[i].num+1)
						{
							clist[clist[i].prev_cource[j]-1].must=0;
							must--;
						}
				}
			}
		clist[i].taken=0;
		if(clist[i].must>=1) must++;
		if(result==1)
		return 1;
		}
        
     
    return 0;
}
void main()
{
	vector <int> prof;
	int resul;
	clock_t t;
	t = clock();
	resul=build(0,0,prof);
	cout<<resul<<endl;
	t = clock() - t;
	cout<<"It took "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}

