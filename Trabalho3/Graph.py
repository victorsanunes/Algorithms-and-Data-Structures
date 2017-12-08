MAX = 1000


class Vertex:
    def __init__(self, node):
        self.id = node
        self.adjacent = {}

    def __str__(self):
        return str(self.id) + ' adjacent: ' + str([x.id for x in self.adjacent])

    def add_neighbor(self, neighbor, weight=0):
        """
        Create a edge bet the vertex and neighbor with a weight

        By default, weight = 0
        """
        self.adjacent[neighbor] = weight

    def get_connections(self):
        """
        Get the conections of the vertex

        Return dictionary keys that are the vertices it is conected to
        """
        return self.adjacent.keys()

    def get_id(self):
        """
        Get the vertex id

        Useful for iterations.
        Return a string
        """
        return self.id

    def get_weight(self, neighbor):
        """
        Get the weight of a conection to the neighbor

        Return an int
        """
        return self.adjacent[neighbor]

    def degree(self):
        """
        Calculates the degree of a vertex
        """
        n = self.get_connections()
        return len(n)

    def closeness(self, distanceArray):
        s = sum(distanceArray.values())
        return 1/s

    def dijkstra(self, g, src):
        Q = set()
        dist = {}
        prev = {}
        for x in g.get_vertices():
            prev[x] = None
            Q.add(x)
            dist[x] = MAX
        dist[src] = 0
        while len(Q) > 0:
            reduced_dist = {x: dist[x] for x in Q}
            u = min(reduced_dist, key=reduced_dist.get)
            Q.remove(u)

            # Nos adjacentes a u
            neighbor = g.get_vertex(u)
            for n in neighbor.get_connections():
                if n.get_id() in Q:
                    w = neighbor.get_weight(n)
                    alt = dist[u] + w
                    if alt < dist[n.get_id()]:
                        dist[n.get_id()] = alt
                        prev[n.get_id()] = u
        return dist, prev

    def betweenness(self, prev):
        filteredPrev = {k: v for k, v in prev.items() if v != None}


