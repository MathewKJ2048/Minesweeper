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
