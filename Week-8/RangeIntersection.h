//
// Created by Oskars Pozdnakovs on 27/11/2017.
//

#ifndef WEEK_8_RANGEINTERSECTION_H
#define WEEK_8_RANGEINTERSECTION_H
class RangeIntersection
{
    map<string, unsigned int> range;

    vector <map <string, vector <unsigned int>>*> intersectingRangePairs;

    // pairs that can be merged not causing logic errors
    // example: [strA: "ABCDEF", strB: "XYWBAE"], merge B - E ranges (strA(2) to strB(6))
    map < map <string, vector <unsigned int>>*,
            vector < map <string, vector <unsigned int>>*>> consecutivePairs;

public:

    void addRangeIntersection(map<string, vector<unsigned int>> *pair1,
                              map<string, vector<unsigned int>> *pair2)
    {
        // TODO checkIfConsecutive()
        // TODO keepOnlyNotRegistered()

    }

    void keepCheapestIntersections()
    {
        // TODO
    }

    const map<string, unsigned int> getRange() {
        return range;
    }


    bool checkIfConsecutive (map <string, vector <unsigned int>> &pair1,
                                    map <string, vector <unsigned int>> &pair2)
    {
        static vector <map <string, vector <unsigned int>>*> consecutives;

        // if intersection contains sequence as 1:-> 2 -> 3, so 2:-> 3 does not happen
        if(std::find(consecutives.begin(), consecutives.end(), &pair2) != consecutives.end() &&
           std::find(consecutives.begin(), consecutives.end(), &pair1) != consecutives.end()) {

            return false;

        } else {

            map <string, unsigned int> range1 = calcRange(pair1);
            map <string, unsigned int> range2 = calcRange(pair2);

            bool pairsAreConsecutive = false;

            if ((range1["min"] < range2["min"]) && (range1["max"] < range2["max"])) { // pair2 precedes p1

                pairsAreConsecutive = true;

            } else if ((range2["min"] < range1["min"]) && (range2["max"] < range1["max"])) { // pair1 precedes p2

                pairsAreConsecutive = true;

            } else
                return false;

            if (pairsAreConsecutive) {

                consecutivePairs[&pair1].push_back(&pair2);

                consecutives.push_back(&pair1);
                consecutives.push_back(&pair2);
                return true;
            }
        }
    }

    void mergeConsecutivePairs ()
    {
        
    }
};

#endif //WEEK_8_RANGEINTERSECTION_H
