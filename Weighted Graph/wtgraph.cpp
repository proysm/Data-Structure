//--------------------------------------------------------------------
//  컴퓨터공학과 2021111954 유수민
//  Laboratory 13                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber)
	:size(0), maxSize(defMaxGraphSize)
{           
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize * maxSize];
	pathMatrix = new int[maxSize * maxSize];
}

WtGraph::~WtGraph()
{
	delete vertexList;
	delete adjMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(v, vertexList[i].label) == 0)
		{
			return i;
		}
	}
	return 0;
}

int WtGraph::getEdge(int row, int col)
{
	if (adjMatrix[(row * 8) + col] = adjMatrix[(col * 8) + row])
	{
		return adjMatrix[(row * 8) + col];
	}
	else
		return infiniteEdgeWt;
}

void WtGraph::setEdge(int row, int col, int wt) 
{
	adjMatrix[row] = wt;
	adjMatrix[col] = wt;
}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
	// isFull
	if (isFull())
		cout << "Graph is Full." << endl;

	// isEmpty
	if (isEmpty())
	{
		vertexList[size] = newVertex;
		size++;
		for (int i = 0; i < size; i++)
		{
			setEdge(((size - 1) * 8) + i, (i * 8) + (size - 1), NULL);
			setPath(((size - 1) * 8) + i, (i * 8) + (size - 1), NULL);
		}
	}

	// else
	else
	{
		bool check = false; // 같은 이름의 정점을 찾았는지
		int index; // 찾은 정점의 인덱스
		for (int i = 0; i < size; i++)
		{
			// 같으면 0 출력, 다르면 1 출력
			if (strcmp(newVertex.label, vertexList[i].label) == 0)
			{
				index = 0;
				check = true;
				break;
			}
		}
		if (check)
		{
			vertexList[index] = newVertex;
			for (int i = 0; i < size; i++)
			{
				setPath((index * 8) + i, (i * 8) + index, NULL);
				setEdge((index * 8) + i, (i * 8) + index, NULL);
			}
		}
		else
		{
			vertexList[size] = newVertex;
			size++;
			for (int j = 0; j < size; j++)
			{
				setPath(((size - 1) * 8) + j, (j * 8) + (size - 1), NULL);
				setEdge(((size - 1) * 8) + j, (j * 8) + (size - 1), NULL);
			}
		}
	}
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
	if (isEmpty())
	{
		cout << "Graph is Empty." << endl;
	}
	else
	{
		int v1Index = 0, v2Index = 0;

		for (int i = 0; i < size; i++)
		{
			v1Index = getIndex(v1);
			v2Index = getIndex(v2);
		}

		if (v1 != 0 && v2 != 0)
		{
			setEdge((v1Index * 8) + v2Index, (v2Index * 8) + v1Index, wt);
		}
	}
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
	if (isEmpty())
		return 0;
	else
	{
		int index = 0; // v와 같은 정점의 인덱스
		// 찾기
		for (int i = 0; i < size; i++)
		{
			if (strcmp(v, vertexList[i].label) == 0)
			{
				index = i;
				break;
			}
		}
		// 값 바꿔주기
		if (strcmp(v, vertexList[index].label) == 0)
		{
			vertexList[index] = vData;
			return 1;
		}
		return 0;
	}
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
	int v1Index = 0, v2Index = 0;
	if (isEmpty() || size == 1)
		return wt, 0;
	else
	{

		for (int i = 0; i < size; i++)
		{
			v1Index = getIndex(v1);
			v2Index = getIndex(v2);
		}

		if (v1 != 0 && v2 != 0)
		{
			wt = getEdge(v1Index, v2Index);
			return wt, 1;
		}

		else
			return 0;
	}
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
	if (isEmpty())
		cout << "Graph is Empty" << endl;
	else
	{
		int tempA[8][8];//adjMatrix를 임시로 담아둘 이차원 배열
		int tempB[8][8];//adjMatrix를 임시로 담아둘 이차원 배열
		int index = 0;
		for (int i = 0; i < size; i++) {
			if (strcmp(v, vertexList[i].label) == 0)
			{
				index = i;
				break;
			}
		}
		
		if (strcmp(v, vertexList[index].label) == 0) 
		{
			Vertex temp;
			// 배열 가장 끝에 v 값이 있는 경우
			if (index == (size - 1))
			{
				for (int j = 0; j < size; j++)
				{
					setPath((index * 8) + j, (j * 8) + index, NULL);
					setEdge((index * 8) + j, (j * 8) + index, NULL);
				}//끝 값 초기화
			}
			// else
			else
			{
				for (int i = index; i < size; i++)
				{
					temp = vertexList[i + 1];
					vertexList[i] = temp;
				}
				for (int j = 0; j < size; j++)
				{
					setEdge((index * 8) + j, (j * 8) + index, NULL);
					setPath((index * 8) + j, (j * 8) + index, NULL);
				}
				for (int j = 0; j < size; j++)
				{
					for (int i = 0; i < size; i++)
					{
						tempA[j][i] = adjMatrix[(j * 8) + i];
						tempB[j][i] = pathMatrix[(j * 8) + i];
					}
				}
				for (int i = (index + 1); i < size; i++)
				{
					for (int j = 0; j < index; j++)
					{
						tempA[i - 1][j] = tempA[i][j];
						tempA[j][i - 1] = tempA[j][i];
						tempB[i - 1][j] = tempB[i][j];
						tempB[j][i - 1] = tempB[j][i];
					}
				}
				for (int i = (index + 1); i < size; i++)
				{
					for (int j = (index + 1); j < size; j++)
					{
						tempA[i - 1][j - 1] = tempA[i][j];
						tempB[i - 1][j - 1] = tempB[i][j];
					}
				}
				for (int j = 0; j < size - 1; j++)
				{
					for (int i = 0; i < size - 1; i++)
					{
						adjMatrix[(j * 8) + i] = tempA[j][i];
						pathMatrix[(j * 8) + i] = tempB[j][i];
					}
				}
			}
			size--;
		}
	}
}

