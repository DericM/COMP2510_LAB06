/*
*    Created on: Mar 10, 2016
*        Author: Mccadden, Deric
* StudentNumber: A00751277
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NAMESIZE 20
#define LINESIZE 256



typedef struct name name;
struct name {
	char last[NAMESIZE];
	char first[NAMESIZE];
};

typedef struct record record;
struct record {
	name name;
	int score;               /* between 0 & 100 inclusive */
};


int input_record(record *prec);
void print_record(const record *prec);




int main()
{


	record *rec = malloc(sizeof(record));
	input_record(&rec);

	print_record(&rec);


	getchar();
    return 0;
}




/*
read in a new record
*/
int input_record(record *prec) {

	char line[LINESIZE];
	char first[NAMESIZE];
	char last[NAMESIZE];
	int score = -1;
	size_t i;

	if (!fgets(line, LINESIZE, stdin)) {
		return 0;
	}

	if (sscanf(line, "%s %s %d %", first, last, score) < 3) {
		return -1;
	}

	if (strlen(first) + 1 >= NAMESIZE || strlen(last) + 1 >= NAMESIZE) {
		return -1;
	}


	if (score < 0 || score > 100) {
		return -1;
	}

	i = 0;
	while (first[i]) {
		first[i] = tolower(first[i]);
		i++;
	}

	i = 0;
	while (first[i]) {
		last[i] = tolower(first[i]);
		i++;
	}

	/*printf("%s %s &d", last, first, score);*/

	prec->score = score;
	strcpy(prec->name.first, first);
	strcpy(prec->name.last, last);

}





/*
prints a record
*/
void print_record(const record *prec) {
	printf("%s %s &d", prec->name.last, prec->name.first, prec->score);
}
