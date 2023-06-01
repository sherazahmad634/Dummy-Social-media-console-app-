#include<iostream>
#include<string>
using namespace std;



class time {
private:
	int sec;
	int min;
	int hr;
public:
	time() :sec(0), min(0), hr(0) {

	}
	time(int thr, int tmin, int tsec) : hr(thr), min(tmin), sec(tsec) {

	}
	void setsec(int tsec) {
		if (tsec >= 0 && tsec < 60) {
			sec = tsec;
		}
		else {
			sec = 0;
		}
	}
	void setmin(int tmin) {
		if (tmin >= 0 && tmin < 60) {
			min = tmin;
		}
		else {
			min = 0;
		}
	}
	void sethr(int thr) {
		if (thr >= 0 && thr < 24) {
			hr = thr;
		}
		else {
			hr = 0;
		}
	}
	void settime(int thr, int tmin, int tsec) {
		if (thr >= 0 && thr < 24) {
			hr = thr;
		}
		else {
			hr = 0;
		}
		if (tmin >= 0 && tmin < 60) {
			min = tmin;
		}
		else {
			min = 0;
		}
		if (tsec >= 0 && tsec < 60) {
			sec = tsec;
		}
		else {
			sec = 0;
		}
	}
	int getsec() {
		return sec;
	}
	int getmin() {
		return min;
	}
	int gethr() {
		return hr;
	}
	void display() {
		
		cout << endl << hr << ":" << min << ":" << sec << "(Hr:Min:Sec)";
		cout << endl << endl;
	}
};
class date {
private:
	int day;
	int month;
	int year;
public:
	date() :day(0), month(0), year(0) {

	}
	date(int tday, int tmonth, int tyear) :day(tday), month(tmonth), year(tyear) {

	}
	void setdate(int tday, int tmonth, int tyear) {
		day = tday;
		month = tmonth;
		year = tyear;
	}
	void setday(int tday) {
		day = tday;
	}
	void setmonth(int tmonth) {
		month = tmonth;
	}
	void setyear(int tyear) {
		year = tyear;
	}
	int getday() {
		return day;
	}
	int getmonth() {
		return month;
	}
	int getyear() {
		return year;
	}
	void display_date() {
		cout  << "Date is:   " << "(" << day << "/" << month << "/" << year << ")"<<endl;
	}
};
class comment {
private:
	string user_comment;
public:
	comment() :user_comment("NULL") {

	}
	comment(string tuser_comment) :user_comment(tuser_comment) {

	}
	void setcomment(string tuser_comment) {
		user_comment = tuser_comment;
	}
	string getcomment() {
		return user_comment;
	}
	void display_Comment() {
		cout << endl << user_comment;
	}
};
class stack_of_comments {  //This Stack handles COMMENTS.
private:
	comment *arr;
	int size;
	int top;
	int top_sequal;
public:
	stack_of_comments() :size(0) {
		arr = new comment[size];
	}
	/*stack(int tsize) :size(tsize){
		arr = new comment[size];
	}*/
	comment COMMENT{ "NULL" };
	stack_of_comments(int tsize) {
		size = tsize;
		arr = new comment[size];
		top = 0;
		top_sequal = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = COMMENT;
		}
	}
	bool isfull() {
		if (top == size) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isempty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(comment COMMENT) {
		if (!isfull()) {
			arr[top] = COMMENT;
			top++;
			top_sequal++;
		}
		else {
			cout << endl << "Stack is Full";
		}
	}
	comment pop() {
		if (!isempty()) {
			top--;
			return arr[top];
			/*comment x = arr[top];
			arr[top] = COMMENT;*/
		}
		else {
			cout << endl << "List is Empty";
			return COMMENT;
		}
	}
	bool isreturn_comm_empty() {
		if (top_sequal == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	comment return_comm() {
		if (!isempty())
		{
			top_sequal--;
			comment x = arr[top_sequal];
			return x;
		}
		else
		{
			return COMMENT;
		}
	}
	comment Top() {
		if (!isempty()) {
			return arr[top - 1];
		}
		else {
			return COMMENT;
		}
	}
	void settop_sequal() {
		top_sequal = top;
	}
};//handles comments
class post {
private:
	int id;
	string owner;
	string content;
	date Date;
	stack_of_comments comm;
	comment var1;
	time Time;
public:
	post() :id(0),owner("NULL"), content("NULL"), Date(0, 00, 0000),comm(50),Time(0,0,0) {

	}
	post(int tid,string towner, string tcontent, date tdate,time tTime) :id(tid),owner(towner), content(tcontent), Date(tdate),Time(tTime) {

	}
	void setpost(int tid, string towner, string tcontent, date tdate,time tTime) {
		id = tid;
		owner = towner;
		content = tcontent;
		Date = tdate;
		Time = tTime;
	}
	void setid(int tid) {
		id = tid;
	}
	void setowner(string towner) {
		owner = towner;
	}
	void setcontent(string tcontent) {
		content = tcontent;
	}
	void setdate(date tdate) {
		Date = tdate;
	}
	void settime(time tTime) {
		Time = tTime;
	}
	void setcomment(comment tcomment) {
		comm.push(tcomment);
	}
	int getid() {
		return id;
	}
	string getowner() {
		return owner;
	}
	string getcontent() {
		return content;
	}
	date getdate() {
		return Date;
	}
	time gettime() {
		return Time;
	}
	stack_of_comments getcomment() {
		return comm;
	}
	void display_Post() {
		cout << endl << "The ID of the Post is: " << id;
		cout << endl << "The Owner Of the Post is: " << owner;
		cout << endl << "The Content of the Post is: " << content;
		cout << endl;
		Date.display_date();
		Time.display();
		cout << endl << "Comments Of the Posts are: ";
		cout << endl;
		while (!comm.isreturn_comm_empty())
		{
			var1=comm.return_comm();
			cout << endl << var1.getcomment();
			cout << endl;
		}

		comm.settop_sequal();

	}
	
	void CommentsOF_posts_display()
	{
		cout << endl << "Comments Of the Posts are: ";
		while (!comm.isreturn_comm_empty())
		{
			var1 = comm.return_comm();
			cout << endl << var1.getcomment();
		}
		comm.settop_sequal();
	}
};

class stack_of_posts
{ //This stack handles Posts 
private:
	post *arr;
	int size;
	int top;
	int top_sequal;
public:
	time post_stack_time{ 00, 00, 00 };
	date datePost{0,0,0000};
	post varPost{0,"NULL", "NULL", datePost,post_stack_time};
	stack_of_posts() :size(0) {

	}
	stack_of_posts(int tsize) {
		size = tsize;
		arr = new post[size];
		top = 0;
		top_sequal = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = varPost;
		}
	}
	bool isfull() {
		if (top == size) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isempty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(post varpost2) {
		if (!isfull()) {
			arr[top] = varpost2;
			top++;
			top_sequal++;
		}
		else {
			cout << endl << "Stack is Full";
		}
	}
	post pop() {
		if (!isempty()) {
			top--;
			return arr[top];
			post x = arr[top];
			arr[top] = varPost;
		}
		else {
			cout <<endl<< "List is Empty";
			
		}
	}
	bool isreturn_post_empty() {
		if (top_sequal == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	post return_post() {
		if (!isempty())
		{
			top_sequal--;
			post x = arr[top_sequal];
			return x;
		}
		else
		{
			return varPost;
		}
	}
	
	post Top() {
		if (!isempty()) {
			return arr[top - 1];
		}
		else {
			return varPost;
		}
	}
	void settop_sequal() {
		top_sequal = top;
	}
	stack_of_posts return_stack_of_posts() {
		
	}
};

class Personnel_tab {
private:
	post posts_var;//handles his/her owen posts
	int size;
	date DATE;
	stack_of_posts posts_stack;
	stack_of_posts posts_stack2;
	stack_of_posts posts_stack3;
	
public:
	Personnel_tab() :size(0),DATE(0,0,0000),posts_stack(20), posts_stack2(20), posts_stack3(20){

	}
	void viewPosts() {
		//posts.display_Post();
		//posts_stack.return_post display_Post();
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
	}
	void addpost(post tposts) {
		posts_stack.push(tposts);
	}
	void DeletePosts() {
		post var3;
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
		cout << endl << "These are all the Posts........";
		cout << endl << "Now which Post you wanna delete, enter ID of that Post: ";
		int id;
		cin >> id;
		cout << endl << "Posts after Deletion: " << endl;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack2.push(var2);
			}
			else {
				var3 = posts_stack.pop();
			}
		}
		cout << endl << "If you want to UNDO your Deleted Post then Press 1";
		cout << endl << "If don't then Press 2: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			posts_stack2.push(var3);
			break;
		}
		case 2:
		{
			cout << endl << "Post deleted Successfully";
			break;
		}
		default:
		{
			cout << endl << "Invalid choice: ";
			break;
		}
		}
		cout << endl << "Posts after Deletion: " << endl;
		while (!posts_stack2.isempty())
		{
			post var2 = posts_stack2.pop();
			var2.display_Post();
			posts_stack.push(var2);
		}
		/*while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
		}
		posts_stack.settop_sequal();
		*/
	}
	void ViewComments() {
		//posts_stack.return_post().CommentsOF_posts_display();
		//tposts.CommentsOF_posts_display();
		post var3;
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
		cout << endl << "These are all the Posts........";
		cout << endl << "Now which Post's comments you wanna see, enter ID of that Post: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack2.push(var2);
			}
			else {
				var3 = posts_stack.pop();
				var3.CommentsOF_posts_display();
				posts_stack2.push(var3);
			}
		}
		while (!posts_stack2.isempty())
		{
			post var2 = posts_stack2.pop();
			posts_stack.push(var2);
		}
	}
	void addcomments2(string com)
	{
		post var5;
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();

		cout << endl << "------------These are all the Posts----------- ";
		cout << endl << "Enter the ID of the Post on which you wanna add comment: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack3.push(var2);
			}
			else {

				post var3 = posts_stack.pop();
				comment commm;
				cout << endl << "Enter the Comment You wanna add: " << endl;
				
				commm.setcomment(com);
				var3.setcomment(commm.getcomment());
				posts_stack3.push(var3);
			}
		}
		while (!posts_stack3.isempty())
		{
			post var6 = posts_stack3.pop();
			posts_stack.push(var6);
		}
		cout << endl << "Updated Comments of the Posts are: ";
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();
	}
	void addcomments() {
		post var5;
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();
		
		cout << endl << "------------These are all the Posts----------- ";
		cout << endl << "Enter the ID of the Post on which you wanna add comment: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack3.push(var2);
			}
			else {
				
				post var3 = posts_stack.pop();
				comment commm;
				cout << endl << "Enter the Comment You wanna add: "<<endl;
				string com;
				cin.ignore();
				getline(cin, com);
				commm.setcomment(com);
				var3.setcomment(commm.getcomment());
				posts_stack3.push(var3);
			}
		}
		while (!posts_stack3.isempty())
		{
			post var6 = posts_stack3.pop();
			posts_stack.push(var6);
		}
		cout << endl << "Updated Comments of the Posts are: ";
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();
	}
	void Delete_Comments() {
		post var5;
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();

		cout << endl << "------------These are all the Posts----------- ";
		cout << endl << "Enter the ID of the Post on which you wanna add comment: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack3.push(var2);
			}
			else {

				post var3 = posts_stack.pop();
				comment commm;
				cout << endl << "Enter the Comment You wanna add: " << endl;
				string com;
				cin.ignore();
				getline(cin, com);
				commm.setcomment(com);
				var3.setcomment(commm.getcomment());
				posts_stack3.push(var3);
			}
		}
		while (!posts_stack3.isempty())
		{
			post var6 = posts_stack3.pop();
			posts_stack.push(var6);
		}
		cout << endl << "Updated Comments of the Posts are: ";
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();
	}
	post getpost() {
		post returns;
		returns=posts_stack.return_post();
		return returns;
	}
	stack_of_posts return_StackOfPosts() {
		return posts_stack;
	}
};
class Node_of_post {
private:
	post val;
	Node_of_post* next;
public:

