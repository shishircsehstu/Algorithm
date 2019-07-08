#include<bits/stdc++.h>
using namespace std;
int total_num;
struct node
{
    int data;
    node* next;

};
void dis(node* root)
{
    while(root!=NULL)
    {

        cout<<root->data<<"->";
        root=root->next;
    }
    cout<<"NULL\n";
}
node* insertt(node* root,int id,int new_data)
{
    int n_2;

    switch(id)
    {
    case 1:
    {
        node* tmp=new node();

        tmp->data=new_data;

        tmp->next=root;
        root=tmp;
        break;
    }

    case 2:
    {
        n_2=total_num/2;
        n_2--;
        node *tmp_root=root;
        node* pre;
        while(n_2--)
        {
           // pre=tmp_root;
            tmp_root=tmp_root->next;
        }

        // cout<<tmp_root->value<<endl;

        node* next2;
        node* temp=tmp_root;
        next2=tmp_root->next;

        node* root2=new node();
        root2->data=new_data;
        tmp_root->next=root2;
        root2->next=next2;
        break;
    }
    case 3:
    {
        n_2=total_num;
        n_2--;

        node *tmp_root=root;
        while(n_2--)
        {
            tmp_root=tmp_root->next;
        }
        // cout<<tmp_root->value<<endl;

        node* next2;
        node* temp=tmp_root;
        next2=tmp_root->next;

        node* root2=new node();
        root2->data=new_data;
        tmp_root->next=root2;
        root2->next=next2;
        break;
    }
    }
    total_num++;
    return root;
}
node* delet(node* root,int id)
{
    cout<<"total="<<total_num<<endl;
    switch(id)
    {
    case 4:
    {
        root=root->next;
    }
    case 5:
    {

        int  n_2=total_num/2;
        if(total_num%2==0)
            n_2--;
        node *tmp_root=root;
        node* pre;
        while(n_2--)
        {
            pre=tmp_root;
            tmp_root=tmp_root->next;
        }

        node* next2;

        next2=tmp_root->next;
        pre->next=next2;
        break;
    }

    case 6:
    {
        int n_2=total_num;
        n_2-=2;
        node *tmp_root=root;
        while(n_2--)
        {
           // cout<<tmp_root->data<<endl;
            tmp_root=tmp_root->next;

        }
        tmp_root->next=NULL;
        // cout<<tmp_root->value<<endl;
        break;
    }
    }
    total_num--;
    return root;
}
node* createLinkList(int n)
{
    int i;
    node *head=NULL;
    node *temp=NULL;
    node *p=NULL;
    for(i=0; i<n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL)//head =root
        {
            head=temp;
        }
        else
        {
            p=head;

            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }
    return head;
}
int main()
{
    int i,j,data;
    node* root;
    cout<<"Ensert the num of node : ";
    cin>>total_num;
    cout<<"Ensert the node data : ";
    root=createLinkList(total_num);
    // printf("%d\n",root);
    while(1)
    {
        cout<<"Link list are: ";

        dis(root);
        cout<<endl;
        int id;

        cout<<"Enter 1 for 1st insert\n";
        cout<<"Enter 2 for middle insert\n";
        cout<<"Enter 3 for last insert\n";
        cout<<"Enter 4 for 1st delete\n";
        cout<<"Enter 5 for middle value delete\n";
        cout<<"Enter 6 for last value delete\n";

        cin>>id;
        if(id<=3)
        {
            cout<<"Enter the cvalue that you want to insert\n";
            cin>>data;
            root=insertt(root,id,data);
            //dis(root);
            // dis(root);
        }
        else
        {
            root=delet(root,id);
            //dis(root);

        }
    }
}



