#include <iostream>
using namespace std;
#include "Mediatheque.cpp"
#include "Document.cpp"
#include "Client.cpp"
#include "Audio.cpp"
#include "Video.cpp"
#include "Livre.cpp"
#include "CategorieClient.cpp"
#include "FicheEmprunt.cpp"
#include "Genre.cpp"
#include "Localisation.cpp"
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
void bienvenue() ;

void gest_client (Mediatheque M) ;

void gest_doc (Mediatheque M) ;

void menu_emp(Mediatheque M) ;


void menuclient (Mediatheque M) ;

void mdpass() ;

void  menupr (Mediatheque M) ;

void gest_emp(Mediatheque M);

void retour(Mediatheque M,int a);

void quit_app();

int main()
{
Mediatheque M("Maktba");
bienvenue() ;
menupr(M);

    return 0;
}
void bienvenue()
{
    system("cls");
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t|                                                             |\n";
cout<<"\t\t\t|                Bienvenue dans la mediatheque                |\n";
cout<<"\t\t\t|                                                             |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
}

void gest_client (Mediatheque M)
{
bienvenue();
cout<<"\t\t\t|                      Espace Employe                         |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t|             1- Ajouter la categorie du client               |\n";
cout<<"\t\t\t|             2- Modifier la categorie du client              |\n";
cout<<"\t\t\t|             3- Supprimer la categorie du client             |\n";
cout<<"\t\t\t|             4- Inscrire un client                           |\n";
cout<<"\t\t\t|             5- Changer le categorie du client               |\n";
cout<<"\t\t\t|             6- Afficher les caracteristiques du client      |\n";
cout<<"\t\t\t|             7- Modifier les caracteristiques du client      |\n";
cout<<"\t\t\t|             8- Renouveler l'inscription du client           |\n";
cout<<"\t\t\t|             9- Resilier client                              |\n";
cout<<"\t\t\t|            10- Changer l'adresse du client                  |\n";
cout<<"\t\t\t|            11- Consulter les emprunts d'un client           |\n";
cout<<"\t\t\t|            12- Consulter la liste des clients               |\n";
cout<<"\t\t\t|            13- Retour                                       |\n";
cout<<"\t\t\t|             0- Quitter                                      |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t                    Tapez votre choix: ";
int choix  ;  cin>>choix  ;
system ("cls");

switch (choix)
{
  case 4: {
        tm tm1;
        tm1.tm_mday=30;
        tm1.tm_mon=12;
        tm1.tm_year=2020;
        Categorie_Client CC;
        Client C1(12345678,"Fekih","Samer","Sousse, Tunisia",&tm1,&CC);
        M.set_liste_client(&C1);gest_client (M);break;
        }
  case 11: {tm tm1;
        Localisation Loc("A15","15");
        Genre G("Genre",2);
        Video V(2,"V","v","2001",false,&G,&Loc,15,"mentionleg");
        M.set_liste_document(&V);
        tm1.tm_mday=30;
        tm1.tm_mon=12;
        tm1.tm_year=2020;
        Categorie_Client CC;
        Client C1(12345678,"Fekih","Samer","Sousse, Tunisia",&tm1,&CC);
        M.set_liste_client(&C1);
        Fiche_emprunt F(&tm1,&tm1,&tm1,&C1,&V);
        C1.set_fiche_emprunt(F);
        C1.AfficherFicheEmpruntsTot();retour(M,2);break;}
  case 12: {M.consulterListeClients();retour(M,2);break;}
  case 13 : menu_emp(M); break ;
  case 0:quit_app();break;

}
}

void gest_doc (Mediatheque M)
{
bienvenue();
cout<<"\t\t\t|                      Espace Employe                         |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t|               1- Ajouter un Audio                           |\n";
cout<<"\t\t\t|               2- Ajouter un livre                           |\n";
cout<<"\t\t\t|               3- Ajouter un video                           |\n";
cout<<"\t\t\t|               4- Rendre un document consultable             |\n";
cout<<"\t\t\t|               5- Rendre un document empruntable             |\n";
cout<<"\t\t\t|               6- Retirer un document                        |\n";
cout<<"\t\t\t|               7- Emprunter un document                      |\n";
cout<<"\t\t\t|               8- Restituer un document                      |\n";
cout<<"\t\t\t|               9- Retour                                     |\n";
cout<<"\t\t\t|               0- Quitter                                    |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t                Tapez votre choix: ";
int choix;
cin>>choix;
switch (choix)
{
case 9 : menu_emp(M) ;
break;
case 1:
    {
        Localisation Loc("A15","15");
        Genre G("Genre",2);
        Audio A(1,"A","a","2000",true,&G,&Loc,"audio");
        M.set_liste_document(&A);gest_doc(M);break;}
case 2:
    {
        Localisation Loc("A15","15");
        Genre G("Genre",2);
        Video V(2,"V","v","2001",false,&G,&Loc,15,"mentionleg");
        M.set_liste_document(&V);gest_doc(M);break;
    }
case 3:
    {
        Localisation Loc("A15","15");
        Genre G("Genre",2);
        Livre L(3,"L","l","2005",true,&G,&Loc,25);
        M.set_liste_document(&L);gest_doc(M);break;
    }
case 0:quit_app();break;
}
}

