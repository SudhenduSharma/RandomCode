#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

enum class OrderType
{
    GFD,
    IOC,
    INVALID
};

static std::unordered_map<std::string,OrderType> const orderTypeTable = { {"GFD",OrderType::GFD}, 
    {"IOC",OrderType::IOC}
};


enum class ReturnValues
{
    BUY_ORDER,
    SELL_ORDER,
    ORDER_NOT_FOUND
};

enum class OperationType
{
    BUY,
    SELL,
    CANCEL,
    MODIFY,
    PRINT,
    INVALID
};

static std::unordered_map<std::string,OperationType> const optypeTable = { {"BUY",OperationType::BUY}, 
    {"SELL",OperationType::SELL}, 
    {"CANCEL",OperationType::CANCEL},
    {"MODIFY",OperationType::MODIFY},
    {"PRINT",OperationType::PRINT},
    {"INAVALID",OperationType::INVALID}
};
OperationType deduceOpearation(const std::string& token)
{
    auto it = optypeTable.find(token);
    if (it != optypeTable.end()) {
        return it->second;
    } 
    return OperationType::INVALID;
}

OrderType deduceOrderType(const std::string& token)
{
    auto it = orderTypeTable.find(token);
    if (it !=  orderTypeTable.end()) {
        return it->second;
    } 
    return OrderType::INVALID;
}


struct Order
{
    std::string id;
    int price;
    int quantity;
    bool isBuy;

    Order(const std::string& oid, const int&  pr,const int& qty,bool isBuyOrder)
        :id(oid),
        price(pr),
        quantity(qty),
        isBuy(isBuyOrder)
    {}
};

struct PriceMatchedOrders
{
    std::vector<Order*> ordersOfSamePrice;
    int quantity;
    int price;

};

//auto less_comp = [](PriceMatchedOrders x, PriceMatchedOrders y){ return x.price < y.price; };
//auto greater_comp = [](PriceMatchedOrders x, PriceMatchedOrders y){ return x.price > y.price; };
struct greater_comp
{
    //bool operator()(const PriceMatchedOrders& x, const PriceMatchedOrders& y) const
    bool operator()(const int& x, const int& y) const
    {
        //return x.price < y.price;
        return x< y;
    }
};

struct less_comp
{
    //bool operator()(const PriceMatchedOrders& x, const PriceMatchedOrders& y) const
    bool operator()(const int& x, const int& y) const
    {
        return x > y;
        //return x.price > y.price;
    }
};

struct OrderBook
{

    //typedef std::unordered_map<string,Order> order_map_t;
    typedef std::map<int,PriceMatchedOrders,greater_comp> sell_order_t;
    typedef std::map<int,PriceMatchedOrders,less_comp> buy_order_t;
    std::unordered_map<string,Order> orders;
    sell_order_t sellOrders;
    buy_order_t buyOrders;

    void Print()
    {
        std::cout<<"SELL:"<<std::endl;
        for(auto it = sellOrders.rbegin(); it != sellOrders.rend(); ++it)
        {
            std::cout<<it->first<<" "<<it->second.quantity<<std::endl;
        }
        std::cout<<"BUY:"<<std::endl;
        for(auto it = buyOrders.begin(); it != buyOrders.end(); ++it)
        {
            std::cout<<it->first<<" "<<it->second.quantity<<std::endl;
        }
    }

    void DebugPrintMap()
    {
        std::cout << "----Buy Orders--- " << std::endl;
        for(auto it = buyOrders.begin(); it != buyOrders.end(); ++it)
        {
            std::cout << it->first << " " << it->second.quantity << std::endl;
            for(auto& it_v : it->second.ordersOfSamePrice)
            {
                std::cout << " " << it_v->quantity << " ";
            }
            std ::cout << std::endl;
        }
        std::cout << "----Sell Orders --- " << std::endl;
        for(auto it = sellOrders.begin(); it != sellOrders.end(); ++it)
        {
            std::cout << it->first << " " << it->second.quantity << std::endl;
            for(auto& it_v : it->second.ordersOfSamePrice)
            {
                std::cout << " " << it_v->quantity << " ";
            }
            std ::cout << std::endl;
        }
        std::cout << "---All Orders --- " << std::endl;
        for(auto& it_all: orders)
        {
            std::cout << "key " << it_all.first << " id " << it_all.second.id << " pr "  << it_all.second.price << " qt " << it_all.second.quantity   << " isBuy " << it_all.second.isBuy  << endl;
        }
    }


