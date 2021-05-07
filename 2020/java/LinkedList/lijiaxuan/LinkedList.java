import java.util.Scanner;

public class Main {
    Node head=new Node();
    Node last=head;
    int size=0;

    class Node{
        Integer data;
        Node next;
        Node pre;

        Node(){
            this.data=null;
            this.next=null;
            this.pre=null;
        }
        Node(Integer data){
            this.data=data;
            this.next=null;
            this.pre=null;
        }
    }

    void firstAdd(int data){
        Node temp=new Node(data);
        Node cur=head.next;
        head.next=temp;
        temp.pre=head;
        temp.next=cur;
        cur.pre=temp;
        size++;
    }
    void lastAdd(int data){
        Node temp=new Node(data);
        last.next=temp;
        temp.pre=last;
        last=temp;
        size++;
    }

    int get(int index){
        Node cur=head.next;
        for (int i = 0; i < index; i++) {
            cur=cur.next;
        }
        return (int) cur.data;
    }

    int remove(int index){
        Node cur=head.next;
        Node front=head;
        for (int i = 0; i < index; i++) {
            front=front.next;
            cur=cur.next;
        }
        int i= (int) cur.data;
        front.next=cur.next;
        cur.next.pre=front;
        size--;
        return i;
    }
    int size(){
        return size;
    }

    void print(){
        Node cur=head.next;
        while(cur!=null){
            System.out.println(cur.data);
            cur=cur.next;
        }
    }
    
    void swap(int index){
        int i=get(index-1);
        Node min=head.next;
        while(min.next!=null){
            if(min.data<=i){
                min=min.next;
            }else{
                break;
            }
        }
        lastAdd(0);
        min=min.pre;
        Node cur=min.next;
        while(cur.next!=null){
            if(cur.data<i){
                cur.pre.next=cur.next;
                cur.next.pre=cur.pre;
                cur.next=min.next;
                min.next.pre=cur;
                min.next=cur;
                cur.pre=min;
                min=min.next;
            }
            cur=cur.next;
        }
        last.pre.next=null;
    }
    public static void main(String[] args) {
        Main list=new Main();
        list.lastAdd(1);
        list.lastAdd(4);
        list.lastAdd(3);
        list.lastAdd(2);
        list.lastAdd(5);
        list.lastAdd(2);
        Scanner sc=new Scanner(System.in);
        int i=sc.nextInt();
        list.print();
        System.out.println("==========");
        list.swap(i);
        list.print();
        System.out.println("==========");
    }
}