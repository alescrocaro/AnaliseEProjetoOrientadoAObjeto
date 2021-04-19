#include <stdio.h>
#include <stdlib.h>

typedef int Value;

class List
{
	private:
		typedef struct Node
		{
  			Value value;
  			struct Node *next;
		} Node;
		
		Node *node = NULL;
		
	public:
		Node **getNode()
		{
			return &node;
		}
		void addToList(Node **list, Value value);
		int sizeOfList(Node **list);
};

void List::addToList(Node **list, Value value)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    
    if(*list == NULL)
	{
        node->next = NULL;
    }
	else
	{
        node->next = *list;
    }
    
    *list = node;    
}
int List::sizeOfList(Node **list)
{
   Node *node = *list;
   int count = 0;
   while(node != NULL)
   {
        count++;
        node = node->next;
   }
   
   return count;   
}

int main()
{
	List lista;
    lista.addToList(lista.getNode(), 1);
    
    printf("List[%p].size = %d", lista.getNode(), lista.sizeOfList(lista.getNode()));
}