    template<bool IsBuy>
        std::enable_if_t<IsBuy,buy_order_t&>
        getOrders()
        {
            return buyOrders;
        }

    template<bool IsBuy>
        std::enable_if_t<!IsBuy,sell_order_t&>
        getOrders()
        {
            return sellOrders;
        }

    template<bool IsBuy>
        void cleanOrder(std::vector<Order*> orders)
        {
            auto& orderMap = getOrders<IsBuy>();
            for(auto it = orders.begin(); it!= orders.end(); ++it)
            {
                auto itSell = orderMap.find((*it)->price);
                auto &priceMatchedOrders = itSell->second.ordersOfSamePrice;
                priceMatchedOrders.erase(std::remove_if(priceMatchedOrders.begin(),
                            priceMatchedOrders.end(),
                            [](const Order* e){return (e->quantity == 0);}), priceMatchedOrders.end() );
                if(priceMatchedOrders.size() == 0)
                {
                    orderMap.erase(itSell);

                }
                this->orders.erase((*it)->id);
            }

        }

    template<bool IsBuy>
        bool Check(const int& tradePrice ,const int& indexPrice)
        {
            bool ret = false; 
            if(!IsBuy)
            {
                ret = (indexPrice <= tradePrice);
                //std::cout << " tradePrice " << tradePrice << "indexprice " << indexPrice <<  " ret " << ret << std::endl;
                return ret;
            }
            else
            {
                ret = (indexPrice >= tradePrice);
                //std::cout << "  NOT  BUY tradePrice " << tradePrice << " indexprice " << indexPrice <<  " ret " << ret << std::endl;
                return ret;
            }

        }

    template<bool IsBuy>
        int handleTrade(const std::string& id, const int&  price,const int& quantity)
        {
            auto& orderMap = getOrders<IsBuy>();;
            auto quantityAsked = quantity;
            //std::cout << " handleTrade quantityAsked "  << quantityAsked << " on price " << price << std::endl;
            std::vector<Order*> orders2Sweep;
            for(auto itOrd = orderMap.begin();itOrd!=orderMap.end() ; ++itOrd)
            {
                //std::cout << "itOrd->second.quantity available " << itOrd->second.quantity  << " on price " << itOrd->second.price  << std::endl;
                //loop until quantityAsked is not fullfilled or list is empty
                for(auto itPriceMatched = itOrd->second.ordersOfSamePrice.begin();itPriceMatched != itOrd->second.ordersOfSamePrice.end() && Check<IsBuy>(price, itOrd->first) && quantityAsked;itPriceMatched++)
                {
                    /*if((*itPriceMatched)->quantity == 0)
                    {
                        std::cout << "DEBUG LOGIC ERROR " << __LINE__ << endl;
                        continue;
                    }
                    */
                    if(quantityAsked >= (*itPriceMatched)->quantity)
                    {
                        //DebugPrintMap();
                        //std::cout << "Trade order-price " << price << "matched with price " << (*itPriceMatched)->price << " " << (*itPriceMatched)->quantity << endl;
                        quantityAsked -= (*itPriceMatched)->quantity;
                        //reduce available quantity by order matched
                        itOrd->second.quantity -= (*itPriceMatched)->quantity;
                        //delete from hash map of orders
                        //std::cout << "handleBuyTrade:sweeped quantityAsked "  << quantityAsked << std::endl;
                        //delete the matched order
                        orders2Sweep.push_back(*itPriceMatched);
                        std::cout<<"TRADE " << (*itPriceMatched)->id << " " << (*itPriceMatched)->price << " "<< (*itPriceMatched)->quantity << " " << id << " " << price << " " << (*itPriceMatched)->quantity << endl;

                        (*itPriceMatched)->quantity = 0;
                        //if(quantityAsked == 0)
                        //    break;

                        //following code is making iterators invalid 
                        //itPriceMatched = itOrd->second.ordersOfSamePrice.erase(itPriceMatched);
                        //orders.erase((*itPriceMatched)->id);
                    }
                    else
                    {
                        //DebugPrintMap();
                        //std::cout << "handleBuyTrade:sweeped all quantityAsked "  << quantityAsked << std::endl;
                        //std::cout << "Trade order-price " << price << "matched with price " << (*itPriceMatched)->price << " " << quantityAsked << endl;
                        (*itPriceMatched)->quantity -= quantityAsked;
                        itOrd->second.quantity -= quantityAsked;
                        std::cout<<"TRADE " << (*itPriceMatched)->id << " "  << (*itPriceMatched)->price << " "<< quantityAsked << " " << id << " " << price << " " << quantityAsked << endl;
                        quantityAsked = 0;
                        //break;
                    }
                }
            }
            //cleanUpSellOrder false == sell
            cleanOrder<IsBuy>(orders2Sweep);
            if(quantityAsked)
            {
                //std::cout << "could not process remaining " << quantityAsked << std::endl;
            }
            return quantityAsked;
        }

