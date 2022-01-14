#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int liczba_wierzcholkow_grafu(vector<vector<int>> graf)
{
    int max_wierzcholek=-1;
    for(int i=0;i<graf.size();i++)
    {
        max_wierzcholek=max(max_wierzcholek,graf[i][0]);
        max_wierzcholek=max(max_wierzcholek,graf[i][1]);
    }
    return max_wierzcholek;
}
vector<vector<int>> wczytaj_graf(string nazwa_pliku)
{
    vector<vector<int>> graf;
    ifstream plik;
    plik.open(nazwa_pliku);
    while(!plik.eof())
    {
        int a,b;
        plik>>a>>b;
        graf.push_back({a,b});
    }
    return graf;
}
void wypisz_graf(vector<vector<int>> graf)
{
    for(int i=0;i<graf.size(); i++)
    {
        cout<<graf[i][0]<<" "<<graf[i][1]<<"\n";
    }
}
void wszyscy_sasiedzi(vector<vector<int>> graf)
{
    int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
    cout<<"Sasiedzi kazdego wierzcholka: \n";
    for(int i=0;i<=liczba_wierzcholkow;i++) //iterujemy si? po wszystkich wierzcho?kach
    {
        vector<bool> sasiedzi( liczba_wierzcholkow); //
        for(int j=0;j<=liczba_wierzcholkow;j++) // zerujemy vector
        {
            sasiedzi[j]=false;
        }
        for(int j=0;j<graf.size();j++) // dla kazdej krawedzi sprawdzamy czy jej poczatek jest wi czyli i
        {
            if(graf[j][0]==i)
            {
                sasiedzi[j]=true;
            }
        }
        cout<<"wierzcholek: "<<i<<" jego sasiedzi: \n";
        for(int j=0;j<=liczba_wierzcholkow;j++)
        {
            if(sasiedzi[j]==true)
            {
                cout<< j<< " ";
            }
        }
        cout<<"\n";
    }
}
void wszystkie_wierzcholki_sasiedzi_wszystkich_wiercholkow(vector<vector<int>> graf)
{
    int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
    cout<<"wierzcholki ktore jest sasiadami wszystkich wierzchokow: \n";
    for(int i=0;i<=liczba_wierzcholkow;i++) //iterujemy po wszystkich wierzcholkach
    {
        vector<bool> sasiedzi( liczba_wierzcholkow); //
        for(int j=0;j<=liczba_wierzcholkow;j++) // zerujemy vector
        {
            sasiedzi[j]=false;
        }
        for(int j=0;j<graf.size();j++) // dla kazdej krawedzi sprawdzamy czy jej koniec jest wi czyli i
        {
            if(graf[j][1]==i)
            {
                sasiedzi[graf[j][0]]=true;
            }
        }
        bool flag=true;
        for(int j=0;j<=liczba_wierzcholkow;j++)
        {
            if(sasiedzi[j]==false)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            cout<<i<<"\n";
        }
    }
}

void stopnie_wychodzace(vector<vector<int>> graf)
{
      int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
      cout<<"stopnie wychodzace wierzcholkow: \n";
      for(int i=0;i<=liczba_wierzcholkow;i++) //iterumey si? po wszystkich wierzcho?kach
      {
          int stopien=0;
          for(int j=0;j<graf.size(); j++)
          {
              if(graf[j][0]==i)
              {
                  stopien++;
              }
          }
        cout<<"stopnie wychodzace wierzcholka "<<i<<" to: "<<stopien<<"\n";
      }
}

void stopnie_wchodzace(vector<vector<int>> graf)
{
      int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
      cout<<"stopnie wchodzace wierzcholkow: \n";
      for(int i=0;i<=liczba_wierzcholkow;i++) //iterumey si? po wszystkich wierzcho?kach
      {
          int stopien=0;
          for(int j=0;j<graf.size(); j++)
          {
              if(graf[j][1]==i)
              {
                  stopien++;
              }
          }
        cout<<"stopnie wchodzace wierzcholka "<<i<<" to: "<<stopien<<"\n";
      }
}
void wiezcholki_izolowane(vector<vector<int>> graf)
{
    int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
    cout<<"wierzcholki izolowane: \n";
    for(int i=0;i<=liczba_wierzcholkow;i++) //iterumey po wszystkich wierzcho?kach
    {
        int stopien=0;
        for(int j=0;j<graf.size(); j++)
        {
            if(graf[j][1]==i)
            {
                stopien++;
            }
        }
        if(stopien==0)
        {
            cout<< i<< "\n";
        }
    }
}
void petle(vector<vector<int>> graf)
{
    int liczba_wierzcholkow=liczba_wierzcholkow_grafu(graf);
    vector<bool> petle(liczba_wierzcholkow);
    for(int i=0;i<liczba_wierzcholkow;i++)
    {
        petle[i]=false;
    }
    for(int i=0;i<graf.size();i++)
    {
        if(graf[i][0]==graf[i][1])
        {
            petle[graf[i][0]]=true;
        }
    }
    cout<<"wszystkie wierzcholki ktore posiadaja petle: \n";
    for(int i=0;i<liczba_wierzcholkow;i++)
    {
        if(petle[i]==true)
        {
            cout<<i<<"\n";
        }
    }
}
void krawedzi_dwustronne(vector<vector<int>> graf)
{
    vector<bool> krawedzie(graf.size());
     for(int i=0;i<krawedzie.size();i++)
    {
        krawedzie[i]=false;
    }
    for(int i=0;i<graf.size()-1; i++)
    {
        for(int j=i+1; j<graf.size(); j++)
        {
            if(graf[i][0]==graf[j][1] && graf[i][1]==graf[j][0])
            {
                krawedzie[i]=true;
            }
        }
    }
    cout<<"krawedzie dwustronne: \n ";
    for(int i=0;i<krawedzie.size(); i++)
    {
        if(krawedzie[i]==true)
        {
            cout<<graf[i][0]<<" "<<graf[i][1]<< " i "<<graf[i][1]<<" "<<graf[i][0]<<"\n";
        }
    }
}
void zapisz_graf_do_pliku(vector<vector<int>> graf, string nazwa_pliku)
{
    ofstream plik(nazwa_pliku);
    for(int i=0;i<graf.size(); i++)
    {
        plik<<graf[i][0]<<" "<<graf[i][1]<<"\n";
    }
}
int main()
{
   vector<vector<int>>graf;
   graf=wczytaj_graf("graf.txt");
   wszyscy_sasiedzi(graf);
   wypisz_graf(graf);
   wszystkie_wierzcholki_sasiedzi_wszystkich_wiercholkow(graf);
   stopnie_wychodzace(graf);
   stopnie_wchodzace(graf);
   wiezcholki_izolowane(graf);
   petle(graf);
   krawedzi_dwustronne(graf);
   zapisz_graf_do_pliku(graf,"Sabina.txt");

    return 0;
}
