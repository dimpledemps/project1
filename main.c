//NATALIA DEMPSEY
//C3316625
//ENG1003
//LAST MODIFIED: 26/04/19

#include <stdio.h>
//FUNCTION PROTOTYPES 

//Turns lowercase input into uppercase letters
char makeUpperCase(char); 
//Turns string input into uppercase letters 
void makeStringUpperCase(char *);
//Finds the index of a character in a string 
int findCharInString(char *, char);
//Encrypt a message with a rotation cipher
void encryptWithRotation(char *, int);
//Encrypt with a substitution cipher 
void encryptWithSubstitution(char *, char *);
//Decrypt with a substitution cipher 
void decryptWithSubstitution(char *, char *);

int main()
{
  //VARIABLES 
    //char ch;
    int x; //int i 
    int key=1;
    char message[101];
    char alphabet[26]; //MOVED FROM CASE 3 AND 4 

   //MENU 
   printf("Please choose an option from the list:\n");
   printf("1.Encrypt a message using rotation cipher \n");
   printf("2.Decrypt a message using rotation cipher\n");
   printf("3.Encrypt a message using substitution cipher\n");
   printf("4.Decrypt a message using substitution cipher\n");
   scanf("%d", &x);

   //SWITCH-CASE THAT CORRELATES WITH USER INPUT 
   switch(x)
   { 
   case 1: //Encrypt message with rotation cipher 

        //Prompt user to enter message to be encrypted
        printf("Enter the message to encrypt:\n");
        scanf("%s", message);
        
        //Prompt user to define key shift; amount is stored in variable key 
        printf("Enter the rotation amount:\n");
        scanf("%d", &key);
        
        //Message and key inputted from user are passed through the function
        encryptWithRotation(message, key);
        
        //Encrypted message printed to the screen
        printf("Encrypted message:%s\n", message);

      break;

    case 2: //Decrypt message with rotation cipher 
         
        //Prompt user to enter message to be decrypted 
        printf("Enter the message to decrypt:\n");
        scanf("%s", message);
        
        //Prompt user to define key shift and store it in the variable key
        printf("Enter the rotation amount:\n");
        scanf("%d", &key);
        
        //Pass message and -key in encryption function 
        //NOTE: -key can be passed because decryption moves backwards
        //Same code for encryption but with -key
        encryptWithRotation(message, -key);
        
        //Print decrypted message to the screen 
        printf("Decrypted message:%s\n", message);
      break;
    
    case 3: //Encrypt message with substitution cipher 
    
        //Prompt user to enter message to encrypt and store it in the //variable message
        printf("Enter the message to encrypt:\n");
        scanf("%s", message);
        
        //Prompt user to enter the encryption alphabet and store it in the variable alphabet, maximum of 26 letters 
        printf("Enter the substitution alphabet:\n");
        //char alphabet[26];
        scanf("%s", alphabet);
        
        //Pass message and alphabet to function
        encryptWithSubstitution(message, alphabet);
        
        //Print encrypted message to the screen 
        printf("Encrypted message:%s\n", message);
      break;

    case 4: //Decrypt with substitution cipher 
        printf("Enter the message to decrypt:\n");
        scanf("%s", message);
        
        //Prompt user to enter the encryption alphabet and store it in the variable alphabet
        printf("Enter the substitution alphabet:\n");
        //char alphabet[26];
        scanf("%s", alphabet);
        
        //Pass message & alphabet to function
        decryptWithSubstitution(message, alphabet);
        
        //Print decrypted message
        printf("Encrypted message:%s\n", message);
        
      break;
    
   default:
      printf("Invalid input, please select an option from the menu\n");
      
   } 
  //Make console look neater 
   printf("\n");
   return 0;
}

//FUNCTIONS
void encryptWithRotation(char *message, int key)
{
  //Variables 
    char ch;
    int i;
    
    //Loop through each character in the message string
    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i]; //ch is now in the first position of array
        
        //Make sure all characters are uppercase
        ch = makeUpperCase(ch);
        
        //Check character is within the ASCII A-Z range before performing any changes 65=A,Z=90
        if(ch >= 65 && ch <= 90)
        {
            //"Rotate" character by key amount
            ch = ch + key;
            
            //If rotated character has gone outside range (eg. z + 1) then "wrap" it back (e.g. z + 1 = a)
            if(ch > 90)
            {
                ch = ch - 26;
            }
            else if(ch < 65)
            {
                ch = ch + 26;
            }
            
            //Replace old character with new character
            message[i] = ch; //new character in position of old character
        }
    }
}

void encryptWithSubstitution(char *message, char *alphabet) 
{
  //Variables
    char ch;
    int i;
    
    //Check alphabet uppercase
    makeStringUpperCase(alphabet);
    
    //Loop through each character in the message string
    for(i = 0; message[i] != '\0'; i++){
        ch = message[i];
        
        //Make sure all characters are uppercase
        ch = makeUpperCase(ch);
        
        //Check character is within the ASCII A-Z range before performing any changes
        if(ch >= 65 && ch <= 90)
        {
            //Convert ASCII value to index value (i.e. A = 0, B = 1, C = ...)
            unsigned char chIndex = ch - 65; //65 is ASCII capital A 
            
            //Get substitution from user supplied alphabet by index
            ch = alphabet[chIndex]; //char *alphabet,directly edit 
            
            //Replace old character with new character
            message[i] = ch;
        }
    }
}
void decryptWithSubstitution (char *message, char *alphabet)
{
  //Variables
  char ch;
  int i;
  
    
    //Check alphabet uppercase
    makeStringUpperCase(alphabet);
    
    //Loop through each character in the message string
    for(i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];
        
        //Make sure all characters are uppercase
        ch = makeUpperCase(ch);
        
        //Check character is within the ASCII A-Z range before performing any changes
        if(ch >= 65 && ch <= 90)
        {
            //Get index of character in user supplied alphabet (e.g. D might be the first letter, index = 0)
            int index = findCharInString(alphabet, ch);
            
            //If not found, their alphabet was missing characters that were needed
            if(index == -1)
            {
                printf("Error: the substitution alphabet supplied was missing characters");
            }
            
            //Get difference between ASCII value of user alphabet char and normal alphabet char
            int diff = alphabet[index] - (65+index);
            ch = ch - diff;
            
            //Replace old character with new character
            message[i] = ch;
        }
    }
}
char makeUpperCase (char ch)
{
    if(ch >= 97 && ch <= 122) //lowercase a=97, lowercase z=122
    {
        ch = ch - 32; // z-a 
    }
    return ch;
}

void makeStringUpperCase(char *string)
{
    int i;
    //Loop through and capitalise each character in string using the function makeUpperCase(char)

    for(i = 0; string[i] != '\0'; i++)
    {
        string[i] = makeUpperCase(string[i]);
    }
}

//Find the index of a character in a string 
int findCharInString(char *string, char ch)
{
    int index;
    //Loop through characters in string and compare to target character, return index if it matches
    for(index = 0; string[index] != '\0'; index++){
        if(string[index] == ch)
        {
            return index;
        }
    }
    
    //If no match found, return -1
    return -1;
}
