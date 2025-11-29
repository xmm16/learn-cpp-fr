# Things I think will probably be useful
- vec | std::views::filter(func / lambda that booleans)
- vec | std::views::take(num to take)
- vec | std::views::drop(num to skip)
       
- std::for_each(v.begin(), v.end(), func / lambda that operates)
- std::transform(v.begin(), v.end(), func / lambda that operates)
- std::find(v.begin(), v.end(), val_to_find);
- std::find_if(v.begin(), v.end(), func / lambda that booleans);
- std::count(v.begin(), v.end(), val_to_count);
- std::count_if(v.begin(), v.end(), func / lambda that booleans);
- std::all_of/any_of/none_of(v.begin(), v.end(), func / lambda that booleans);
- std::search(v.begin(), v.end(), w.begin(), w.end());
- std::replace(v.begin(), v.end(), val_to_find, val_to_replace);
- std::replace_if(v.begin(), v.end(), func / lambda that booleans, val_to_replace);
- std::fill(v.begin(), v.end(), val_to_fill_with);
- std::sort(v.begin(), v.end(), optional func / lambda);
- std::reverse(v.begin(), v.end());
- std::merge(v.begin(), v.end(), w.begin(), w.end(), out.begin());
- std::move(v) // moves ownership of v to whatever you assign the move to
- std::copy(v.begin(), v.end(), out.begin())
- std::unordered_map<key_type, value_type> name;
- std::swap(v, w);

# lvals and rvals
- lvals are anything that has an address like 'a' when 'int a = 5' has already been declared
- rvals are anything thats temporary like '5'
- int& x is a reference to an lval in a function parameter
- int&& x is a reference to an rval in a function parameter

# std::vector constructors
Valid std::vector constructors

Size + default value
```cpp
std::vector<int> v(5, 10); // size 5, all elements 10
// v = {10, 10, 10, 10, 10}
```

From iterator range
```cpp
std::vector<int> v(vec.begin() + 2, vec.begin() + 5);
// copies elements from vec[2] up to vec[4] into v
```

Initializer list
```cpp
std::vector<int> v = {1, 2, 3, 4};
```

# operations on vectors
- v.push_back(value);
- v.emplace_back(constructor_args...);
- v.insert(v.begin() + index, value);
- v.insert(v.begin() + index, count, value);
- v.erase(v.begin() + index);
- v.erase(v.begin() + start_index, v.begin() + end_index);
- v.pop_back();
- v.clear();
- v.assign(count, value);
- v.assign(initializer_list);
- v.assign(first_it, last_it);
- v.at(i);
- v.front();
- v.back();
- v.size();
- v.capacity();
- v.empty();
- v.resize(new_size);
- v.resize(new_size, fill_value);
- v.reserve(expected_size);
- v.shrink_to_fit();

# operations on strings
- s.push_back(ch);
- s.pop_back();
- s.append("text");
- s.append(count, ch);
- s.append(other_string);
- s.append(first_it, last_it);
- s.insert(pos, "text");
- s.insert(pos, count, ch);
- s.insert(pos, other_string);
- s.insert(pos, other_string, subpos, count);
- s.erase(pos, count);
- s.erase(it);
- s.erase(first_it, last_it);
- s.clear();
- s.replace(pos, count, "text");
- s.replace(pos, count, other_string);
- s.replace(first_it, last_it, "text");
- s.replace(first_it, last_it, other_string);
- s.substr(pos);
- s.substr(pos, count);

# things other than vectors to use
- std::vector<T>
- std::deque<T> // fast push and pop at front and back
- std::list<T> doubly linked list
- std::forward_list<T> singly linked list
- std::valarray<T>
- std::span<T>

