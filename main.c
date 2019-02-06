#include <stdio.h>
//#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Structs.h"

void printCR();
void printCP();
void printSNAP();
void printCDH();
void insertSnap();
void insertCp();
void insertCdh();
void insertCr();
void insertCsg();
void deleteCr();
void deleteCP();
tlistCP lookupCp();
void saveSnap();
void saveCsg();
void saveCr();
void saveCp();
void saveCdh();
void GrNinC();
void WhNaToD();


SNAP snap[3][20];
CP cp[8][20];
CDH cdh[6][20];
CR cr[3][20];
CSG csg[6][20];

void printSNAP() {
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (snap[i][j].ID != NULL) {
				SNAP s = snap[i][j];
				printf("\n ID: %d", s.ID);
				printf("\n name: %s", s.name);
				printf("\n address: %s", s.address);
				printf("\n phone: %s", s.phNum);
			}
		}
	}
}

void printCP() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			if(cp[i][j].course != NULL) {
				CP C = cp[i][j];
				printf("\n course: %s", C.course);
				printf("\n prerequisite: %s", C.prereq);
			}
		}
	}
}

void printCR() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (cr[i][j].course != NULL) {
				CR C = cr[i][j];
				printf("\n course: %s", C.course);
				printf("\n room: %s", C.room);
			}
		}
	}
}

void printCDH() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			if (cdh[i][j].course != NULL) {
				CDH C = cdh[i][j];
				printf("\n course: %s", C.course);
				printf("\n day: %s", C.day);
				printf("\n hour: %s", C.hour);
			}
		}
	}
}

void printCSG() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j ++) {
			if (csg[i][j].course != NULL) {
				CSG C = csg[i][j];
				printf("\n course: %s", C.course);
				printf("\n ID: %d", C.ID);
				printf("\n grade: %s", C.grade);
			}
		}
	}
}

bool containsSnap(int studID) {
	int hash = studID % 3;
	int i = 0;
	while (snap[hash][i].ID != NULL) {
		if (snap[hash][i].ID == studID) {
			return true;
		}
		i++;
	}
	return false;
}

void insertSnap(int studentID, char *Name, char *Address, char *Pnumber) {
	if (containsSnap(studentID) == true) {
	}
	else {
		int hash = studentID % 3;
		int i = 0;
		while (snap[hash][i].ID != NULL) {
			i++;
		}
		SNAP s = { studentID, Name, Address, Pnumber };
		snap[hash][i] = s;
	}
}
int addLetters(char *s) {
	int sum = 0;
	for (int i = 0; i < strlen(s); i++) {
		sum += s[i];
	}
	return sum;
}
bool containsCp(char *Course, char *prerequisite) {
	int sum = addLetters(Course);
	int hash = sum % 8;
	int i = 0;
	while (cp[hash][i].course != NULL) {
		if (cp[hash][i].course == Course && cp[hash][i].prereq == prerequisite) {
			return true;
		}
		i++;
	}
	return false;
}

void insertCp(char *Course, char *prerequisite) {
	if (containsCp(Course, prerequisite) == true) {
	}
	else {
		int sum = addLetters(Course);
		int hash = sum % 8;
		int i = 0;
		while (cp[hash][i].course != NULL) {
			i++;
		}
		CP c = { Course, prerequisite };
		cp[hash][i] = c;
	}
}
bool containsCdh(char *Course, char *Day) {
	int sum = addLetters(Course);
	int hash = sum % 6;
	int i = 0;
	while (cdh[hash][i].course != NULL) {
		if (cdh[hash][i].course == Course && cdh[hash][i].day == Day) {
			return true;
		}
		i++;
	}
	return false;
}

void insertCdh(char *Course, char *Day, char *hour) {
	if (containsCdh(Course, Day) == true) {

	}
	else {
		int sum = addLetters(Course);
		int hash = sum % 6;
		int i = 0;
		while (cdh[hash][i].course != NULL) {
			i++;
		}
		CDH c = { Course, Day, hour };
		cdh[hash][i] = c;
	}
}

bool containsCSG(char *Course, int studID) {
	int sum = addLetters(Course);
	int hash = sum % 6;
	int i = 0;
	while (csg[hash][i].course != NULL) {
		if (csg[hash][i].course == Course && csg[hash][i].ID == studID) {
			return true;
		}
		i++;
	}
	return false;
}

