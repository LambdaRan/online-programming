

// 打印消息
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

// 快速排序
template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if(first == last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    ForwardIt middle1 = std::partition(first, last, 
                            [pivot](const auto& em){ return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last, 
                            [pivot](const auto& em){ return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}

// 归并排序
template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

// 插入排序
// insertion sort
for (auto i = v.begin(); i != v.end(); ++i) {
    std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
}

// 二分查找
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
    // 注意：类型 T 和 Forward 解引用后的类型都必须可隐式转换为
    // 用于 Compare 的 Type1 和 Type2 。
    // 这严格于 lower_bound 要求（见上述）
 
    first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}

// 以随机数填充 vector
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<> dis(0, 9);

std::vector<int> v1(10), v2(10);
std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
