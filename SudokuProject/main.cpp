#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include<sstream>
#include<string>
 
using namespace std;
 
const int N = 9;
vector<int> src;
int table[N][N];
 
void ouput(FILE *fp)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            fprintf(fp,"%d ",table[i][j]);//cout << table[i][j] << "  ";
        }
        fprintf(fp,"\n");//cout << endl;
    }
}
 
// 初始化中间的九宫格
void centerInit()
{
	src.clear();
    for (int i = 0; i < N; ++i)
    	if(i!=2)
        src.push_back(i + 1);
    random_shuffle(src.begin(), src.end()); // 随机化序列
    src.push_back(3);
 	//for (std::vector<int>::iterator m = src.begin(); m != src.end(); m++ )
 	//{
 	//	cout << *m<<" ";
	// }
	// cout <<"\n";
    int k = 0;
    for (int i = 3; i < 6; ++i)
        for (int j = 3; j < 6; ++j)
            table[i][j] = src[k++];
}
 
// 由中间的九宫格交叉变换，初始化上下左右四个九宫格
void crossInit()
{
    for (int i = 3; i < 6; ++i)
    {
        int l = 0;
        for (int j = 3; j < 6; ++j)
        {
            if (i == 3)
            {
                table[i + 1][l] = table[i][j];
                table[i + 2][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 4)
            {
                table[i + 1][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 5)
            {
                table[i - 2][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
        }
    }
    for (int j = 3; j < 6; ++j)
    {
        int l = 0;
        for (int i = 3; i < 6; ++i)
        {
            if (j == 3)
            {
                table[l][j + 1] = table[i][j];
                table[l + 6][j + 2] = table[i][j];
                ++l;
            }
            else if (j == 4)
            {
                table[l][j + 1] = table[i][j];
                table[l + 6][j - 1] = table[i][j];
                ++l;
            }
            else if (j == 5)
            {
                table[l][j - 2] = table[i][j];
                table[l + 6][j - 1] = table[i][j];
                ++l;
            }
        }
    }
}
 
// 初始化四个角上的四个九宫格
void cornerInit()
{
    for (int i = 0; i < 3; ++i)
    {
        int l = 0;
        for (int j = 3; j < 6; ++j)
        {
            if (i == 0)
            {
                table[i + 1][l] = table[i][j];
                table[i + 2][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 1)
            {
                table[i + 1][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 2)
            {
                table[i - 2][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
        }
    }
    for (int i = 6; i < 9; ++i)
    {
        int l = 0;
        for (int j = 3; j < 6; ++j)
        {
            if (i == 6)
            {
                table[i + 1][l] = table[i][j];
                table[i + 2][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 7)
            {
                table[i + 1][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
            else if (i == 8)
            {
                table[i - 2][l] = table[i][j];
                table[i - 1][l + 6] = table[i][j];
                ++l;
            }
        }
    }
}
 
// 根据设定的难度随机挖数
void generateSudoku(int difficulty)
{
    difficulty *= 20;
    while (difficulty--)
    {
        //table[rand() % 9][rand() % 9] = 0;
    }
}
 
// 初始化数独
// 先随机生成中间的九宫格，再通过交叉生成上下左右四个九宫格，
// 最后通过交叉生成四个角上的九宫格
/*
交叉顺序如下：
9  7  8  3  1  2  6  4  5
3  1  2  6  4  5  9  7  8
6  4  5  9  7  8  3  1  2
7  8  9  1  2  3  4  5  6
1  2  3  4  5  6  7  8  9
4  5  6  7  8  9  1  2  3
8  9  7  2  3  1  5  6  4
2  3  1  5  6  4  8  9  7
5  6  4  8  9  7  2  3  1
*/
void init(int difficulty)
{
   
    memset(table, 0, sizeof(table));
    centerInit();
    crossInit();
    cornerInit();
    //generateSudoku(difficulty);
}
 
int main(int argc,char *argv[])
{
	string str;
	if(argc==3)
	{
		str=argv[2];
	} 
	
	int n=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>'9'||str[i]<'0')
		n=-1;
	}
	
	
	FILE *fp;
	fp=fopen("sudoku.txt","a"); 
    
	if(n==-1)
	{
		printf("输入错误！\n");
		return 0;
	} 
	n=atoi(str.c_str()); 
	/* srand(time(NULL));
	int n; 
	 cin >>n;
	 FILE *fp;
	fp=fopen("sudoku.txt","a"); */
    while (n--)
    {
        /*cout << "Please select the difficulty(1~4), input 0 to exit: ";
        cin >> d;
        if (d == 0)
        {
            break;
        }*/
        init(1);
        ouput(fp);
        fprintf(fp,"\n");//cout<<endl;
    }
 	fclose(fp);
    return 0;
}
