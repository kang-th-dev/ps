//queue implement
class queue{
    private:
        int v;
        int rear,front,size;
        int *q;
    public:
        queue(int v);
        ~queue();
        bool empty();
        void push(int v);
        int pop();
        
};
bool queue::empty(){
   return rear- front !=0 ? false : true; 
}
void queue::push(int v){
    q[rear ++] = v;
}
int queue::pop(){
    return q[front++];
}

//constructor
queue::queue(int v){
    this->v = v;
    q = new int[v];
    rear = 0;
    front = 0;
    size = 0;
}

//destroy
queue::~queue(){
    delete[] q;
}