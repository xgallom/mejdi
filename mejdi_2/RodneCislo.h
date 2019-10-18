//
// Created by xgallom on 10/18/19.
//

#ifndef MEJDI_2__RODNECISLO_H
#define MEJDI_2__RODNECISLO_H

namespace Mesiac {
	enum Enum {
		Januar,
		Februar,
		Marec,
		April,
		Maj,
		Jun,
		Jul,
		August,
		September,
		October,
		November,
		December,

		Size
	};
}

namespace Pohlavie {
	enum Enum : bool {
		Muz,
		Zena
	};
}

class RodneCislo {
public:
	int rokNarodenia();
	Mesiac::Enum mesiacNarodenia();
	int denNarodenia();

	Pohlavie::Enum pohlavie();

	static RodneCislo precitajRodneCislo();
private:
	char m_rodneCislo[12];
	Pohlavie::Enum m_pohlavie;
};

std::ostream &operator<<(std::ostream &os, const Mesiac::Enum &mesiac);
std::ostream &operator<<(std::ostream &os, const Pohlavie::Enum &pohlavie);

#endif //MEJDI_2__RODNECISLO_H
