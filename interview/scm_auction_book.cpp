#include <iostream>
#include <vector>
#include <map>
using namespace std;

// hackerrank coding challenge by Stevens capital management

/*  clearing price is the price which maximize the trading volume of buy/sell orders
 * if multiple prices maximize the matched volume, choose the lowest price
 * at clearing price, all buy orders above it are filled or all sell orders below it are filled
 * if the highest buy price is lower than the lowest sell price, no deal is made, clearing price is 0
 */

struct Order{
    Order(int _price, int _size, char _dir): price(_price), size(_size), dir(_dir){}
    int price;
    int size;
    char dir;
};

int getclearingPrice(const vector<Order> & orders){
    int record = 0; // record volume
    int sellsize = 0; // sell volume
    int clp = 0; // clearing price
    map<int,int> buy;
    map<int,int> sell;
    for (Order order: orders){
        if (order.dir == 'B' && order.size > 0)
            buy[order.price] = order.size;
        if (order.dir == 'S' && order.size > 0)
            sell[order.price] = order.size;
    }
    // loop through sell price
    for (auto s:sell){
        int ask = s.first; // ask price
        int buysize = 0; // total buysize
        sellsize += s.second;
        cout << "ask:" <<ask<<endl;
        for (auto b:buy){
            if (b.first < ask)
                continue;  // buy price too low
            else{
                if (buysize + b.second < sellsize )
                    buysize += b.second;
                else {
                    buysize = sellsize; // sold out
                    break;
                }

            }
        } // end buy loop
        // check the transaction volume at this price
        if (buysize> record){
            clp = ask;
            record = buysize;
            cout << "clear at:"<<clp <<", transaction volume:" <<record <<endl;
        }
    }// end sell loop
    return clp;
}


int main ()
{
    vector<Order> orders;
    /*
    Order a(50,100,'B');
    orders.push_back(a);
    Order b(48,100,'S');
    orders.push_back(b);
    */
    Order a(50,100,'B');
    orders.push_back(a);
    Order a2(51,150,'B');
    orders.push_back(a2);
    Order b(49,200,'S');
    orders.push_back(b);

    getclearingPrice(orders);

    return 0;
}
