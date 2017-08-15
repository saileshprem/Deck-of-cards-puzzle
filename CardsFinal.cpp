//
//  The algorithm finds the number of rounds required for each card to get back
//  to its original position and finds their LCM, which gives us the total number
//  of rounds required.
//  This effectively reduces the total number of swaps done
//  and the iterations performed. Also, the rounds for each card is found in-place,
//  reducing space complexity.
//

#include <iostream>
#include <queue>
#include <algorithm>

// This function finds the resultant array after the first round. This array is used
// to find the number of rounds required for each card to get back to its original position
std::vector<int> ExchangeArray(std::queue<int> Hand)
{
  std::vector<int> Table;
  while(!Hand.empty())
  {
  Table.push_back(Hand.front());
  Hand.pop();
  if(!Hand.empty())
  {
    Hand.push(Hand.front());
    Hand.pop();
  }
  }
  std::reverse(Table.begin(),Table.end());
  return Table;
}

// Find the GCD
int gcd(int a,int b)
{
  if(b==0)
    return a;
  else
    return gcd(b, a%b);
}

// Find the LCM
int findLCM(int a, int b)
{
return (a*b)/gcd(a,b);
}

int main(int argc, char* argv[])
{
    int N = std::stoi(argv[1]);
    std::queue<int> A,Hand;
    std::vector<int> EArray;
    for(int i=0; i<N; i++)
        Hand.push(i);

    EArray = ExchangeArray(Hand); // Finds the rotated array after the first round
    int result=1;

    // Block that finds the number of rounds required for each card to get back
    // to its original position
    for(int k=0; k<EArray.size(); k++)
    {
      int RotationRounds = 1, Rotate = k;
      while(EArray[Rotate]!=k)
        {
          Rotate = EArray[Rotate];
          RotationRounds++;
        }
        result = findLCM(result,RotationRounds); // LCM of all cards' is the result
    }
    std::cout<<"For "<<N<<" cards, it takes "<<result<<" rounds to get back the original order."<<std::endl;
}
