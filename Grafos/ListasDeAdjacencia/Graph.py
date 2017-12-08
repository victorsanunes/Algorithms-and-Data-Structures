import random

def createGraph(V):
    graph = dict()
    for i in range(V):
        graph[i] = list()
    return graph

def createEdgeWithWeight(graph, source, dest, weight, direction):
    graph[source][dest] = weight
    if direction == False:
        graph[dest][source] = weight

def createGraphWithWeight(V):
    graph = dict()
    for i in range(V):
        graph[i] = dict()
    return graph

def createEdge(graph, source, dest, direction):
    if dest not in graph[source]:
        graph[source].append(dest)
    if direction == False:
        if source not in graph[dest]:
            graph[dest].append(source)

def printGraph(graph):
    for k in graph:
        print(repr(k) + ": " + repr(graph[k]))

def generateRandomEdge(source, nodes):
    dest = random.randint(0, nodes)
    return dest

def generateRandomGraph(nodes, maxDegree, weight):
    if weight == False:
        gr = createGraph(nodes)
        for source in range(nodes):
            edges = random.randint(0, maxDegree)
            for i in range(edges):
                dest = generateRandomEdge(source, nodes-1)
                direction = random.randint(0, 1)
                if direction == 0:
                    print("Source: " + str(source) + " Dest: " + str(dest))
                    createEdge(gr, source, dest, True)
                else:
                    print("Source: " + str(source) + " Dest: " + str(dest))
                    createEdge(gr, source, dest, False)
    else:
        gr = createGraphWithWeight(nodes)
        for source in range(nodes):
            edges = random.randint(0, maxDegree)
            for i in range(edges):
                dest = generateRandomEdge(source, nodes-1)
                weight = random.randint(0, 10)
                direction = random.randint(0, 1)
                if direction == 0:
                    createEdgeWithWeight(graph=gr, source=source,
                                            dest=dest, weight=weight, direction = True)
                else:
                    createEdgeWithWeight(graph=gr, source=source,
                                            dest=dest, weight=weight, direction = False)
    return gr

def BFS(graph, start):
    """
    Breadth First Search implementation

    start is the initial vertex
    """
    color = dict()
    distances = dict()
    for k in graph:
        color[k] = 0
        distances[k] = 0
    v = start
    color[v] = 1
    Q = list()
    Q.append(v)
    while len(Q) != 0:
        u = Q[0]
        Q.remove(Q[0])
        print(repr(u))
        for v in graph[u]:
            if color[v] == 0:
                color[v] = 1
                distances[v] += 1
                Q.append(v)
        color[u] = 2

def DFS(graph, start, state):
    """
    Depth First Search implementation

    start is the initial vertex
    state is the state array to determine weather a vertex has been visited
    or not
    """
    v = start
    state[v] = 1
    print("Reaching: " + repr(v))
    aux = graph[v]
    print(aux)
    for i in aux:
        if state[i] == 0:
            DFS(graph, i, state)

def initializeSingleSource(G, s):
    d = dict()
    for v in G[s]:
        d[v] = 1000

def extractMin(Q):
    smallest = 1000
    u = -1
    for k in Q:
        if Q[k] < smallest:
            smallest = Q[k]
            u = k
    return u

def removekey(d, key):
    r = dict(d)
    del r[key]
    return r

def dijkstra(graph, start):
    visited = {start: 1}
    path = dict()
    distances = dict()

    # ================== INITIALIZE SINGLE SOURCE ==============================
    for v in graph:
        distances[v] = 1000
        path[v] = None
    distances[start] = 0

    S = set(graph.keys())
    S.discard(start)
    # print("Solution Set: " + str(S))
    pred = start

    # Pega os vertices adjacentes que ainda nao foram visitados
    Q = graph[pred]
    Adj = graph[pred]
    for k in Q:
        if k not in S:
            Q = removekey(Q, k)
    print("Q: " + repr(Q))
    while len(Q) != 0:
        for v in Q:
            if Q[v] + distances[pred] < distances[v]:
                distances[v] = Q[v] + distances[pred]
        print("distances" + repr(distances))
        u = extractMin(Q)
        print("smallest: " + repr(u))
        pred = u
        S.discard(u)
        Q = graph[pred]
        for k in Q:
            if k not in S:
                Q = removekey(Q, k)
        print("Q: " + repr(Q))
    return distances

def dijkstra2(graph, src):
    Q = set()
    dist = {}
    prev = {}
    for x in range(0, len(graph)):
        prev[x] = None
        Q.add(x)
        dist[x] = 1000
    dist[src] = 0
    while len(Q) > 0:
        reduced_dist = {x: dist[x] for x in Q}
        u = extractMin(reduced_dist)
        Q.remove(u)
        neighbors_u = graph[u]
        for n in neighbors_u:
            if n in Q:
                alt = dist[u] + graph[u][n]
                if alt < dist[n]:
                    dist[n] = alt
                    prev[n] = u
    return dist, prev


def Dijkstra(graph, source, target):
    dist = dict()
    prev = dict()
    selected = {key: 0 for key in graph}

    for k in graph:
        dist[k] = 1000
        prev[k] = -1
    start = source
    selected[start] = 1
    dist[start] = 0
    while selected[target] == 0:
        smallest = 1000
        m = 0
        for k in graph[start]:
            d = dist[start] + graph[start][k]
            if d < dist[k] and selected[k] == 0:
                dist[k] = d
                prev[d] = start
            if smallest > dist[k] and selected[k] == 0:
                smallest = dist[k]
                m = k
        start = m
        selected[start] = 1
    print(dist)

def main():
    random.seed(12)
    # gr = generateRandomGraph(10, 3, True)
    gr = createGraphWithWeight(9)
    A = 0
    B = 1
    C = 2
    D = 3
    E = 4
    # createEdgeWithWeight(gr, 0, 1, 4, False)
    # createEdgeWithWeight(gr, 0, 7, 8, False)
    # createEdgeWithWeight(gr, 1, 7, 11, False)
    # createEdgeWithWeight(gr, 1, 2, 8, False)
    # createEdgeWithWeight(gr, 2, 3, 7, False)
    # createEdgeWithWeight(gr, 2, 8, 2, False)
    # createEdgeWithWeight(gr, 2, 5, 4, False)
    # createEdgeWithWeight(gr, 3, 4, 9, False)
    # createEdgeWithWeight(gr, 3, 5, 14, False)
    # createEdgeWithWeight(gr, 4, 5, 10, False)
    # createEdgeWithWeight(gr, 6, 8, 6, False)
    # createEdgeWithWeight(gr, 6, 7, 1, False)
    # createEdgeWithWeight(gr, 7, 8, 7, False)
    createEdgeWithWeight(gr, A, E, 10, True)
    createEdgeWithWeight(gr, A, D, 3, True)
    createEdgeWithWeight(gr, A, B, 1, True)
    createEdgeWithWeight(gr, B, C, 5, True)
    createEdgeWithWeight(gr, C, E, 1, True)
    createEdgeWithWeight(gr, D, C, 2, True)
    createEdgeWithWeight(gr, D, E, 6, True)


    printGraph(gr)
    print("===================================")
    # state = dict()
    # for k in gr:
    #     state[k] = 0
    # DFS(gr, 0, state)
    # dijkstra(gr,0)
    #
    # printGraph(gr)
    # print("visited: " + repr(v))
    # d = dijkstra(gr, A)
    # Dijkstra(gr, 0, 4)
    d, p = dijkstra2(gr, 0)
    print(d)
main()