class Graph:
    def __init__(self):
        self.vert_dict = {}
        self.num_vertices = 0

    def __iter__(self):
        return iter(self.vert_dict.values())

    def add_vertex(self, node):
        """
        Add a vertex to the graph
        """
        self.num_vertices = self.num_vertices + 1
        new_vertex = Vertex(node)
        self.vert_dict[node] = new_vertex
        return new_vertex

    def get_vertex(self, n):
        """
        Get the vertex that n is conected to

        returns a dictionary
        """
        if n in self.vert_dict:
            return self.vert_dict[n]
        else:
            return None

    def add_edge(self, frm, to, cost = 1):
        if frm not in self.vert_dict:
            self.add_vertex(frm)
        if to not in self.vert_dict:
            self.add_vertex(to)

        self.vert_dict[frm].add_neighbor(self.vert_dict[to], cost)
        self.vert_dict[to].add_neighbor(self.vert_dict[frm], cost)

    def get_vertices(self):
        """
        Get all the vertices that are in the graph
        """
        return self.vert_dict.keys()

    def dijkstra(self, src):
        """
        Implementation of the Dijkstra algorithm

        Returns a tuple with the distances array (dictionary) and the paths
        (dictionary)

        return dist, prev
        """
        Q = set()
        dist = {}
        prev = {}
        for x in self.get_vertices():
            prev[x] = None
            Q.add(x)
            dist[x] = MAX
        dist[src] = 0
        while len(Q) > 0:
            reduced_dist = {x: dist[x] for x in Q}
            u = min(reduced_dist, key=reduced_dist.get)
            Q.remove(u)

            # Nos adjacentes a u
            neighbor = self.get_vertex(u)
            for n in neighbor.get_connections():
                if n.get_id() in Q:
                    w = neighbor.get_weight(n)
                    alt = dist[u] + w
                    if alt < dist[n.get_id()]:
                        dist[n.get_id()] = alt
                        prev[n.get_id()] = u
        return dist, prev

    def allShortestPaths(self):
        """
        Runs Dijkstra for the entire graph

        Returns a tuple with the distances array and paths for all the vertex

        return dist (dictionary of dictionary), paths (dictionary of dictionary)
        """
        vertices = self.get_vertices()
        paths = {}
        dist = {}

        for v in vertices:
            dist[v], paths[v] = self.dijkstra(v)
        return dist, paths

    def clustering(self):
        """
        Calculates the clustering for all the vertex of the graph

        Returns a dictionary
        """

        vertices = list(self.get_vertices())
        clusteringValue = {i: 0 for i in vertices}
        for i in vertices:
            vertex = self.get_vertex(i)
            for j in vertex.get_connections():
                for k in j.get_connections():
                    if k.get_id() == i and j.get_id() != i:
                        clusteringValue[i] += 1
                        # print("YES")
                        # print("1: " + str(i))
                        # print("2: " + str(j.get_id()) + "(" + str(j) + ")")
                        # print("3: " + str(k.get_id()) + "(" + str(k) + ")")

        normal = dict()
        degree = {i : 0 for i in self.get_vertices()}
        for v in self:
            degree[v.get_id()] = v.degree()
        print(clusteringValue)

        for i in clusteringValue:
            normal[i] = 2*clusteringValue[i]/(degree[i]*(degree[i]-1))
        return normal
        # return clusteringValue

    def betweenness(self):
        """
        Calculate the betweenness for all the vertex of the graph

        Returns a dictionary
        """

        vertices = list(self.get_vertices())
        new_bc = {}
        paths = {}
        dist = {}
        for i in vertices:
            dist[i] = dict()
            paths[i] = dict()
        allDist, allPaths = self.allShortestPaths()

        betweennessValue = {i: 0 for i in vertices}

        # Get shortest paths between all pairs of vertices
        # Para cada no a ter a betweenness calculada
        for c in vertices:
            # print("ALLPATHS: + " + str(allPaths[c]))
            # Itera para pegar o menor caminho
            # Para cada um dos predecessores de c
            for j in allPaths[c]:
                k = j
                while k != c and k != None:
                    # print("K: "+str(k))
                    betweennessValue[k] += 1
                    # print(betweennessValue)
                    k = allPaths[c][k]
                # print("===========================")
        normal = {i: betweennessValue[i]/max(betweennessValue.values()) for i in betweennessValue}
        return normal

if __name__ == '__main__':

    g = Graph()

    g.add_vertex('a')
    g.add_vertex('b')
    g.add_vertex('c')
    g.add_vertex('d')
    g.add_vertex('e')
    g.add_vertex('f')

    g.add_edge('a', 'b', 7)
    g.add_edge('a', 'c', 9)
    g.add_edge('a', 'f', 14)
    g.add_edge('b', 'c', 10)
    g.add_edge('b', 'd', 15)
    g.add_edge('c', 'd', 11)
    g.add_edge('c', 'f', 2)
    g.add_edge('d', 'e', 6)
    g.add_edge('e', 'f', 9)

    # for v in g:
    #     for w in v.get_connections():
    #         vid = v.get_id()
    #         wid = w.get_id()
    #         print ('( %s , %s, %3d)'  % ( vid, wid, v.get_weight(w)))
    #
    # for v in g:
    #     print ('g.vert_dict[%s]=%s' %(v.get_id(), g.vert_dict[v.get_id()]))


    degree = dict()
    closeness = dict()
    betweenness = g.betweenness()
    clustering = g.clustering()

    for v in g:
        dist, prev = g.dijkstra(v.get_id())
        closeness[v.get_id()] = v.closeness(dist)
        degree[v.get_id()] = v.degree()
        print("Closeness " + str(v.get_id()) + ": "\
                            +str(closeness[v.get_id()]))
        print("Degree " + str(v.get_id()) + ": "\
                            +str(degree[v.get_id()]) )
        print("===============================================================")
        print("")

    print("betweenness: " + str(betweenness))
    print("clustering: " + str(clustering))
    print("===============================================================")
    print("")
    dist, prev = g.allShortestPaths()
    for k in prev:
        print("PREV["+ str(k)+"]" + str(prev[k]))
        print("DIST["+ str(k)+"]" + str(dist[k]))
        print("===============================================================")
        print("")
