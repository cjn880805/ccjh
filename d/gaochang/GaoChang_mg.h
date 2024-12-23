//GaoCang_mg.h ธ฿ฒýรินฌ
//วุฒจ 2002.11.12

YEWAIDOOR_BEGIN(CRGaoChang_mg);

virtual void create()			
{
	set_name("ธ฿ฒýรินฌ");

	CDoor * a = add_yewaidoor("west", 2, 20);
	CDoor * b = add_yewaidoor("north", 2, 20);
	CDoor * c = add_yewaidoor("east", 2, 20);
	CDoor * d = add_yewaidoor("south", 2, 20);

	a->set_name("รินฌฮ๗");
	b->set_name("รินฌฑฑ");
	c->set_name("รินฌถซ");
	d->set_name("รินฌฤฯ");
	add_door("ปฦบำษณฤฎ2", "ปฦบำษณฤฎ2", "ธ฿ฒýรินฌ");

};

YEWAIDOOR_END;
