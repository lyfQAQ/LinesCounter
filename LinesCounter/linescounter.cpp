#include "linescounter.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LinesCounter::LinesCounter(const QString &filePath)
            :filePath(filePath),codeLines(0), commentLines(0),
             blankLines(0)
{
}

void LinesCounter::Counter()
{
    QString line;
    QFile file(filePath);
    if(file.open(QFile::ReadOnly))
    {
        QTextStream out(&file);
        while(!out.atEnd())
        {
           line = out.readLine();
           if(line.startsWith(" "))
               line.remove(" ");

           if(line.startsWith("/*"))
           {
               commentLines++;
               line = out.readLine();
               while(!line.endsWith("*/"))
               {
                   if(line == "")
                       blankLines++;
                    else
                       commentLines++;
                   line = out.readLine();
               }
           }
           else if(line.startsWith("//"))
           {
                commentLines++;
           }
           else if(line == "")
               blankLines++;
           else
               codeLines++;
        }
    }

}

int LinesCounter::GetCodeLines() const
{
    return codeLines;
}

int LinesCounter::GetCommentLines() const
{
    return commentLines;
}

int LinesCounter::GetBlankLines() const
{
    return blankLines;
}
