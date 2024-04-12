
#include<string>
#include<iostream>
using namespace std;
class Base{
	public:
	string name;
	int roll_no;
	//Constructor
	Base(){
	name="Null";
	roll_no=0;
	}
	
	virtual void Accept_Internal_assissment()=0;
	virtual void Accept_University_Examination_Mark()=0;
};

class Derived: public Base{
	public:
		 string subject[5];
		 string subject_code[5];
		 int i,ch,pos,flag=0,internal_assissment[5],university_examination_mark[5],total[5],cia1[5],cia2[5],cia3[5],cia[5];
	
		Derived()
		{
			for(i=0;i<5;i++)
			{
				subject[i]="Null";
				subject_code[i]="Null";
				internal_assissment[i]=0;
				university_examination_mark[i]=0;
			}
		}
		void Accept_student_Details(){		//Pure virtual function
			cout<<"Enter your name : ";
			cin>>name;
			cout<<"Enter roll no.: ";
			cin>>roll_no;
		}
			
		void Accept_Subject_details(){
			cout<<"Enter your 5 subject name : ";
			for(i=0;i<5;i++)
			cin>>subject[i];
			cout<<"Enter subject code for subject"<<endl;
			for(i=0;i<5;i++)
			{
				cout<<"Enter subject code of "<<subject[i]<<" subject : ";
				cin>>subject_code[i];
			}	
		}
		
		void Accept_Internal_assissment(){		//Pure virtual function
			cout<<"Enter mark of interal assessment: "<<endl;
			
			for(i=0;i<5;i++)
			{
				cout<<"Enter interal assessment mark of "<<subject[i]<<" subject : "<<endl;
				cout<<"Enter the mark of 1st CIA(out of 20): ";
				cin>>cia1[i];
				cout<<"Enter the mark of 2nd CIA(out of 20): ";
				cin>>cia2[i];
				cout<<"Enter the mark of 3rd CIA(out of 20): ";
				cin>>cia3[i];
				cout<<"Enter the mark of Self Learing Activity(out of 20): ";
				cin>>cia[i];
				total[i]+=cia1[i]+cia2[i]+cia3[i];
				total[i]=total[i]/3;
				internal_assissment[i]=total[i]+cia[i];
			}	
		}
		
		void Accept_University_Examination_Mark(){		//Pure virtual function
			cout<<"Enter mark of University Examination: "<<endl;
			for(i=0;i<5;i++)
			{
				cout<<"Enter University Examination mark of "<<subject[i]<<" subject : ";
				cin>>university_examination_mark[i];
			}	
		}
		
		void Display(){
			cout<<"||Student name: "<<name<<endl;
			cout<<"||Roll No.: "<<roll_no<<endl;
			cout<<"||University Result :"<<endl;
			cout<<"\n||Subject||Subject Code || Internal Assissment  ||Examination mark||\tTotal\t||"<<endl;
			for(i=0;i<5;i++)
			cout<<"||"<<subject[i]<<"\t ||\t"<<subject_code[i]<<"\t||\t"<<internal_assissment[i]<<"\t\t||\t"<<university_examination_mark[i]<<"\t  ||\t"<<internal_assissment[i]+university_examination_mark[i]<<"\t||"<<endl;
			
		}
		
