#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
White = Uppercase, Black = Lowercase
1 - pawn p
2 - rook r
3 - bishop b
4 - knight h
5 - queen q
6 - king k
*/
char board[8][8] = {
    {'r', 'h', 'b', 'q', 'k', 'b', 'h', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}
};

void display()
{
    printf("\t    a   b   c   d   e   f   g   h\n");
    printf("\t  ---------------------------------\n");
    
    for (int i = 0; i < 8; i++) {
        printf("\t%d |", 8 - i);  // Print row labels from 8 to 1
        for (int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);  // Print each piece with a space and a pipe separator
        }
        printf("\n\t  ---------------------------------\n");
    }
}

int pawn(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int rook(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int knight(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int bishop(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int queen(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int king(int init_column, int init_row, int final_column, int final_row)
{
    return 0;
}

int processMove(char* move, int turn)
{
    int init_column = 8 - (move[1] - '0');
    int init_row = tolower(move[0]) - 'a';
    int final_column = 8 - (move[4] - '0');
    int final_row = tolower(move[3]) - 'a';

    if (init_column >= 0 && init_column <= 7 && init_row >= 0 && init_row <= 7 && final_column >= 0 && final_column <= 7 && final_row >= 0 && final_row <=7)
    {
        char piece = board[init_column][init_row];

        if (piece == ' ')
        {
            printf("Invalid move. No piece at that location.\n");
            return 1;
        }

        if (((turn % 2) == 0 && isupper(piece)) || ((turn % 2) == 1) && islower(piece))
        {
            board[init_column][init_row] = ' ';
            board[final_column][final_row] = piece;
        }
        else
        {
            printf("Invalid move. Not current turn's piece.\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid move. Out-of-bounds coordinates.\n");
        return 1;
    }

    return 0;
}

void printPiece(char piece) {
    switch(piece) {
        case 'K': printf("%lc", 0x2654); break;  // White King ♔
        case 'Q': printf("%lc", 0x2655); break;  // White Queen ♕
        case 'R': printf("%lc", 0x2656); break;  // White Rook ♖
        case 'B': printf("%lc", 0x2657); break;  // White Bishop ♗
        case 'H': printf("%lc", 0x2658); break;  // White Knight ♘
        case 'P': printf("%lc", 0x2659); break;  // White Pawn ♙
        case 'k': printf("%lc", 0x265A); break;  // Black King ♚
        case 'q': printf("%lc", 0x265B); break;  // Black Queen ♛
        case 'r': printf("%lc", 0x265C); break;  // Black Rook ♜
        case 'b': printf("%lc", 0x265D); break;  // Black Bishop ♝
        case 'h': printf("%lc", 0x265E); break;  // Black Knight ♞
        case 'p': printf("%lc", 0x265F); break;  // Black Pawn ♟
        default: printf(" ");  // Empty square
    }
}

void clear()
{
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Unix/Linux
    #endif
}

void titlescreen()
{
    clear();
    printf(" ▄████████   ███    ███    ██████████    ▄████████    ▄████████ \n");
    printf("███    ███   ███    ███    ███    ███   ███    ███   ███    ███ \n");
    printf("███    ███   ███    ███    ███          ███    █▀    ███    █▀  \n");
    printf("███          ███▄▄▄▄███    ███▄▄▄       ███          ███        \n");
    printf("███          ███▀▀▀▀███    ███▀▀▀       ██████████   ██████████ \n");
    printf("███    ███   ███    ███    ███                 ███          ███ \n");
    printf("███    ███   ███    ███    ███    ███    ▄█    ███    ▄█    ███ \n");
    printf("████████▀    ███    ███    ██████████  ▄████████▀   ▄████████▀  \n");
    printf("                                                     _:_\n");
    printf("                Programmed by Benjamin Ryan         '-.-'\n");
    printf("                                           ()      __.'.__\n");
    printf("                                        .-:--:-.  |_______|\n");
    printf("                                 ()      \\____/    \\=====/\n");
    printf("                                 /\\      {====}     )___(\n");
    printf("                      (\\=,      //\\\\      )__(     /_____\\ \n");
    printf("      __    |'-'-'|  //  .\\\\   (    )    /____\\     |   | \n");
    printf("     /  \\   |_____| (( \\_  \\    )__(      |  |      |   | \n");
    printf("     \\__/    |===|   ))  `\\_)  /____\\     |  |      |   | \n");
    printf("    /____\\   |   |  (/     \\    |  |      |  |      |   | \n");
    printf("     |  |    |   |   | _.-'|    |  |      |  |      |   | \n");
    printf("     |__|    )___(    )___(    /____\\    /____\\    /_____\\ \n");
    printf("    (====)  (=====)  (=====)  (======)  (======)  (=======) \n");
    printf("    }===={  }====={  }====={  }======{  }======{  }======={ \n");
    printf("   (______)(_______)(_______)(________)(________)(_________) \n");

    getchar();
}

void gameloop()
{
    int turn = 0;
    char move[10];

    while(1)
    {
        clear();
        display();

        if (turn % 2 == 0)
        {
            printf("White's turn: ");
        }
        else
        {
            printf("Black's turn: ");
        }

        fgets(move, sizeof(move), stdin);

        if (move[0] == 'q')
        {
            printf("Quitting game.");
            break;
        }

        if ((move[2] == ' ' || move[2] == '-') && move[5] == '\n')
        {
            while (processMove(move, turn) != 0)
            {
                if (turn % 2 == 0)
                {
                    printf("White's turn: ");
                }
                else
                {
                    printf("Black's turn: ");
                }

                fgets(move, sizeof(move), stdin);

                if (move[0] == 'q')
                {
                    printf("Quitting game.");
                    return;
                }
            }

            turn++;
        }
        else
        {
            printf("Invalid move. Use format '{letter}{number}-{letter}{number}.");
        }
    }
}

int main()
{
    titlescreen();
    gameloop();
}