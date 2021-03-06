#include <iostream>
#include "Enemy.h"
#include <vector>

using namespace std;
using std::vector;

int main() {

	vector<int> scores(5, 0);

	scores[0] = 1; scores[1] = 2; scores[2] = 3;

	for (int i = 0; i < scores.size(); ++i) {
		cout << "scores " << i << " = " << scores[i] << "\n";
	}

	vector<Enemy>* enemies = new vector<Enemy>(3);
	vector<ArmedEnemy>* aenemies = new vector<ArmedEnemy>(10);
	ArmedEnemy ninth, tenth;
	Enemy fourth, fifth;

	enemies->push_back(fourth);
	enemies->push_back(fifth);
	cout << "size of enemies = " << enemies->size() << "\n";

	int i = 0;
	for (vector<Enemy>::iterator it = enemies->begin(); it != enemies->end(); ++it)
	{
		it->set_score(scores[i]);
		cout << "score = " << it->get_score() << "\n";
		++i;
	}

	Enemy newthird;
	enemies->insert(enemies->begin() + 2, newthird);
	enemies->erase(enemies->begin() + 2);

	Enemy& back = enemies->back();
	cout << "hit points last element = " << back.get_hit_points() << "\n";

	enemies->pop_back();
	cout << "new size of enemies = " << enemies->size() << "\n";

	// clear enemies of elements
	enemies->clear();

	delete enemies;
	system("pause");
	return 0;
}