    ReturnValues removeOrderById(const std::string& id)
    {
        ReturnValues ret = ReturnValues::ORDER_NOT_FOUND;
        auto it = orders.find(id);
        //std::cout << "remove id " << id <<endl;
        //DebugPrintMap();
        if(it == orders.end())
        {
            //std::cout << "DEBUG Order not found " << __LINE__ <<endl;
            return ReturnValues::ORDER_NOT_FOUND;
        }
        int price = it->second.price;
        int quantity = it->second.quantity;
        bool isBuy =  it->second.isBuy;
        //std::cout << "DEBUG removeOrderById " << isBuy <<  " " << __LINE__ <<endl;
        if(it!= orders.end())
        {
            if(isBuy)
            {
                ret = ReturnValues::BUY_ORDER;
                removeOrder<true>(id,price,quantity);
            }
            else
            {
                ret = ReturnValues::SELL_ORDER;
                removeOrder<false>(id,price,quantity);
            }
            orders.erase(it);
        }
        else
        {
            std::cout << " order not found : removeOrder: id "  << id  << " price " << price  << " quantity " << quantity << " " << __LINE__ << std::endl;
        }
        //DebugPrintMap();
        return ret;
    }
    template<bool IsBuy>
        bool removeOrder(const std::string& id, const int&  price,const int& quantity)
        {
            auto& orderMap = getOrders<IsBuy>();;
            //std::cout << " DEBUG order found in all order map : removeOrder: id "  << id  << " price " << price  << " quantity " << quantity << " " << __LINE__ << std::endl;
            auto it_buy_sell = orderMap.find(price);
            if(it_buy_sell != orderMap.end())
            {
                //std::cout << " DEBUG order found in  buy/sell map : removeOrder: id "  << id  << " price " << price  << " quantity " << quantity << " " << __LINE__ << std::endl;
                //TODO remove order from vector
                //Order* p = &pairObj.first->second;
                auto &priceMatchedOrders = it_buy_sell->second.ordersOfSamePrice;
                priceMatchedOrders.erase(std::remove_if(priceMatchedOrders.begin(),
                        priceMatchedOrders.end(),
                        [&id](const Order* e){return (e->id == id);}), priceMatchedOrders.end() );
                it_buy_sell->second.quantity -= quantity;
                if(it_buy_sell->second.quantity == 0)
                    orderMap.erase(it_buy_sell);

            }
            else
            {
                std::cout << "LOGIC ERROR " << __LINE__ << std::endl;
                return false;
            }
            return true;
        }

