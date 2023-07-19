#ifndef SDDS_LBSHAPE_H
#define SDDS_LBSHAPE_H

#include "Shape.h"

namespace sdds {
	class LbShape : public Shape {
		char* m_label{ nullptr };
	protected:
		const char* label() const;
	public:
		LbShape();
		LbShape(const char* label);
		~LbShape();
		LbShape(const LbShape& labelShape) = delete;
		LbShape& operator=(const LbShape& labelShape) = delete;
		void getSpecs(std::istream& is);
	};
}



#endif // !SDDS_LBSHAPE_H
