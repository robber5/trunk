#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string get_file_string(string path_to_file){
    std::ifstream ifs(path_to_file);
    return string((std::istreambuf_iterator<char>(ifs)),
                  (std::istreambuf_iterator<char>()));
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) 
{
	int result = 0;
	int dirRec[8][2]();
	for(vector<vector<int>>::iterator it = obstacles.begin(); it != obstacles.end(); it++)
	{
		int c_x = *it, r_y = *(it + 1);
		if(c_x == c_q && r_y > r_q && r_y <= n)
		{
			//dir 0
			if(r_y < dirRec[0][1] || dirRec[0][1] == 0){
				dirRec[0][0] = c_x;
				dirRec[0][1] = r_y;				
			}
			break;
		}
		
	}
	
	
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

	string prevent_temp_temp;
    prevent_temp_temp = get_file_string("./testcase_climbing_queenattack.txt");
	vector<string> obstacles_temp = split_string(prevent_temp_temp);

    vector<vector<int>> obstacles(k);
	   
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
			int tmp = stoi(obstacles_temp[i*2 + j]);
            obstacles[i][j] = tmp;
            //cin >> obstacles[i][j];
        }

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}