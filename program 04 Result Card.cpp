#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name;
	int rollNo;
	string Department;
	int English,math,physics;
	int total;
	int Marks;
	float persentage;
	cout<<"Enter Student Name:";
	cin>>name;
	cout<<"Enter roll no:";
	cin>>rollNo;
	cout<<"Enter department:";
	cin>>Department;
	cout<<"Enter mark in english:";
	cin>>English;
	cout<<"Enter mark in math:";
	cin>>math;
	cout<<"Enter mark in physics:";
	cin>>physics;
	total=English+math+physics;
	persentage=(total/300)*100;
	cout<<"=======================================\n";
	cout<<"\tStudent Result Card\n";
	cout<<"=======================================\n";
	cout<<"Subject\t\tMarks\n";
	cin>>English\n;
	cin>>math;
	cin>>physics;
	cout<<"Name:\t\t"<<name<<endl;
	cout<<"RollNo:\t\t"<<rollNo<<endl;
	cout<<"Department:\t"<<Department<<endl;
	cout<<"=======================================\n";
	cout<<"Total Marks:"<<total<<"/300\n";
	cout<<"Persentage:\t"<<persentage<<"%\n";
	cout<<"Grade:\t\tA+\n";
	cout<<"congratulations"<<name<<"!\n";
	cout<<"=======================================\n";
	
	
	 
}
