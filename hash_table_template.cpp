#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

template<class T>
class Node
{
	public:
	T data;
	Node* next;
	Node(T phone_no)
	{
		data = phone_no;
		next = NULL;
	}
};

template<class U>
class link
{
	public:
	Node<U>** hash_table = new Node<U>*[SIZE];
	void insert_node(U phone_no, int);
	int hash_index(U phone_no, int hash_size);
	void display();
	void initialize_null();
	int digit_extration(int);
	
};

template<class U>
void link<U>::initialize_null()
{
	for (int i=0; i<SIZE; ++i)
	{
		hash_table[i] = NULL;
	}

}

template<class U>
void link<U>::display()
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

template<class U>
int link<U>::hash_index(U phone_no, int hash_size){
	
	int index = phone_no%hash_size;
    cout<<"Hash Code of: "<<phone_no<<" is: "<<index<<endl;
	return index;
	
}

template<class U>
void link<U>::insert_node(U phone_no, int index)
{
	
	Node<U>* new_node = new Node<U>(phone_no);
	

	if (hash_table[index] == NULL)
	{
		hash_table[index] = new_node;
	}
	else{
		Node<U>* next_node = new Node<U>(phone_no);
		Node<U>* temp = hash_table[index];
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
	link<long long> table1;
	long long phone_no;
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