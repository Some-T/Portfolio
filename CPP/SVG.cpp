#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include <cstdlib>

using namespace std;

void printSVG(string sFileName, vector<vector<float>> vf_lines) //This is outputting the structure or like a template of a basic html file for the user.
{
	ofstream output;

	output.open(sFileName);

	if(output.is_open())
	{
		output << "<!DOCTYPE html>" << endl;
		output << "<html>" << endl;
		output << "<body>" << endl;
		output << "<svg height=\"900\" width=\"900\">" << endl;
		for(int i = 0;i < vf_lines.size();i++)
		{
			output << "<line x1=\"" << vf_lines[i][0] << "\" ";
			output << "y1=\"" << vf_lines[i][1] << "\" ";
			output << "x2=\"" << vf_lines[i][2] << "\" ";
			output << "y2=\"" << vf_lines[i][3] << "\" style=\"stroke:rgb(30,30,75);stroke-width:2\" />";
			output << endl;
		}
		output << "</svg>" << endl;
		output << "</body>" << endl;
		output << "</html>" << endl;
	}

	output.close();
}

void Koch(int iDepth, vector<vector<float>>& vf_lines);

int main()
{
	vector<vector<float>> vf_lines; // A load of lines  ((x1,y1), (x2,y2));
	vector<float> vf_line(4); // A single line
	

	// Set initial lines (equilateral triangle)
	vf_line[0] = 100.0f; vf_line[1] = 700.0f; vf_line[2] = 450.0f; vf_line[3] = 94.0f;
	vf_lines.push_back(vf_line);
	vf_line[0] = 450.0f; vf_line[1] = 94.0f; vf_line[2] = 800.0f; vf_line[3] = 700.0f; 
	vf_lines.push_back(vf_line);
	vf_line[0] = 800.0f; vf_line[1] = 700.0f; vf_line[2] = 100.0f; vf_line[3] = 700.0f; 
	vf_lines.push_back(vf_line);

	// Run the Koch Snowflake algorithm
	Koch(6, vf_lines);

	// Print the lines as an html file with inline scalar vector graphics
	printSVG("snowflake.html", vf_lines);

	return 0;
}

void Koch(int iDepth, vector<vector<float>>& vf_lines)
{
	if(iDepth > 0) // If we are still recursing
	{
		int iStartSize = vf_lines.size(); // For all initial lines
		for(int i = 0;i < iStartSize;i++)
		{
			// Calculate the five point on the Koch lines
			float a_a[2], a_b[2], a_c1[2], a_c2[2], a_c[2], a_d[2], a_e[2];

			a_a[0] = vf_lines[i][0];a_a[1] = vf_lines[i][1];

			a_b[0] = vf_lines[i][0] + 0.33 * (vf_lines[i][2] - vf_lines[i][0]);
			a_b[1] = vf_lines[i][1] + 0.33 * (vf_lines[i][3] - vf_lines[i][1]);

			a_c1[0] = vf_lines[i][0] + 0.5 * (vf_lines[i][2] - vf_lines[i][0]);
			a_c1[1] = vf_lines[i][1] + 0.5 * (vf_lines[i][3] - vf_lines[i][1]);

			// Translate to origin
			a_c2[0] = a_c1[0]-a_b[0];
			a_c2[1] = a_c1[1]-a_b[1];

			// Rotate 60 degrees CW
			a_c[0] = 0.5f * a_c2[0] + 0.866f * a_c2[1];
			a_c[1] = -0.866f * a_c2[0] + 0.5f * a_c2[1];

			// Extend
			a_c[0] = a_c[0] * 1.732;
			a_c[1] = a_c[1] * 1.732;

			// Translate back
			a_c[0] = a_c[0] + a_b[0];
			a_c[1] = a_c[1] + a_b[1];

			a_d[0] = vf_lines[i][0] + 0.66 * (vf_lines[i][2] - vf_lines[i][0]);
			a_d[1] = vf_lines[i][1] + 0.66 * (vf_lines[i][3] - vf_lines[i][1]);

			a_e[0] = vf_lines[i][2];a_e[1] = vf_lines[i][3];

			// Add the four Koch lines
			vector<float> vf_KochLine(4);

			vf_KochLine[0] = a_a[0];vf_KochLine[1] = a_a[1];
			vf_KochLine[2] = a_b[0];vf_KochLine[3] = a_b[1];
			vf_lines.push_back(vf_KochLine);

			vf_KochLine[0] = a_b[0];vf_KochLine[1] = a_b[1];
			vf_KochLine[2] = a_c[0];vf_KochLine[3] = a_c[1];
			vf_lines.push_back(vf_KochLine);

			vf_KochLine[0] = a_c[0];vf_KochLine[1] = a_c[1];
			vf_KochLine[2] = a_d[0];vf_KochLine[3] = a_d[1];
			vf_lines.push_back(vf_KochLine);

			vf_KochLine[0] = a_d[0];vf_KochLine[1] = a_d[1];
			vf_KochLine[2] = a_e[0];vf_KochLine[3] = a_e[1];
			vf_lines.push_back(vf_KochLine);
		}

		// Delete the four original lines
		vf_lines.erase(vf_lines.begin(),vf_lines.begin()+iStartSize);

		// Decrement depth
		iDepth--;
		// Perform recursive call
		Koch(iDepth, vf_lines);
	}

	//system("pause");
       	  //return 0;
}
