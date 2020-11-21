#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

void color (char *oracion,int N){
 int color=N;
/*if(v!=0) b
{
   HANDLE  hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  /*for(int color = 1; color < 255; color++)
  {*/
  /*  SetConsoleTextAttribute(hConsole, color); b

   std::cout<<oracion << v <<endl;
  ///}
/*}else b
{
  HANDLE  hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  /*for(int color = 1; color < 255; color++)
  {*/
 /*   SetConsoleTextAttribute(hConsole, color);

  /* std::cout<<oracion <<endl; b
  ///}
}*/

  HANDLE  hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  /*for(int color = 1; color < 255; color++)
  {*/
    SetConsoleTextAttribute(hConsole, color);

   std::cout<<oracion <<endl;
  ///}



}

#endif // COLOR_H_INCLUDED