void insertCsg(char *Course, int studentID, char *Grade) {
	if (containsCSG(Course, studentID) == true) {

	}
	else {
		int sum = addLetters(Course);
		int hash = sum % 6;
		int i = 0;
		while (csg[hash][i].course != NULL) {
			i++;
		}
		CSG c = { Course, studentID, Grade };
		csg[hash][i] = c;
	}
}

bool containsCr(char *Course, char *Room) {
	int sum = addLetters(Course);
	int hash = sum % 3;
	int i = 0;
	while (cr[hash][i].course != NULL) {
		if (cr[hash][i].course == Course && cr[hash][i].room == Room) {
			return true;
		}
		i++;
	}
	return false;
}

void insertCr(char *Course, char *Room) {
	if (containsCr(Course, Room) == true) {
	}
	else {
		int sum = addLetters(Course);
		int hash = sum % 3;
		int i = 0;
		while (cr[hash][i].course != NULL) {
			i++;
		}
		CR c = { Course, Room };
		cr[hash][i] = c;
	}
}

void deleteSnap(int studID, char *Name, char *Address, char *Phone) {
	if (studID != 0) {
		int hash = studID % 3;
		int j = 0;
		while (snap[hash][j].ID != NULL) {
			if (snap[hash][j].ID == studID) {
				snap[hash][j].ID = NULL;
				snap[hash][j].name = NULL;
				snap[hash][j].address = NULL;
				snap[hash][j].phNum = NULL;
			}
			j++;
		}
	}
	else if (Name != "*" && Address != "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].address == Address && snap[i][j].phNum == Phone) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name == "*" && Address != "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].address != NULL) {
				if (snap[i][j].address == Address && snap[i][j].phNum == Phone) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name != "*" && Address == "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].phNum == Phone) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name != "*" && Address != "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].address == Address) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name == "*" && Address == "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].phNum != NULL) {
				if (snap[i][j].phNum == Phone) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name != "*" && Address == "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else if (Name == "*" && Address != "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].address != NULL) {
				if (snap[i][j].address == Address) {
					snap[i][j].ID = NULL;
					snap[i][j].name = NULL;
					snap[i][j].address = NULL;
					snap[i][j].phNum = NULL;
				}
				j++;
			}
		}
	}
	else {
		printf("\n The information given is incorrect for deleting");
	}
}


void deleteCr(char *Course, char *Room) {
	if (Course != "*" && Room != "*") {
		int sum = addLetters(Course);
		int hash = sum % 3;
		int j = 0;
		while (cr[hash][j].course != NULL) {
			if (cr[hash][j].course == Course && cr[hash][j].room == Room) {
				cr[hash][j].course = NULL;
				cr[hash][j].room = NULL;
			}
			j++;
		}
	}
	else if (Course == "*") {
		for (int j = 0; j < 3; j++) {
			int i = 0;
			while (cr[j][i].course != NULL) {
				if (cr[j][i].room == Room) {
					cr[j][i].course = NULL;
					cr[j][i].room = NULL;
				}
				i++;
			}
		}
	}
	else {
		for (int j = 0; j < 3; j++) {
			int i = 0;
			while (cr[j][i].course != NULL) {
				if (cr[j][i].course == Course) {
					cr[j][i].course = NULL;
					cr[j][i].room = NULL;
				}
				i++;
			}
		}
	}
}

void deleteCp(char *Course, char *PreR) {
	if (Course != "*" && PreR != "*") {
		int sum = addLetters(Course);
		int hash = sum % 8;
		int j = 0;
		while (cp[hash][j].course != NULL) {
			if (cp[hash][j].course == Course && cp[hash][j].prereq == PreR) {
				cp[hash][j].course = NULL;
				cp[hash][j].prereq = NULL;
			}
			j++;
		}
	}
	else if (Course == "*") {
		for (int j = 0; j < 8; j++) {
			int i = 0;
			while (cp[j][i].course != NULL) {
				if (cp[j][i].prereq == PreR) {
					cp[j][i].course = NULL;
					cp[j][i].prereq = NULL;
				}
				i++;
			}
		}
	}
	else {
		printf("\n it gets there");
		for (int j = 0; j < 8; j++) {
			int i = 0;
			while (cp[j][i].course != NULL) {
				if (cp[j][i].course == Course) {
					cp[j][i].course = NULL;
					cp[j][i].prereq = NULL;
				}
				i++;
			}
		}
	}
}

