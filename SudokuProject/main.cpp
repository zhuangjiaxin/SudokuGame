#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include<sstream>
#include<string>
 
using namespace std;
 
 FILE *fp;
const int N = 9;
vector<int> src;
int table[N][N],n=0;
 
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
 
 void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}


// ��ʼ���м�ľŹ���
void centerInit()
{
	/*src.clear();
    for (int i = 0; i < N; ++i)
    	if(i!=2)
        src.push_back(i + 1);
    random_shuffle(src.begin(), src.end()); // ���������
    src.push_back(3);
 	//for (std::vector<int>::iterator m = src.begin(); m != src.end(); m++ )
 	//{
 	//	cout << *m<<" ";
	// }
	// cout <<"\n";
    int k = 0;
    for (int i = 3; i < 6; ++i)
        for (int j = 3; j < 6; ++j)
            table[i][j] = src[k++];*/
}
 
// ���м�ľŹ��񽻲�任����ʼ�����������ĸ��Ź���
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
 
// ��ʼ���ĸ����ϵ��ĸ��Ź���
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
 
// �����趨���Ѷ��������
void generateSudoku(int difficulty)
{
    difficulty *= 20;
    while (difficulty--)
    {
        //table[rand() % 9][rand() % 9] = 0;
    }
}
 
// ��ʼ������
// ����������м�ľŹ�����ͨ�������������������ĸ��Ź���
// ���ͨ�����������ĸ����ϵľŹ���
/*
����˳�����£�
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
   
    //memset(table, 0, sizeof(table));
    //centerInit();
    crossInit();
    cornerInit();
    //generateSudoku(difficulty);
}
 
 void perm(int list[],int low,int high){
    if(low==high){   //��low==highʱ,��ʱlist��������һ������,���list
        //for(int i=0;i<=low;i++)
            //cout<<list[i];
        //cout<<endl;
        
        int k = 0;
    for (int i = 3; i < 6; ++i)
        for (int j = 3; j < 6; ++j)
            {
            	table[i][j] = list[k++];
            	//cout<<table[i][j]<<" ";
			}
			//cout<<endl;
            n--;
            if(n>=0)
            {
            	init(1);
        ouput(fp);
        fprintf(fp,"\n");//cout<<endl;
			}
			else 
			{
				fclose(fp);
				exit(1);
			}
            
    }else{
        for(int i=low;i<=high;i++){//ÿ��Ԫ�����һ��Ԫ�ؽ���
            swap(list[i],list[low]); 
            perm(list,low+1,high); //������,�õ�������,�ú���perm�õ������е�ȫ����
            swap(list[i],list[low]);//���,��Ԫ�ؽ�������,��ԭ,Ȼ�󽻻���һ��Ԫ��
        }
    }
}

int main(int argc,char *argv[])
{
	string str;
	if(argc==3)
	{
		str=argv[2];
	} 
	
	//int n=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>'9'||str[i]<'0')
		n=-1;
	}
	
	
	//FILE *fp;
	fp=fopen("sudoku.txt","w"); 
    
	if(n==-1)
	{
		printf("�������\n");
		return 0;
	} 
	n=atoi(str.c_str()); 
	/* srand(time(NULL));
	int n; 
	 cin >>n;
	 FILE *fp;
	fp=fopen("sudoku.txt","a"); 
    while (n--)
    {
        cout << "Please select the difficulty(1~4), input 0 to exit: ";
        cin >> d;
        if (d == 0)
        {
            break;
        }
        
        init(1);
        ouput(fp);
        fprintf(fp,"\n");//cout<<endl;
    }*/
    
    int list[9]={1,2,4,5,6,7,8,9,3};
	perm(list,0,7);

 	fclose(fp);
    return 0;
}
