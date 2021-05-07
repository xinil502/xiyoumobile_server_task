public class Stack {
    Node head=new Node();
    Node last=head;
    int size=0;
    int []max=new int[100];
    int t=0;

    public class Node{
        Integer data;
        Node next;
        public Node(){
            this.data=null;
            this.next=null;
        }
        public Node(int data){
            this.data=data;
            this.next=null;
        }
    }

    public void push(int data){//入栈
        Node temp=new Node(data);
        last.next=temp;
        last=temp;
        if(t==0){
            max[t++]=data;
        }else{
            int max1=max[t-1]>data?max[t-1]:data;
            max[t++]=max1;
        }
        size++;
    }

    public int pop(){//出栈
        Node cur=head.next;
        int i=cur.data;
        head.next=cur.next;
        t--;
        size--;
        return i;
    }

    public int peek(){//获取栈顶元素
        int i=last.data;
        return i;
    }

    public boolean isEmpty(){//判空
        return size==0;
    }
    public int size(){//获取栈内元素个数
        return size;
    }

    public void print(){//打印栈内所有元素
        Node cur=head.next;
        while(cur!=null){
            System.out.println(cur.data);
            cur=cur.next;
        }
    }
    int getMax(){//常数时间内获得栈内最大值
        if(!isEmpty())
            return max[t-1];
        else
            return -1;
    }

    public static void main(String[] args) {
        Stack st=new Stack();
        st.push(1);
        st.push(5);
        st.push(1);
        st.push(9);
        st.push(10);
        st.push(1);
        st.pop();
        st.pop();
        int i=st.getMax();
        System.out.println("max:"+i);
        System.out.println("栈顶元素："+st.peek());
        System.out.println("栈内元素个数："+st.size());

    }
}
