using namespace std;
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct title
{
	char title[10];
};

title ti[5];

struct Book
{
	int id;
	char name[20], author[20];
	double price, rating;

	//	Default Constructor
	Book()
	{
		this->id = 0;
		strcpy(this->name, "N/A");
		strcpy(this->author, "N/A");
		this->price = 0;
		this->rating = 0;
	}
	// Parameterised Constructor
	Book(int id, char *name, char *author, double price, double rating)
	{
		this->id = id;
		strcpy(this->name, name);
		strcpy(this->author, author);
		this->price = price;
		this->rating = rating;
	}
	// Seters / Mutators
	void setid(int id)
	{
		this->id = id;
	}
	void setname(char *name)
	{
		strcpy(this->name, name);
	}
	void setauthor(char *author)
	{
		strcpy(this->author, author);
	}
	void setprice(double price)
	{
		this->price = price;
	}
	void setrating(double rating)
	{
		this->rating = rating;
	}

	// Geters / Accessors
	int getid()
	{
		return this->id;
	}
	char *getname()
	{
		return this->name;
	}
	char *getauthor()
	{
		return this->author;
	}
	double getprice()
	{
		return this->price;
	}
	double getrating()
	{
		return this->rating;
	}
	// Function Declaration
	void display();
};

void titledisplay();
void settitle(title *);
void setdata(Book *);
void scan(Book *, int, int);
Book *top3(Book *, int);
// void search(Book *, int);
Book *add_Book(Book *, int *);
int rm_Book(Book *, int, int *);
void up_Book(Book *, int, int);
int searchid(Book *, int, int);
int searchname(Book *, char *, int);
void searchauthor(Book *, char *, int);
Book *dup(Book *, int);

int main()
{
	settitle(ti);
	int n = 5, c;
	//	printf("Enter No of Books:- ");
	//	scanf("%d",&n);
	// Book *b = (Book *)calloc(n, sizeof(Book));
	Book *b = new Book[n];
	setdata(b);
	//	scan(b,n,0);
	do
	{
		system("CLS");
		cout << "\n---------------------------------------------------------\n";
		cout << "\t\tSelect Any Operation";
		cout << "\n---------------------------------------------------------\n";
		cout << "\n\t1.Display Books Detail List\n\t2.Show Top 3 Books\n\t3.Search Book\n\t4.Add Book\n\t5.Remove Book\n\t6.Update Book Data\n\t0.Exit\n";
		cout << "\n---------------------------------------------------------\n";
		cout << "\tEnter Your Choice:-  ";
		cin >> c;

		switch (c)
		{
		case 1:
		{
			titledisplay();
			for (int i = 0; i < n; i++)
				b[i].display();
			break;
		}
		case 2:
		{
			Book *p = top3(b, n);
			if (p != NULL)
			{
				titledisplay();
				for (int i = 0; i < 3; i++)
					p[i].display();
				free(p);
			}
			break;
		}
		case 3:
		{
			int c;
			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tSelect Any One";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Search By Book ID\n\t2.Search By Book Name\n\t3.Search By Book Author\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;

			switch (c)
			{
			case 1:
			{
				int id;
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book ID:-  ";
				cin >> id;

				int a = searchid(b, n, id);
				if (a >= 0)
				{
					titledisplay();
					b[a].display();
				}
				else
					cout << "\n\t Sorry Book Record Are NOT Found!\n";
				break;
			}
			case 2:
			{
				char nm[20];
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book Name:-  ";
				fflush(stdin);
				gets(nm);
				int i = searchname(b, nm, n);
				if (i >= 0)
				{
					titledisplay();
					b[i].display();
				}
				else
					cout << "\n\t Sorry Book Record Are NOT Found!\n";
				break;
			}
			case 3:
			{
				char nm[20];
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book Author Name:-  ";
				fflush(stdin);
				gets(nm);
				searchauthor(b, nm, n);
				break;
			}
			default:
			{
				cout << "\n\tInvalid Choice! Please Try Again!";
				break;
			}
			}
			break;
		}
		case 4:
		{
			b = add_Book(b, &n);
			if (b != NULL)
			{
				cout << "\n\tBook Details Will Be Added Successfully!\n";
				//					titledisplay();
				//					display(b,n);
			}
			break;
		}
		case 5:
		{
			int c;
			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tSelect Any One";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Remove By Book ID\n\t2.Remove By Book Name\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;

			switch (c)
			{
			case 1:
			{
				int a;
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book ID You Want to Delete:-  ";
				cin >> a;
				int i = searchid(b, n, a);
				if (i >= 0)
				{
					rm_Book(b, i, &n);
					cout << "\n\t Record Deleted Succesfully!\n";
				}
				else
					cout << "\n\t Sorry Book Record Are NOT Found!\n";
				break;
			}
			case 2:
			{
				char a[20];
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Books Name You Want to Delete:-  ";
				fflush(stdin);
				gets(a);
				int i = searchname(b, a, n);
				if (i >= 0)
				{
					titledisplay();
					b[i].display();
					rm_Book(b, i, &n);
					cout << "\n\t This Record Was Deleted Succesfully!\n";
				}
				else
					cout << "\n\t Sorry Book Record Are NOT Found!\n";
				break;
			}
			default:
			{
				cout << "\n\tInvalid Choice! Please Try Again!";
				break;
			}
			}
			break;
		}
		case 6:
		{
			int c;
			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tSelect Any One";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Select Book By ID to Update\n\t2.Select Book By Name To Update\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;

			switch (c)
			{
			case 1:
			{
				int a, i;
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book ID You Want to Update:-  ";
				cin >> a;
				i = searchid(b, n, a);
				if (i >= 0)
					up_Book(b, i, n);

				else
					cout << "\n\t Sorry Book Details Not Found!";
				break;
			}
			case 2:
			{
				int i;
				char a[20];
				cout << "\n---------------------------------------------------------\n";
				cout << "\tEnter Book Name You Want to Update:-  ";
				fflush(stdin);
				gets(a);
				i = searchname(b, a, n);
				if (i >= 0)
					up_Book(b, i, n);
				else
					cout << "\n\t Sorry Book Details Not Found!";
				break;
			}
			default:
			{
				cout << "\n\tInvalid Choice! Please Try Again!";
				break;
			}
			}
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "\n\tInvalid Choice! Please Try Again!";
			break;
		}
		}
		if (c != 0)
		{
			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tDo You Want to Continue?";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Continue\n\t0.Exit\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;

			if (c != 1 && c != 0)
				cout << "\n\t Invalid Choice! Please Try Again\n";
		}
	} while (c != 0);
}

