#borasakshi
# all functionality of linked list in better time
class node():
    def __init__(self,data):
        self.data=data
        self.next=None
def takeinput(head=None):
    data=int(input())
    temp=head
    while(data!=-1):
        newnode=node(data)
        if head==None:
            head=newnode
            temp=head
        else:
            while(temp.next!=None):
                temp=temp.next
            temp.next=newnode
        data=int(input())
    return head


def printll(head):
    temp=head
    while(temp!=None):
        print(temp.data,end="")
        temp=temp.next
def reversell(head):
    if head.next==None :
        return head
    else:
        temp=head.next
        newhead=reversell(head.next)
        temp.next=head
        head.next=None
        return newhead
def findmid(head):
    slow=head
    fast=head
    try:
        while(fast.next!=None):
            slow=slow.next
            fast=fast.next.next
        print(slow.data)
    except:
        print(slow.data)
def delete(head,pos):
    temp=head
    while(pos>1):
        pos-=1
        temp=temp.next
    temp.next=temp.next.next
    return head
def insert(head,pos,data):
    newnode=node(data)
    if pos==0:
        newnode.next=head
        return newnode
    i=0
    temp=head
    while(i<pos-1):
        temp=temp.next
        i+=1
    newnode.next=temp.next
    temp.next=newnode
    return head


def deli(head,n):
    f,s=head,head
    while(n):
        f=f.next
        n-=1
    if( not f):
        return s.next
    while(f and f.next):
        f=f.next
        s=s.next
    s.next=s.next.next
    return head







if __name__=='__main__':

    n1=takeinput()

    printll(n1)
    print()
    n2=deli(n1,1)
    printll(n2)
