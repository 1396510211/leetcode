#include<map>

struct DoubleLinkedNode
{
	int key;
	int value;
	DoubleLinkedNode* prev;
	DoubleLinkedNode* next;
	DoubleLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
	DoubleLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
	LRUCache(int capacity)
	{
		m_capacity = capacity;
		m_head = new DoubleLinkedNode();
		m_tail = new DoubleLinkedNode();
		m_head->next = m_tail;
		m_tail->prev = m_head;
	}

	int get(int key)
	{
		if (m_cache.count(key) == 0) {
			return -1;
		}
		DoubleLinkedNode* node = m_cache[key];
		moveToHead(node);
		return node->value;
	}

	void put(int key, int value)
	{
		if (m_cache.count(key) == 0) {
			DoubleLinkedNode* node = new DoubleLinkedNode(key, value);
			m_cache[key] = node;
			addToHead(node);
			m_size++;
			if (m_size > m_capacity) {
				DoubleLinkedNode* node = removeFromTail();
				m_cache.erase(node->key);
				delete(node);
				m_size--;
			}
		}
		else {
			DoubleLinkedNode* node = m_cache[key];
			node->value = value;
			moveToHead(node);
		}
	}

	void addToHead(DoubleLinkedNode* node)
	{
		node->prev = m_head;
		node->next = m_head->next;
		m_head->next->prev = node;
		m_head->next = node;
	}
	void removeNode(DoubleLinkedNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void moveToHead(DoubleLinkedNode* node)
	{
		removeNode(node);
		addToHead(node);
	}
	DoubleLinkedNode* removeFromTail()
	{
		DoubleLinkedNode* node = m_tail->prev;
		removeNode(m_tail->prev);
		return node;
	}

private:
	std::map<int, DoubleLinkedNode*> m_cache;
	DoubleLinkedNode* m_head{ nullptr };
	DoubleLinkedNode* m_tail{ nullptr };
	int m_capacity{ 0 };
	int m_size{ 0 };
};