		//Edit Data
		void Edit_Data()
		{
			cout<<"1: Edit Name\n2: Edit Roll no\n3: Edit Internal Assissment Mark\n4: Edit University Examination Mark\n5: Edit Subject Name\n6: Edit Subject Code\nEnter Your Choice: ";
			cin>>ch;
			string old_name,new_name;
			int old_roll_no,new_roll_no;
			string temp_subject;
			string temp_code;
			int temp_mark;
			switch(ch)
			{
				case 1:
				cout<<"Edit Name"<<endl;
					cout<<"Enter New Name: ";
					cin>>new_name;
					name=new_name;
					cout<<"Successfully Done!"<<endl;	
				break;
				
				case 2:
				cout<<"Edit Roll no"<<endl;
					cout<<"Enter New Roll no: ";
					cin>>new_roll_no;
					roll_no=new_roll_no;
					cout<<"Successfully Done!"<<endl;
				break;
				
				case 3:
					cout<<"Edit Internal Assissment Mark"<<endl;
					cout<<"Enter Subject Name: ";
					cin>>temp_subject;
					for(i=0;i<5;i++)
					{	
						if(subject[i]==temp_subject)
						{
							pos=i;
							flag=1;
							break;
						}
					}
					if(flag==1)
					{
					int temp_mark;
						cout<<"Enter Mark: ";
						cin>>temp_mark;
						internal_assissment[pos]=temp_mark;
						cout<<"Successfully Done!"<<endl;
					}
					else
					cout<<"Not Found!";
						flag=0;
					
				break;
				
				case 4:
					cout<<"Edit University Examination Mark"<<endl;
					cout<<"Enter Subject Name: ";
					cin>>temp_subject;
					for(i=0;i<5;i++)
					{	
						if(subject[i]==temp_subject)
						{
							pos=i;
							flag=1;
							break;
						}
					}
					if(flag==1)
					{
						cout<<"Enter Mark: ";
						cin>>temp_mark;
						university_examination_mark[pos]=temp_mark;
						cout<<"Successfully Done!"<<endl;
					}
					else
					cout<<"Not Found!";
						flag=0;
					
				break;
				
				case 5:
					cout<<"Edit Subject Name";
					cout<<"Enter Old name of Subject: ";
					cin>>temp_subject;
					for(i=0;i<5;i++)
					{	
						if(subject[i]==temp_subject)
						{
							pos=i;
							flag=1;
							break;
						}
					}
					if(flag==1)
					{
						cout<<"Enter new name of subject: ";
						cin>>temp_subject;
						subject[pos]=temp_subject;
						cout<<"Successfully Done!"<<endl;
					}
					else
					cout<<"Not Found!";
						flag=0;
				break;
				
				case 6:
					cout<<"Edit Subject Code";
					cout<<"Enter Subject Name: ";
					cin>>temp_subject;
					for(i=0;i<5;i++)
					{	
						if(subject[i]==temp_subject)
						{
							pos=i;
							flag=1;
							break;
						}
					}
					if(flag==1)
					{
					//int temp_mark;
						cout<<"Enter New code for Subject: ";
						cin>>temp_code;
						subject_code[pos]=temp_code;
						cout<<"Successfully Done!"<<endl;
					}
					else
					cout<<"Not Found!";
					//Set Flag Again to zero
						flag=0;
				break;
				
				default:
					cout<<"Wrong Choice!"<<endl;
			}
		}
		
		
};

int main(){
	Derived obj[10];
	int ch,choice,i,n,rn,flag=0,pos=0;
	
	
	cout<<"Enter the number of student: ";
	cin>>n;
do{
	
	cout<<"Menu\n1: Insert Data of Student\n2: Enter Subject Name\n3: Enter Internal Assissment Mark\n4: Enter University Examination Mark\n5: Display Data\n6: Edit Data\n7: Search for Record\nEnter your choice: ";
	cin>>ch;
	
	switch(ch){
	case 1:
		for(i=0;i<n;i++)
		{
			obj[i].Accept_student_Details();
		}
	break;
	
	case 2:
			for(i=0;i<n;i++)
		{
			obj[i].Accept_Subject_details();
		}
	break;
	
	case 3:
		cout<<"Internal Assissment Mark!"<<endl;
		cout<<"Enter Roll no whose Data do you want to insert: ";
		cin>>rn;
		for(i=0;i<n;i++)
		{
			if(obj[i].roll_no==rn)
			{
				pos=i;
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			obj[pos].Accept_Internal_assissment();
		}
		else
		cout<<"Not Found!"<<endl;
		
		flag=0;  
	break;
	
	case 4:
		cout<<"University Examination  Mark!"<<endl;
		cout<<"Enter Roll no whose Data do you want to insert: ";
		cin>>rn;
		for(i=0;i<n;i++)
		{
			if(obj[i].roll_no==rn)
			{
				pos=i;
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			obj[pos].Accept_University_Examination_Mark();
		}
		else
		cout<<"Not Found!"<<endl;
		
		flag=0;  
	break;
	
	case 5:
		for(i=0;i<n;i++)
		{
			obj[i].Display();
		}
	break;
	
	case 6:
		cout<<"Edit Data!"<<endl;
		cout<<"Enter Roll no whose Data want to update: ";
		cin>>rn;
		for(i=0;i<n;i++)
		{
			if(obj[i].roll_no==rn)
			{
				pos=i;
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			obj[pos].Edit_Data();
		}
		else
		cout<<"Not Found!"<<endl;
		
		flag=0;  
        	break;
	
	case 7:
		cout<<"Search for Record"<<endl;
		cout<<"Enter Roll no whose Data want to Search: ";
		cin>>rn;
		for(i=0;i<n;i++)
		{
			if(obj[i].roll_no==rn)
			{
				pos=i;
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			obj[pos].Display();
		}
		else
		cout<<"Not Found!"<<endl;
		
		flag=0;  
	break;
	
	default :
	cout<<"Wrong Choice!"<<endl;
	}
	cout<<"Do you want to Continue\n1:Yes\n2:No\nChoice: ";
	cin>>ch;
	}while(ch==1);
		
	return 0;
}