void Book ::display()
{
	cout << left << setw(8) << this->id << "| " << left << setw(20) << this->name << "| " << left << setw(20) << this->author << "| " << setw(15) << fixed << setprecision(2) << this->rating << "| " << setw(15) << fixed << setprecision(2) << this->price << "|";
	// printf("%-8d| %-20s| %-20s| %-15f| %-15lf|", this->id, this->name, this->author, this->rating, this->price);
	cout << "\n----------------------------------------------------------------------------------------\n";
}

void setdata(Book *b)
{
	b[0].setid(101);
	b[0].setname("Spider Man");
	b[0].setauthor("Stanly");
	b[0].setprice(500);
	b[0].setrating(4.5);

	b[1].setid(102);
	b[1].setname("Mrutunjay");
	b[1].setauthor("Shivaji Sawant");
	b[1].setprice(450);
	b[1].setrating(4.6);

	b[2].setid(103);
	b[2].setname("PaniPat");
	b[2].setauthor("Vishvas Patil");
	b[2].setprice(600);
	b[2].setrating(4);

	b[3].setid(104);
	b[3].setname("Chava");
	b[3].setauthor("Shivaji Sawant");
	b[3].setprice(550);
	b[3].setrating(4.8);

	b[4].setid(105);
	b[4].setname("Sriman Yogi");
	b[4].setauthor("Ranjeet Desai");
	b[4].setprice(850);
	b[4].setrating(5);
}

void scan(Book *b, int n, int s)
{
	float id;
	for (int i = s; i < n; i++)
	{
		char c[20];
		int f = 1;
		do
		{
			f = 1;
			int t;
			cout << "\nEnter Book ID:- ";
			scanf("%d", &t);
			if (searchid(b, n, t) >= 0 || t <= 0)
				cout << "\n\tEntered ID Alrady Exist! OR Not Valid! Plese Try Again\n";
			else
			{
				b[i].setid(t);
				f = 0;
			}
		} while (f != 0);
		do
		{
			f = 1;
			cout << "Enter Book Name:- ";
			fflush(stdin);
			gets(c);
			if (searchname(b, c, n) >= 0)
				cout << "\n\tEntered Name Alrady Exist! Plese Try Again\n\n";
			else
			{
				b[i].setname(c);
				f = 0;
			}
		} while (f != 0);
		cout << "Enter Book Author Name:- ";
		fflush(stdin);
		gets(c);
		b[i].setauthor(c);
		cout << "Enter Book Price:- ";
		double price;
		cin >> price;
		b[i].setprice(price);
		do
		{
			f = 1;
			cout << "Enter Book Rating:- ";
			cin >> id;
			if (id > 5 || id < 0)
				cout << "\n\tInvalid Rating! Try Again\n\n";
			else
			{
				b[i].setrating(id);
				f = 0;
			}
		} while (f != 0);
	}
}

