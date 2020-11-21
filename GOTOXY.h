#ifndef GOTOXY_H_INCLUDED
#define GOTOXY_H_INCLUDED

void gotoxy(int x, int y)
{
    HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void suma(int x, int y){

int s=0;
s=x+y;
cout<<s <<endl;
}

#endif // GOTOXY_H_INCLUDED
