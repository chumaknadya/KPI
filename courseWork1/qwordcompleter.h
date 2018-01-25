#ifndef QWORDCOMPLETER_H
#define QWORDCOMPLETER_H



#include <QCompleter>




class QWordCompleter : public QCompleter
{
    Q_OBJECT
public:
    QWordCompleter(const QStringList& completions, QObject *parent = Q_NULLPTR);
    ~QWordCompleter();

    // QObject interface
public:
    virtual bool eventFilter(QObject *o, QEvent *e);
    int getMinCompletionPrefixLength() const;
    void setMinCompletionPrefixLength(int value);
public slots:
    void replaceCurrentWord(QString text);
private:
    int minCompletionPrefixLength = 1;
};

#endif // QWORDCOMPLETER_H
