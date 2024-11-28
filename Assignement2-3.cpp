#include <iostream>
#include<vector>
#include <string>
#include < cstdlib >

using namespace std;
using std::string;

class SocialMedia
{
public:
	string platformName;
	string username;
	int numPosts;

	SocialMedia()
	{
		username = username;
		numPosts = 0;

	}
	SocialMedia(string platform, string name, int posts)
		: platformName(platform), username(name), numPosts(posts) {}

	virtual ~SocialMedia() {}

	virtual void addPost(const::string& content) = 0;
	virtual void displayProfile() const = 0;
	virtual int countCharacters() const = 0;
	virtual void deletePosts(int index) = 0;
};


class Linkedin :public SocialMedia
{

public:
	int connections;
	string JobTitle;
	vector<string> Linkedinposts;

	

	/*Linkedin(int connections = 0, std::string JobTitle = " ", std::string username = " ", std::string platformName = " ", int numPosts = 0)
	{
		platformName = platformName;
		username = username;
		numPosts = numPosts;
		connections = connections;
		JobTitle = JobTitle;

	}*/

	Linkedin(string platform , string name, int posts, int con, string Job)
		: SocialMedia(platform, name, posts), connections(con), JobTitle(Job) {}

	~Linkedin() {
		cout << "The Linkedin profile is being deleted" << endl;
	}
	void addPost(const std::string& content) {
		Linkedinposts.push_back(content);
		numPosts++;
		connections++;
	}

	void displayProfile()const {
		cout << "Platform's name: " << platformName << endl;
		cout << "user's name: " << username << endl;
		cout << "number of posts: " << numPosts << endl;
		cout << "User's connections: " << connections <<endl<< "User's job" << JobTitle;

	}
	int countCharacters()const {
		int count = 0;
		for (const string& post : Linkedinposts)
		{
			
			 count += post.size();
		}

		return count;
	}

	void deletePosts(int index) {
		if (index >= 0 && index < Linkedinposts.size()) {
			Linkedinposts.erase(Linkedinposts.begin() + index);
			numPosts--;
		}
		else {
			cout << "Invalid index.";
		}
		connections++;
	}
};

class Facebook : public SocialMedia
{
public:
	int freindsCount;
	vector<int> likePerPost;
	vector<string> Facebookposts;
	/*Facebook()
	{
		platformName = platformName;
		username = username;
		numPosts = numPosts;
		int freindsCount;
		vector<int> likePerPost;
	}
	*/

	Facebook(string platform, string name, int posts, int freinds = 0, vector<int> likes = {}, vector<string> Faceposts ={})
		:  SocialMedia(platform, name, posts), freindsCount(freinds), likePerPost(likes), Facebookposts(Faceposts) {}

	~Facebook() {
		cout << "Facebook's profile is being deleted" << endl;
	}

	void addPost(const std::string& content) {
		
		Facebookposts.push_back(content);
		numPosts++;
		srand(static_cast<unsigned int>(time(0)));


		for (int i = 0; i < 5; i++) {
			int randomLikes = rand() % 101; 
			likePerPost.push_back(randomLikes);
		}
	}

	void displayProfile()const {
		cout << "Platform's name: " << platformName << endl;
		cout << "user's name: " << username << endl;
		cout << "number of posts: " << numPosts << endl;
		cout << "number of friends: " << freindsCount << endl;
		int totallikes= 0;
		for (int i = 0; likePerPost.size() > i; i++) {
			totallikes +=likePerPost[i];
		}
		
		int averagelikes = totallikes / likePerPost.size();
		cout << "average likes per post: " << averagelikes << endl;
	}

	int countCharacters()const {
		int count= 0;
		for (const string& post : Facebookposts)
		{
			count += post.size();
		}
		cout << "charcters in all posts: " << count<<endl;
		return count;
	}

	void deletePosts(int index) {
		if (index >= 0 && index < Facebookposts.size()) {
			Facebookposts.erase(Facebookposts.begin() + index);
			numPosts--;
		}
		else {
			cout << "Invalid index.";
		}
		likePerPost.erase(likePerPost.begin() + index);

	}
	
};

class Twitter : public SocialMedia {
public:
	vector<string> tweetCollection;



	Twitter(string platform, string name,int posts, vector<string> tweetCol ={})
		: SocialMedia(platform, name, posts), tweetCollection(tweetCol) {}

	~Twitter() {
		cout << "The Twitter's profile is deleted"<<endl;
	}

	void addPost(const std::string& content) {
		if (content.size() <= 280) {
			tweetCollection.push_back(content);
			numPosts++;
		}
		else
			cout << "Your tweet is too long";
	}

	void displayProfile()const {
		cout << "Platform's name: " << platformName << endl;
		cout << "user's name: " << username << endl;
		cout << "tweet count: " << numPosts<<endl;

		for (int i = 0; tweetCollection.size() > i; i++)
			cout << tweetCollection[i]<< endl;
	}

	int countCharacters()const {
		int count = 0;
		for (const string& post : tweetCollection)
		{
			count += post.size();
		}
		cout << "charcters in all posts: " << count << endl;
		return count;
	}

	void deletePosts(int index) {
		if (index >= 0 && index < tweetCollection.size()) {
			tweetCollection.erase(tweetCollection.begin() + index);
			numPosts--;
		}
		else {
			cout << "Invalid index.";
		}
		

	}
};

int main() 
{
	Linkedin Alex("Linkedin","Alex",10,400,"programmer");
	
	Alex.addPost("My name is Alex");
	Alex.addPost("Today was a good day");
	Alex.countCharacters();
	Alex.displayProfile();
	Alex.deletePosts(0);
	Alex.displayProfile();



	Facebook Jerem("Facebook","Jerem", 10, 300);
	Jerem.addPost("I had a walk today");
	Jerem.addPost("Yesterday I have seen a rabbit");
	Jerem.countCharacters();
	Jerem.displayProfile();
	Jerem.deletePosts(0);
	Jerem.displayProfile();
	
	Twitter Jane("Tweeter", "Jane",10);
	Jane.addPost("I have seen my friend in the restaurant\n");
	Jane.addPost("I was in an escape room with my friends\n");
	Jane.displayProfile();
	Jane.deletePosts(0);
	Jane.displayProfile();
	
	Jane.countCharacters();
	return 0;
}