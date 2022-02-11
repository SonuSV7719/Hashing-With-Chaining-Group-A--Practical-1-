#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	Node(int phone_no)
	{
		data = phone_no;
		next = NULL;
	}
};

class link
{
	public:
	Node** hash_table = new Node*[SIZE];
	void insert_node(int phone_no, int);
	int hash_index(int phone_no, int hash_size);
	void display();
	void initialize_null();
	
};

void link::initialize_null()
{
	for (int i=0; i<SIZE; ++i)
	{
		hash_table[i] = NULL;
	}

}
void link::display()
{
	cout<<"================================Hash Table================================="<<endl<<endl;
	cout<<"Index";
	cout<<"\t\tArray of linked list"<<endl<<endl;
	for(int i=0; i<SIZE; ++i)
	{
		cout<<i;
		cout<<"\t|";
		
		// cout<<hash_table[i]->data<<"->";
		while(hash_table[i] != NULL)
		{
			cout<<"\t"<<hash_table[i]->data<<"->";
			hash_table[i] = hash_table[i]->next;
		}
		
        if(hash_table[i] == NULL)
        {
            cout<<"\tNULL";
        }
		cout<<endl;
	}
}

int link::hash_index(int phone_no, int hash_size){
	
	int index = phone_no%hash_size;
    cout<<"Hash Code of: "<<phone_no<<" is: "<<index<<endl;
	return index;
	
}

void link::insert_node(int phone_no, int index)
{
	
	Node* new_node = new Node(phone_no);
	

	if (hash_table[index] == NULL)
	{
		hash_table[index] = new_node;
	}
	else{
		Node* next_node = new Node(phone_no);
		Node* temp = hash_table[index];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = next_node;
	}


}

int main()
{
	int n;
	link table1;
	int phone_no;
	cout<<"How many phone numbers you want to enter: ";
	cin>>n;
	table1.initialize_null();
	for (int i=0; i<n; ++i)
	{
		cout<<"Enter phone_no: ";
		cin>>phone_no;
		int index = table1.hash_index(phone_no, SIZE);
		table1.insert_node(phone_no, index);
		
	}
	table1.display();
	
	return 0;
}