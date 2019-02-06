#pragma once
typedef struct s_SNAP {
	int ID;
	char *name;
	char *address;
	char *phNum;
}SNAP;
typedef struct s_CP {
	char *course;
	char *prereq;
	
}CP;
typedef struct s_CDH {
	char *course;
	char *day;
	char *hour;
	
}CDH;
typedef struct s_CR {
	char *course;
	char *room;
}CR;
typedef struct s_CSG {
	char *course;
	int ID;
	char *grade;
	
}CSG;
typedef struct s_CRDH {
	char *course;
	char *room;
	char *day;
	char *hour;
}CRDH;

typedef struct s_tlistCSG {//returning structure for lookup cuz C is bullshit
	CSG list[20];
}tlistCSG;
typedef struct s_tlistCP {//returning structure for lookup cuz C is bullshit
	CP list[20];
}tlistCP;
typedef struct s_tlistCDH {//returning structure for lookup cuz C is bullshit
	CP list[20];
}tlistCDH;

