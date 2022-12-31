#include <stdio.h>

#include <string.h>

#include <iostream>

#include <fstream>

#include <cctype>

using namespace std;

const int MAX_SIZE = 99;

bool CheckWord(string search) {
  int length;
  string ligne;
  ifstream Myfile;
  ifstream monFichier("ods4.txt");

  if (!monFichier.is_open()) {
    cerr << "Erreur lors de l'ouverture du fichier" << endl;
    return 1;
  }

  while (getline(monFichier, ligne)) {
    length = ligne.length();
    ligne = ligne.substr(0, length - 1);

    if (ligne == search) {
      monFichier.close();
      return true;
    }
  }

  monFichier.close();
  return false;
}

string CheckLetterWord(string lettres) {

  string line;
  string searchString;
  string wordchoise;
  string lettretoadd;
  int placetoletter = lettres.size();

  searchString = lettres;
  ifstream file("ods4.txt");

  if (file.is_open()) {
    while (getline(file, line)) {
      int lineLength = line.length(); 

      string word = ""; 

      for (int i = 0; i < lineLength; i++) 
      {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r') {
          if (word.find(lettres) == 0) {

            wordchoise = word;

          }

          word = "";
        } else {
          word += line[i];

        }
      }

    }

    file.close();
  } else {
    cout << "Impossible d'ouvrir le fichier" << endl;
  }

  if (!wordchoise.empty()) {
    lettretoadd = wordchoise[placetoletter];
    wordchoise = "";
    return lettretoadd;
  } else {
    srand(time(NULL));
    int nombreAleatoire = rand() % 26;
    char lettreAleatoire = 'A' + nombreAleatoire;
    string s(1, lettreAleatoire);
    return s;
  }

}

string FindLetterWord(string lettres) {

  string line;
  string searchString;
  string wordchoise;
  string lettretoadd;

  searchString = lettres;
  ifstream file("ods4.txt");

  if (file.is_open()) {
    while (getline(file, line)) {
      int lineLength = line.length();

      string word = ""; 

      for (int i = 0; i < lineLength; i++)
      {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r') {
          if (word.find(lettres) == 0) {

            wordchoise = word;

          }

          word = "";
        } else {
          word += line[i];

        }
      }

    }

    file.close();
  } else {
    cout << "Impossible d'ouvrir le fichier" << endl;
  }

  return wordchoise;

}

int main(int argc, char * argv[]) {
  int i, u(0), j(0), l(0), t(0), z(0), taillelettres(0), nmb_partie(0), num_perdant, num_perdant_tab, gagnant(0), perdant(0), partie_finie(0), resultat_fonc, nmbjoueur(0), placejoueur_r, placejoueur_d;
  string mot_test, str = "", resultat_fonc_1, wordfind;
  char lettre;
  char * lettres = new char[MAX_SIZE];
  char * joueur = new char[strlen(argv[argc - 1])];
  nmbjoueur = strlen(argv[argc - 1]);
  float score[nmbjoueur];
  joueur = argv[argc - 1];

  for (z = 0; z < nmbjoueur; z++) {
    joueur[z] = joueur[z] - 'a' + 'A';
  }

  for (i = 0; i < nmbjoueur + 1; i++)

  {
    score[i] = 0;

  }

  for (i = 0; joueur[i] == nmbjoueur; ++i) {
    cout << joueur[i] << "\n";
  }

  while (partie_finie == 0) {
    nmb_partie = nmb_partie + 1;
    cout << "\n\n" << "Partie n°" << nmb_partie << "\n\n";
    while (gagnant == 0 || perdant == 0) {
      for (u = 0; u < nmbjoueur; ++u) {

        cout << u + 1 << joueur[u] << "(";
        taillelettres = strlen(lettres);
        cout << lettres;
        cout << ") > ";
        if (joueur[u] == 'R') {

          string s = lettres;
          resultat_fonc_1 = CheckLetterWord(s);
          cout << "\n";
          lettres[taillelettres] = resultat_fonc_1[0];
          taillelettres++;

        } else {
          cout << " ";
          string input;
          cin >> input;
          lettre = input[0];

          while (!isalpha(lettre) && !(lettre == '?' || lettre == '!')) {
            cout << "\nIl s'agit d'un chiffre ou d'un caractère special non autorisé, veuillez recommencer !\n";
            cout << u + 1 << joueur[u] << "(";
            taillelettres = strlen(lettres);
            cout << lettres;
            cout << ") > ";
            cin >> input;
            lettre = input[0];
          }

          if (lettre == '?') {
            if (taillelettres == 0) {
              cout << "La liste des lettres est vide, commande impossible !\n";
              break;
              break;
            }

            if (u == 0) {
              cout << " - " << u + 1 << joueur[u] << " demande à " << nmbjoueur << joueur[nmbjoueur - 1] << " à quel mot il pense : ";
              placejoueur_d = nmbjoueur;
              placejoueur_r = nmbjoueur - 1;
            } else {
              cout << " - " << u + 1 << joueur[u] << " demande à " << u << joueur[u - 1] << " à quel mot il pense : ";
              placejoueur_d = u;
              placejoueur_r = u - 1;
            }

            if (joueur[placejoueur_r] == 'R') {
              wordfind = FindLetterWord(lettres);
              if (!wordfind.empty()) {
                str = wordfind;
                cout << str;
              } else {
                cout << "Pas trouvé";
                str = lettres;
              }

            } else {
              cin >> str;

              for (t = 0; t < str.length(); ++t) {
                str[t] = str[t] - 'a' + 'A';
              }

            }

            resultat_fonc = CheckWord(str);

            if (resultat_fonc) {

              cout << "\nLe mot " << str << " existe dans le dictionnaire donc " << placejoueur_d + 1 << joueur[placejoueur_d] << " se prend un quard de singe. \n";
              perdant = 1;
              gagnant = 1;
              num_perdant = placejoueur_d + 1;
              num_perdant_tab = placejoueur_d;
              break;
              break;
              break;

            } else {

              cout << "\nLe mot " << str << " n'existant pas dans le dictionnaire donc " << placejoueur_r + 1 << joueur[placejoueur_r] << " se prend un quard de singe. \n";
              perdant = 1;
              gagnant = 1;
              num_perdant = placejoueur_r + 1;
              num_perdant_tab = placejoueur_r;
              break;
              break;
              break;
            }

          } else if (lettre == '!') {
            cout << " - " << u + 1 << joueur[u] << " Abandonne, il prend donc un quart de singe\n";
            perdant = 1;
            gagnant = 1;
            num_perdant = u + 1;
            num_perdant_tab = u;
            break;
            break;
            break;
          } else {
            if (lettre >= 'a' && lettre <= 'z') {
              lettre -= 'a' - 'A';
            }
            lettres[taillelettres] = lettre;
            taillelettres++;
          }
        }
      }
    }
    for (int p = 0; p < MAX_SIZE; p++) {
      lettres[p] = '\0';
    }

    cout << "\nLe perdant est : " << num_perdant << joueur[num_perdant_tab] << "; \n";
    score[num_perdant - 1] = score[num_perdant - 1] + 0.25;

    for (l = 0; l < nmbjoueur; l++) {
      cout << l + 1 << joueur[l] << ": ";
      cout << score[l] << "; ";
    }
    gagnant = 0;
    num_perdant = 0;
    for (j = 0; j < nmbjoueur; j++) {
      if (score[j] == 1) {
        cout << "\n\nLes Parties sont finies, " << j + 1 << joueur[j] << " est le grand perdant ! \n\n";
        goto finished;
      }
    }
  }
  finished:
    exit(1);
}