    template<bool isBuy>
        bool addOrder(const std::string& id, const int&  price,const int& quantity)
        {
            auto pairObj = orders.emplace(std::piecewise_construct,
                    std::forward_as_tuple(id),
                    std::forward_as_tuple(id, price,quantity,isBuy));
            if(pairObj.second)
            {
                //insertion successful
                //insert into buy sell
                auto& orderMap = getOrders<isBuy>();
                auto it = orderMap.find(price);
                if(it != orderMap.end())
                {
                    //Order* p = &pairObj.first->second;
                    it->second.ordersOfSamePrice.push_back(&pairObj.first->second);
                    it->second.quantity += quantity;
                }
                else
                {
                    PriceMatchedOrders ord;
                    ord.price = price;
                    ord.quantity = quantity;
                    ord.ordersOfSamePrice.push_back(&pairObj.first->second);
                    orderMap[price] = ord;
                }
            }
            else
            {
                //order already exist
                std::cout << "order exists" << std::endl;
            }
            //DebugPrintMap();
            return pairObj.second;
        }

    bool isMatch(const int& buyPrice, const int& sellPrice)
    {
        if(buyPrice >= sellPrice)
        {
            //std::cout << "match found --> Trade" << std::endl; 
            return true;
        }
        return false;
    }

    template<bool IsBuy>
        bool match(const int& offerPrice )
        {
            //if buy order check on sell side map
            auto& orderMap = getOrders<!IsBuy>();
            if(orderMap.begin() != orderMap.end())
            {
                //std::cout << "Orders.begin " << orderMap.begin()->first << " offerPrice " << offerPrice << endl;
                if(IsBuy)
                {
                    return isMatch(offerPrice , orderMap.begin()->first);
                }
                else
                {
                    return isMatch(orderMap.begin()->first,offerPrice);
                }
            }
            return false;
        }


};
bool ParseCancel(const vector<std::string>& tokens, std::string& id)
{
    if(tokens.size() != 2)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }
    id = tokens[1];
    return true;
}
bool ParseBuySell(const vector<std::string>& tokens,OrderType &outOrderType,int &price,int& quantity, std::string& id)
{
    if(tokens.size() != 5)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }

    outOrderType = deduceOrderType(tokens[1]);
    if(outOrderType == OrderType::INVALID)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }
    std::string::size_type sz;
    try
    {
        price = std::stoi (tokens[2],&sz);
        quantity = std::stoi (tokens[3],&sz);
    }
    catch(...)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }
    id = tokens[4];
    return true;
}

bool ParseModify(const vector<std::string>& tokens,OperationType &outOpType,int &price,int& quantity, std::string& id)
{
    //#MODIFY order1 SELL 1 84
    if(tokens.size() != 5)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }
    /*
       for(auto& tk : tokens )
       {
       cout << tk << endl;
       }
       */
    id = tokens[1];

    outOpType = deduceOpearation(tokens[2]);

    std::string::size_type sz;
    try
    {
        price = std::stoi (tokens[3],&sz);
        quantity = std::stoi (tokens[4],&sz);
    }
    catch(...)
    {
        std::cout << "INVALID INPUT " << __LINE__ << endl;
        return false;
    }
    return true;
}



class OrderHandler 
{
    public :
        template<OperationType operationType>
            void handleOrder(std::vector <std::string>& tokens);
        template<bool IsBuy>
            void handleBuySell(const std::string& id,const int& price,const int& quantity,bool isGfd);
        ReturnValues removeOrderById(const std::string& id);
    public : 
        OrderBook orderBook;
};

ReturnValues OrderHandler::removeOrderById(const std::string& id)
{
    return orderBook.removeOrderById(id);
}

    template<bool IsBuy>
