#include "pch.h"
#include "CppUnitTest.h"
#include "TreeMap.h"
#include "BinaryTree.h"
#include "TreeMapCA.cpp"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestPutAndGet)
		{
			TreeMap<int, std::string> map;
			map.put(1, "one");
			map.put(2, "two");

			Assert::AreEqual(std::string("one"), map.get(1));
			Assert::AreEqual(std::string("two"), map.get(2));
		}

		TEST_METHOD(TestContainsKey) 
		{
			TreeMap<int, std::string> map;
			map.put(1, "Goblin");

			Assert::IsTrue(map.containsKey(1));
			Assert::IsFalse(map.containsKey(39));
		}

		TEST_METHOD(TestRemoveKey)
		{
			TreeMap<int, std::string> map;
			map.put(1, "Goblin");

			Assert::IsTrue(map.containsKey(1));
			Assert::IsTrue(map.removeKey(1));
			Assert::IsFalse(map.containsKey(1));
		}

		TEST_METHOD(TestClear)
		{
			TreeMap<int, std::string> map;
			map.put(1, "Blishbino");
			map.put(2, "Haztoe");
			map.clear();

			Assert::AreEqual(0, map.size());
		}

		TEST_METHOD(TestSize) 
		{
			TreeMap<int, std::string> map;
			map.put(1, "Blishbino");

			Assert::AreEqual(1, map.size());
		}

		TEST_METHOD(TestFileBreakDown)
		{
			std::ofstream out("Pepsi.txt");
			out << "goblins are known for gobbling pepsi max and foraging Tesco";
			out.close();

			TreeMap<char, BinaryTree<std::string>> result = FileBreakdown();

			Assert::IsTrue(result.containsKey('a'));
			Assert::IsTrue(result.containsKey('g'));
			Assert::IsTrue(result.containsKey('f'));
			Assert::IsTrue(result.containsKey('m'));

			BinaryTree<std::string>& aWords = result.get('a');
			Assert::AreEqual(2, aWords.count());

			BinaryTree<std::string>& gWords = result.get('g');
			Assert::AreEqual(2, gWords.count());

			BinaryTree<std::string>& fWords = result.get('f');
			Assert::AreEqual(2, fWords.count());

			BinaryTree<std::string>& mWords = result.get('m');
			Assert::AreEqual(2, mWords.count());
		}

	};
}
