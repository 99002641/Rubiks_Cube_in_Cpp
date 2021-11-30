#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <bits/stdc++.h>
using namespace std;

enum actcion { leftUp, leftDown , rightUp, rightDown, upLeft, upRight, downLeft, downRight};

typedef pair<int, vector<int>> pairType;

static priority_queue< pairType, vector<pairType>, greater<pairType> > pq;

void storePaths(vector<int> v)
{
    pairType p;
    p.first  = v.size();
    p.second = v;

    pq.push(p);
}

void printAllPaths()
{
    while(!pq.empty())
    {
        auto i = pq.top();
        pq.pop();
        cout<<" size : "<<i.first<<"\n";

        for(auto j : i.second)
        {
            cout<<" ,"<<j;
        }
        cout<<"\n";
    }
}

void swap0(vector<int>& vec)
{
    int temp = vec[0];
    vec[0] = vec[1];
    vec[1] = temp;
}

void swap1(vector<int>& vec)
{
    int temp = vec[1];
    vec[1] = vec[2];
    vec[2] = temp;
}

void swap2(vector<int>& vec)
{
    int temp = vec[2];
    vec[2] = vec[3];
    vec[3] = temp;
}

void swap3(vector<int>& vec)
{
    int temp = vec[3];
    vec[3] = vec[4];
    vec[4] = temp;
}

void swap4(vector<int>& vec)
{
    int temp = vec[4];
    vec[4] = vec[5];
    vec[5] = temp;
}

void swap5(vector<int>& vec)
{
    int temp = vec[5];
    vec[5] = vec[6];
    vec[6] = temp;
}

void swap6(vector<int>& vec)
{
    int temp = vec[6];
    vec[6] = vec[7];
    vec[7] = temp;
}

void swap7(vector<int>& vec)
{
    int temp = vec[7];
    vec[7] = vec[8];
    vec[8] = temp;
}


vector<int> getPaths(std::vector<int> vec, int code, int count, std::vector<int> paths)
{
    if(count >= 7)
    {
        vector<int> v;
        return v;
    }

    if(code < 8)
        paths.push_back(code);

    switch (code)
    {
    case leftUp: {
        // leftUp();
        swap0(vec);
        break;

    }

    case leftDown: {
        // leftDown();
        swap1(vec);
        break;
    }

    case rightUp: {
        // rightUp();
        swap2(vec);
        break;
    }

    case rightDown: {
        // rightDown();
        swap3(vec);
        break;
    }

    case upLeft: {
        // upLeft();
        swap4(vec);
        break;
    }

    case upRight: {
        // upRight();
        swap5(vec);
        break;
    }

    case downLeft: {
        // downLeft();
        swap6(vec);
        break;
    }

    case downRight: {
        // downRight();
        swap7(vec);
        break;
    }

    default :
        break;

    }

    // for(auto i : vec)
    // cout<<" "<<i;
    // cout<<" code : "<<code;
    // cout<<"\n\n";

    //  if((vec[0] == vec[1] == vec[2] == vec[3]) &&
    // (vec[4] == vec[5] == vec[6] == vec[7]) &&
    // (vec[8] == vec[9] == vec[10] == vec[11]) &&
    // (vec[12] == vec[13] == vec[14] == vec[15]))
    // return paths;


    if((vec[0] == vec[1]) &&
            (vec[2] == vec[3]) &&
            (vec[4] == vec[5]) &&
            (vec[6] == vec[7]))
    {
        //   cout<<" found combination :";
        //     for(auto i : vec)
        // cout<<" "<<i;
        // cout<<" code : "<<code;
        // cout<<"\n";

        //  cout<<" path :";
        //     for(auto j : paths)
        // cout<<", "<<j;
        // cout<<"\n\n";

        if(pq.empty())
        {
            storePaths(paths);
            return paths;
        }

        if(paths.size() <= pq.top().first)
        {
            cout<<" paths.size() :" <<paths.size();
            storePaths(paths);
        }

        return paths;
    }


    vector<int> vec1;

    //leftUp
    if(getPaths(vec, leftUp, count+1, paths).size() != 0)
        vec1 = getPaths(vec, leftUp, count+1, paths);

    //leftDown
    if(getPaths(vec, leftDown, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, leftDown, count+1, paths).size())
        vec1 = getPaths(vec, leftDown, count+1, paths);

    //rightUp
    if(getPaths(vec, rightUp, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, rightUp, count+1, paths).size())
        vec1 = getPaths(vec, rightUp, count+1, paths);

    //rightDown
    if(getPaths(vec, rightDown, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, rightDown, count+1, paths).size())
        vec1 = getPaths(vec, rightDown, count+1, paths);

    // //upLeft
    // if(getPaths(vec, upLeft, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, upLeft, count+1, paths).size())
    // vec1 = getPaths(vec, upLeft, count+1, paths);

    // //upRight
    // if(getPaths(vec, upRight, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, upRight, count+1, paths).size())
    // vec1 = getPaths(vec, upRight, count+1, paths);

    // //downLeft
    // if(getPaths(vec, downLeft, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, downLeft, count+1, paths).size())
    // vec1 = getPaths(vec, downLeft, count+1, paths);

    // //downRight
    //  if(getPaths(vec, downRight, count+1, paths).size() != 0 && vec1.size() > getPaths(vec, downRight, count+1, paths).size())
    // vec1 = getPaths(vec, downRight, count+1, paths);

    return vec1;

}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    vector<int> vec = { 1, 2, 2, 1, 3, 3, 4, 4 };
    vector<int> path;
    vector<int> vec1 = getPaths(vec, 10, 0, path );

    printAllPaths();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