	Node_of_post(post tval) : val(tval), next(NULL) {
	}

	void setVal(post tval) {
		val = tval;
	}
	void setNext(Node_of_post* tnext) {
		next = tnext;
	}
	post getvalue() {
		return val;
	}
	Node_of_post* getnext() {
		return next;
	}
	void display() {
		val.display_Post();
	}
};
class linklist_Post {
private:
	Node_of_post* Head;
public:
	linklist_Post()
	{
		Head = NULL;
	}
	void sortInsert_Post(post val)
	{
		Node_of_post* N = new Node_of_post(val);
		if (Head == NULL)
		{
			Head = N;
		}
		else if (Head->getvalue().gettime().gethr() < val.gettime().gethr() && Head->getvalue().gettime().gethr() != val.gettime().gethr())
		{
			if (Head->getvalue().gettime().gethr() < val.gettime().gethr() && Head->getvalue().gettime().gethr() != val.gettime().gethr())
			{
				N->setNext(Head);
				Head = N;
			}
			else if (Head->getvalue().gettime().getmin() < val.gettime().getmin() && Head->getvalue().gettime().getmin() != val.gettime().getmin())
			{
				N->setNext(Head);
				Head = N;
			}
			else if (Head->getvalue().gettime().getsec() < val.gettime().getsec() && Head->getvalue().gettime().getsec() != val.gettime().getsec())
			{
				N->setNext(Head);
				Head = N;
			}
			else if (Head->getvalue().gettime().getsec() == val.gettime().getsec())
			{
				N->setNext(Head);
				Head = N;
			}
		}
		
		else 
		{
			Node_of_post* t1, *t2;
			t1 = t2 = Head;
			while (t2 != NULL)
			{
				if (t2->getvalue().gettime().gethr() > val.gettime().gethr() && t2->getvalue().gettime().gethr() != val.gettime().gethr())
				{
					if (t2->getvalue().gettime().gethr() > val.gettime().gethr() && t2->getvalue().gettime().gethr() != val.gettime().gethr())
					{
						t1 = t2;
						t2 = t2->getnext();
					}
					else if (t2->getvalue().gettime().getmin() > val.gettime().getmin() && t2->getvalue().gettime().getmin() != val.gettime().getmin())
					{
						t1 = t2;
						t2 = t2->getnext();
					}
					else if (t2->getvalue().gettime().getsec() > val.gettime().getsec() && t2->getvalue().gettime().getsec() != val.gettime().getsec())
					{
						t1 = t2;
						t2 = t2->getnext();
					}
					else if (t2->getvalue().gettime().getsec() == val.gettime().getsec() && t2->getvalue().gettime().getsec() != val.gettime().getsec())
					{
						t1 = t2;
						t2 = t2->getnext();
					}
				}
				else
				{
					break;
				}
			}
			t1->setNext(N);
			N->setNext(t2);
		}
	}
	void Display() {
		Node_of_post* temp = Head;
		while (temp != NULL)
		{
			temp->getvalue().display_Post();
			temp = temp->getnext();
		}
	}
};

