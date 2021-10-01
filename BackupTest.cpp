#include "Backup.h"

int main()
{

    std::string str = selectPath();
    std::string str2 = selectPath();

    fs::path p1(str);
    fs::path p2(str2);

    fs::copy(p1, p2 / getLastPathToken(str), fs::copy_options::recursive | fs::copy_options::overwrite_existing);

    return 0;
}

std::string selectPath()
{
    int size = 100;
    char Bufor[100];
    const char zenityP[] = "/usr/bin/zenity";
    char Call[2048];

    sprintf(Call, "%s --file-selection --directory --modal --title=\"%s\" ", zenityP, "Select file");

    FILE *f = popen(Call, "r");
    fgets(Bufor, size, f);

    int ret = pclose(f);
    if (ret < 0)
        perror("file_name_dialog()");

    // convert string to path object
    std::string str = Bufor;
    return str.substr(0, str.length() - 1);
}

std::string getLastPathToken(std::string str)
{
    std::istringstream ss(str);
    std::string stringBuffer;
    std::vector<std::string> x;
    x.clear();
    while (getline(ss, stringBuffer, '/'))
    {
        x.push_back(stringBuffer);
        int size = 100;
    }

    // last dir name from path
    return x[x.size() - 1];
}