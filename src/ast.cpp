#include <iostream>
#include <string>
#include "ast.h"

using namespace std;


/*
Methode  : eval
Klasse : IntExp
Beschreibung :
    Gibt den Wert des Knotens zurück.
.

Parameter:
	keine

Rückgabe:
	Numerischer Wert der dem Wert dieses Knotens entspricht
*/

int IntExp::eval() { return val; }

/*
Methode  : pretty
Klasse : IntExp
Beschreibung :
    Bearbeitet den aktuellen Knoten einer Ganzzahl Ausdrucks und gibt diesem als ein Stringobjekt zurück.
.

Parameter:
	keine

Rückgabe:
	ein Stringobjekt mit der Textrepresentation dieses Knotens.
*/


string IntExp::pretty() {
    return to_string(val);
}

string IntExp::superPretty() {
    return (this->pretty());
}

vector<Code> IntExp::translate() {
    vector<Code> a;
    a.push_back(newPush(val));
    return a;
}


/*
Methode  : eval
Klasse : IntExp
Beschreibung :
    Berehnet den wert des knotens, sowie aller Tochterknoten.

Parameter:
	keine

Rückgabe:
	Numericher Wert der dem wert dieses Knotens sowie aller Tochterknotten entspricht
*/


int PlusExp::eval() { return e1->eval() + e2->eval(); }

/*
Methode  : pretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten einer Additionsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit eine Anfangs sowie endklammer versehen.

Parameter:
	keine

Rückgabe:
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
string PlusExp::pretty() {
    string s("(");                // "klammer öffnen" anhängen
    s.append(e1->pretty());        // linken Knotten ausführen und das Ergebnis anhängen
    s.append("+");                // Pluszeichen anhängen
    s.append(e2->pretty());        // rechten Knotten ausführen und das Ergebnis anhängen
    s.append(")");                // "klammer zu" anhängen
    return s;
}


string PlusExp::superPretty() {
    return ("");
}

vector<Code> PlusExp::translate() {
    vector<Code> a = e1->translate();
    vector<Code> b = e2->translate();
    a.insert(a.end(), b.begin(), b.end());
    a.push_back(newPlus());
    return a;
}

/*
Methode  : eval
Klasse : MultExp
Beschreibung :
    Berehnet den wert des knotens, sowie aller Tochterknoten.
.

Parameter:
	keine

Rückgabe:
	Numericher Wert der dem wert dieses Knotens sowie aller Tochterknotten entspricht
*/

int MultExp::eval() { return e1->eval() * e2->eval(); }

/*
Methode  : pretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten eines Multiplikationsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit eine Anfangs- sowie Endklammer versehen.

Parameter:
	keine

Rückgabe:
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
string MultExp::pretty() {
    string s("(");                // "klammer öffnen" anhängen
    s.append(e1->pretty());    // linken Knotten durchwandern und das Ergebnis anhängen
    s.append("*");                // multiplikationszeichen anhängen
    s.append(e2->pretty());        // rechten Knotten ausführen und das Ergebnis anhängen
    s.append(")");                // "klammer zu" anhängen
    return s;
}

string MultExp::superPretty() {
    return ("");
}

vector<Code> MultExp::translate() {
    vector<Code> a = e1->translate();
    vector<Code> b = e2->translate();
    a.insert(a.end(), b.begin(), b.end());
    a.push_back(newMult());
    return a;
}


/*
Methode  : newInt
Klasse : IntExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ IntExp.
	Der neu erstellter Knoten ist immer ein Endknoten und bestzt selbst keine Äste.

Parameter:
	i - wert des Knotens.

Rückgabe:
	ein Objekt vom TYP IntExp
*/


EXP newInt(int i) {
    return std::make_shared<IntExp>(i);
}

/*
Methode  : newPlus
Klasse : PlusExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ PlusExp.
	Der Objekt PlusExp ist ein Knoten der immer zwei Äste besitz.
	Dem knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.

Parameter:
	l - linker Ausdruck
	r - rechter Ausdruck

rückgabe:
		ein Objekt vom TYP PlusExp
*/
EXP newPlus(EXP l, EXP r) {
    return std::make_shared<PlusExp>(l, r);
}

/*
Methode  : newMult
Klasse : MultExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ MultExp.
	Der Objekt MultExp ist ein Knoten der immer zwei Äste besitz.
	Dem Knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.

Parameter:
	l - linker Ausdruck
	r - rechter Ausdruck

rückgabe:
		ein Objekt vom TYP PlusExp
*/

EXP newMult(EXP l, EXP r) {
    return std::make_shared<MultExp>(l, r);
}