class Node {
public:
	char ch;
	bool terminal;
	Node* child[26];

	Node(char c)
	{
		ch = c;
		terminal = false;
		for (int i = 0; i < 26; i++)
		{
			child[i] = NULL;
		}
	}
};

class Tries
{
public:
	Node* root;

	Tries()
	{
		root = createNode('\0');
	}

	Node* createNode(char c)
	{
		Node* newNode = new Node(c);
		return newNode;
	}

	void Insert(string word)
	{
		Node* temp = root;
		char ch = '\0';
		int pos = 0;

		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];
			if (ch != 32)
			{

				pos = ch - 'a';


				if (temp->child[pos] == NULL)
				{
					temp->child[pos] = createNode(ch);
				}
				temp = temp->child[pos];
			}
		}
		temp->terminal = true;
	}
	void Display(Node* temp, string word)
	{
		if (temp == NULL)
			return;

		if (temp != root)
			word = word + temp->ch;
		if (temp->terminal)
			cout << word << endl;
		for (int i = 0; i < 26; i++)
		{
			Display(temp->child[i], word);
		}
	}

	Node* search(Node* temp, string key, int index)
	{

		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}
		int i = ch - 'a';

		return	search(temp->child[i], key, ++index);

	}
};
class friend_usr {
private:
	string name;
public:
	friend_usr() :name("NONE")
	{

	}
	friend_usr(string tname) :name(tname)
	{

	}
	void set_friend(string tname)
	{
		name = tname;
	}
	string get_friend()
	{
		return name;
	}
};

class queue_of_friends {
private:
	int size, front, rare, cap, curr;
	friend_usr* arr;

public:
	friend_usr f{ "NONE" };
	queue_of_friends() :size(5)
	{
		arr = new friend_usr[size];
		front = rare = cap = curr = 0;

		for (int i = 0; i < size; i++)
		{
			arr[i] = f;
		}

	}
	queue_of_friends(int tsize)
	{
		size = tsize;
		arr = new friend_usr[size];
		front = rare = cap = curr = 0;

		for (int i = 0; i < size; i++)
		{
			arr[i] = f;
		}

	}