void OrderHandler::handleBuySell(const std::string& id,const int& price,const int& quantity,bool isGfd)
{
    int remaining =  0;
    if(orderBook.match<IsBuy>(price))
    {
        //remaining =  orderBook.handleBuyTrade("id11", 100,350);
        remaining =  orderBook.handleTrade<!IsBuy>(id, price,quantity);
        //std::cout << " remaining " << remaining << " "<< __LINE__ << endl;
        if(remaining > 0 && isGfd)
            orderBook.addOrder<IsBuy>(id, price,remaining);
        else if(remaining == 0)
        {
            //NO Op
        }
        else
        {
            //std::cout << "LOGIC ERROR " << __LINE__ << std::endl;
        }
    }
    else if(isGfd)
    {
        orderBook.addOrder<IsBuy>(id, price,quantity);
    }
    else
    {
        //IOC order don't store
    }
}


    template<>
void OrderHandler::handleOrder<OperationType::BUY>(std::vector <std::string>& tokens)
{
    int price;
    int quantity; 
    std::string id;
    OrderType outOrderType;
    if(!ParseBuySell(tokens,outOrderType,price,quantity,id))
    {
        std::cout << "INPUT ERROR " << __LINE__ << std::endl;
        return;
    }

    if(price<=0 || quantity <= 0 || id.empty())
        return;
    bool isGfd = (outOrderType == OrderType::GFD)? true:false;
    handleBuySell<true>(id ,price, quantity,isGfd);

    // std::cout << "id " << id << " price "  << price  << " quantity " << quantity << __LINE__ << endl;
    //std::cout << "handle BUY" << endl;
    /*
       int remaining =  0;
       if(orderBook.match<false>(100))
       {
    //remaining =  orderBook.handleBuyTrade("id11", 100,350);
    remaining =  orderBook.handleTrade<false>(id, price,quantity);
    std::cout << " remaining " << remaining << endl;
    if(remaining > 0)
    orderBook.addOrder<true>(id, price,remaining);
    else
    {
    std::cout << "LOGIC ERROR " << __LINE__ << std::endl;
    }
    }
    else
    {
    orderBook.addOrder<true>(id, price,quantity);
    }
    */
    /*
    //std::cout <<"BUY handler" << std::endl;

    orderBook.addOrder<false>("id8", 100,55);
    orderBook.addOrder<false>("id9", 95,65);
    orderBook.addOrder<false>("i10", 90,85);
    orderBook.addOrder<false>("id11", 105,55);

    //std::cout << "book before -->";
    orderBook.DebugPrintMap();
    //std::cout << "<---";

    int remaining =  0;
    if(orderBook.match<false>(100))
    {
    //remaining =  orderBook.handleBuyTrade("id11", 100,350);
    remaining =  orderBook.handleTrade<false>("id11", 100,350);
    std::cout << " remaining " << remaining << endl;
    if(remaining > 0)
    orderBook.addOrder<true>("id11", 100,remaining);
    else
    {
    std::cout << "LOGIC ERROR" << std::endl;
    }
    }
    //std::cout << "book after -->";
    orderBook.DebugPrintMap();
    //std::cout << "<---";
    return;

    orderBook.addSellOrder("id8", 100,55);
    orderBook.addBuyOrder("id1", 100,30);
    orderBook.addBuyOrder("id2", 100,40);
    orderBook.addBuyOrder("id3", 102,40);
    orderBook.addBuyOrder("id4", 102,45);
    orderBook.addSellOrder("id5", 104,45);
    orderBook.addSellOrder("id6", 108,50);
    orderBook.addSellOrder("id7", 109,55);
    */
    //orderBook.DebugPrintMap();
}

    template<>
void OrderHandler::handleOrder<OperationType ::SELL>(std::vector <std::string>& tokens)
{
    int price;
    int quantity; 
    std::string id;
    OrderType outOrderType;
    // std::cout << "id " << id << " price "  << price  << " quantity " << quantity << __LINE__ << endl;
    if(!ParseBuySell(tokens,outOrderType,price,quantity,id))
    {
        std::cout << "INPUT ERROR " << __LINE__ << std::endl;
        return;
    }

    if(price<=0 || quantity <= 0 || id.empty())
        return;

    bool isGfd = (outOrderType == OrderType::GFD)? true:false;
    handleBuySell<false>(id ,price, quantity,isGfd);
    /*
       int remaining =  0;
       if(orderBook.match<true>(price))
       {
       remaining =  orderBook.handleTrade<true>(id, price,quantity);
       if(remaining>0)
       orderBook.addOrder<false>(id, price,remaining);
       else
       {
       std::cout << "LOGIC ERROR " << __LINE__ << std::endl;
       }
       }
       else
       {
       orderBook.addOrder<false>(id, price,quantity);
       }
       */

    return;
}

    template<>
