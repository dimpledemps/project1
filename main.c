#include <stdio.h>
#include <string.h>
#include <stdlib>

//define function
//lower case letters

//c=c-65
//function prototype here 
void encrypt(char* text, int key);
int main(void){

int key=1; //shift letters by one place 
char text[101]; //array of letters *check this

printf("Enter word for encryption");
fgets(text, sizeof(text), stdin);
//print text
printf("Ciphered text:");
encrypt(text,key);


void encrypt(chair* text, int key)
{
	int i=0;
	char cipher;
	char cipherValue;
//backspace character is \0 
	//-1 terminating character 
	while(text[i] != \0 && strlen(text) -1 >i)
	{
		cypherValue=((int)text[i]-97 + key) % 26 + 97;
		cipher=char(cipherValue);

		printf("%c\n", cipher);
		i++;

	}
}






















//(char) chipherValue
//int main(){
  
//void decryptCipher(char arr[])
//for (int i=0; i < )
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
//switch	
//char c=0;
//basic scaffold 
//Rotation cipher where a=0,b=1,c=2...z=25
//go through entire array until finding /N character 

//void rotation(char* text, int key);
//int main(){
	//int key=1;
	//char str[100];


    //char str[100];
   // printf("Please enter a message to decrypt");
}




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
