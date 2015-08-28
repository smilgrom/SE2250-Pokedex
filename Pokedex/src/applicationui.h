#ifndef ApplicationUI_H_
#define ApplicationUI_H_
#include <bb/cascades/AbstractPane>
#include <bb/cascades/DropDown>
#include <QObject>

namespace bb
{
    namespace cascades
    {
        class Application;
    }
}
using namespace bb::cascades;
/*!
 * @brief Application object
 *
 *
 */
class PokemonList; // forward declaration to avoid including header

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    void init(int langInd);
    // callables from QML
    Q_INVOKABLE void typeSelected(int type);
    Q_INVOKABLE void languageSelected(int language);

    virtual ~ApplicationUI() { }
private:
    PokemonList *m_pokemonList;
    DropDown *dropDown;
    AbstractPane *root;

};

#endif /* ApplicationUI_H_ */
