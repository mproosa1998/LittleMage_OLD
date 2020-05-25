#include "BitmapStore.h"
#include <assert.h>

using namespace sf;
using namespace std;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(string const& filename) {
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	// auto == map<string, Texture>

	auto keyValuePair = bitmapsMap.find(filename);
	// auto == map<string, Texture>::iterator

	if (keyValuePair == bitmapsMap.end()) {
		auto& texture = bitmapsMap[filename];
		texture.loadFromFile(filename);
	}
}

Texture& BitmapStore::getBitmap(string const& filename) {
	auto& m = m_s_Instance->m_BitmapsMap;
	// auto == map<string, Texture>

	auto keyValuePair = m.find(filename);
	// auto == map<string, Texture>::iterator

	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	}
}