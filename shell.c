void biosgets(char *str); // get a string from the user
void biosputs(char *str); // print a string to the screen
void welcome();           // clear the screen and print the welcome message
void help();              // print the help menu
void cls();               // clear the screen
void mem();    // print the size of the conventional memory of the IBM PC
void quit();   // reboot the machine
void exit();   // reboot the machine
void reboot(); // reboot the machine
int Strcmp(char *src, char *dst); // utility function to compare strings

////////////////////////////////////////////
void main() {
  welcome();

  while (1) {
    char str[10];
    biosputs("\n\r>");
    biosgets(str);

    if(Strcmp(str,"mem")){mem();}
    if(Strcmp(str,"help")){help();}
    if(Strcmp(str,"cls")){cls();}
    if(Strcmp(str,"quit")){quit();}
    if(Strcmp(str,"exit")){exit();}
    if(Strcmp(str,"reboot")){reboot();}


    // Write your code here
  }
}
/////////////////////////////////////////////
void biosputs(char *str) {
  int i = 0;
  char holdc;
  while (str[i]) {
    holdc = str[i++];
    _asm {
			mov ah, 0Eh
			mov al, holdc
			mov bx, 7
			int 10h
    }
  }
}
/////////////////////////////////////////////
void biosgets(char *str) {
    int i =-1 ;
    char holdc;
    do{
        _asm{ mov ah,1
        int 21h
        mov holdc, AL
        }
        str[++i]=holdc;


    }while(holdc!='\r');
    str[i]='\0';
  // Write your code here
}
/////////////////////////////////////////////
void welcome() {
 cls();
biosputs("welcome to rafik and ahmed os \n\r Type help if you need it.\n\r");
}
/////////////////////////////////////////////
void help() {
    biosputs("help - print out this list\n\rcls - clear the screen\n\rmem - print the size of memory the computer ha\n\rquit - reboot the machine\n\rexit - same as quit\n\rreboot - same as exit\n\r");
  // Write your code here
}
/////////////////////////////////////////////
void cls() {
    _asm{mov al, 03h
        mov ah, 0
        int 10h
    }
  // Write your code here
}
/////////////////////////////////////////////
void mem() {
    int size;
    char* digit;
    int temp = size;
    int i = 0;
    
    _asm{
        int 12h
        mov size,AX
    }
    while(temp>0)
    {
      temp /= 10;
      i++;
    }
    digit = (char*)malloc(i+1);
    digit[i] = '\0';
    while(size>0)
    {
      digit[i-1] = size%10 + '0';
      i--;
      size /= 10;
    }
    biosputs(digit);
  // Write your code here
}
/////////////////////////////////////////////
void quit() {
  char* answer;
  biosputs("Do you really want to quit our operating system? Y/N\n\r");
  biosgets(answer);
  if(Strcmp(answer,"Y") || Strcmp(answer,"y")){
    _asm{
      int 19h
    }
  }
  // Write your code here
}
/////////////////////////////////////////////
void exit() {
  _asm{
    int 19h
  }
  // Write your code here
}
/////////////////////////////////////////////
void reboot() {
  _asm{
    int 19h
  }
  // Write your code here
}
/////////////////////////////////////////////
int Strcmp(char *src, char *dst) {
    int i=0; int retval=0;
    while(src[i]!='\0'&&dst[i]!='\0')
    {
      if(src[i]==dst[i])
      {
        i++;
        retval = 1;
      }
      else
      {
        retval = 0;
        break;
      }
    }
    return retval;
  // Write your code here
}
//////////////////////////////////////////////
