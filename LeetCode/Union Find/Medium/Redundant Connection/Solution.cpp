// Union Find

class Solution {
    class DSU {
        private:
            int N;
            vector<int> depth;       // 현재 트리의 깊이
            vector<int> rootOfNodes; // 경로 압축(Path Compression)으로 루트 노드 가리킴

        public:
            DSU(int N) {
                this->N = N;

                for (int node = 0; node < N; ++node) {
                    depth.push_back(1);
                    rootOfNodes.push_back(node);
                }
            }

            int find(int node) {
                if (rootOfNodes[node] == node) return node;

                return rootOfNodes[node] = find(rootOfNodes[node]);
            }

            bool doUnion(int node1, int node2) {
                node1 = find(node1);
                node2 = find(node2);

                if (node1 == node2) return false;
                else {
                    if (depth[node1] > depth[node2]) {
                        rootOfNodes[node2] = node1;
                        depth[node1] += depth[node2];
                    }
                    else {
                        rootOfNodes[node1] = node2;
                        depth[node2] += depth[node1];
                    }

                    return true;
                }
            }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        DSU dsu(N);
        for (auto edge : edges) {
            if (!dsu.doUnion(edge[0] - 1, edge[1] - 1)) return edge;
        }

        return {};
    }
};