Book *top3(Book *b, int n)
{
	int c;
	cout << "\n---------------------------------------------------------\n";
	cout << "\t\tSelect Any One";
	cout << "\n---------------------------------------------------------\n";
	cout << "\n\t1.Top 3 By Highest Rating\n\t2.Top 3 By Highest Price\n";
	cout << "\n---------------------------------------------------------\n";
	cout << "\tEnter Your Choice:-  ";
	cin >> c;

	switch (c)
	{
	case 1:
	{
		Book *p = dup(b, n), t;
		for (int j = 0; j < n - 1; j++)
			for (int i = 0; i < n - 1; i++)
				if (p[i].getrating() < p[i + 1].getrating())
				{
					t = p[i];
					p[i] = p[i + 1];
					p[i + 1] = t;
				}
		return p;
		break;
	}
	case 2:
	{
		Book *p = dup(b, n), t;
		for (int j = 0; j < n - 1; j++)
			for (int i = 0; i < n - 1; i++)
				if (p[i].getprice() < p[i + 1].getprice())
				{
					t = p[i];
					p[i] = p[i + 1];
					p[i + 1] = t;
				}
		return p;
		break;
	}
	default:
	{
		cout << "\n\tInvalid Choice! Please Try Again!";
		return NULL;
		break;
	}
	}
}

Book *add_Book(Book *p, int *n)
{
	int a;
	cout << "\n---------------------------------------------------------\n";
	cout << "\tEnter No of Books You Want to Add:-  ";
	cin >> a;

	Book *b = dup(p, (*n + a));
	scan(b, *n + a, *n);
	(*n) += a;
	return b;
}

int rm_Book(Book *b, int i, int *n)
{
	for (int j = i; j < *n; j++)
		b[j] = b[j + 1];
	return *n -= 1;
}

void up_Book(Book *b, int i, int n)
{
	int c;
	titledisplay();
	b[i].display();
	do
	{
		cout << "\n---------------------------------------------------------\n";
		cout << "\t\tSelect Any One";
		cout << "\n---------------------------------------------------------\n";
		cout << "\n\t1.Update Book Price\n\t2.Update Book Rating\n\t0.Exit\n";
		cout << "\n---------------------------------------------------------\n";
		cout << "\tEnter Your Choice:-  ";
		cin >> c;

		if (c == 1)
		{
			cout << "Enter Book Price:- ";
			double price;
			cin >> price;
			b[i].setprice(price);
			cout << "\n\t Price Updated Succesfully!\n";

			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tDo You Want to Update Again?";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Continue\n\t0.Exit\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;

			if (c != 1 || c != 0)
				cout << "\n\t Invalid Choice! Please Try Again\n";
		}
		else if (c == 2)
		{
			cout << "Enter Book Rating:- ";
			float rating;
			cin >> rating;
			b[i].setrating(rating);
			cout << "\n\t Rating Updated Succesfully!\n";

			cout << "\n---------------------------------------------------------\n";
			cout << "\t\tDo You Want to Update Again?";
			cout << "\n---------------------------------------------------------\n";
			cout << "\n\t1.Continue\n\t0.Exit\n";
			cout << "\n---------------------------------------------------------\n";
			cout << "\tEnter Your Choice:-  ";
			cin >> c;
			if (c != 1 && c != 0)
				cout << "\n\t Invalid Choice! Please Try Again\n";
		}
	} while (c != 0);
}

void settitle(title *ti)
{
	strcpy(ti[0].title, "ID");
	strcpy(ti[1].title, "Name");
	strcpy(ti[2].title, "Author");
	strcpy(ti[3].title, "Rating");
	strcpy(ti[4].title, "Price");
}
void titledisplay()
{
	// printf("\n----------------------------------------------------------------------------------------\n");
	// printf("%-8s| %-20s| %-20s| %-15s| %-15s|", ti[0].title, ti[1].title, ti[2].title, ti[3].title, ti[4].title);
	// printf("\n----------------------------------------------------------------------------------------\n");
	cout << "\n----------------------------------------------------------------------------------------\n";
	cout << left << setw(8) << ti[0].title << "| " << left << setw(20) << ti[1].title << "| " << left << setw(20) << ti[2].title << "| " << setw(15) << ti[3].title << "| " << setw(15) << ti[4].title << "|";
	cout << "\n----------------------------------------------------------------------------------------\n";
}

int searchid(Book *b, int n, int id)
{
	for (int i = 0; i < n; i++)
		if (b[i].getid() == id)
			return i;
	return -1;
}

int searchname(Book *b, char *nm, int n)
{
	for (int i = 0; i < n; i++)
		if (strcasecmp(b[i].getname(), nm) == 0)
			return i;
	return -1;
}

void searchauthor(Book *b, char *nm, int n)
{
	int c = 0;
	for (int i = 0; i < n; i++)
		if (strcasecmp(b[i].getauthor(), nm) == 0)
		{
			if (c == 0)
			{
				titledisplay();
				c++;
			}
			b[i].display();
		}
	if(c==0)
		cout << "\n\t Sorry Book Record Are NOT Found!\n";
}

Book *dup(Book *b, int n)
{
	// Book *p = (Book *)calloc(n, sizeof(Book));
	Book *p = new Book[n];
	for (int i = 0; i < n; i++)
		p[i] = b[i];
	return p;
}