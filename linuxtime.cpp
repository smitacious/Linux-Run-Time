#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void work(void) //function to creat loop
{
	//looping variables
	
	double y;
	double x = 3.0;
	double e = 2.0;
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<400000; j++0)
		{
			y = pow(x,e);
		} // ends j loop
		
		printf("Loop %d of work cycle\n", i); /* pauses for one sceond between loops
												 so that the work cycle takes a little time */
		sleep(1); /* if attempting to run this function in c++
					 you will need to include unistd.h */
					 
	} // ends i loop
} // ends work()

int main(void)
{
	//variables to be used
	
	double beginTotalTime;
	double beginIdleTime;
	double endTotalTime;
	double endIdleTime;
	double programTotalTime = 0.0;
	double programIdelTime=0.0;
	double programWorkTime=0.0;
	double percentage =0.0;
	
	cout<<"\nHere is the beginTotalTime * beginIdleTime:"<<endl;
	
	//opening a stream to gather information from "/proc/uptime"
	ifstream uptime("/proc/uptime");
	uptime>>beginTotalTime>>beginIdleTime; //capturing values
	uptime.close(); //closes the stream
	
	//setting information to the hundreth decimal position & printing information
	cout<<fixed<<setprecision(2)<<beginTotalTime<<"   "<<beginIdleTime<<"\n"<<endl;
	
	work() //calls the function to create the loop
	
	cout<<"\nHere is the endTotalTime * endIdleTime:"<<endl;
	uptime.open("/proc/uptime");
	uptime>>endTotalTime<<endIdleTime;
	uptime.close();
	cout<<endTotalTime<<"   "<<endIdleTime<<"\n"<<endl;
	
	//calculating portion
	
	programTotalTime = endTotalTime - beginTotalTime;
	programIdelTime = endIdleTime - beginIdleTime;
	programWorkTime = programTotalTime - programIdelTime;
	percentage = (programWorkTime / programTotalTime) * 100;
	
	//final screen output 
	cout<<"The program's total time is: "<<programTotalTime<<endl;
	cout<<"The program's idle time is: "<<programIdelTime<<endl;
	cout<<"The program's work time is: "<<programWorkTime<<endl;
	cout<<"The percentage the CPU was busy is: "<<percentage<<endl;
	
	return 0;
} //ends main()
	