using namespace std;
int main(){

    //10 characters;
    int i[] ={1,2,3,4,5};
    int *g = i;

    cout << g <<endl;

    int *c;

    *c = *g  ; // only value is passed to c, but the address of c is uncertain. though legal, it is prone to error.
    //*c++ = *g++; // after value assignment, each pointer increases their address for next element
    //c = g++;
    //cout << *c <<endl;
    cout << g <<endl;
    g++;
    cout << g <<endl;
    int f = *g;
    cout << f <<endl;
    return 0;
}