
// FLAGS/UNFLAGS (i,j)th COORDINATE AND CHANGES FLAG-COUNTER
void flag(int i,int j, int flagsLeft)  
{
    if (table[i][j]='F')    // IF ALREADY FLAGGED
    {
        table[i][j]='0'; // REMOVE THE FLAG
        flagsLeft++;    
    }   
    
    else
    {
       table[i][j]='F';     // ADD FLAG 
       flagsLeft--;
    }
    
}