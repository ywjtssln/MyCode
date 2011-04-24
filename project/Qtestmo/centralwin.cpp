#include "centralwin.h"

CentralWin::CentralWin()
{
	setStyleSheet("* { background: blue}");
#if 0
	vl = new QVBoxLayout();
	central_win = new QStackedWidget(this);
	tool_button = new ToolButton();

	central_win->setStyleSheet("* { background: blue}");
	central_win->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	tool_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	tool_button->setStyleSheet("* { background: green}");
	tool_button->setFixedHeight(100);

	vl->setContentsMargins(0, 0, 0, 0);
	vl->setSpacing(0);
	vl->addWidget(central_win);
	vl->addWidget(tool_button);

	setLayout(vl);

#endif


}