	void setsize(int tsize)
	{
		size = tsize;
		arr = new friend_usr[size];
	}
	bool isfull()
	{


		if (cap == size)
		{
			return true;
		}
		else
			return false;
	}
	bool isempty()
	{
		if (cap == 0)
		{
			return true;
		}
		else
			return false;
	}
	void Enqueue(friend_usr val)
	{
		if (!isfull())
		{
			arr[rare] = val;
			rare = (rare + 1) % size;
			cap++;
		}

		else
		{
			cout << "Queue is Full" << endl;
		}

	}
	friend_usr Dequeue()
	{
		if (!isempty())
		{
			friend_usr x = arr[front];
			arr[front] = f;
			front = (front + 1) % size;
			curr = (curr + 1) % size;
			--cap;
			return x;
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
	}
	friend_usr display()
	{
		if (!isempty())
		{
			friend_usr x = arr[curr];
			curr = (curr + 1) % size;
			return x;
		}
		else
		{
			cout << "Queue is Empty" << endl;
		}
	}
	int get_cap()
	{
		return cap;
	}
	void set_curr()
	{

		curr = front;

	}
};

class message {
private:
	string msg;
	string name;
public:
	message() :msg("NONE"), name("NONE")
	{

	}
	message(string tmsg, string tname) :msg(tmsg), name(tname)
	{

	}
	void setmsg(string var)
	{
		msg = var;

	}
	void setmsg_sender_name(string n_msg)
	{
		name = n_msg;

	}
	string get_msg()
	{
		return msg;

	}
	string get_msg_n()
	{
		return name;

	}
	string get_msg_oname()
	{
		return name;
	}
	void display()
	{
		cout << name << ":";
		cout << msg << endl;
	}
};

class Friend_tab {
private:

	queue_of_friends friend_requests;
	queue_of_friends friend_list;

public:
	Friend_tab() :friend_requests(50), friend_list(50)
	{

	}
	Friend_tab(int tsize1, int tsize2) :friend_requests(tsize1), friend_list(tsize2)
	{

	}

	queue_of_friends get_queue_f_list()
	{
		return friend_list;
	}
	string send_friend_request(Tries& t)
	{
		string key;
		cout << "Enter Name you want to send request" << endl;
		//cin.ignore();
		cin >> key;

		int flag = 0;
		Node* temp = t.search(t.root, key, 0);

		key.erase(key.size() - 1);
		if (temp)
		{
			cout << "**SUGGESTIONS**" << endl;
			t.Display(temp, key);
			flag = 1;
		}
		else
		{
			cout << "Not Found" << endl;
			return "0";
		}
		if (flag == 1)
		{
			string request;

			cout << "--Enter the name of person from Suggestions to which  you want to send Friend Request--" << endl;
			cin.ignore();
			getline(cin, request);
			cout << "*Your Request has been sent** " << endl;
			return request;
		}
	}
	void other_usr_request(string n)
	{
		friend_list.Enqueue(n);
	}
	void set_Request(string n)
	{
		friend_requests.Enqueue(n);
	}
	string accept_request()
	{
		queue_of_friends friend_requests2{ 50 };
		friend_usr f;
		cout << "<<Your Friend requests>>" << endl;
		int cap = friend_requests.get_cap();
		int range = 0;
		while (range < cap)
		{
			cout << friend_requests.display().get_friend() << endl;
			range++;
		}
		friend_requests.set_curr();
		string request;
		cout << "Enter the name of person of you want to Accept Friend Request From the Above List" << endl;
		cin.ignore();
		getline(cin, request);
		friend_list.Enqueue(request);
		while (!friend_requests.isempty())
		{
			f = friend_requests.Dequeue().get_friend();
			if (f.get_friend() != request)
			{
				friend_requests2.Enqueue(f);
			}
		}
		while (!friend_requests2.isempty())
		{
			f = friend_requests2.Dequeue().get_friend();
			friend_requests.Enqueue(f);
		}
		return request;
	}
	void my_friends()
	{
		cout << "\t <<<<<<<FRIEND LIST>>>>>" << endl;
		int cap = friend_list.get_cap();
		int range = 0;
		while (range < cap)
		{
			cout << friend_list.display().get_friend() << endl;
			range++;
		}
		friend_list.set_curr();
	}
};
class stack_of_messages
{
private:
	message* arr;
	int cap;
	int size;
	int top;
	int top_sequal;
public:
	message var{ "NONE", "NONE" };
	stack_of_messages() :size(50) {
		top = top_sequal = cap = 0;
		arr = new message[size];
		for (int i = 0; i < size; i++) {
			arr[i] = var;
		}
	}
	stack_of_messages(int tsize) {
		size = tsize;
		arr = new message[size];
		top = 0;
		cap = 0;
		top_sequal = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = var;
		}
	}
	bool isfull() {
		if (top == size) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isempty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(message tvar) {
		if (!isfull()) {
			arr[top] = tvar;
			top++;
			top_sequal++;
		}
		else {
			cout << endl << "Stack is Full";
		}
	}
	message pop()
	{
		if (!isempty())
		{
			top--;
			return arr[top];
			message x = arr[top];
			arr[top] = var;
			return x;
		}
		else
		{
			cout << endl << "List is Empty";

		}
	}
	bool isreturn_conv_empty() {
		if (top_sequal == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	message return_msg() {
		if (!isempty())
		{
			top_sequal--;
			message x = arr[top_sequal];
			return x;
		}
		else
		{
			return var;
		}
	}
	message Top() {
		if (!isempty()) {
			return arr[top - 1];
		}
		else {
			cout << "Stack is Empty" << endl;
		}
	}
	int get_topS()
	{
		return top_sequal;
	}
	void settop_sequal() {
		top_sequal = top;
	}


};

class message_tab_hash {
private:
	stack_of_messages* bucket;
	int key;
	int size;
public:

	message_tab_hash() :size(51), key(0)
	{
		bucket = new stack_of_messages[size];
	}
	message_tab_hash(int tsize)
	{
		size = tsize;
		key = 0;
		bucket = new stack_of_messages[size];
	}
	int HashFun(string name)
	{

		int length = name.length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + name[i];

			i++;
		}
		key = key % size;

		return key;

	}
	stack_of_messages search(string name)
	{
		int length = name.length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + name[i];

			i++;
		}
		key = key % size;
		return bucket[key];
	}
	void insert(message var, string name)
	{

		int key = HashFun(name);
		bucket[key].push(var);
	}
	void display(string name)
	{
		stack_of_messages st = search(name);
		while (!st.isreturn_conv_empty())
		{
			message m = st.return_msg();
			m.display();
		}
		st.settop_sequal();
	}
	
};
class Home_Tab {
private:
	post posts_var;//handles his/her owen posts
	int size;
	date DATE;
	stack_of_posts posts_stack;
	stack_of_posts posts_stack2;
	stack_of_posts posts_stack3;
	
