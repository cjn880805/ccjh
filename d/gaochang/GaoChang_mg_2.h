//GaoCang_mg_2.h ʮ�˵������һ
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_2);

virtual void create()			
{
	set_name("��Ȫ֮·");

	CDoor * a = add_yewaidoor("west", 3, 20);
	CDoor * b = add_yewaidoor("north", 3, 20);
	CDoor * c = add_yewaidoor("east", 3, 20);
	CDoor * d = add_yewaidoor("south", 3, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("�߲��Թ�", "�߲��Թ�", "�߲���Ȫ֮·");
	add_npc("dy_master");

	set("long", "������ͨ��ʮ�˵����ġ���Ȫ�������ܵ����걻һ��Ī�������������ţ�����һ���޴�ĵ��¶�Ѩ��Ե�������ϵ�������ȥ��");


};

YEWAIDOOR_END;
