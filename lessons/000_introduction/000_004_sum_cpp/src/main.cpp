#include "sum.h"
#include "sum_variants.h"
#include <iostream>
#include <vector>
//#include <list>
//#include <deque>


using namespace std;

int main() {
    cout << "What's your name? ";
    string name;
    cin >> name;

    cout << "\nHello " << name << ", how many values should be added? ";
    int number_of_summands = 0;
    cin >> number_of_summands;

    float cur_number = 0.0f;
    vector<float> summands;
    for( int index = 0; index < number_of_summands; ++index ) {
        cout << "Please put in " << index+1 << ". number! ";
        cin >> cur_number;
        summands.push_back( cur_number );
    }

    //float sum = calculate_sum_of( summands );
    float sum = sum_template( summands );

    size_t index = 0;;
    for( auto& cur_summand : summands )
    {
        cout << cur_summand;
        if( index+1 < summands.size() ) {
            cout << " + ";
        }
        ++index;
    }
    cout << " = " << sum << endl;
    cout << "See you " << name << "!" << endl;
}
