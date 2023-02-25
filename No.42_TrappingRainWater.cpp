// Author:  Sheng (Raymond) Liao
// Date:    January 2023

/* 42. Trapping Rain Water
   
   Given n non-negative integers representing an elevation map where the width of each bar is 1, 
   compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int res = trapRHigh(height);
        return res;
    }

    int trapRHigh(vector<int>& height) {
        int s = 0, cvol = 0, res = 0;
        bool dcl1st = true, dcl = false, acc = false;

        for (int i = 0; i < height.size(); ++i) {
            if (i < height.size()-1) {
                if (height[i] > height[i+1]) {
                    // Find the 1st left-side bar of a hollow.
                    if (dcl1st) {
                        dcl1st = false;
                        s = i;
                    }
                    dcl = true;
                }
                else if (height[i] < height[i+1] && dcl) {
                    acc = true;
                    dcl = false;
                }
            }

            // Cacluate the volume of water in a hollow.
            if (acc) {
                if (height[i] >= height[s]) {
                    int wvol = height[s] * (i-s-1) - cvol;
                    res += wvol;

                    // cout << "s: " << s << endl;
                    // cout << "i: " << i << endl;
                    // cout << "cvol: " << cvol << endl;
                    // cout << "wvol: " << wvol << endl;

                    cvol = 0;
                    acc = false;

                    if (i < height.size()-1 && height[i] > height[i+1])
                        s = i;
                    else
                        dcl1st = true;
                }
                // No larger hollow will appear.
                else if (i == height.size()-1) {
                    vector<int> heightRev;
                    for (int i = height.size()-1; i >= s; --i) {
                        heightRev.push_back(height[i]);
                    }
                    res += trapRHigh(heightRev);
                }
            }

            if (!dcl1st && i != s){
                cvol += height[i];
            }
        }

        return res;
    }
};