	linklist_Post l1;
	Friend_tab friendTab;

public:
	Home_Tab() :size(0), DATE(0, 0, 0000), posts_stack(20), posts_stack2(20), posts_stack3(20) {

	}
	void getFriend_Set_Post() {
		queue_of_friends que_friends;

	}
	void viewPosts() {
		//posts.display_Post();
		//posts_stack.return_post display_Post();
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
	}
	void addpost(post tposts) {
		posts_stack.push(tposts);
	}
	void DeletePosts() {
		post var3;
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
		cout << endl << "These are all the Posts........";
		cout << endl << "Now which Post you wanna delete, enter ID of that Post: ";
		int id;
		cin >> id;
		cout << endl << "Posts after Deletion: " << endl;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack2.push(var2);
			}
			else {
				var3 = posts_stack.pop();
			}
		}
		cout << endl << "If you want to UNDO your Deleted Post then Press 1";
		cout << endl << "If don't then Press 2: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			posts_stack2.push(var3);
			break;
		}
		case 2:
		{
			cout << endl << "Post deleted Successfully";
			break;
		}
		default:
		{
			cout << endl << "Invalid choice: ";
			break;
		}
		}
		cout << endl << "Posts after Deletion: " << endl;
		while (!posts_stack2.isempty())
		{
			post var2 = posts_stack2.pop();
			var2.display_Post();
			posts_stack.push(var2);
		}
		/*while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
		}
		posts_stack.settop_sequal();
		*/
	}
	void ViewComments() {
		//posts_stack.return_post().CommentsOF_posts_display();
		//tposts.CommentsOF_posts_display();
		post var3;
		while (!posts_stack.isreturn_post_empty())
		{
			posts_var = posts_stack.return_post();
			posts_var.display_Post();
		}
		posts_stack.settop_sequal();
		cout << endl << "These are all the Posts........";
		cout << endl << "Now which Post's comments you wanna see, enter ID of that Post: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack2.push(var2);
			}
			else {
				var3 = posts_stack.pop();
				var3.CommentsOF_posts_display();
				posts_stack2.push(var3);
			}
		}
		while (!posts_stack2.isempty())
		{
			post var2 = posts_stack2.pop();
			posts_stack.push(var2);
		}
	}

	void addcomments() {
		post var5;
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();

		cout << endl << "------------These are all the Posts----------- ";
		cout << endl << "Enter the ID of the Post on which you wanna add comment: ";
		int id;
		cin >> id;
		while (!posts_stack.isempty())
		{
			if (posts_stack.Top().getid() != id) {
				post var2 = posts_stack.pop();
				posts_stack3.push(var2);
			}
			else {

				post var3 = posts_stack.pop();
				comment commm;
				cout << endl << "Enter the Comment You wanna add: " << endl;
				string com;
				cin.ignore();
				getline(cin, com);
				commm.setcomment(com);
				var3.setcomment(commm.getcomment());
				posts_stack3.push(var3);
			}
		}
		while (!posts_stack3.isempty())
		{
			post var6 = posts_stack3.pop();
			posts_stack.push(var6);
		}
		cout << endl << "Updated Comments of the Posts are: ";
		while (!posts_stack.isreturn_post_empty())
		{
			var5 = posts_stack.return_post();
			var5.display_Post();
			//posts_stack3.push(var5);
		}
		posts_stack.settop_sequal();
	}
};

class Sign_Up
{
private:
	string name;
	string mobile_no;
	string password;
	string username;
	message_tab_hash m;
	Friend_tab f;
	Personnel_tab personal_tab;
	Home_Tab home_tab;
public:
	Sign_Up() :name("NULL"), mobile_no("NULL"), password("NULL"), username("NULL") {

	}
	Sign_Up(string tname, string tmobile_no, string tpassword, string tusername) :name(tname), mobile_no(tmobile_no), password(tpassword), username(tusername) {

	}
	void setSign_up(string tname, string tmobile_no, string tpassword, string tusername) {
		name = tname;
		mobile_no = tmobile_no;
		password = tpassword;
		username = tusername;

	}
	void setFriendTab(Friend_tab tf)
	{
		f = tf;
	}
	void setPersonalTAB(Personnel_tab tpersonal_tab) {
		personal_tab = tpersonal_tab;
	}
	Personnel_tab getPersonalTAB() {
		return personal_tab;
	}
	void viewPost()
	{
		personal_tab.viewPosts();
	}
	Friend_tab get_F_tab()
	{
		return f;
	}
	void setHomeTab(Home_Tab thome_tab) {
		home_tab = thome_tab;
	}
	Home_Tab getHomeTab() {
		return home_tab;

	}
	void setMsg(message ms, string name)
	{
		m.insert(ms, name);
	}
	message_tab_hash get_msg_tab()
	{
		return m;
	}
	string friend_request(Tries t)
	{
		string n = f.send_friend_request(t);
		return n;
	}
	string accept_request()
	{
		string n = f.accept_request();
		return n;
	}
	void set_request(Sign_Up s)
	{

		f.set_Request(s.getname());
	}
	void set_requestof_other(Sign_Up s)
	{
		f.other_usr_request(s.getname());
	}
	void see_friendlist()
	{
		f.my_friends();
	}
	void setname(string tname) {
		name = tname;
	}
	void setmobile(string tmobile_no) {
		mobile_no = tmobile_no;
	}
	void setpassword(string tpassword) {
		password = tpassword;
	}
	void setusername(string tusername) {
		username = tusername;
	}
	string getname() {
		return name;
	}
	string getmobile() {
		return mobile_no;
	}
	string getpassword() {
		return password;
	}
	string getusername() {
		return username;
	}

