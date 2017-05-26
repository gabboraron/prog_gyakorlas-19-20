#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED
#include <fstream>
#include <vector>
#include <string>

using namespace std;

enum status{norm,abnorm};

struct vasarlas{
    string time;
    string id;
    std::vector<string> things;
};

class enor{
    public:
        enor(const std::string&);
        enum enorerror{OpenError};
        void first();
        void next();
        void current();
        bool end() const;
    private:
        std::ifstream x;
        status sx;
        void read();
        void osszegez();

        vasarlas MostOfItem;
        vasarlas LessOfItem;
        int maxboughtitem = 0;
        bool isfirst = true;
        int minboughtitem = 0;
        int voltarukod23;
};


#endif // ENOR_H_INCLUDED
