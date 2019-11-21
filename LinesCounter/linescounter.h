#ifndef LINESCOUNTER_H
#define LINESCOUNTER_H

#include <QString>

class LinesCounter
{
public:
    LinesCounter(const QString& filePath);
    void Counter();
    int GetCodeLines() const;
    int GetCommentLines() const;
    int GetBlankLines() const;
private:
    QString filePath;
    int codeLines;
    int commentLines;
    int blankLines;
};

#endif // LINESCOUNTER_H
