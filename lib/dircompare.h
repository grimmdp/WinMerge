#ifndef DIRCOMPARE_H
#define DIRCOMPARE_H

class QString;
class QDir;

class DirCompare
{
public:
    DirCompare(const QString &left, const QString &right);
    ~DirCompare();

    void DoCompare();

private:
    QDir *mLeftDir;
    QDir *mRightDir;
};

#endif // DIRCOMPARE_H
