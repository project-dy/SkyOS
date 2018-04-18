#include "SkyTest.h"
#include "stdint.h"
#include "stdio.h"
#include "windef.h"
#include "exception.h"
#include "string.h"
#include "memory.h"
#include "Vector.h"
#include "Stack.h"
#include "jsmn.h"
#include "map.h"
#include "list.h"
#include "linkedlist.h"
#include "TestInteger.h"
#include "SkyConsole.h"
#include "queue.h"
#include "stl_string.h"
#include "deque.h"

using namespace std;

#define kprintf SkyConsole::Print

static const char *JSON_STRING =
"{\"user\": \"johndoe\", \"admin\": false, \"uid\": 1000,\n  "
"\"groups\": [\"users\", \"wheel\", \"audio\", \"video\"]}";

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
		strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

void TestV8086();
void TestMap();
void TestList();
void TestCPP14();
void TestJson();
void TestString();
void TestVector();
void TestStack();


void SkyTest()
{
	TestMap();
	TestList();
	TestCPP14();	

	//TestV8086();
}

void TestStack()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (s.size() > 0)
	{
		int data = s.pop();
		SkyConsole::Print("%d\n", data);
	}
}

void TestString()
{
	std::string str("abc");
	SkyConsole::Print("%s\n", str.c_str());

	std::string str2 = str;
	str2 = "cdf";
	SkyConsole::Print("%s\n", str2.c_str());

	/*void test(String str)
	{
	cout << str << endl;
	}

	int main()
	{
	String bar = "Hello";
	cout << ("a" + String("b")) << endl;
	}*/

	/*int main()
	{
	String a = "foo";
	String b = "bar";
	a = b;
	cout << a << endl;
	}*/

	/*int main()
	{
		cout << "|" << String("  baz  ").trim() << "|" << endl;
		cout << "|" << String("  baz  ").trimleft() << "|" << endl;
		cout << "|" << String("  baz  ").trimright() << "|" << endl;
		cout << "|" << String("  ").trim() << "|" << endl;
		cout << "|" << String("b  ").trim() << "|" << endl;
		cout << "|" << String(" b  ").trim() << "|" << endl;
		cout << "|" << String("  b").trim() << "|" << endl;
		cout << "|" << String("  b ").trim() << "|" << endl;
	}

	int main()
	{
	String str;

	int count = str.getline(cin);

	cout << str << endl;
	cout << count << endl;
	}*/

	/*void test(const String &a, String b)
	{
	cout << a << b << endl;
	}

	int main()
	{
	String a = "foo";
	cout << a << endl;
	cout << "---" << endl;

	cout << strlen(a) << " should equal " << a.length() << endl;
	cout << a + "bar" << endl;
	test("foo", "bar");
	cout << "---" << endl;

	cout << a << endl;

	cout << a.substr(0, 2) << endl;
	cout << a.substr(1, 2) << endl;
	cout << a.substr(0, 4) << endl;
	cout << a.substr(3) << endl;
	cout << a.substr(3, 3) << endl;
	cout << a.substr(-2) << endl;
	cout << a.substr(-2, 2) << endl;
	cout << a.substr(-3) << endl;
	cout << a.substr(-3, 2) << endl;
	cout << a.substr(-3, 3) << endl;
	cout << a.substr(-4) << endl;
	cout << a.substr(-4, 4) << endl;
	cout << a.substr(-4, 5) << endl;
	cout << "---" << endl;

	cout << a[0] << endl;
	cout << a.get(0) << endl;
	cout << a[-3] << endl;
	cout << a.get(-3) << endl;

	a.set(0, 'F');
	cout << a << endl;
	a.set(-3, 'B');
	cout << a << endl;

	cout << a.set(4, 'A') << endl;
	cout << a.set(-4, 'A') << endl;
	cout << a.set(0, '\0') << endl;
	cout << a << endl;
	cout << "---" << endl;

	String c = "123";
	cout << (atoi(c) + 1) << endl;
	cout << "---" << endl;

	String d;
	cout << "Enter some text and then press enter:" << endl;
	cout << "Entered " << d.getline(cin) << " characters." << endl;
	cout << d << endl;

	return 0;
	}*/
}

void TestDeque()
{
	std::deque<int> a;
	
	for (int i = 1; i < 6; i++)
		a.push_front(i);

	for (int i = 0; i < 5; i++)
		SkyConsole::Print("%d\n", a[i]);		
}

void TestVector()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);

	while (vec.size() > 0)
	{
		int data = vec.back();
		SkyConsole::Print("%d\n", data);
		vec.pop_back();
	}

	for (;;);
}