	void Display() {
		cout << endl << "The Name of the User is: " << name;
		cout << endl << "Mobile Number of the User is: " << mobile_no;
		cout << endl << "The Password of the User is: " << password;
		cout << endl << "The Username of the User is: " << username;
	}
	void addpost() {
		cout << endl << "--------Enter the Information of the Post you wanna add-------- ";
		post tp;
		int id;
		cout << endl << "Enter the ID of the Post: ";
		cin >> id;
		//tp.setid(id);
		string owner;
		cout << endl << "Who is the Ownwer of the Post: ";
		cin >> owner;
		//tp.setowner(owner);
		string content;
		cout << endl << "Content of the Post: ";
		cin >> content;
		//tp.setcontent(content);
		cout << endl << "-----------Enter Date Of the Post------------- ";
		int day, month, year;
		cout << endl << "Enter the day: ";
		cin >> day;
		cout << endl << "Enter the Month: ";
		cin >> month;
		cout << endl << "Enter the Year: ";
		cin >> year;
		date Date;
		Date.setdate(day, month, year);
		cout << endl << "-----------Enter Time Of the Post------------- ";
		int hours, mint, sec;
		cout << endl << "Enter the Hours: ";
		cin >> hours;
		cout << endl << "Enter the mint: ";
		cin >> mint;
		cout << endl << "Enter the sec: ";
		cin >> sec;
		time time_post(hours, mint, sec);
		tp.setpost(id, owner, content, Date, time_post);
		personal_tab.addpost(tp);
		cout << endl << endl << "Now the updated Posts are: ";
		personal_tab.viewPosts();
	}
	void View_posts() {
		cout << endl << endl << "These are all the Posts: ";
		personal_tab.viewPosts();
	}
	void DeletePosts_Personal() {
		personal_tab.DeletePosts();
	}
	void ViewCommentsPersonal() {
		personal_tab.ViewComments();
	}
	void AddcommentsPersonal() {
		personal_tab.addcomments();
	}
};
class Hash_username {
private:
	int size;
	Sign_Up* bucket;
public:
	Sign_Up temp{ "NONE", "NONE", "NONE", "NONE" };
	Hash_username() :size(101)
	{
		bucket = new Sign_Up[size];
		for (int i = 0; i < size; i++)
		{
			bucket[i] = temp;
		}
	}
	int HashFun(Sign_Up var)
	{

		int length = var.getusername().length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + var.getusername()[i];

			i++;
		}

		key = key % size;
		if (bucket[key].getusername() != "NONE")
		{
			return 0;
		}

		return key;
	}
	void insert(Sign_Up var)
	{
		string user_name;
		int key = HashFun(var);
		while (key == 0)
		{
			cout << "This Username Already Exist" << endl;
			cout << "Please Enter Another username" << endl;
			cin >> user_name;
			var.setusername(user_name);
			key = HashFun(var);
		}

		bucket[key] = var;
	}
	Sign_Up search(string name)
	{

		int length = name.length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + name[i];

			i++;
		}
		key = key % size;
		return bucket[key];

	}
};
class Hash_name {
private:
	int size;
	Sign_Up* bucket;
public:
	Sign_Up temp{ "NONE", "NONE", "NONE", "NONE" };
	Hash_name() :size(101)
	{

		bucket = new Sign_Up[size];
		for (int i = 0; i < size; i++)
		{
			bucket[i] = temp;
		}
	}
	int HashFun(string name)
	{

		int length = name.length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + name[i];

			i++;
		}
		key = key % size;

		return key;

	}
	Sign_Up search(string name)
	{

		int length = name.length();
		int i = 0, key = 0;
		while (i < length)
		{
			key = key + name[i];

			i++;
		}
		key = key % size;
		return bucket[key];

	}
	void insert(Sign_Up var)
	{
		string user_name;
		int key = HashFun(var.getname());
		bucket[key] = var;
	}
};

int Main_menu()
{
	int x;
	cout << "PRESS-1 TO SIGN UP" << endl;
	cout << "PRESS-2 TO LOG IN" << endl;
	cout << "PRESS-3 TO EXIT" << endl;
	cout << endl << endl;
	cin >> x;
	return x;
}
int Login_menu()
{
	int x;
	cout << "PRESS-1 TO GO TO PERSONAL TAB" << endl;
	cout << "PRESS-2 TO GO TO HOME TAB" << endl;
	cout << "PRESS-3 TO GO TO FRIEND TAB" << endl;
	cout << "PRESS-4 TO GO TO MESSAGE TAB" << endl;
	cout << "PRESS-5 TO GO BACK TO MAIN MENU" << endl;
	cout << endl << endl;
	cin >> x;
	return x;
}

