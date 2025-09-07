#include<iostream>
#include<string>
using namespace std;

class Item{
public:
    int data;
    string name;
    float price;
    float rating;
    Item* next;
    Item(int value,string n,float p,float r){
        data=value;
        name=n;
        price=p;
        rating=r;
        next=NULL;
    }
};

class Order{
public:
    int orderdata;
    string customer_name;
    float totalprice;
    int items[100];
    int count;
    Order* next;
    Order(int o,string c){
        orderdata=o;
        customer_name=c;
        totalprice=0;
        count=0;
        next=NULL;
    }
};

class Menu{
    Item* head;
    Item* tail;
public:
    Menu(){
        head=NULL;
        tail=NULL;
    }

    void addItem(int data,string name,float price,float rating){
        Item* newItem=new Item(data,name,price,rating);
        if(head==NULL){
            head=tail=newItem;
        }
        else{
            tail->next=newItem;
            tail=newItem;
        }
    }

    void deleteItem(int data){
        if(head==NULL){
            cout<<"No Item there at Menu(EMPTY)"<<endl;
            return;
        }
        if(head->data==data){
            Item* temp=head;
            head=head->next;
            if(!head){
                tail=NULL;
            }
            cout<<temp->data<<"....Item deleted !"<<endl;
            delete temp;
            return ;
        }

        Item* temp=head;

        while(temp->next && temp->next->data!=data){
            temp=temp->next;
        }
        if(!temp->next){
            cout<<"Item Not Found !"<<endl;
            return;
        }
        Item* remove=temp->next;
        temp->next=remove->next;
        if(remove==tail){
            tail=temp;
        }
        delete remove;
        cout<<endl;
        cout<<"**Item deleted !"<<endl;

    }

    void updateItem(int data,string newname,float newprice,float newrating){
        
        Item* temp=search(data);
        if(temp){
            temp->data=data;
            temp->name=newname;
            temp->price=newprice;
            temp->rating=newrating;
            cout<<endl;
            cout<<"Item updated...."<<endl;
        }
        else{
            cout<<endl;
             cout<<"Item Not Found !!"<<endl;
        }
    }

