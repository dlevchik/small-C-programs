//TODO: simplify program by using sprintf() and %X
#include <stdio.h>

char whatChar(int n){
  switch(n){
      case 10:
        return 'A';
      break;
      case 11:
        return 'B';
      break;
      case 12:
        return 'C';
      break;
      case 13:
        return 'D';
      break;
      case 14:
        return 'E';
      break;
      case 15:
        return 'F';
      break;
  }
  return n + '0';
}

int rgb(int r, int g, int b, char *output)
{
  
  if(r > 255){r = 255;}  if(g > 255){g = 255;}  if(b > 255){b = 255;}
  if(r < 0){r = 0;}      if(g < 0){g = 0;}      if(b < 0){b = 0;}
  
  output[0] = whatChar((int) r/16);
  output[1] = whatChar((int) (r % 16));
    
  output[2] = whatChar((int) g/16);
  output[3] = whatChar((int) (g % 16));
  
  output[4] = whatChar((int) b/16);
  output[5] = whatChar((int) (b % 16));
  
  output[6] = '\0';
  return 0; 
}

int main(int argc, char const *argv[])
{
  char output[7] = {0};

  rgb(218, 112, 214, output);
  printf("#%s;\n", output);

  rgb(255, 255, 300, output);
  printf("#%s;\n", output);

  rgb(0, -10, 21, output);
  printf("#%s;\n", output);

  rgb(46, 444, 112, output);
  printf("#%s;\n", output);

  getchar();
  getchar();
  return 0;
}

