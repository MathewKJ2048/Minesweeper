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
    
   
   void set_field(int i_ex,int j_ex)               //mutator //fill this up
   {  
	
       for (int i = 0; i < r; i++)                                       //sets both mines and numbers
         {
           for (int j = 0; j < c; j++)
           {
            number[i][j] = 0;
            }
         }
	   
      for (int i = 0; i < r; i++)
        {
        for (int j = 0; j < c; j++)
          {
            is_mine[i][j] = 0;
          }
       }
	   
      
    for (int i = 0; i < num_mines;)
      {
       
        int l = rand() % r;
        int m = rand() % c;
        if (is_mine[l][m] == true || (l == i_ex && m == j_ex))
            continue;
        else
        {
            i++;
            is_mine[l][m] = true;
            number[l][m] = -1;

            if (l == 0 && m == 0) // checking top left corner
            {

                number[1][0] += 1;

                number[1][1] += 1;

                number[0][1] += 1;
            }
            else if (l == 0 && m == c - 1) // checking top right corner
            {
                number[0][c - 2] += 1;
                number[1][c - 2] += 1;
                number[1][c - 1] += 1;
            }
            else if (l == r - 1 && m == 0) // checking bottom left corner
            {
                number[r - 2][0] += 1;
                number[r - 2][1] += 1;
                number[r - 1][1] += 1;
            }
            else if (l == r - 1 && m == c - 1) // checking bottom right corner
            {
                number[r - 1][c - 2] += 1;
                number[r - 2][c - 2] += 1;
                number[r - 2][c - 1] += 1;
            }
            else if (l == 0) // checking upper boundary tiles
            {
                number[l][m - 1] += 1;
                number[l][m + 1] += 1;
                number[l + 1][m - 1] += 1;
                number[l + 1][m] += 1;
                number[l + 1][m + 1] += 1;
            }
            else if (m == 0) // checking left boundary tiles
            {
                number[l - 1][m] += 1;
                number[l - 1][m + 1] += 1;
                number[l][m + 1] += 1;
                number[l + 1][m] += 1;
                number[l + 1][m + 1] += 1;
            }
            else if (m == c - 1) // checking right boundary tiles
            {
                number[l - 1][m - 1] += 1;
                number[l - 1][m] += 1;
                number[l][m - 1] += 1;
                number[l + 1][m - 1] += 1;
                number[l + 1][m] += 1;
            }
            else if (l == r - 1) // checking lower boundary tiles
            {
                number[l - 1][m - 1] += 1;
                number[l - 1][m] += 1;
                number[l - 1][m + 1] += 1;
                number[l][m - 1] += 1;
                number[l][m + 1] += 1;
            }
            else
            {
                number[l - 1][m - 1] += 1;
                number[l - 1][m] += 1;
                number[l - 1][m + 1] += 1;
                number[l][m - 1] += 1;
                number[l][m + 1] += 1;
                number[l + 1][m - 1] += 1;
                number[l + 1][m] += 1;
                number[l + 1][m + 1] += 1;
            }
        }
    }
       
	   
    for (int i = 0; i < r; i++)
      {
        for (int j = 0; j < c; j++)
        {
            if (is_mine[i][j] == true)
            {
                number[i][j] = -1;
            }
            
        }
    } 
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
	is_q_marked[i][j]=false;
        if(!is_swept[i][j])
        is_flagged[i][j]=true;
	//update state
    }
    void deflag(int i,int j)  //mutator
    {
        if(!is_swept[i][j])
        is_flagged[i][j]=false;
	//update state
    }
    void q_mark(int i,int j)  //mutator
    {
	is_flagged[i][i]=false;
        if(!is_swept[i][j])
        is_q_marked[i][j]=true;
	//update state
    }
    void de_q_mark(int i,int j)  //mutator
    {
        if(!is_swept[i][j])
        is_q_marked[i][j]=false;
	//update state
    }
    void sweep_from(int i, int j)  //mutator
    {
	    //fill this up
	    //floodfill 0s
	    //deflag and de_q_mark swept squares manually
	    //ensure state is updated
	    //ensure num_swept is updated
    }
    
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
	    //use ASCII characters alone to represent set_board
	    //graphics can be added later
    }
    
};