void deleteCSG(char *Course, int studID, char *Grade) {
	if (Course != "*" && studID != 0) {
		printf("\n it is deleting");
		int sum = addLetters(Course);
		int hash = sum % 6;
		int j = 0;
		while (csg[hash][j].course != NULL) {
			if (csg[hash][j].course == Course && csg[hash][j].ID == studID) {
				csg[hash][j].course = NULL;
				csg[hash][j].ID = NULL;
				csg[hash][j].grade = NULL;
				printf("\n deletes");
			}
			j++;
		}
	}
	else if (Course == "*" && studID != 0) {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].course != NULL) {
				if (csg[i][j].ID == studID) {
					csg[i][j].course = NULL;
					csg[i][j].ID = NULL;
					csg[i][j].grade = NULL;
				}
				j++;
			}
		}
	}
	else if (Course == "*" && studID == 0) {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].grade != NULL) {
				if (csg[i][j].grade == Grade) {
					csg[i][j].course = NULL;
					csg[i][j].ID = NULL;
					csg[i][j].grade = NULL;
				}
				j++;
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].course != NULL) {
				if (csg[i][j].course == Course) {
					csg[i][j].course = NULL;
					csg[i][j].ID = NULL;
					csg[i][j].grade = NULL;
				}
				j++;
			}
		}
	}
}

void deleteCDH(char *Course, char *Day, char *Hour) {
	if (Course != "*" && Day != "*") {
		printf("\n it is deleting");
		int sum = addLetters(Course);
		int hash = sum % 6;
		int j = 0;
		while (cdh[hash][j].course != NULL) {
			if (cdh[hash][j].course == Course && cdh[hash][j].day == Day) {
				cdh[hash][j].course = NULL;
				cdh[hash][j].day = NULL;
				cdh[hash][j].hour = NULL;
				printf("\n deletes");
			}
			j++;
		}
	}
	else if (Course == "*" && Day != "*") {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (cdh[i][j].course != NULL) {
				if (cdh[i][j].day == Day) {
					cdh[i][j].course = NULL;
					cdh[i][j].day = NULL;
					cdh[i][j].hour = NULL;
				}
				j++;
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (cdh[i][j].course != NULL) {
				if (cdh[i][j].course == Course) {
					cdh[i][j].course = NULL;
					cdh[i][j].day = NULL;
					cdh[i][j].hour = NULL;
				}
				j++;
			}
		}
	}
}

SNAP lookupSnap(int studID, char *Name, char *Address, char *Phone) {
	SNAP look = { NULL, NULL, NULL, NULL };
	if (studID != 0) {
		int hash = studID % 3;
		int j = 0;
		while (snap[hash][j].ID != NULL) {
			if (snap[hash][j].ID == studID) {
				look = snap[hash][j];
			}
			j++;
		}
		return look;
	}
	else if (Name != "*" && Address != "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].address == Address && snap[i][j].phNum == Phone) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name == "*" && Address != "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].address != NULL) {
				if (snap[i][j].address == Address && snap[i][j].phNum == Phone) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name != "*" && Address == "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].phNum == Phone) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name != "*" && Address != "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name && snap[i][j].address == Address) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name == "*" && Address == "*" && Phone != "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].phNum != NULL) {
				if (snap[i][j].phNum == Phone) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name != "*" && Address == "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].name != NULL) {
				if (snap[i][j].name == Name) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else if (Name == "*" && Address != "*" && Phone == "*") {
		for (int i = 0; i < 3; i++) {
			int j = 0;
			while (snap[i][j].address != NULL) {
				if (snap[i][j].address == Address) {
					look = snap[i][j];
				}
				j++;
			}
		}
		return look;
	}
	else {
		printf("\n The information given is incorrect for deleting");
		return look;
	}
}
tlistCSG lookupCSG(char *Course, int studID, char *Grade) {
	tlistCSG look = { NULL };
	int c = 0;
	if (Course != "*" && studID != 0) {
		int sum = addLetters(Course);
		int hash = sum % 6;
		int j = 0;
		while (csg[hash][j].course != NULL) {
			if (csg[hash][j].course == Course && csg[hash][j].ID == studID) {
				look.list[c] = csg[hash][j];
				c++;
			}
			j++;
		}
		return look;
	}
	else if (Course == "*" && studID != 0) {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].course != NULL) {
				if (csg[i][j].ID == studID) {
					look.list[c] = csg[i][j];
					c++;
				}
				j++;
			}
		}
		return look;
	}
	else if (Course == "*" && studID == 0) {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].grade != NULL) {
				if (csg[i][j].grade == Grade) {
					look.list[c] = csg[i][j];
					c++;
				}
				j++;
			}
		}
		return look;
	}
	else {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (csg[i][j].course != NULL) {
				if (csg[i][j].course == Course) {
					look.list[c] = csg[i][j];
					c++;
				}
				j++;
			}
		}
		return look;
	}
}

