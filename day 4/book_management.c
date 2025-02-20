#include<stdio.h>

struct Fiction_t{
    char title[200];
    char author[100];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t{
    char title[200];
    char author[100];
    float price;
};
typedef struct NonFiction_t NonFiction;

union BookType_t{
    Fiction fiction;
    NonFiction nonfiction;
};

typedef union BookType_t BookType;

struct Book_t{
    int type;
    BookType booktype;
};

typedef struct Book_t Book;

Book books[1000];
int bookcount;

void addBooks();
void displayBooks();

int main(){
    addBooks();
    displayBooks();
    return 0;
}

void addBooks(){
    printf("Enter number of books: ");
    scanf("%d",&bookcount);
    for(int i = 0;i < bookcount;i++){
        printf("Type of book (1 - Ficion ,2 - Non Fiction):\n");
        scanf("%d",&books[i].type);

        switch(books[i].type){
            case 1: {
                printf("Enter fiction Book Details(Title,Author,Price):");
                scanf("%s%s%f",books[i].booktype.fiction.title,
                               books[i].booktype.fiction.author,
                               &books[i].booktype.fiction.price);
            }break;
            case 2: {
                printf("Enter Non fiction Book Details(Title,Author,Price):");
                scanf("%s%s%f",books[i].booktype.nonfiction.title,
                               books[i].booktype.nonfiction.author,
                               &books[i].booktype.nonfiction.price);
            }break;
        }
    }
}

void displayBooks(){
    for(int i = 0;i < bookcount;i++){
        switch(books[i].type){
            case 1: {
                printf("Fiction Book: %s ,Author: %s ,Price: %.2f\n",books[i].booktype.fiction.title,
                               books[i].booktype.fiction.author,
                               books[i].booktype.fiction.price);
            }break;
            case 2: {
                printf("Non Fiction Book: %s ,Author: %s ,Price: %.2f\n",books[i].booktype.nonfiction.title,
                               books[i].booktype.nonfiction.author,
                               books[i].booktype.nonfiction.price);
            }break;
        }
    }
}