//GaoCang_mg.h �߲��Թ�
//�ز� 2002.11.12

YEWAIDOOR_BEGIN(CRGaoChang_mg);

virtual void create()			
{
	set_name("�߲��Թ�");

	CDoor * a = add_yewaidoor("west", 2, 20);
	CDoor * b = add_yewaidoor("north", 2, 20);
	CDoor * c = add_yewaidoor("east", 2, 20);
	CDoor * d = add_yewaidoor("south", 2, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("�ƺ�ɳĮ2", "�ƺ�ɳĮ2", "�߲��Թ�");

};

YEWAIDOOR_END;