void WtGraph::removeEdge(char* v1, char* v2)
{
	if (isEmpty() || size == 1)
		cout << "Graph is Empty." << endl;
	else
	{
		int v1Index = 0, v2Index = 0;
		for (int i = 0; i < size; i++)
		{
			v1Index = getIndex(v1);
			v2Index = getIndex(v2);
		}
		if (v1Index != 0 && v2Index != 0)
		{
			setPath((v1Index * 8) + v2Index, (v2Index * 8) + v1Index, NULL);
			setEdge((v1Index * 8) + v2Index, (v2Index * 8) + v1Index, NULL);
		}
	}
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
	for (int i = 0; i < ((size * 8) + size); i++)
	{
		adjMatrix[i] = NULL;
		pathMatrix[i] = NULL;
	}
	size = 0;
}

bool WtGraph::isEmpty() const
{
	if (size == 0) return 1;
	else return 0;
}

bool WtGraph::isFull() const
{
	if (size == maxSize) return 1;
	else return 0;
}

//--------------------------------------------------------------------

void WtGraph::showStructure()
{
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (areAllEven())
		cout << "NOT all vertices have even degree." << endl;
	else
		cout << "All vertices have even degree." << endl;

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getEdge(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}

		cout << endl << "Path matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getPath(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

//--------------------------------------------------------------------

// In-lab 1 functions
 int WtGraph::getPath(int row, int col)
 {
	 if (pathMatrix[(row * 8) + col] = pathMatrix[(col * 8) + row])
		 return pathMatrix[(row * 8) + col];

	 else
		 return infiniteEdgeWt;
 }

 void WtGraph::setPath(int row, int col, int wt)
 {
	 pathMatrix[row] = wt;
	 pathMatrix[col] = wt;
 }

 void WtGraph::computePaths() 
 { 
	 for (int j = 0; j < size; j++)
		 setPath((size * 8) + j, (j * 8) + size, NULL);

	 for (int i = 0; i < ((size * 8) + size); i++)
		 pathMatrix[i] = adjMatrix[i];

	 for (int k = 0; k < size; k++)
	 {
		 for (int i = 0; i < size; i++)
		 {
			 for (int j = 0; j < size; j++)
			 {
				 if (pathMatrix[(i * 8) + j] != 0 && pathMatrix[(i * 8) + k] != 0 && pathMatrix[(k * 8) + j] != 0) {
					 if (pathMatrix[(i * 8) + j] > pathMatrix[(i * 8) + k] + pathMatrix[(k * 8) + j])
					 {
						 pathMatrix[(i * 8) + j] = (pathMatrix[(i * 8) + k] + pathMatrix[(k * 8) + j]);
					 }
				 }
			 }
		 }
	 }
 }

//--------------------------------------------------------------------

// In-lab 3 function
bool WtGraph::areAllEven()
{
	int row, col, temp;
	int cnt = 0; //Edge의 개수

	if (isEmpty())
		return false;

	for (row = 0; row < size; row++)
	{
		cnt = 0;
		for (col = 0; col < size; col++)
		{
			temp = getEdge(row, col);
			if (temp != infiniteEdgeWt)
				cnt++;
		}
		if (cnt & 2 != 0) return false;
	}
	return true;
}