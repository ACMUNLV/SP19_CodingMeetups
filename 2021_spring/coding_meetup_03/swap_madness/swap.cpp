/// @author Benjamin Alcocer
/// @brief Problem: Swap Madness. Uses Ford Fulkerson with BFS.
/// @source Each function has sources, but again:
///
/// https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
/// https://en.wikipedia.org/wiki/Parity_of_a_permutation
/// https://www.youtube.com/watch?v=NlQqmEXuiC8
///-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

// Number of vertices in given graph (will be the same for this problem
int N, M;
typedef std::vector<std::vector<int>> Graph;
#define endl "\n"

///-----------------------------------------------------------------------------
/// A DFS based recursive function that returns true if a matching for vertex u
/// is possible.
/// 
/// @source https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
///-----------------------------------------------------------------------------
bool bpm(const Graph& bpGraph, int u, bool seen[], int matchR[])
{
    // Try every job one by one 
    for (int v = 0; v < N; v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (bpGraph[u][v] && !seen[v]) 
        { 
            // Mark v as visited 
            seen[v] = true;  
  
            // If job 'v' is not assigned to an  
            // applicant OR previously assigned  
            // applicant for job v (which is matchR[v])  
            // has an alternate job available.  
            // Since v is marked as visited in  
            // the above line, matchR[v] in the following  
            // recursive call will not get job 'v' again 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
  
///-----------------------------------------------------------------------------
/// Returns maximum number of matching from M to N.
///
/// @source https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
///-----------------------------------------------------------------------------
int maxBPM(const Graph& bpGraph)
{ 
    // An array to keep track of the  
    // applicants assigned to jobs.  
    // The value of matchR[i] is the  
    // applicant number assigned to job i, 
    // the value -1 indicates nobody is 
    // assigned. 
    int matchR[N];
  
    // Initially all jobs are available 
    memset(matchR, -1, sizeof(matchR)); 
  
    // Count of jobs assigned to applicants 
    int result = 0;  
    for (int u = 0; u < M; u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
  
        // Find if the applicant 'u' can get a job 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
} 

///-----------------------------------------------------------------------------
/// Lets define the parity of a word as the number of inversions in that word.
/// Two words with the same parity cannot be swapped, while words with
/// different parity can be swapped.
///  
/// @source https://en.wikipedia.org/wiki/Parity_of_a_permutation
///-----------------------------------------------------------------------------
int parity(string const& word, size_t size)
{
    int p = 0;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (word[j] < word[i])
            {
                p += 1;
            }
        }
    }
    return p % 2;
}

///-----------------------------------------------------------------------------
/// Swap the two indices, return the swapped string.
///-----------------------------------------------------------------------------
string swap(string const &str, size_t i, size_t j)
{
    string word(str);
    word[i] = str[j];
    word[j] = str[i];
    return word;
}

///-----------------------------------------------------------------------------
/// Here are some print functions if you are going to debug anything
///-----------------------------------------------------------------------------
/*
void printVector(const vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printGraph(const Graph& graph)
{
    for (size_t i = 0; i < graph.size(); ++i)
    {
        printVector(graph[i]);
    }
    cout << endl;
}
*/

int main()
{
    // Get size of set
    size_t n;
    cin >> n;

    // Let Maximum Bipartite Matching functions work
    N = n;
    M = n;

    // word -> hold words in set
    // graph -> graph to use for max bipartite functions
    // wordIndex -> mapping of word<string> to its index<int>
    vector<string> words(n);
    Graph graph(n, vector<int>(n, 0));
    unordered_map<string, int> wordIndex;
    
    // read in words
    for (size_t i = 0; i < n; ++i)
    {
        cin >> words[i];
        wordIndex[words[i]] = i;
    }
    
    size_t length = words[0].size(); // word length
    for (size_t i = 0; i < n; ++i)
    {
        int wordParity = parity(words[i], words[i].size());
        
        // Select either 1 or 0, and only that from then on
        if (wordParity == 0)
        {
            for (size_t a = 0; a < length; ++a)
            {
                for (size_t b = a + 1; b < length; ++b)
                {
                    string swapped = swap(words[i], a, b);
                    auto search = wordIndex.find(swapped);
                    if (search != wordIndex.end())
                    {
                        graph[i][search->second] = 1;
                    }
                }
            }
        }
    }

    // example graph output for Testcase 0
    //~ printGraph(graph);
    //~ 0 1 0 1 1 0
    //~ 0 0 0 0 0 0
    //~ 0 1 0 1 1 0
    //~ 0 0 0 0 0 0
    //~ 0 0 0 0 0 0
    //~ 0 1 0 1 1 0

    cout << n - maxBPM(graph);

    return 0; 
} 
