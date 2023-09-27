#pragma once

// geode additions thank you

#include <cstring>
#include <string>
#include <stdexcept>
#include <utility>
#include <map>
#include <vector>
#include "core/utilities/game.h"
#include "core/macros.h"

namespace gd {
    class GDString  {
    public:
        CINNAMON_API void winDtor() {
            return reinterpret_cast<void(__thiscall*)(GDString*)>(cinnamon::utilities::base + 0xf6e0)(this);
        }
        CINNAMON_API GDString& winAssign(GDString const& p0, size_t p1, size_t p2) {
            return reinterpret_cast<GDString&(__thiscall*)(GDString*, GDString const&, size_t, size_t)>(cinnamon::utilities::base + 0xf720)(this, p0, p1, p2);
        }
        CINNAMON_API GDString& winAssign(char const* p0, size_t p1) {
            return reinterpret_cast<GDString&(__thiscall*)(GDString*, char const*, size_t)>(cinnamon::utilities::base + 0xf680)(this, p0, p1);
        }
        CINNAMON_API GDString& winAssign(char const* p0) {
            return reinterpret_cast<GDString&(__thiscall*)(GDString*, char const*)>(cinnamon::utilities::base + 0xf840)(this, p0);
        }
    };

    struct InternalString {
        union {
            char m_storage[16];
            char* m_pointer;
        };

        size_t m_length;
        size_t m_capacity;
    };

    class string : GDString {
    private:
        InternalString m_data;

        char* get_data() {
            if (m_data.m_capacity < 16) return m_data.m_storage;
            return m_data.m_pointer;
        }

        const char* get_data() const {
            if (m_data.m_capacity < 16) return m_data.m_storage;
            return m_data.m_pointer;
        }

    public:
        string() {
            m_data.m_storage[0] = 0;
            m_data.m_length = 0;
            m_data.m_capacity = 15;
        }
            
        string(string const& param) : string() {
            (void)this->winAssign(param.c_str(), param.size());
        }
            
        string(string&& param) : string() {
            (void)this->winAssign(param.c_str(), param.size());
        }
        
        string(char const* param) : string() {
            (void)this->winAssign(param, std::strlen(param));
        }
        
        string(std::string const& param) : string() {
            (void)this->winAssign(param.c_str(), param.size());
        }
            
        string& operator=(string const& param) {
            (void)this->winAssign(param.c_str(), param.size());
            return *this;
        }
            
        string& operator=(string&& param) {
            (void)this->winAssign(param.c_str(), param.size());
            return *this;
        }
        
        string& operator=(char const* param) {
            (void)this->winAssign(param, std::strlen(param));
            return *this;
        }
            
        string& operator=(std::string const& param) {
            (void)this->winAssign(param.c_str(), param.size());
            return *this;
        }

        void clear() {
            (void)this->winDtor();
        }

        ~string() {
            (void)this->winDtor();
        }

        char& at(size_t pos) {
            if (pos >= m_data.m_length) throw std::out_of_range("gd::string::at");
            return (*this)[pos];
        }

        char const& at(size_t pos) const {
            if (pos >= m_data.m_length) throw std::out_of_range("gd::string::at");
            return (*this)[pos];
        }

        char& operator[](size_t pos) {
            return this->get_data()[pos];
        }

        char const& operator[](size_t pos) const {
            return this->get_data()[pos];
        }

        char* data() {
            return this->get_data();
        }

        char const* data() const {
            return this->get_data();
        }

        char const* c_str() const {
            return this->get_data();
        }

        size_t size() const {
            return m_data.m_length;
        }

        bool operator<(const gd::string& other) const {
            return std::string_view(this->c_str(), this->size()) < std::string_view(other.c_str(), other.size());
        }

        bool empty() const {
            return this->size() == 0;
        }

        operator bool() const {
            return !this->empty();
        }

        operator std::string() const {
            return std::string(this->c_str(), this->size());
        }

        operator std::string_view() const {
            return std::string_view(this->c_str(), this->size());
        }
    };

    template <class T>
    using vector = std::vector<T>;

    template <class K, class V>
    using map = std::map<K, V>;
}