    Item* search(int data){
        Item * temp=head;
        while(temp){
            if(temp->data==data){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }

    void display(){
        if(head==NULL){
            cout<<"Menu EMPTY"<<endl;
            return;
        }
        Item* temp=head;
        int idx=1;
        while(temp!=NULL){
            cout<<idx<<"."<<"(ID:"<<temp->data<<")"<<temp->name<<"   "<<temp->price<<".Rs/-"<<"   "<<"Rating:"<<temp->rating<<""<<endl;
            temp=temp->next;
            idx++;
        }
        cout<<endl;
    }
};

class Queue{
    Order* front;
    Order* rear;
    int ordercount;
    float salevalue;
public:
    Queue(){
        front=rear=NULL;
        ordercount=1;
        salevalue=0;
    }
    void place(Menu & obj,string customername){
        Order* newOrder=new Order(ordercount++,customername);
        int choice;
        do{
            cout<<"Enter Item  ID To Place(0 for exit):";
            cin>>choice;
            Item* item=obj.search(choice);
            if(choice==0){
                break;
            }
            if(item!=NULL){
                newOrder->items[newOrder->count++]=choice;
                newOrder->totalprice+=item->price;
                cout<<"**Item:"<<item->name<<"  Added"<<endl;
            }
            else{
                cout<<"Invalid ID entered"<<endl;
            }
        }while(true);
        
        if(newOrder->count==0){
            cout<<"No order placed !"<<endl;
            delete newOrder;
            return;
        }

        if(front==NULL){
            front=rear=newOrder;
        }

        else{
            rear->next=newOrder;
            rear=newOrder;
        }
        cout<<endl;
        cout<<"**Order placed Successfully ID:"<<newOrder->orderdata<<endl;
    }

    void process(Menu & obj){
         if(front==NULL){
            cout<<"**No Orders are There!"<<endl;
            return;
         }
         cout<<endl;
         Order* temp=front;
         cout<<"---BILL PROCESSING--"<<endl;
         cout<<"Order ID:"<<temp->orderdata<<endl;
         cout<<"Customer:"<<temp->customer_name<<endl;

         cout<<"----BILL---"<<endl;
         for(int i=0;i<temp->count;i++){
            Item* item=obj.search(temp->items[i]);
            if(item){
                cout<<"Item Name:"<<item->name<<endl<<"Price:"<<item->price<<".Rs/-"<<endl;
                cout<<"Rating:"<<item->rating<<"*"<<endl;
            }
         }
         cout<<"**Total price:"<<temp->totalprice<<".Rs/-"<<endl;
         cout<<endl;

         salevalue+=temp->totalprice;

         front=front->next;
         if(front==NULL){
            rear=NULL;
         }
         delete temp;
    }

    void cancel(int data){
        if(front==NULL){
            cout<<"**No order to cancel"<<endl;
            return;
        }

        if(front->orderdata==data){
        Order* temp=front;
        front=front->next;

        if(!front){
            rear=NULL;
        }

        delete temp;
        cout<<"**First order cancelled!"<<endl;
        return;
        }
        Order* temp=front;
        while(temp->next && temp->next->orderdata!=data){
            temp=temp->next;
        }

        if(temp->next){

            Order* remove=temp->next;
            temp->next=remove->next;
            
            if(remove==rear){
                rear=temp;
            }
            delete remove;
            cout<<"**Order cancelled !**"<<endl;
        }
        else{
            cout<<"Order Not Found !"<<endl;
        }
    }

    void displayPending(){
        if(front==NULL){
            cout<<"**No Orders left!"<<endl;
            return;
        }
        cout<<endl;
        cout<<"---Pending Orders----"<<endl;
        Order* temp=front;
        while(temp){
            cout<<"Order ID:"<<temp->orderdata<<endl;
            cout<<"Customer Name:"<<temp->customer_name<<endl;
            cout<<"Total price:"<<temp->totalprice<<".Rs/-"<<endl;
            cout<<endl;
            temp=temp->next;
        }
    }

    void salesReport(){
        cout<<endl;
        cout<<"---Sales Report---"<<endl;
        cout<<"**Today sales Report:"<<salevalue<<".Rs/-"<<endl;
        cout<<endl;
    }
};

int main(){

    Menu obj;
    Queue que;

    obj.addItem(1,"Chicken",250,4);
    obj.addItem(2,"SandWich",150,3.5);
    obj.addItem(3,"Ice cream",80,4);
    obj.addItem(4,"Noodles",100,3.7);
    obj.addItem(5,"Biryani",300,5);
    int choice;
        cout<<"======FOOD ORDERING SYSTEM======"<<endl;
        cout<<"1.Display Menu"<<endl;
        cout<<"2.Add Item "<<endl;
        cout<<"3.Search Item"<<endl;
        cout<<"4.Update Item"<<endl;
        cout<<"5.Delete Item"<<endl;
        cout<<"6.Place Order"<<endl;
        cout<<"7.BILL Process Order"<<endl;
        cout<<"8.Cancel Order"<<endl;
        cout<<"9.Display Pending Orders"<<endl;
        cout<<"10.Sale Report(Today)"<<endl;
        cout<<"0.Exit"<<endl;
    do{
        cout<<"Enter Your choice ?-->";
        cin>>choice;

        switch(choice){
            case 1:cout<<endl;
                   obj.display();
                   break;
            case 2:{
                int data;
                string name;
                float price;
                float rating;
                cout<<"Enter ID To ADD:";
                cin>>data;
                cout<<"Enter Name of Item:";
                cin>>name;
                cout<<"Enter price of Item:";
                cin>>price;
                cout<<"Give Rating:";
                cin>>rating;
                cout<<endl;
                obj.addItem(data,name,price,rating);
                break;
            }
        case 3:{
                int data;
                cout<<"Enter ID to Search:";
                cin>>data;
                Item* found=obj.search(data);
                if(found){
                    cout<<endl;
                    cout<<"**Item found-- "<<found->name<<"   "<<"Price:"<<found->price<<".Rs/-   "<<"Rating:"<<found->rating<<endl;
                }
                else{
                    cout<<"Item Not Found!"<<endl;
                }
                cout<<endl;
                break;
        }
        case 4:{
                int data;
                string newname;
                float newprice;
                float newrating;
                cout<<"Enter ID to Update:";
                cin>>data;
                cout<<"Enter Name of Item to Update:";
                cin>>newname;
                cout<<"Enter price of Item:";
                cin>>newprice;
                cout<<"Give Item Rating:";
                cin>>newrating;
                obj.updateItem(data,newname,newprice,newrating);
                break;
        }
        case 5: {
                int data;
                cout<<"Enter Item ID to delete:";
                cin>>data;
                obj.deleteItem(data);
                break;
        }
        case 6:{
                string customername;
                cout<<"Enter your(customer) name:";
                cin>>customername;
                cout<<endl;
                que.place(obj,customername);
                break;
        }
        case 7:{
                que.process(obj);
                break;
        }
        case 8:{
                int data;
                cout<<"Enter Order ID to Cancel:";
                cin>>data;
                que.cancel(data);
                break;
        }
        case 9:{
                que.displayPending();
                break;
        }
        case 10:{
                que.salesReport();
                break;
        }
        case 0: cout<<"Exiting...."<<endl<<"Thanks..Visit Us Again !!"<<endl;
                break;
                
        default: cout<<"Invalid Choice!"<<endl;
        }
    }while(choice!=0);

    return 0;
}