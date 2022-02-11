#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

class Node
{
	public:
	string data;
	Node* next;
	Node(string name)
	{
		data = name;
		next = NULL;
	}
};

class link
{
	public:
	Node** hash_table = new Node*[SIZE];
	void insert_node(string name, int);
	int hash_index(string name, int hash_size);
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

int link::hash_index(string name, int hash_size){
	
	int sum =0;
	for (int i= 0; i<name.size(); i++){
		
		cout<<"ASCII value of "<<name[i]<<" is: "<<int(name[i])<<endl;
		sum = sum + int(name[i]);	
		
	}
	
	cout<<"After modulo of "<<name<<" Whose sum is: "<<sum<<" is "<<sum%hash_size<<endl;
	int index = sum%hash_size;
	return index;
	
	
}

void link::insert_node(string name, int index)
{
	
	Node* new_node = new Node(name);
	

	if (hash_table[index] == NULL)
	{
		hash_table[index] = new_node;
	}
	else{
		Node* next_node = new Node(name);
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
	string name;
	cout<<"How many strings you want to enter: ";
	cin>>n;
	table1.initialize_null();
	for (int i=0; i<n; ++i)
	{
		cout<<"Enter name: ";
		cin>>name;
		int index = table1.hash_index(name, SIZE);
		table1.insert_node(name, index);
		
	}
	table1.display();
	
	return 0;
}