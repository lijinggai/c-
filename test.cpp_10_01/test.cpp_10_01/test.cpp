#include<stdio.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3

void menu()
{
    printf("#########################\n");
    printf("######1.PLAY 0.EXIT######\n");
    printf("#########################\n");
}

void Intiboard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }

    }
}
void Dispaly(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < row - 1)
                    printf("|");
            }
            printf("\n");
        }

    }
}
void PlayerMove(char board[ROW][COL], int row, int col)
//��Ϸ���㷨ʵ��
{
    printf("�������\n");
    int x = 0;
    int y = 0;
    while (1)
    {
        printf("����������>:\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("���������Ա�ռ��������");
            }
        }
        else
        {
            printf("����Ƿ�������������");
        }
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("������\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }

}
int IsFull(char board[ROW][COL], int row, int col)//�ж�ƽ��
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] == ' ';
            return 0;
        }
    }
    return 1;
}
char IsWin(char board[ROW][COL], int row, int col)//�ж���Ӯ
{
    int i = 0;
    for (i = 0; i < row; i++) //��Ӯ
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return '*';
        }
    }

    for (i = 0; i < col; i++) //��Ӯ
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return board[1][1];
    if (1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
    return 'C';
}
void game()
{
    char ret = 0;
    char board[ROW][COL] = { 0 };
    //��ʼ������
    Intiboard(board, ROW, COL);
    //��ʾ���̸�
    Dispaly(board, ROW, COL);
    //��Ϸ��ʼ
    while (1)
    {
        char ret = 0;
        PlayerMove(board, ROW, COL);//�����
        Dispaly(board, ROW, COL);
        ret = IsWin(board, ROW, COL);//�ж���Ӯ
        if (ret != 'C')
        {
            break;
        }
        ComputerMove(board, ROW, COL);
        Dispaly(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
    }

    if (ret == '*')
    {
        printf("���Ӯ��\n");

    }
    else if (ret == '#')
    {
        printf("��������\n");
    }
    else
    {
        printf("ƽ��\n");
    }

}

void test()//�Ƿ�Ҫ����Ϸ
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("������>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("������\n");
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("������ϣ�����������\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}
