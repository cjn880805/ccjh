//GaoCang_mg_4.h ������������Ź�
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_4);

virtual void create()			
{
	set_name("���Ź�");

	CDoor * a = add_yewaidoor("west", 5, 20);
	CDoor * b = add_yewaidoor("north", 5, 20);
	CDoor * c = add_yewaidoor("east", 5, 20);
	CDoor * d = add_yewaidoor("south", 5, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("�κ���", "�߲��κ���", "�߲����Ź�");
	add_npc("dy_master");

	set("long", "һ����ʽ¥ͤ���ĽǷ��ܡ���ڵ�ɽ�ſ�����������ã��Ѫ���ĺ����ϣ����ź��˵ġ����Źء��������֣�����עĿ���ز������Σ�ȸѻ���룬�������£�������ɭ�ֲ�֮�С�");

};

YEWAIDOOR_END;
