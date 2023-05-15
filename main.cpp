#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;



void readStudentData(ifstream &rss, int scores[], int id[], int &count, bool &tooMany);
float mean(int scores[], int count);
void printGrade(int oneScore, float average);
void printTable(int id[], int scores[], int count);

const int MAX_SIZE = 5; 

int main() {
	ifstream rss;
	int scores[MAX_SIZE];
	int id[MAX_SIZE];
	int i , count = 0;
	float average = 0;
	int oneScore=0;
	bool tooMany;
	string grades;
	int avg=0;
	rss.open("scores.txt");
	cout<< "Student IDs"<< setw(17)<<"Score"<< setw(17)<< "Grade"<< endl;
	readStudentData(rss,scores,id,count,tooMany);
    if(tooMany=true){
    printTable(id,scores,count);
}
cout<<"Average score: " <<mean(scores,count)<< "%";
}

void printTable(int id[], int scores[], int count){
    int i;
    int oneScore;
    float average=mean(scores,count);;
    for(i=0; i<5; ++i){
    cout << id[i] <<setw(17) << scores[i];
    cout<<"             ";
    printGrade(scores[i], average);
    cout<< endl;
    }
}
void printGrade(int oneScore, float average){
    if(oneScore>average+10) {
        cout<<"Outstanding";
    } 
    else if(oneScore<average-10) {
        cout<<"UnSatisfactory";
    }else {
        cout<<"Satisfactory";
    }
}

float mean(int scores[], int count) {
	int id[MAX_SIZE];
	int sum = 0;
	float average;
	for(int i = 0; i <MAX_SIZE; i++) {
	sum += scores[i];
	count++;
}
	average = sum / MAX_SIZE;
return average;
}

void readStudentData(ifstream &rss, int scores[], int id[], int &count, bool &tooMany) {
int studentID;
int studentScores;
rss>>studentID;
rss>>studentScores;
while (count < MAX_SIZE) {
	id[count] = studentID;
	scores[count] = studentScores;
    count++;
	rss>>studentID>>studentScores;

if (count > MAX_SIZE) {
	tooMany = true;
}
	else 
	tooMany = false;
}
}
