#include "Sheet.h"

Sheet::Sheet() : _path("") {}

Sheet::Sheet(std::string path) : _path(std::move(path)) {}

void Sheet::setPath(const std::string& path)
{
    _path = path;
}

void Sheet::write(const std::vector<std::vector<std::string>>& data) const
{
    std::fstream file;
    file.open(_path, std::ios::out);

    for (auto element : data)
    {
        std::string s;
	    for (auto basicString : element)
	    {
            s.append(basicString + ";");
	    }
        file << s << "\n";
    }

    file.close();
}


/**
 * read csv file as table of floats
 *
 * all "" (empty strings) converts to 0, be careful
 * all not empty strings will crash with exception BE CAREFUL TWICE !!!
 */
std::vector<std::vector<float>> Sheet::readAsFloat() const
{
    auto* data = new std::vector<std::vector<float>>;

    // File pointer
    std::fstream file;
    file.open(_path, std::ios::in);

    std::vector<float> row;
    std::string word, line;

    while (file >> line) 
    {
        row.clear();

        // used for breaking words
        std::stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ';'))
        {
            if(word.empty())
            {
	            row.push_back(0);
            }
            else
            {
                float num = std::stof(word);
                row.push_back(num);
            }
        }

        // add current row to data vector
    	data->push_back(row);
    }

    file.close();

    return *data;
}