tlistCDH lookupCDH(char *Course, char *Day, char *Hour) {
	tlistCDH look = { NULL };
	int c = 0;
	if (Course != "*" && Day != "*") {
		printf("\n it is deleting");
		int sum = addLetters(Course);
		int hash = sum % 6;
		int j = 0;
		while (cdh[hash][j].course != NULL) {
			if (cdh[hash][j].course == Course && cdh[hash][j].day == Day) {
				look.list[c] = cdh[hash][j];
				c++;
			}
			j++;
		}
		return look;
	}
	else if (Course == "*" && Day != "*") {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (cdh[i][j].course != NULL) {
				if (cdh[i][j].day == Day) {
					look.list[c] = cdh[i][j];
					c++;
				}
				j++;
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			int j = 0;
			while (cdh[i][j].course != NULL) {
				if (cdh[i][j].course == Course) {
					look.list[c] = cdh[i][j];
					c++;
				}
				j++;
			}
		}
		return look;
	}
}

CR lookupCr(char *Course, char *Room) {
	CR look = { NULL, NULL };
	if (Course != "*" && Room != "*") {
		int sum = addLetters(Course);
		int hash = sum % 3;
		int j = 0;
		while (cr[hash][j].course != NULL) {
			if (cr[hash][j].course == Course && cr[hash][j].room == Room) {
				look = cr[hash][j];
			}
			j++;
		}
		return look;
	}
	else if (Course == "*") {
		for (int j = 0; j < 3; j++) {
			int i = 0;
			while (cr[j][i].course != NULL) {
				if (cr[j][i].room == Room) {
					look = cr[j][i];
				}
				i++;
			}
		}
		return look;
	}
	else {
		for (int j = 0; j < 3; j++) {
			int i = 0;
			while (cr[j][i].course != NULL) {
				if (cr[j][i].course == Course) {
					look = cr[j][i];
				}
				i++;
			}
		}
		return look;
	}
}

tlistCP lookupCp(char *Course, char *PreR) {
	tlistCP look = { NULL };
	int c = 0;
	if (Course != "*" && PreR != "*") {
		int sum = addLetters(Course);
		int hash = sum % 8;
		int j = 0;
		while (cp[hash][j].course != NULL) {
			if (cp[hash][j].course == Course && cp[hash][j].prereq == PreR) {
				look.list[c] = cp[hash][j];
				c++;
			}
			j++;
		}
		return look;
	}
	else if (Course == "*") {
		for (int j = 0; j < 8; j++) {
			int i = 0;
			while (cp[j][i].course != NULL) {
				if (cp[j][i].prereq == PreR) {
					look.list[c] = cp[j][i];
					c++;
				}
				i++;
			}
		}
		return look;
	}
	else {
		printf("\n it gets there");
		for (int j = 0; j < 8; j++) {
			int i = 0;
			while (cp[j][i].course != NULL) {
				if (cp[j][i].course == Course) {
					look.list[c] = cp[j][i];
					c++;
				}
				i++;
			}
		}
		return look;
	}
}

CSG selectEX1[6];

void Example1() {
	int sum = addLetters("CS101");
	int hash = sum % 6;
	int j = 0;
	int i = 0;
	while (csg[hash][j].course != NULL) {
		if (csg[hash][j].course == "CS101") {
			selectEX1[i].course = csg[hash][j].course;
			selectEX1[i].ID = csg[hash][j].ID;
			selectEX1[i].grade = csg[hash][j].grade;
			i++;
		}
		j++;
	}
}

int projID[6];//pointer for student Ids for example 2 part 3
//we reuse the list of tuples from example one which is saved as a global variable, this makes it a lot less code and more clear
void Example2() {
	Example1();
	for (int i = 0; i < 3; i++) {
		projID[i] = selectEX1[i].ID;
	}
}

void printEx1() {
	int i = 0;
	while (selectEX1[i].course != NULL) {
		printf("\n Course: %s", selectEX1[i].course);
		printf("\n StudentID: %d", selectEX1[i].ID);
		printf("\n Grade: %s", selectEX1[i].grade);
		i++;
	}
}

void printEx2() {
	int i = 0;
	for(int i = 0; i < 3; i++){
		printf("\n studentID: %d", projID[i]);
	}
}

CRDH join[6];//array of structure for new joint tble of CR and CDH cuz it wont allow return function for 

