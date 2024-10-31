#include<iostream>
#include<iomanip>
using namespace std;
struct fcfs{
	int burst,arrival,id,completion,waiting,turnaround,response;
	
};
fcfs meh[30];
class FCFS{
	public:
		int n;
		void fcfsIn(){
			cout<<"\nenter number of process";
			cin>>n;
			for(int i=0;i<n;i++){
				cout<<"\nenter arrival time of p"<<i<<":";
				cin>>meh[i].arrival;
				cout<<"\nenter burst time of p"<<i<<":";
				cin>>meh[i].burst;
				meh[i].id=i;
			}
			cout<<"\n|arrival|burst\n";
			for(int j=0;j<n;j++){
				cout<<"P"<<"|"<<meh[j].arrival<<"|"<<meh[j].burst<<"\n";
				
			}
		}
		void process(){
			cout<<"\nsequence of process is:";
			int currentTime=0;
			for(int i=0;i<n;i++){
				if(currentTime<meh[i].arrival){
					while(currentTime<meh[i].arrival){
						cout<<"NULL";
						currentTime++;
						
					}
				}
				meh[i].response=currentTime-meh[i].arrival;
				cout<<"P"<<meh[i].id<<"";
				currentTime+=meh[i].burst;
				meh[i].completion=currentTime;
				meh[i].turnaround=meh[i].completion-meh[i].arrival;
				meh[i].waiting=meh[i].turnaround-meh[i].burst;
			}
			
		}
		void displayGantChart(){
			cout<<"\n\nGantChart:\n";
			int currentTime=0;
			for(int i=0;i<n;i++){
				if(currentTime<meh[i].arrival){
					while(currentTime<meh[i].arrival){
						cout<<"| NULL";
						currentTime++;
						
					}
				}
				cout<<"|P"<<meh[i].id<<"";
				currentTime+=meh[i].burst;
			}
			cout<<"|\n";
			currentTime=0;
			cout<<"0";
			for(int i=0;i<n;i++){
				if(currentTime<meh[i].arrival){
					while(currentTime<meh[i].arrival){
						cout<<"";
						currentTime++;
						
					}
					
				}
				currentTime+=meh[i].burst;
				cout<<setw(5)<<currentTime;
				
				
			}
			cout<<"\n";
			
		}
		void displaymetrics(){
			double totalwaiting=0,totalturnaround=0,totalcompletion=0;
			cout<<"\n\n|completion time|waitingtime|turnaroundtime|responsetime\n";
			for(int j=0;j<n;j++){
				totalwaiting+=meh[j].waiting;
				totalturnaround+=meh[j].turnaround;
				totalcompletion+=meh[j].completion;
				cout<<"P"<<j<<"|"<<setw(15)<<meh[j].completion<<"|"<<setw(12)<<meh[j].waiting<<"|"<<setw(15)<<meh[j].turnaround<<"|"<<setw(12)<<meh[j].response<<"\n";
				
			
				
			}
			cout<<"\nAverage completion time:"<<totalcompletion/n;
			cout<<"\nAverage waiting time:"<<totalwaiting/n;
			cout<<"\nAverage turnaround time:"<<totalturnaround/n;
			
		}
		
};
int main(){
	FCFS obj;
	obj.fcfsIn();
	obj.process();
	obj.displayGantChart();
	obj.displaymetrics();
	return 0;
}
