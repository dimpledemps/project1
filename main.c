#include <stdio.h>
#include <string.h>

int main(){
    
    //switch	
//char c=0;
//basic scaffold 
//Rotation cipher where a=0,b=1,c=2...z=25
//go through entire array until finding /N character 

void rotation(char* text, int key);
int main(){
	int key=1;
	char str[100];


/*switch(c)

case 1:
	printf("Please select an option");
	break;
case 2:
	printf("Encryption using a rotation cipher ");
	break;
case 3:
	printf("Decryption using a rotation cipher");
	break;
case 4:
	printf("Encryption using a substitution cipher");
	break;
case 5:
	printf("Decryption using a substitution cipher");
	break;
default:printf("No option selected, please select an option");
	break;

    //printf("Insert some stuff");
    //printf("Even more stuff than before");
    //printf("Including extra so I can do a commit");
    //printf("Please work");
  return 0;
 }
