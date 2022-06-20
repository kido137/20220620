#include <iostream>
#include <queue>
#include <format>

using namespace std;

struct Vector
{
public:
	int X;
	int Y;
};

int main()
{
	int Map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	queue<Vector> SavePosition;

	Vector PlayerPosition = { 1, 1 };

	int Value = -1;
	Map[PlayerPosition.Y][PlayerPosition.X] = Value;

	SavePosition.push(PlayerPosition);
	while (!SavePosition.empty())
	{
		Vector QueuePosition = SavePosition.front();
		SavePosition.pop();

		//Right
		if (Map[QueuePosition.Y][QueuePosition.X + 1] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.X++;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Down
		if (Map[QueuePosition.Y + 1][QueuePosition.X] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.Y++;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Left
		if (Map[QueuePosition.Y][QueuePosition.X - 1] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.X--;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
		//Up
		if (Map[QueuePosition.Y - 1][QueuePosition.X] == 0)
		{
			Vector NewPosition = QueuePosition;
			NewPosition.Y--;
			SavePosition.push(NewPosition);
			Map[NewPosition.Y][NewPosition.X] = Map[QueuePosition.Y][QueuePosition.X] - 1;
		}
	}


	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			printf("%5d", Map[Y][X]);
		}

		cout << endl;
	}

}