void menu_emp(Mediatheque M)
{ string m1;
   bienvenue();
cout<<"\t\t\t|                      Espace Employe                         |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t|               1- Gestion du client                          |\n";
cout<<"\t\t\t|               2- Gestion du document                        |\n";
cout<<"\t\t\t|               3- Trouver les emprunts en retard             |\n";
cout<<"\t\t\t|               4- Afficher les statistiques                  |\n";
cout<<"\t\t\t|               5- Consulter le catalogue des documents       |\n";
cout<<"\t\t\t|               6- Retour                                     |\n";
cout<<"\t\t\t|               0- Quitter                                    |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t                Tapez votre choix: ";
int choix  ;  cin>>choix  ;
system("cls");
switch (choix)

{  case 6 : menupr(M) ; break ;
   case 1 :gest_client(M) ;  break ;
   case 2 :gest_doc(M)    ;  break ;
   case 5: M.consulterCatalogueDocuments();
            retour(M,0);break;
   case 0:quit_app();break;
default : menu_emp(M) ;
} }

void menuclient (Mediatheque M)
{
bienvenue();
cout<<"\t\t\t|                      Espace Client                          |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t|                  1- Consulter catalogue document            |\n";
cout<<"\t\t\t|                  2- Consulter emprunts Client               |\n";
cout<<"\t\t\t|                  3- Pouvoir emprunter                       |\n";
cout<<"\t\t\t|                  4- Changer l'adresse                       |\n";
cout<<"\t\t\t|                  5- Retour                                  |\n";
cout<<"\t\t\t|                  0- Quitter                                 |\n";
cout<<"\t\t\t---------------------------------------------------------------\n";
cout<<"\t\t\t                Tapez votre choix: ";
int choix  ;  cin >>choix  ;
system ("cls");
switch (choix)
{  case 5:menupr (M) ;  break  ;
case 1: M.consulterCatalogueDocuments();
            retour(M,1);
            break;
case 0:quit_app();break;
default : menupr (M); } }


void  menupr (Mediatheque M)
{   int c ;
    bienvenue();
do{
            bienvenue();
            cout<<"\t\t\t|                     1- Espace Employe                       |\n";
            cout<<"\t\t\t|                     2- Espace Client                        |\n";
            cout<<"\t\t\t|                     3- Quitter                              |\n";
            cout<<"\t\t\t---------------------------------------------------------------\n";
            cout<<"\t\t\t                    Tapez votre choix: ";

cin>>c ;
system("cls");
}while ((c!=1)&&(c!=2)&&(c!=3)) ;
switch (c)
{
case 1 : mdpass();menu_emp(M);
break ;
case 2 :system("cls") ;menuclient(M); break;
case 3: quit_app();break;
default : system("cls") ;menupr (M);

do{
            bienvenue();
            cout<<"\t\t\t|                     1- Espace Employe                       |\n";
            cout<<"\t\t\t|                     2- Espace Client                        |\n";
            cout<<"\t\t\t|                     3- Quitter                              |\n";
            cout<<"\t\t\t---------------------------------------------------------------\n";
            cout<<"\t\t\t                    Tapez votre choix: ";
cin>>c;
bienvenue();
}while ((c!=1)&&(c!=2)&&(c!=3)) ;
}
}
void retour(Mediatheque M,int a)
{
    cin.ignore();
    do {
     cout<<"\n\t\t\t--------------------------------------------------------------------------\n";
     cout<<"\t\t\t--------------------------------------------------------------------------\n";
     cout << '\n' << "\t\t\t\tAppuyez sur ENTRER pour retourner au menu precedente...";
   } while (cin.get() != '\n');
    if (a==0)
    {
        menu_emp(M);
    }
    else if (a==1)
    {
        menuclient(M);
    }
    else if (a==2)
    {
        gest_client(M);
    }
    else if(a==3)
    {
        gest_doc(M);
    }
}
void quit_app()
{
    cout<<"\t\t\t---------------------------------------------------------------\n";
    cout<<"\t\t\t|               Vous avez quitte la Mediatheque !             |\n";
    cout<<"\t\t\t|                  Merci pour votre visite :)                 |\n";
    cout<<"\t\t\t---------------------------------------------------------------\n";
    exit(0);
}
string getpass()
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;
  DWORD con_mode;
  DWORD dwRead;

  HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

  GetConsoleMode( hIn, &con_mode );
  SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                     cout <<"\b \b";
                    password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             cout <<'*';
         }
    }
  cout <<endl;
  return password;
}
void mdpass()
{
            const char ENTER = 13;
            string id,mdp;
            bienvenue();
            cout<<"\t\t\t|                      Espace Employe                         |\n";
            cout<<"\t\t\t---------------------------------------------------------------\n";
            cout<<"\t\t\t                  Identifiant: ";cin>>id;
            cout<<"\t\t\t                  Mot de passe: ";mdp=getpass();
            cout<<"\t\t\t---------------------------------------------------------------\n";
            while (id!="EMPLOYE"||mdp!="EMPLOYE")
            {
                cout<<"\t\t\t              Votre mot de passe est incorrect. \n";
                cin.ignore();
                cout << '\n' << "\t\t\t              Appuyez sur ENTREE pour reessayer.";
                do {
                } while (_getch() != ENTER);
                system("cls");
                bienvenue();
                cout<<"\t\t\t|                      Espace Employe                         |\n";
                cout<<"\t\t\t---------------------------------------------------------------\n";
                cout<<"\t\t\t                  Identifiant: ";cin>>id;
                cout<<"\t\t\t                  Mot de passe: ";mdp=getpass();
                cout<<"\t\t\t---------------------------------------------------------------\n";
            }
}


