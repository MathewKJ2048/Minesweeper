class Minefield
{
    private:
    int r,c;                     //r,c - number of rows,columns
    int num_mines;               //total number of mines
    bool is_mine[15][15];        //true if mine is at (i,j), false otherwise
    bool is_swept[15][15];       //true if swept, false otherwise
    bool is_q_marked[15][15];    //true if q_marked, false otherwise
    bool is_flagged[15][15];     //true if flagged, false otherwise
    short number[15][15];        //stores total number of mines in the eight surrounding tiles
    char state[15][15];          //store info which can be revealed to player
    bool loss;                   //becomes true when game is lost, false till then
    int num_swept;               //holds number of swept tiles
    int num_flagged;             //holds number of flags used
	
    void set_field(int i_ex,int j_ex)   //mutator
    {
        //fill this up
        //sets both mines and numbers
    }
    
    
    public:
    Minefield(int rows, int cols, int num, int i_ex, int j_ex)  //constructor
    {
        r=rows;
        c=cols;
        num_mines=num;
        set_field(i_ex,j_ex);
    }
    
    
    void flag(int i,int j)  //mutator
    {
        if(!is_swept[i][j])
	{
	    clear(i,j);
	    num_flagged+=1;
            is_flagged[i][j]=true;
	    //update state
	}
    }
    void q_mark(int i,int j)  //mutator
    {
        if(!is_swept[i][j])
	{
            clear(i,j);
            is_q_marked[i][j]=true;
	    //update state
	}	
    }
    void clear(int i,int j)   //mutator
    {
	 if(is_flagged[i][j]){is_flagged[i][j]=false;num_flagged-=1;}
	 if(is_q_marked[i][j]){is_q_marked[i][j]=false;}
    }
	
    void sweep_util(int i, int j) // a utility function which just accepts a zero location and flood fills all the zeros
    {
  	if(i<0||i>=r||j<0||j>=c)
  	{
    		return;
  	}
  
  	if(number[i][j]!=0)
  	{
    		return;
  	}
  	is_swept[i][j]=true;
  	number[i][j]=-10; //changing the zeros to 10 (which helps us to identify the zeros which have opened)
  	state[i][j] ='O'; //changing the toPrint array which is printed at the end
  	sweep_util(i-1,j);
  	sweep_util(i+1,j);
  	sweep_util(i,j-1);
  	sweep_util(i,j+1);
    }
	
	
    void sweep_from(int i, int j) // the main function which tackles all inputs of position (which are not visited) other that flag and question mark
	//assuming that flag and question mark functions are called before hand only and the given position cannot have those two.
    {
	is_swept[i][j]=true;
    	if(is_mine[i][j])
 	{
    		state[i][j]='B';
    		loss=true;
    		return;
  	}
  	//bomb tackled
  	// now handling numbers
  	if(number[i][j]!=0&&number[i][j]!=-10)
  	{
    		state[i][j]=(char)(48+number[i][j]);
    		return;
   	}
   
   	//now handling only remaining case i.e. 0
   	sweep_util(i,j); //this will only flood fill zeroes
   
   	int l,m;

   	num_swept=0; // making num_swept zero becasue i will be counting it again
   	//now adding boundary elements of zero flood by checking neighbours of each element. If the neighbouring element is found to be -10 i.e. visited zero, it's neighbor must be visible
   	for(l=0;l<r;l++)
   	{
    		for(m=0;m<c;m++)
    		{
      			if(l==0&&m==0) // checking top left corner
      			{ 
				if((number[1][0]==-10||number[1][1]==-10||number[0][1]==-10)&&number[0][0]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(l==0&&m==c-1) // checking top right corner
      			{ 
				if((number[0][c-2]==-10||number[1][c-2]==-10||number[1][c-1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(l==r-1&&m==0) // checking bottom left corner
      			{ 
				if((number[r-2][0]==-10||number[r-2][1]==-10||number[r-1][1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(l==r-1&&m==c-1) // checking bottom right corner
      			{ 
				if((number[r-1][c-2]==-10||number[r-2][c-2]==-10||number[r-2][c-1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(l==0) // checking upper boundary tiles
      			{ 
				if((number[l][m-1]==-10||number[l][m+1]==-10||number[l+1][m-1]==-10||number[l+1][m]==-10||number[l+1][m+1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(m==0) // checking left boundary tiles
      			{ 
				if((number[l-1][m]==-10||number[l-1][m+1]==-10||number[l][m+1]==-10||number[l+1][m]==-10||number[l+1][m+1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
          				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if(m==c-1) // checking right boundary tiles
      			{ 
				if((number[l-1][m-1]==-10||number[l-1][m]==-10||number[l][m-1]==-10||number[l+1][m-1]==-10||number[l+1][m]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
					state[i][j]=(char)(48+number[i][j]);
				}
			}
      			else if(l==r-1) // checking lower boundary tiles
      			{ 
				if((number[l-1][m-1]==-10||number[l-1][m]==-10||number[l-1][m+1]==-10||number[l][m-1]==-10||number[l][m+1]==-10)&&number[l][m]!=-10)
				{
          				is_swept[l][m]=true;
         				state[i][j]=(char)(48+number[i][j]);
        			}
      			}
      			else if((number[l-1][m-1]==-10||number[l-1][m]==-10||number[l-1][m+1]==-10||number[l][m-1]==-10||number[l][m+1]==-10||number[l+1][m-1]==-10||number[l+1][m]==-10||number[l+1][m+1]==-10)&&number[l][m]!=-10)
      			{
        			is_swept[l][m]=true;
        			state[i][j]=(char)(48+number[i][j]);
      			}

      			if(is_swept[l][m])
	    		num_swept++;

      		if(is_flagged[l][m]&&state[l][m]!='F')
            	is_flagged[l][m]=false;
            
      		if(is_q_marked[l][m]&&state[l][m]!='?')
            	is_q_marked[l][m]=false;

    		}//closing m loop
  	}// closing l loop
    } // closed void sweep_from function
  
    
    bool check_win()  //accessor
    {
         if(num_swept+num_mines==r*c)return true;
         else return false;
    }
    bool check_loss()  //accessor
    {
	 return loss;       
    }
    char get_state_of(int i,int j)  //accessor
    {
        return state[i][j];
    }
    
    void print()
    {
	 //fill this up
	 //use ASCII characters
	 //graphics can be added later
    }
    
};

