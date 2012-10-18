#include <stdio.h>

int main(int argc, char *argv[]){
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);

	for(int i=0; i <count; i++){
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	return 0;
}
