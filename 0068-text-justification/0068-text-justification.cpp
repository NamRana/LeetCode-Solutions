class Solution {
public:
  string createLine(vector<string>& words, int i, int j, vector<int>& spaces, int maxWidth) {
	string line(maxWidth, ' ');
	int k = 0;
	for(int w = i; w<j; w++) {
		int n = words[w].size();
		for(int l = 0; l<n; l++) {
			line[k++] = words[w][l];
		}
		if(w != j-1) {
			for(int l = 0; l<spaces[w-i]; l++) {
				line[k++] = ' ';
			}
		}
	}
	return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	int i = 0;
	int n = words.size();
	vector<string> lines;
	while(i<n) {
		int chars = 0;
		chars += words[i].size();
		vector<int> spaces;
		int j = i+1;
		while(j<n && chars < maxWidth) {
			if(chars + words[j].size() + 1 > maxWidth) {
				break;
			}
			spaces.push_back(1);
			chars += words[j].size() + 1;
			j++;
		}
		if(j == n) {
			lines.push_back(createLine(words, i, j, spaces, maxWidth));
		}
		else {
			int spaceLeft = maxWidth - chars;
			int n_spaces = spaces.size();
			int addToAll = ((n_spaces)?(spaceLeft/n_spaces):0);
			int extra = ((n_spaces)?(spaceLeft%n_spaces):0);
			for(int k = 0; k<n_spaces; k++) {
				spaces[k] += addToAll;
				if(extra) {
					spaces[k]++;
					extra--;
				}
			}
			lines.push_back(createLine(words, i, j, spaces, maxWidth));
		}
		i = j;
	}
	return lines;
}
};