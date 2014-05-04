// IDA*£¨Iterative deepening A*£© 

#include<string>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

#define SIZE 3
typedef int board[SIZE][SIZE];
board target = {1,2,3,8,0,4,7,6,5};		// the target configuration
board start;	// the start configuration
int add[4][2]={-1,0,0,1,1,0,0,-1};

/************************* heuristic function *****************************/
int targetplace[SIZE*SIZE][2];			
int CAL_H(board & node) 
{
	int i,j;
	int re = 0;
	for (i=0; i<SIZE; i++) for (j=0; j<SIZE; j++) if (node[i][j]) 
	{
		re += abs(i - targetplace[node[i][j]][0])
			+ abs(j - targetplace[node[i][j]][1]);
	}
	return re;
}
/***************************************************************/

bool can_solve() // to decide whether the problem has a solution
{					
	int i,j,k1,k2;
	for (i=0; i<SIZE; i++) 
		for (j=0; j<SIZE; j++) 
		{
			if (start[i][j]==0) 
			{
				start[i][j] = SIZE*SIZE;
				k1 = (SIZE-1-i) + (SIZE-1-j);
			}
			if(target[i][j]==0)
			{
				target[i][j] = SIZE*SIZE;
				k2 = (SIZE-1-i) + (SIZE-1-j);
			}
		}
	for (i=0; i<SIZE*SIZE; i++) 
		for (j=i+1; j<SIZE*SIZE; j++) 
		{
			if (start[i/SIZE][i%SIZE] > start[j/SIZE][j%SIZE]) 
				k1++;		
			if (target[i/SIZE][i%SIZE] > target[j/SIZE][j%SIZE]) 
				k2++;		
		}
	for (i=0; i<SIZE; i++) for (j=0; j<SIZE; j++) 
	{
		if (start[i][j]==SIZE*SIZE) 
			start[i][j]=0;		
		if (target[i][j]==SIZE*SIZE) 
			target[i][j]=0;		
	}
	return (k1%2)==(k2%2);
}

void out_board(board state,int step)	//to print each configuration
{           
	int i,j;
	cout<<"STEP: "<<step<<endl;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cout<<state[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void output(int dep, char path[]) // output the solution
{			
	int i,j,x1,y1,x0,y0;
	board state;
	memcpy(state, start, sizeof(state));
	out_board(state,0);
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			if(state[i][j]==0)
			{	
				x0=i;
				y0=j;
			}
	for (i=0; i<dep; i++) 
	{
		x1=x0+add[path[i]][0];
		y1=y0+add[path[i]][1];
		state[x0][y0] = state[x1][y1];
		state[x1][y1] = 0;
		x0 = x1, y0 = y1;
		out_board(state,i+1);
	}
	cout<<"The minimum number of steps is "<<dep<<endl;
}

/***********************************************************************************/

int ans;
char path[100000];
int max_depth, max_nodes, tot_nodes, cur_nodes;

bool ida(board & node, int x0, int y0, int dep, int d, int h) //IDA*
{	
	if(dep>max_depth) max_depth = dep;
	cur_nodes ++;

	int i,x1,y1,h1;
	if (memcmp(node, target, sizeof(target))==0) 
	{
		output(dep, path);
		return 1;
	}
	if (dep==ans) return 0;
	
	board node1;
	for (i=0; i<4; i++) 
	{
		if (((i%2)==(d%2)) && i!=d) 
			continue;
		x1 = x0 + add[i][0];
		y1 = y0 + add[i][1];
		if (x1<0||y1<0||x1==SIZE||y1==SIZE) 
			continue;
		memcpy(node1, node, sizeof(node1));
		node1[x1][y1] = 0;
		node1[x0][y0] = node[x1][y1];
		
		if (i==3 && y1<targetplace[node[x1][y1]][1]) 
			h1=h-1;
		else if (i==1 && y1>targetplace[node[x1][y1]][1]) 
			h1=h-1;
		else if (i==0 && x1<targetplace[node[x1][y1]][0]) 
			h1=h-1;
		else if (i==2 && x1>targetplace[node[x1][y1]][0]) 
			h1=h-1;
		else 
			h1=h+1; 
		if (h1+dep+1>ans) 
			continue;			
		path[dep] = i;
		if (ida(node1,x1,y1,dep+1,i,h1)) 
			return 1; 
	}
	return 0;
}

int main() 
{
	int i,j,k,x0,y0;

	clock_t begin, finish;
	double  duration;
	cout<<"Please input the start configuration:"<<endl;
	for (i=0;i<SIZE;i++)for(j=0;j<SIZE;j++) 
	{
		cin>>k;
		start[i][j] = k;
		if (k==0) { x0=i; y0=j; }
	}
	if (!can_solve()) 
	{ 
		cout<<"This puzzle is not solvable."<<endl;
		return 0;
	}

	begin = clock();
	for (k=1,i=0; i<SIZE; i++) for (j=0; j<SIZE; j++) 
	{
		targetplace[target[i][j]][0] = i;
		targetplace[target[i][j]][1] = j;
	}	
		
	max_depth = 0;
	max_nodes = 0;	
	tot_nodes = 0;	
	i = -1;
	j = CAL_H(start);
	for (ans=j; ; ans+=1) 
	{
		cur_nodes = 0;
		if (ida(start,x0,y0,0,i,j)) 
			break;
		if(cur_nodes>max_nodes) 
			max_nodes = cur_nodes;
		tot_nodes += cur_nodes;
	}
	finish = clock();         
	duration = (double)(finish - begin) / CLOCKS_PER_SEC;
	cout<<"running time: "<<duration<<" seconds"<<endl;
	cout<<max_depth<<endl;
	return 0;
}

/*
sample input(start configuration):
	3 6 5
	7 0 2
	1 4 8
*/