int Personal_Tab_Menu() {
	int x;
	cout << endl << "PRESS-1 TO ADD POST IN YOUR PERSONNAL TAB ";
	cout << endl << "PRESS-2 TO ADD COMMENTS TO YOUR POSTS ";
	cout << endl << "PRESS-3 TO VIEW YOUR POSTS ";
	cout << endl << "PRESS-4 TO VIEW COMMENST OF YOUR POSTS ";
	cout << endl << "PRESS-5 TO DELETE THE POST ";
	
	cout << endl << endl;

	cin >> x;
	return x;
}
int Home_tab_Menu() {
	int x;
	cout << endl << "PRESS-1 TO VIEW ALL POSTS ";
	cout << endl << "PRESS-2 TO ADD COMMENST ON THE POSTS ";
	cout << endl << "PRESS-3 TO ADD YOUR POST  ";
	cout << endl << "PRESS-4 TO DELETE ONLY YOUR POST ";
	cout << endl << "PRESS-5 TO view COMMENTS ON THE POSTS ";
	cout << endl << "PRESS-6 To GO BACK TO LOGIN MENU ";
	cout << endl << endl;
	cin >> x;
	return x;
}
int Friend_tab_menu()
{
	int x;
	cout << "PRESS-1 TO SEND FRIEND REQUEST" << endl;
	cout << "PRESS-2 TO ACCEPT FRIEND REQUEST" << endl;
	cout << "PRESS-3 TO SEE YOUR FRIEND LIST" << endl;
	cout << "PRESS-4 TO GO BACK TO LOG IN MENU" << endl;
	cout << endl << endl;
	cin >> x;
	return x;
}
int message_menu()
{
	int x;
	cout << "PRESS-1 TO SEND MESSAGE" << endl;
	cout << "PRESS-2 TO SEE CONVERSATION WITH YOUR FRIEND " << endl;
	cout << "PRESS-3 TO GO BACK TO LOG IN MENU" << endl;
	cout << endl << endl;
	cin >> x;
	return x;
}

