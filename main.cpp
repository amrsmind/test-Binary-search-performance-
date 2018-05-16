#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

class  Searcher{
private:
    vector<string> words;
public:

void loadData(ifstream &file,int numofwords){
        string word;
        for(int i=0;i<numofwords;i++){
            file>>word;
            words.push_back(word);
        }

    }


int binarySearch(vector<string> arr, int l, int r, string x,int counter){
   counter++;
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        if (arr[mid] == x){
            counter++;
            return counter;}

        if (arr[mid] > x){
            counter++;
            return binarySearch(arr, l, mid-1, x,counter);
        }
        return binarySearch(arr, mid+1, r, x,counter);
   }

   return counter;
}

void testperformance(bool found,int trials,double &time,double &com){
    int numberofconditions = 0;
    double cumulativetime=0;
    if(found==1){
     int sizevector = words.size();
     random_device rd;
     mt19937 eng(rd());
     uniform_int_distribution<> distr(0, sizevector-1);
     for(int i=0;i<trials;i++){
     string randomwordinvector = words[distr(eng)];
//   cout<<distr(eng)<<endl;
     clock_t start,end;
     start = clock();
     numberofconditions+=binarySearch(words,0,words.size()-1,randomwordinvector,0);
     end = clock();
     double timeinmsecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC; // casting the difference between the time
     cumulativetime+=timeinmsecs;
     }
     double comparisonsaverage = numberofconditions/trials;
     double timeaverage = cumulativetime/trials;
     cout<<"Time average: "<<timeaverage<<" , comparisons average: "<<comparisonsaverage<<endl;
     time = timeaverage;
     com = comparisonsaverage;
      }

     else{
    string nonexistingword = "------";
        for(int i=0;i<trials;i++){
     clock_t start,end;
     start = clock();
     numberofconditions+=binarySearch(words,0,words.size()-1,nonexistingword,0);
     end = clock();
     double timeinmsecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC; // casting the difference between the time
     cumulativetime+=timeinmsecs;
     }
     double comparisonsaverage = numberofconditions/trials;
     double timeaverage = cumulativetime/trials;
     cout<<"Time average: "<<timeaverage<<" , comparisons average: "<<comparisonsaverage<<endl;
     time = timeaverage;
     com = comparisonsaverage;
     }
    }

//    void bigtest(ifstream &file,int constraint,bool foundword){
//        loadData(file,constraint);
//        testperformance(foundword,100);
//    }
};

int main()
{
    ifstream file("words.txt");
    Searcher s;
    double t;
    double c;
    ofstream file1("founded_chart.csv",ios::app);
    file1<<"number_of_words,"<<"average_comparisons,"<<"average_time"<<endl;
    for(int i=10000;i<=80000;i+=10000){
    s.loadData(file,i);
    s.testperformance(1,100,t,c);
    file1<<i<<","<<c<<","<<t<<endl;
   }
    ofstream file2("not_founded_chart.csv",ios::app);
        file2<<"number_of_words,"<<"average_comparisons,"<<"average_time"<<endl;

   for(int i=10000;i<=80000;i+=10000){
    s.loadData(file,i);
    s.testperformance(0,100,t,c);
    file2<<i<<","<<c<<","<<t<<endl;

   }
    file.close();




    return 0;
}
