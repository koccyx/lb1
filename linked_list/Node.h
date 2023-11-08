#ifndef TIZD_NODE_H
#define TIZD_NODE_H
namespace FSN {
    class Node {
    public:
        double data;
        Node *next;

        Node(double data);
    };
};
#endif //TIZD_NODE_H
