#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

__gnu_pbds::priority_queue<int> pq;

pq.begin(),pq.end()

pq.modify(it,x);
//把it指到的元素改成x
pq.join(qp);
//把qp中的元素都搬到當前這個pq，並清空qp
pq.erase(it);
//把it指到的元素從pq中移除


tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s; 
s.find_by_order(order);
//找到第order+1小的元素，太大回傳end
s.order_of_key(key);
//詢問有多少個比key小的元素