void TestMap()
{
	std::map<int, int> m10;
	std::map<int, int>::iterator it1;
	std::map<int, int>::iterator it2;

	m10[1] = 2;
	m10[2] = 4;
	m10[3] = 6;
	m10[4] = 8;
	m10[5] = 10;
	m10[6] = 12;
	m10[7] = 14;
	m10[8] = 16;
	m10[8] = 18;
	int i = 0;
	for (it1 = m10.begin(); it1 != m10.end(); it1++) {
		//cout << (*it1).first << "   " << (*it1).second << endl;
		kprintf("%d  %d\n", (*it1).first, (*it1).second);
		i++;
	}

	//cout << "ERASE BY KEY" << endl;
	m10.erase(3);
	i = 0;
	for (it1 = m10.begin(); it1 != m10.end(); it1++) {
		//cout << (*it1).first << "   " << (*it1).second << endl;
		kprintf("%d  %d\n", (*it1).first, (*it1).second);
		i++;
	}

	for (;;);
}

void TestQueue()
{
	queue queue;
	QueueNode* pNode = new QueueNode();
	pNode->_data = (void*)5;
	queue.Enqueue(pNode);

	QueueNode* pNode2 = new QueueNode();
	pNode2->_data = (void*)10;
	queue.Enqueue(pNode2);

	QueueNode* result = queue.Dequeue();
	delete result;
	result = queue.Dequeue();
	delete result;
}

void TestJson()
{
	int i;
	int r;
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */

	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t) / sizeof(t[0]));
	if (r < 0) {
		kprintf("Failed to parse JSON: %d\n", r);
		return;
	}

	/* Assume the top-level element is an object */
	if (r < 1 || t[0].type != JSMN_OBJECT) {
		kprintf("Object expected\n");
		return;
	}

	char buf[256];
	memset(buf, 0, 256);


	/* Loop over all keys of the root object */
	for (i = 1; i < r; i++) {
		if (jsoneq(JSON_STRING, &t[i], "user") == 0) {
			/* We may use strndup() to fetch string value */
			memcpy(buf, JSON_STRING + t[i + 1].start, t[i + 1].end - t[i + 1].start);
			kprintf("- User: %s\n", buf);
			i++;
		}
		else if (jsoneq(JSON_STRING, &t[i], "admin") == 0) {

			kprintf("- Admin: %.*s\n", t[i + 1].end - t[i + 1].start,
				JSON_STRING + t[i + 1].start);
			i++;
		}
		else if (jsoneq(JSON_STRING, &t[i], "uid") == 0) {

			kprintf("- UID: %.*s\n", t[i + 1].end - t[i + 1].start,
				JSON_STRING + t[i + 1].start);
			i++;
		}
		else if (jsoneq(JSON_STRING, &t[i], "groups") == 0) {
			int j;
			kprintf("- Groups:\n");
			if (t[i + 1].type != JSMN_ARRAY) {
				continue;
			}
			for (j = 0; j < t[i + 1].size; j++) {
				jsmntok_t *g = &t[i + j + 2];
				kprintf("  * %.*s\n", g->end - g->start, JSON_STRING + g->start);
			}
			i += t[i + 1].size + 1;
		}
		else {
			kprintf("Unexpected key: %.*s\n", t[i].end - t[i].start,
				JSON_STRING + t[i].start);
		}
	}

	for (;;);
}

void TestCPP14()
{
	auto func = [x = 5]() { return x; };
	auto n1 = func();
	kprintf("Lamda n1:%d\n", n1);

	constexpr TestInteger size(10);
	int x[size];
	x[3] = 11;
	kprintf("constexor x[3]:%d\n", x[3]);
}

void TestList()
{
	list<int> fstList = list<int>();
	list<int> scndList = list<int>();
	int counter = 0;

	for (int i = 0; i <= 10; ++i) {
		fstList.push_back(i);
	}
	list<int>::Iterator iter = fstList.begin();
	while (iter != fstList.end())
	{
		kprintf("item %d  done\n", *iter);
		iter++;
	}

	kprintf("done!!\n");

	/*while (1) {
	for (int i = 0; i <= 10; ++i) {
	fstList.push_back(i);
	}

	for (int i = 6; i <= 15; ++i) {
	scndList.push_front(i);
	}

	std::List<int>::Iterator iter = fstList.begin();

	fstList.splice(++iter, scndList);
	scndList.concat(fstList);
	fstList.concat(scndList);

	fstList.pop_back();
	fstList.clear();
	//std::cout << "Cycle # " << counter << " done" << std::endl;
	printf("Cycle %d  done\n", counter);
	++counter;
	}*/


}

