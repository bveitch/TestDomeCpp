/*
   Question: TestDome - Friends

   Given a data structure representing a social network, write a function
   that finds friends of a certain degree. Friends of the first degree
   are a member's immediate friends, friends of the second degree are
   friends of a member's friends excluding first degree friends, etc.

   For example, if A is a friend with B and B is a friend with C, then
   getFriendsOfDegree(A, 2) should return C since C is the only second
   degree friend of A (B is a first degree friend of A).
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <iostream>
#include <unordered_set>


class Member
{
public:

   Member(std::string email)
   {
      this->email = email;
   }

   std::string getEmail() const
   {
      return this->email;
   }

   std::vector<Member*> getFriends() const
   {
      return this->friends;
   }

   void addFriend(Member* _friend)
   {
      this->friends.push_back(_friend);
   }

private:

   std::string email;
   std::vector<Member*> friends;
};

class Friends
{
public:

   static std::vector<Member*> getFriendsOfDegree(Member* member, int degree)
   {
       std::vector<Member*> prevfriends={member};
       std::unordered_set<Member*> foundfriends;
        std::vector<Member*> newfriends{};
        for(auto k=1; k<=degree; k++){
            for(auto f: prevfriends){
                std::vector<Member*> friendsof=f->getFriends();
           
                for(auto ff:friendsof){
                    if(foundfriends.find(ff)==foundfriends.end()) newfriends.push_back(ff);
                    foundfriends.emplace(ff);
                }
            }
            prevfriends.resize(newfriends.size());
            std::copy(newfriends.begin(),newfriends.end(),prevfriends.begin());
            newfriends.clear();
            for(auto f: prevfriends){
                std::cout << f->getEmail() << '\n';
            }
        }
        return prevfriends;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   Member a("A");
   Member b("B");
   Member c("C");

   a.addFriend(&b);
   b.addFriend(&c);

   std::vector<Member*> friends = Friends::getFriendsOfDegree(&a, 2);
   for (std::vector<Member*>::iterator it = friends.begin(); it != friends.end(); ++it)
   {
      std::cout << (*it)->getEmail() << '\n';
   }
}
#endif