int main()
{
	Hash_name h_n;
	Hash_username h_un;
	Sign_Up set;
	Sign_Up s_f;
	Tries t;
	string name;
	string mobile_no;
	string password;
	string username;
	string tmsg;
	message msg;
	message_tab_hash m_hash;
    
	Personnel_tab pstb_2;
    post posts_1;
	post posts_2;
	int id;
	string owner;
	string content;
	date Date;
	stack_of_comments comm;
	comment var1;
	time Time;
	Home_Tab home;
	int hour, min, sec;
	int day, month, year;
	int friend_choice;
	int msg_choice;
	cout << "WELCOME TO BICHU-MAKKHI APP" << endl;
	int x = Main_menu();
	while (x != 3)
	{
		switch (x)
		{
		case 1:

		{
			system("cls");
			cout << "Enter name" << endl;
			cin.ignore();
			getline(cin, name);
			set.setname(name);
			cout << "Enter mobile_no" << endl;
			cin >> mobile_no;
			set.setmobile(mobile_no);
			cout << "Enter Password" << endl;
			cin >> password;
			set.setpassword(password);
			cout << "Enter user name" << endl;
			cin >> username;
			set.setusername(username);
			h_un.insert(set);
			h_n.insert(set);
			t.Insert(set.getname());
			system("cls");
			x = Main_menu();
			break;
		}
		case 2:
			system("cls");
			int flag = 0;
			cout << "Enter your UserName" << endl;
			cin >> username;
			cout << "Enter your password" << endl;
			cin >> password;
			set = h_un.search(username);
			if (set.getusername() == "NONE")
			{
				cout << "INVALID USERNAME OR PASSWORD" << endl;
			}
			else
			{
				if (set.getusername() == username)
				{
					if (set.getpassword() == password)
					{
						set = h_n.search(set.getname());
						flag = 1;
						int log_in = Login_menu();
						while (log_in != 5)
						{
							switch (log_in)
							{
							case 1:
							{
								int persnl_tab = Personal_Tab_Menu();
								Personnel_tab pstb_1;
								while (persnl_tab != 6)
								{
									
									switch (persnl_tab)
									{
									case 1:
									{
										
										cout << endl << "----------Enter the Information for the Post You Wanna ADD------------ ";
										cout << endl << "Enter the ID Of the Post: ";
										cin >> id;
										cout << endl << "Enter Owner of the Post: ";
										cin.ignore();
										getline(cin, owner);
										cout << endl << "Enter the Content of the Post: ";
										cin.ignore();
										getline(cin, content);
										cout << endl << "--------Enter the Date of the Post----------";
										cout << endl << "Enter the Day: ";
										cin >> day;
										cout << endl << "Enter the Month: ";
										cin >> month;
										cout << endl << "Enter the Year: ";
										cin >> year;
										Date.setdate(day, month, year);
										cout << endl << "---------Enter the Time of the Post--------- ";
										cout << endl << "Enter the Hours: ";
										cin >> hour;
										cout << endl << "Enter the Minutes: ";
										cin >> min;
										cout << endl << "Enter the Seconds: ";
										cin >> sec;
										Time.settime(hour, min, sec);
										posts_1.setpost(id, owner, content, Date, Time);
									    pstb_1.addpost(posts_1);
										home.addpost(posts_1);
										set.setPersonalTAB(pstb_1);
										//set.setPersonalTAB(pstb_1);
										h_n.insert(set);
										set = h_n.search(set.getname());
										persnl_tab = Personal_Tab_Menu();
										break;
									}
									case 2:
									{
										cout << endl << "-------Information for the Comments to Add--------";
										set.getPersonalTAB().addcomments();
										
										//set.setPersonalTAB(pstb_1);
										h_n.insert(set);
										set = h_n.search(set.getname());
										persnl_tab = Personal_Tab_Menu();
										break;
									}
									case 3:
									{
										cout << endl << endl << "--------ALL the Posts in Your Personal Tab Are------- " << endl << endl;
										pstb_1.viewPosts();
									//	set.viewPost();
										persnl_tab = Personal_Tab_Menu();
										break;
									}
									case 4:
									{
										cout << endl << "-------To View Comments Of the Posts--------";
										pstb_1.ViewComments();
										//set.getPersonalTAB().ViewComments();
										persnl_tab = Personal_Tab_Menu();
										break;
									}
									case 5:
									{
										cout << endl << "---------To Delete Posts----------";
										
										pstb_1 .DeletePosts();
										set.setPersonalTAB(pstb_1);
										h_n.insert(set);
										set = h_n.search(set.getname());
										persnl_tab = Personal_Tab_Menu();
										break;
									}


									}


								}
								log_in = Login_menu();
								break;
							}



							case 2:
							{
								int homeTab = Home_tab_Menu();
								while (homeTab != 6)
								{
									switch (homeTab)
									{
									case 1:


									{
										home.viewPosts();
										/*
										Personnel_tab pstb2;
										post pt;
										Sign_Up user;
										stack_of_posts p1;
										stack_of_posts p2;
										queue_of_friends q;
										Hash_name hn;
										linklist_Post linkedlist;
										q = set.get_F_tab().get_queue_f_list();
										int cap = q.get_cap();
										int range = 0;
										while (range < cap)
										{
											string f = q.display().get_friend();
											user = hn.search(f);
											p1 = user.getPersonalTAB().return_StackOfPosts();
											while (!p1.isreturn_post_empty())
											{
												pt = p1.return_post();
												linkedlist.sortInsert_Post(pt);
											}
											p1.settop_sequal();
											range++;
										}
										q.set_curr();
										p1 = set.getPersonalTAB().return_StackOfPosts();
										while (!p1.isreturn_post_empty())
										{
											pt = p1.return_post();
											linkedlist.sortInsert_Post(pt);
										}
										p1.settop_sequal();
										linkedlist.Display();*/
										homeTab = Home_tab_Menu();
										break;
									}
									case 2:
									{
										cout << endl << "-------Information for the Comments to Add--------";
										home.addcomments();
										homeTab = Home_tab_Menu();
										break;
									}
									case 3:
									{
										cout << endl << "----------Enter the Information for the Post You Wanna ADD------------ ";
										cout << endl << "Enter the ID Of the Post: ";
										cin >> id;
										cout << endl << "Enter Owner of the Post: ";
										cin.ignore();
										getline(cin, owner);
										cout << endl << "Enter the Content of the Post: ";
										cin.ignore();
										getline(cin, content);
										cout << endl << "--------Enter the Date of the Post----------";
										cout << endl << "Enter the Day: ";
										cin >> day;
										cout << endl << "Enter the Month: ";
										cin >> month;
										cout << endl << "Enter the Year: ";
										cin >> year;
										Date.setdate(day, month, year);
										cout << endl << "---------Enter the Time of the Post--------- ";
										cout << endl << "Enter the Hours: ";
										cin >> hour;
										cout << endl << "Enter the Minutes: ";
										cin >> min;
										cout << endl << "Enter the Seconds: ";
										cin >> sec;
										Time.settime(hour, min, sec);
										posts_1.setpost(id, owner, content, Date, Time);
										
										home.addpost(posts_1);
										//home.addpost(posts_1);
										//pstb_1.addpost(posts_1);
										homeTab = Home_tab_Menu();
										break;
									}
									case 4:
									{
										cout << endl << "---------To Delete Posts----------";
										//set.getHomeTab().DeletePosts();
										home.DeletePosts();
										homeTab = Home_tab_Menu();
										break;
									}
									case 5:
									{
										set.getHomeTab().addcomments();
										home.addcomments();
										homeTab = Home_tab_Menu();
										break;
									}

									default:
										break;
									}
								}
								log_in = Login_menu();
								break;
							}

							case 3:
								set = h_n.search(set.getname());
								friend_choice = Friend_tab_menu();
								while (friend_choice != 4)
								{
									switch (friend_choice)
									{
									case 1:

										name = set.friend_request(t);
										if (name != "0")
										{
											s_f = h_n.search(name);

											s_f.set_request(set);
											h_n.insert(s_f);
										}

										friend_choice = Friend_tab_menu();
										break;
									case 2:

										name = set.accept_request();
										s_f = h_n.search(name);
										s_f.set_requestof_other(set);
										h_n.insert(s_f);
										friend_choice = Friend_tab_menu();
										break;
									case 3:
										set = h_n.search(set.getname());
										set.see_friendlist();
										friend_choice = Friend_tab_menu();
										break;
									}
								}
								log_in = Login_menu();
								break;

							case 4:
								msg_choice = message_menu();
								while (msg_choice != 3)
								{
									switch (msg_choice)
									{
									case 1:
										cout << "Enter friend name to which you want to send msg" << endl;
										cin >> name;
										s_f = h_n.search(name);
										cout << "Type the message you want to send" << endl;
										cin.ignore();
										getline(cin, tmsg);
										msg.setmsg(tmsg);
										msg.setmsg_sender_name(set.getname());

										s_f.setMsg(msg, set.getname());
										set.setMsg(msg, s_f.getname());

										h_n.insert(s_f);
										h_n.insert(set);
										msg_choice = message_menu();
										break;
									case 2:
										cout << "Enter friend name to see conversation" << endl;
										cin >> name;
										s_f = h_n.search(name);
										set = h_n.search(set.getname());
										m_hash = set.get_msg_tab();
										m_hash.display(s_f.getname());
										msg_choice = message_menu();
										break;
									}
								}
								log_in = Login_menu();
								break;
							}
						}
					}
				}
				if (flag == 0)
				{
					cout << "INVALID USERNAME OR PASSWORD" << endl;
				}
				x = Main_menu();
				break;
			}
		}
	}
	cout << "\t\t BICCHU-MAKKHI" << endl;
	system("pause");
	return 0;
}