void OrderHandler::handleOrder<OperationType ::CANCEL>( std::vector <std::string>& tokens)
{
    //std::cout <<"CANCEL handler" <<std::endl;
    std::string id;
    if(!ParseCancel(tokens, id))
    {
        std::cout << "INPUT ERROR " << __LINE__ << std::endl;
        return;
    }
    removeOrderById(id);

}

    template<>
void OrderHandler::handleOrder<OperationType ::MODIFY>(std::vector <std::string>& tokens)
{
    //std::cout <<"MODIFY handler" <<std::endl;
    OperationType outOpType;
    int price = 0;
    int quantity = 0;
    std::string id;
    if(!ParseModify(tokens,outOpType,price,quantity, id))
    {
        std::cout << "INPUT ERROR " << __LINE__ << std::endl;
        return;
    }
    if(price<=0 || quantity <= 0 || id.empty())
        return;
    //std::cout << "DEBUG:MODIFY id " << id << " price " << price << " qt " << quantity  <<  endl;

    ReturnValues ret =  removeOrderById(id);
    if(ret ==    ReturnValues::ORDER_NOT_FOUND)
        return;

    bool isBuy = (outOpType == OperationType::BUY)? true:false;
    if(isBuy)
    {
        handleBuySell<true>(id ,price, quantity,true);
    }
    else
    {
        handleBuySell<false>(id ,price, quantity,true);
    }
        
    //std::cout << "DEBUG removeOrderById returned " << ret <<  " " << __LINE__ <<endl;
}

    template<>
void OrderHandler::handleOrder<OperationType ::PRINT>(std::vector <std::string>& tokens)
{
    //std::cout <<"PRINT handler " << __LINE__ <<std::endl;
    orderBook.Print();
    //std::cout <<" ----- " << __LINE__ <<std::endl;
    //orderBook.DebugPrintMap();
}


void tokenize(std::string const &str, const char delim,
        std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}


int main(int argc,char**argv)
    try
{
    OrderHandler orderHandler;
    while(1)
    {
        std::string line;
        getline(cin,line);
        //std::cout << line << " " << __LINE__ << endl;
        if(line.empty())
            break;

        std::vector<std::string>    tokens;
        tokenize(line,' ',tokens);
        if(!tokens.empty())
        {
            OperationType operation = deduceOpearation(tokens[0]);
            //  std::cout<< "token_size " << tokens.size() <<  __LINE__ << endl;
            //std::cout<< "operation " << int(operation) << __LINE__ << endl;
            switch(operation)
            {
                case OperationType::BUY :
                    {
                        orderHandler.handleOrder<OperationType::BUY>(tokens);
                        break;
                    }
                case OperationType::SELL :
                    {
                        orderHandler.handleOrder<OperationType::SELL>(tokens);
                        break;
                    }
                case OperationType::CANCEL :
                    {
                        orderHandler.handleOrder<OperationType::CANCEL>(tokens);
                        break;  
                    }
                case OperationType::MODIFY :
                    orderHandler.handleOrder<OperationType::MODIFY>(tokens);
                    break;  
                case OperationType::PRINT :
                    orderHandler.handleOrder<OperationType::PRINT>(tokens);
                    break;  
                default : 
                    {
                        std::cout << "INVALID INPUT " << __LINE__ << std::endl;
                        ;
                    }
            }
        }
        else
        {
            std::cout << "INVALID INPUT " << __LINE__ << std::endl;
        }
    }
    /*        for(auto& tk : tokens )
              {
              cout << tk << endl;
              }
              */
}
catch(...)
{

}
