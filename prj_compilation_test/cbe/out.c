extern int printd(int i);
int main(){
if(!(i==0)) goto L2;
{
i = 0;
goto L1;
}
L2: if(!(i==1)) goto L3;
{
i = 1;
goto L1;
}
L3: if(!(i==2)) goto L4;
i = 2;
L4: if(!(i==3)) goto L5;
goto L1;
L5: if(!(i==4)) goto L6;
i = 4;
L6: 
L1:a = 5;
}

