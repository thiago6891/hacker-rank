#include <iostream>
#include <stack>
#include <string>
#include <list>
#include <vector>
using namespace std;

// The State can be modeled using the x and y coordiantes of the plane.
class State {
  	int _x;
  	int _y;
  
public:
  	void set(int x, int y) { _x = x; _y = y; }
  	int getX() { return _x; }
  	int getY() { return _y; }
};

enum Action {
  	NONE,
  	UP,
  	RIGHT,
  	DOWN,
  	LEFT
};

class Node {
public:
  	State state;
  	Action action;
  	Node* parent;
};

class Problem {
  	int _n;
  	State _init;
  	State _goal;
  
public:
  	Problem(int size) { _n = size; }
  	void setInit(State s) { _init = s; }
  	void setGoal(State s) { _goal = s; }
  	State getInit() { return _init; }
  	
  	vector<Action> getActions(State s) {
      	vector<Action> r;
      	
      	if (s.getY() > 0) r.push_back(UP);
      	if (s.getX() < _n - 1) r.push_back(RIGHT);
      	if (s.getY() < _n - 1) r.push_back(DOWN);
      	if (s.getX() > 0) r.push_back(LEFT);
      
      	return r;
    }
  	
  	State result(State s, Action a) {
      	State r;
      
      	if (a == UP) r.set(s.getX(), s.getY() - 1);
      	else if (a == RIGHT) r.set(s.getX() + 1, s.getY());
      	else if (a == DOWN) r.set(s.getX(), s.getY() + 1);
      	else if (a == LEFT) r.set(s.getX() - 1, s.getY());
      
      	return r;
    }
  	
  	bool goalTest(State s) {
      	return s.getX() == _goal.getX() && s.getY() == _goal.getY();
    }
};

class Agent {
  	stack<Action> _seq;
  	
  	// This function receives as parameter the goal node that was found and walks up through the
  	// parent nodes until it finds the node with the initial state. Since all the actions are
  	// reversed, they are placed in a stack so the agent can solve the problem by performing the
  	// actions in the correct order.
  	void __solution(Node n) {
      	Node* tmp = &n;
      	while (tmp->action != NONE) {
          	_seq.push(tmp->action);
          	tmp = tmp->parent;
        }
    }
  	
  	// Breadth-First Search was used to find the solution to the problem.
  	void __search(Problem p) {
      	Node* n = new Node();
      	n->state = p.getInit();
      	n->action = NONE;
      	
      	if (p.goalTest(n->state)) {
        	__solution(*n);
          	return;
      	}
      	
      	list<Node> frontier;
      	frontier.push_back(*n);
      
      	list<State> explored;
      	
      	while (true) {
          	if (frontier.empty()) return;
          	
          	n = new Node();
          	n->state = frontier.front().state;
          	n->action = frontier.front().action;
          	n->parent = frontier.front().parent;
          	frontier.pop_front();
          	
          	explored.push_back(n->state);
          
          	vector<Action> a = p.getActions(n->state);
          	for (int i = 0; i < a.size(); i++) {
              	Node* child = new Node();
              	child->state = p.result(n->state, a[i]);
              	child->action = a[i];
              	child->parent = n;
              	
              	bool inFrontier = false;
              	list<Node>::iterator fit = frontier.begin();
              	while (fit != frontier.end()) {
                  	if ((*fit).state.getX() == child->state.getX() &&
                        (*fit).state.getY() == child->state.getY()) {
                      	inFrontier = true;
                      	break;
                    }
                  	fit++;
                }
              
              	bool inExplored = false;
              	list<State>::iterator eit = explored.begin();
              	while (eit != explored.end()) {
                  	if ((*eit).getX() == child->state.getX() &&
                        (*eit).getY() == child->state.getY()) {
                      	inExplored = true;
                      	break;
                    }
                  	eit++;
                }
              
              	if (!inFrontier && !inExplored) {
                  	if (p.goalTest(child->state)) {
                      	__solution(*child);
                      	return;
                    }
                  	frontier.push_back(*child);
                }
            }
        }
    }
  
public:
  	Agent(Problem p) {
      	__search(p);
    }
  	
  	void outputSolution() {
      	while(!_seq.empty()) {
          	Action a = _seq.top();
          	_seq.pop();
          	if (a == UP) cout << "UP" << endl;
          	else if (a == RIGHT) cout << "RIGHT" << endl;
            else if (a == DOWN) cout << "DOWN" << endl;
            else if (a == LEFT) cout << "LEFT" << endl;
        }
    }
};

int main() {
    int N; cin >> N;
  	
  	// The problem is instantiated by finding its initial and goal states.
  	// The grid size N is needed to implement the Problem::getActions(State) function.
  	Problem problem(N);
  	for (int j = 0; j < N; j++) {
      	for (int i = 0; i < N; i++) {
          	char c; cin >> c;
          	if (c == 'm') {
              	State init;
              	init.set(i, j);
              	problem.setInit(init);
            } else if (c == 'p') {
              	State goal;
              	goal.set(i, j);
              	problem.setGoal(goal);
            }
        }
    }
  	
  	Agent agent(problem);
  	agent.outputSolution();
  	
    return 0;
}
