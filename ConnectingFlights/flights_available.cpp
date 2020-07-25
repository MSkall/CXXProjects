#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <stack>

// time complexity
// DFS: O(V+E)

const int MAXSIZE = 1e5; // to allocate enough memory
std::vector<int> adj[MAXSIZE];
int deg[MAXSIZE]; // track number in-degree nodes

// for strongly connected components
std::vector<int> rev_adj[MAXSIZE];
int rep_node[MAXSIZE]; // caling rep_node[v] will return u - the representative of strongly connected component
bool visited[MAXSIZE];
bool visited2[MAXSIZE];
std::stack<int> mystack;

void DFS1(int u)
{
	visited[u] = true;

	for(int v : adj[u])
	{
		if(visited[v] == false)
		{
			DFS1(v);
		}
	}

	// for Kosaraju, add to stack
	mystack.push(u);
}

// goes through all nodes in u's component and set representative nodes to u
void DFS2(int u, int rep)
{
	visited2[u] = true;
	rep_node[u] = rep;
	for(int v : rev_adj[u])
	{
		if(!visited[v])
		{
			DFS2(v, rep);
		}
	}
}

// need to ensure that from startingAirport, flyers can get to any other destination
// might have to hop multiple flights, but will guarantee you get to another airport
int findRoutesToConnect(std::vector<std::string> airports, std::vector<std::vector<std::string> > routes, std::string startingAirport)
{
	// *** unordered_map would improve to constant time O(1) for operations
	std::map<std::string, int> airport_map; // map converts string to id number
	std::vector<std::vector<std::string> > connecting_flights;

	// O(N)
	// store airport ids in map
	int n = airports.size();
	for(int i = 0; i < n; i++)
	{
		airport_map[airports[i]] = i;
	}

	// O(M)
	// create adjacency list for edges for flights
	for(std::vector<std::string> e : routes)
	{
		std::string firstNode = e[0];
		std::string secondNode = e[1];
		// adding the edge from firstNode to secondNode
		// ex. route [ABC, DEF]
		// adjacency list for ABC would mean adding DEF to list
		// grab id of ABC from map, access the element in adj and push back id of secondNode
		adj[airport_map[firstNode]].push_back(airport_map[secondNode]);
	}

	// O(N + M)
	// find strongly connected components -- Kosaraju algorithm O(n+m)
	// create reverse adjacency list - transpose of graph
	for(int i = 0; i < n; i++)
	{
		for(int j : adj[i])
		{
			rev_adj[j].push_back(i);
		}
	}

	// O(N + M) - visited each node once, go through each edge once for each edge
	// run DFS for nodes not visited
	// this is where stack will get populated
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			DFS1(i);
		}
	}

	// O(N + M)
	while(mystack.size() > 0)
	{
		int u = mystack.top();
		// remove top of stack
		mystack.pop();

		// check unvisited nodes and perform DFS2
		if(!visited2[u])
		{
			DFS2(u, u);
		}
	}

	// O(N + M)
	// go through edges to determine degree
	for(int i = 0; i < n; i++)
	{
		for(int j : adj[i])
		{
			// check that edges are in different components
			// add edge from rep[i] to rep[j]
			if(rep_node[i] != rep_node[j])
			{
				adj[rep_node[i]].push_back(rep_node[j]);
				++deg[rep_node[j]];
			}
		}
	}

	// O(N)
	// count number of components with 0 in-degree and aren't S
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		// want to iterate over nodes in condensed graph
		// essentially "ignore" nodes that are not representatives

		// check that the node is a representative node
		// check that the node has 0 in-degree
		// make sure starting airport is node current not
		if(rep_node[i] == i && deg[i] == 0 && i != rep_node[airport_map[startingAirport]])
		{
			++ans;
		}
	}

	return ans;
}

int main()
{
	std::vector<std::string> airports = {"XYZ", "ABC", "DEF", "GHI"};
	std::vector<std::vector<std::string> > routes = { {"ABC", "DEF"}, {"DEF","GHI"}, {"GHI", "XYZ"}};

	std::string startingAirport = "XYZ";
	std::cout << findRoutesToConnect(airports, routes, startingAirport) << std::endl;
	
	return 0;
}