#include <stdio.h>
#include <math.h>
#include<stdlib.h>

static int number=1;				//this value is used for numbering the tromino



void trominoTile(int size,int len,int board[][len],int k, int x, int y, int c_x, int c_y){
	
	//if the matrix is 2x2 matrix then start numbering the tromino
    if(k==1){
        for(int i=c_x;i<c_x+size;i++){
            for(int j=c_y;j<c_y+size;j++){
                if(board[i][j]==0){
                    board[i][j]=number;
                }
                
            }
        }
        
        number=number+1;
    }
    
    else if(k>1){
        
        int new_size=size/2;
        int new_k = k-1;
        
        //if the hole is the first quadrant of the matrix
        if(x<c_x+new_size && y<c_y+new_size ){
            
            trominoTile(new_size, len, board, new_k, x, y, c_x, c_y);
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size, c_x, c_y+new_size);
            
            board[c_x+new_size][c_y+new_size]=number;
            board[c_x+new_size][c_y+new_size-1]=number;
            board[c_x+new_size-1][c_y+new_size]=number;
            
            number = number +1;
            
            
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size, c_x+new_size, c_y+new_size);
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size-1, c_x+new_size, c_y);
            
        }
		
        //if the hole is in the second quadrant of the matrix
        else if(x<c_x+new_size && y>=c_y+new_size ){
            
            trominoTile(new_size, len, board, new_k, x, y, c_x, c_y+new_size);
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size-1, c_x+new_size, c_y);
            
            board[c_x+new_size][c_y+new_size]=number;
            board[c_x+new_size-1][c_y+new_size-1]=number;
            board[c_x+new_size][c_y+new_size-1]=number;
            
            number = number +1;
            
            
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size, c_x+new_size, c_y+new_size);
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size-1, c_x, c_y);
            
        }
        
		//if the hole is in the thrid quadrant of the matrix
        else if(x>=c_x+new_size && y<c_y+new_size ){
            
            trominoTile(new_size, len, board, new_k, x, y, c_x+new_size, c_y);
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size, c_x, c_y+new_size);
            
            board[c_x+new_size][c_y+new_size]=number;
            board[c_x+new_size-1][c_y+new_size-1]=number;
            board[c_x+new_size-1][c_y+new_size]=number;
            
            number = number +1;
            
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size, c_x+new_size, c_y+new_size);
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size-1, c_x, c_y);
            
        }
        
		//if the hole is in the fouth quadrant of the matrix
        else if(x>=c_x+new_size && y>=c_y+new_size ){
            
            trominoTile(new_size, len, board, new_k, x, y, c_x+new_size, c_y+new_size);
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size, c_x, c_y+new_size);
            
            board[c_x+new_size-1][c_y+new_size-1]=number;
            board[c_x+new_size][c_y+new_size-1]=number;
            board[c_x+new_size-1][c_y+new_size]=number;
            
            number = number +1;
            
            
            trominoTile(new_size, len, board, new_k, c_x+new_size-1, c_y+new_size-1, c_x, c_y);
            trominoTile(new_size, len, board, new_k, c_x+new_size, c_y+new_size-1, c_x+new_size, c_y);            
            
        }
        
    }
    
    
}

int main(int argv, char *argc[])
{	 
	//geting the values from command line argument
    int k,x,y;
    k = atoi(argc[1]);								//matrix size
    x = atoi(argc[2]);								//x cordinate of the hole
	y = atoi(argc[3]);								//y cordinate of the hole
    
    int size = 1;
    int c_x=0;
    int c_y=0;
    
	//size of the matrix(power function)
	for(int i=1; i<=k; i++){
		size = size*2;
	}
	
	int len = size;
	
	printf("size %d", size);
    int board[size][size];							//board matrix
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[i][j]=0;
        }
    }
    
    board[x][y]=-1;									//stroing the board matrix with -1
    
    trominoTile(size, len, board, k, x, y, c_x, c_y);
    
	
	//printing the output matrix with trominos
    printf("output is:\n");
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]==-1){
                printf("x\t");
            }
            else{
                printf("%d \t",board[i][j]);
            }
        }    
        printf("\n");
    }     
    
    return 0;
}