void Example3() {
	int count = 0;//counting done for adding tuples to new joint tabke of CR and CDH
	for (int hval = 0; hval < 3; hval++) {
		int i = 0; 
		while(cr[hval][i].course != NULL){//have to check if there is a tuple in the bucket and stop when there are empty buckets
			char *C = cr[hval][i].course;
			int sum = addLetters(C);
			int hash = sum % 6;//hash by size of CDH
			int j = 0;
			printf("\n course: %s", C);
			while (cdh[hash][j].course != NULL) {//checking if it exists and traversing the buckets at the specific index
				if (cdh[hash][j].course == cr[hval][i].course) {
					CRDH c = { cdh[hash][j].course, cr[hval][i].room, cdh[hash][j].day, cdh[hash][j].hour };
					join[count] = c;
					count++;//increase index of array of new joint table
				}
				j++;//traverse bucket
			}
			i++;
		}
	}
}

void printEx3() {
	for (int i = 0; i < 6; i++) {
		printf("\n course: %s", join[i].course);
		printf("\n room: %s", join[i].room);
		printf("\n day: %s", join[i].day);
		printf("\n hour: %s", join[i].hour);
	}
}

DH DaysHours[3];

void Example4() {
	Example3();
	int j = 0;
	for (int i = 0; i < strlen(join); i++) {
		if (join[i].room == "Turing Aud.") {
			DH d = { join[i].day, join[i].hour };
			DaysHours[j] = d;
			j++;
		}
	}
}

void printEx4() {
	for (int i = 0; i < 3; i++) {
		printf("\n Day: %s", DaysHours[i].day);
		printf("\n Hour: %s", DaysHours[i].hour);
	}
}


int main() {
	printf("\n SNAP:");
	insertSnap(12345, "C. Brown", "12 Apple St.", "555-1234");
	insertSnap(67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
	insertSnap(22222, "P. Patty", "56 Grape Blvd.", "555-9999");
	printSNAP();
	printf("\n");
	
	printf("\n CP:");
	insertCp("CS101", "CS100");
	insertCp("EE200", "EE005");
	insertCp("EE200", "CS100");
	insertCp("CS120", "CS101");
	insertCp("CS121", "CS120");
	insertCp("CS205", "CS101");
	insertCp("CS206", "CS121");
	insertCp("CS206", "CS205");
	printCP();
	printf("\n");
	
	printf("CDH: ");
	insertCdh("CS101", "M", "9AM");
	insertCdh("CS101", "W", "9AM");
	insertCdh("CS101", "F", "9AM");
	insertCdh("EE200", "Tu", "10AM");
	insertCdh("EE200", "W", "1PM");
	insertCdh("EE200", "Th", "10AM");
	printCDH();
	printf("\n");

	printf("\n CSG:");
	insertCsg("CS101", 12345, "A");
	insertCsg("CS101", 67890, "B");
	insertCsg("EE200", 12345, "C");
	insertCsg("EE200", 22222, "B+");
	insertCsg("CS101", 33333, "A-");
	insertCsg("PH100", 67890, "C+");
	printCSG();
	
	printf("\n CR");
	insertCr("CS101", "Turing Aud.");
	insertCr("EE200", "25 Ohm Hall");
	insertCr("PH100", "Newton Lab");
	printCR();

	printf("\n lookup CS101, 12345, *, (CSG)");
	tlistCSG l1 = lookupCSG("CS101", 12345, "*");
	char *g = l1.list[0].grade;
	printf("\n grade: %s", g);

	printf("\n lookup CS205, CS120, (CP)");
	tlistCP l2 = lookupCp("CS205", "CS120");
	char *c = l2.list[0].course;
	char *p = l2.list[0].prereq;
	printf("\n Course: %s", c);
	printf("\n Prereq: %s", p);

	printf("\n delete CS101 from CR");
	deleteCr("CS101", "*");
	printf("\n resulting table: ");
	printCR();
	printf("\n insert CS205, CS120 in CP");
	insertCp("CS205", "CS120");
	printf("\n resulting table: ");
	printCP();
	printf("\n insert CS205, CS101, CP	");
	insertCp("CS205", "CS101");
	printf("\n resulting table: ");
	printCP();

	printf("\n");
	printf("\n Example 1 results: ");
	Example1();
	printEx1();
	printf("\n Example 2 results: ");
	Example2();
	printEx2();
	printf("\n Example 3 results: ");
	Example3();
	printEx3();
	printf("\n Example 4 results: ");
	Example4();
	printEx4();

	return 0;
}
